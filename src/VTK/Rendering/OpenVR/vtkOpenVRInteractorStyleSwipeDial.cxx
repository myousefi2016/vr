/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleSwipeDial.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStyleSwipeDial.h"

#include "vtkNew.h"
#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"
#include <valarray>
#include "vtkRenderWindowInteractor3D.h"

#include <vector>
#include <deque>
#include <utility>	//std::pair
#include <iterator>
#include "vtkOpenVRRenderWindowInteractor.h"
#include "vtkTextActor3D.h"
#include "vtkTextProperty.h"
#include "vtkStdString.h"
#include "vtkRenderer.h"
#include "vtkOpenVRRenderer.h"
#include "vtkOpenVRCamera.h"
#include "vtkVariant.h"
#include "vtkPNGReader.h"
#include "vtkImageActor.h"
#include "vtkImageMapper3D.h"

#include "vtkOpenVRTextFeedback.h"
#include "vtkOpenVRTouchPadImage.h"
#include "vtkOpenVRTouchPadPointer.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyleSwipeDial);

//A/R: (A)bsolute/(R)elative increment
//D/I: (D)ecimal/(I)nteger adjust
//S/F: (S)low/(F)ast swipe
const double ADS = 0.01;
const double ADF = 0.1;
const double AIS = 1.;
const double AIF = 10.;
const double RS = 0.01;
const double RF = 0.1;


//PIMPL to use STL (ref: VTKUsersGuide, 303)
typedef std::pair<double, double> AngleRadius;
typedef std::deque<AngleRadius> AngleRadiusBase;
class vtkDequeAngleRadius:
	public AngleRadiusBase {};
		


	

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwipeDial::vtkOpenVRInteractorStyleSwipeDial()
{
	this->AngleRadiusRecord = new vtkDequeAngleRadius;
	this->AbsoluteInc = true;
	//this->PositiveInc = true;

	//Text3D to modify Props' attributes.
	this->TextFeedback = vtkOpenVRTextFeedback::New();
	

	//Images
	/*this->ImgReader = vtkPNGReader::New();
	this->HasImage = true;
	this->NextImage = 0;

	//In this class, only one image needed.
	this->ImgReader->SetFileName("..\\..\\..\\VTK\\Rendering\\OpenVR\\SwipeDial_Image0.png");
	ImgReader->Update();

	this->ImgActor = vtkImageActor::New();
	this->ImgActor->GetMapper()->SetInputData(this->ImgReader->GetOutput());
	this->ImgActor->PickableOff();
	this->ImgActor->DragableOff();
	this->ImgRenderer = NULL;*/
	this->TouchPadImage = vtkOpenVRTouchPadImage::New();
	this->TouchPadImage->LoadSingleImage("..\\..\\..\\VTK\\Rendering\\OpenVR\\SwipeDial_Image0.png");
	this->TouchPadImage->Init();



	//TouchPad Pointer
	this->TouchPadPointer = vtkOpenVRTouchPadPointer::New();

}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwipeDial::~vtkOpenVRInteractorStyleSwipeDial()
{
	delete this->AngleRadiusRecord;

	//Remove Text3D
	if (this->TextFeedback)
	{
		this->TextFeedback->Delete();
	}

	//Remove Image:
	/*this->SetTouchPadImage(false);
	if (this->ImgActor)
	{
		this->ImgActor->Delete();
	}
	if (this->ImgReader)
	{
		this->ImgReader->Delete();
	}
	if (this->ImgRenderer)
	{
		this->ImgRenderer->Delete();
	}*/
	if (this->TouchPadImage)
	{
		this->TouchPadImage->Delete();
	}

	//Delete pointer
	if (this->TouchPadPointer)
	{
		this->TouchPadPointer->Delete();
	}

}

/*
//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::OnSwipe()	//adapted from vtkInteractorStyle3D::OnMouseMove()
{
	//NOTE May be useful on the future: vr::VREvent_ButtonTouch

	//Do I need another function where to set state == VTKIS_SWIPE ? I think so.
	switch(this->State)
	{
		//case VTKIS_ ...
	}
}

void vtkOpenVRInteractorStyleSwipeDial::OnLongTap()
{
	int x = this->Interactor->GetEventPosition()[0];
	int y = this->Interactor->GetEventPosition()[1];
	this->FindPokedRenderer(x, y);
	if (this->CurrentRenderer == NULL)
	{
		return;
	}
}
*/

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::OnRightButtonDown()
{
	if (this->TextFeedback->GetTextIsVisible() && this->TextFeedback->GetTextActor())
	{
		//Downcast to a 3D Interactor.
		vtkRenderWindowInteractor3D *rwi =
			static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

		float x = rwi->GetTouchPadPosition()[0];	// Values between -1 and 1.
		float y = rwi->GetTouchPadPosition()[1];

		float radius = sqrt(x*x + y*y);

		int region = int(8. * atan2(x, y) / vtkMath::Pi());		// Clockwise values, starting in (x,y) = (0,1)
		region = (x > 0) ? region : (region + 15);						// 16 regions. Integer values in range [0, 15]

		if (this->TextFeedback->GetDefaultMsgOn())
		{
			this->TextFeedback->GetTextActor()->SetInput("1");		//Create field with message (avoid hardcoding)
			this->TextFeedback->SetDefaultMsgOn(false);
			this->TextFeedback->SetHasUnsavedChanges(true);
		}

		double newValue = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToDouble();

		if (radius > .65)
		{
			switch(region)
			{
			case 4:		newValue *= 1.02;			break;
			case 5:		newValue *= 1.05;			break;
			case 11:	newValue *= 0.98;			break;
			case 10:	newValue *= 0.95;			break;
			case 6:		newValue *= 4;				break;
			case 7:		newValue *= 8;				break;
			case 9:		newValue /= 4;				break;
			case 8:		newValue /= 8;				break;
			case 3:		AbsoluteInc = true;		break;
			case 12:	AbsoluteInc = false;	break;
			default: break;
			}

			this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
			this->TextFeedback->SetHasUnsavedChanges(true);
		}
		else if (radius > .3)
		{
			switch (region)
			{
			case 4: case 5:		newValue *= 1.01;	break;
			case 10: case 11:	newValue *= 0.99;	break;
			case 6: case 7:		newValue *= 2;		break;
			case 8: case 9:		newValue /= 2;		break;
			default: break;
			}

			this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
			this->TextFeedback->SetHasUnsavedChanges(true);
		}
		else
		{
			if(region < 8)	// Accept value
			{
				this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOff();
				this->TextFeedback->SetHasUnsavedChanges(false);
			}
			else			// Restore default: 0
			{
				newValue = 0;	//Add field with the value (as a string?)
				this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
				this->TextFeedback->SetHasUnsavedChanges(true);
			}
		}

		this->TextFeedback->GetTextActor()->SetInput(vtkVariant(newValue).ToString());
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::OnRightButtonUp()
{
	// do nothing except overriding the default OnRightButtonDown behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::OnMiddleButtonDown()
{
	//Get current renderer (if is not got already)
	if (this->Interactor)
	{
		int pointer = this->Interactor->GetPointerIndex();
		this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
			this->Interactor->GetEventPositions(pointer)[1]);
	}

	bool TextEmpty = false;
	if (this->TextFeedback->GetTextActor()) TextEmpty = !bool(vtkStdString(" ").compare(this->TextFeedback->GetTextActor()->GetInput()));

	//Second Click. Already created and changes saved: can be hidden.
	if (this->TextFeedback->GetTextActor() && this->TextFeedback->GetTextRenderer() != NULL
		&& (!this->TextFeedback->GetHasUnsavedChanges() || TextEmpty))
	{

		if (this->TextFeedback->GetTextRenderer() != NULL && this->TextFeedback->GetTextActor())
		{
			//Remove from renderer
			this->TextFeedback->GetTextRenderer()->RemoveViewProp(this->TextFeedback->GetTextActor());
			this->TextFeedback->SetTextRenderer(NULL);
			//Restore initial values
			this->TextFeedback->GetTextActor()->SetInput(this->TextFeedback->GetTextDefaultMsg());
			this->TextFeedback->SetDefaultMsgOn(true);
			this->TextFeedback->SetTextIsVisible(false);

			//Test:
			//this->ShowTestActor(false);
		}
	}
	//Either or is not created or has changes or is not shown
	else
	{
		//First Click ever. Not created yet: create it and place it properly.
		if (!this->TextFeedback->GetTextActor())
		{
			this->TextFeedback->Init();
		}

		//First Click. Created but not shown. Check if used different renderer to previous visualization.
		if (this->CurrentRenderer != this->TextFeedback->GetTextRenderer())
		{
			if (this->TextFeedback->GetTextRenderer() != NULL && this->TextFeedback->GetTextActor())
			{
				this->TextFeedback->GetTextRenderer()->RemoveViewProp(this->TextFeedback->GetTextActor());
			}
			if (this->CurrentRenderer != 0)
			{
				this->CurrentRenderer->AddViewProp(this->TextFeedback->GetTextActor());
			}
			else
			{
				vtkWarningMacro(<< "no current renderer on the interactor style.");
			}
			this->TextFeedback->SetTextRenderer(this->CurrentRenderer);
			this->TextFeedback->SetTextIsVisible(true);
			this->TextFeedback->SetHasUnsavedChanges(false);

			//Test:
			//this->ShowTestActor(true);
		}

	}

	//Place text opposite to the camera
	vtkOpenVRRenderer *ren = vtkOpenVRRenderer::SafeDownCast(this->CurrentRenderer);
	vtkOpenVRCamera *camera = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());

	double wScale = camera->GetDistance();			//World scale
	double *camPos = camera->GetPosition();         //Camera Position
	double *camOri = camera->GetOrientation();		//Camera Orientation: rotation in (X,Y,Z)

	const double d2c = 0.5;		//Text distance to camera.

								//3D Rotation and Translation Maths
	double cosw = cos(vtkMath::RadiansFromDegrees(camOri[1]));
	double sinw = sin(vtkMath::RadiansFromDegrees(camOri[1]));
	double projection[3] = { sinw, 0, -cosw };
	vtkMath::Normalize(projection);

	double txtPos[3];

	for (int i = 0; i < 3; i++)
		txtPos[i] = camPos[i] + projection[i] * d2c;

	this->TextFeedback->GetTextActor()->SetScale(0.00125 * wScale);	//Default scale is ridiculously big
	this->TextFeedback->GetTextActor()->SetOrientation(0, -camOri[1], 0);
	this->TextFeedback->GetTextActor()->SetPosition(txtPos);
	this->TextFeedback->GetTextActor()->GetTextProperty()->SetFontSize(60);

	//Render Scene
	if (this->Interactor)
	{
		this->Interactor->Render();
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::OnMiddleButtonUp()
{
	// do nothing except overriding the default OnMiddleButtonUp behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::OnUntap()
{
	this->FlushValues();

	Superclass::OnUntap();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::TrackFinger()
{
	vtkErrorMacro(<< "TrackFinger()");
	if (this->TextFeedback->GetTextIsVisible())
	{
		//current renderer
		if (this->Interactor)
		{
			int pointer = this->Interactor->GetPointerIndex();
			this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
				this->Interactor->GetEventPositions(pointer)[1]);
		}

		//Touchpad position (-1,1)
		vtkOpenVRRenderWindowInteractor *rwi =
			static_cast<vtkOpenVRRenderWindowInteractor *>(this->Interactor);
		float *tpos = rwi->GetTouchPadPosition();
		float angle = 180. * atan2(tpos[0], tpos[1]) / vtkMath::Pi();	//Angle in degrees.
		float radius = sqrt(tpos[0] * tpos[0] + tpos[1] * tpos[1]);

		//Update record: Add new values and remove old values if maximum is reached:
		if (this->AngleRadiusRecord->size() == MAX_REC)
		{
			this->AngleRadiusRecord->pop_front();
		}
		this->AngleRadiusRecord->push_back(AngleRadius(angle, radius));

		// Find out direction of swipe
		switch (this->GetSwipeDirection())
		{
		case -1:	//Anti-clockwise
			this->UpdateValue();
			break;
		case 1:		//Clockwise
			this->UpdateValue();
			break;
		default:
			break;
		}
	}
}

//----------------------------------------------------------------------------
double vtkOpenVRInteractorStyleSwipeDial::GetAngle(int pos)
{
	return this->AngleRadiusRecord->at(pos).first;
}

//----------------------------------------------------------------------------
double vtkOpenVRInteractorStyleSwipeDial::GetRadius(int pos)
{
	return this->AngleRadiusRecord->at(pos).second;
}

//----------------------------------------------------------------------------
double vtkOpenVRInteractorStyleSwipeDial::GetAvgDiffAngle()
{
	//Sum all of them (always incremental values) and get average (used to get swiping speed)
	double diffAngle = 0;
	std::deque<AngleRadius>::iterator it1 = AngleRadiusRecord->begin();
	std::deque<AngleRadius>::iterator it2 = ++(AngleRadiusRecord->begin());
	for (it1, it2; it2 != AngleRadiusRecord->end(); ++it1, ++it2)
	{
		diffAngle += fabs(it1->first - it2->first);
	}
	diffAngle /= this->AngleRadiusRecord->size();
	return diffAngle;
}

//----------------------------------------------------------------------------
double vtkOpenVRInteractorStyleSwipeDial::GetAvgRadius()
{
	double radius = 0.0;
	std::deque<AngleRadius>::iterator it = AngleRadiusRecord->begin();
	for (it; it != AngleRadiusRecord->end(); ++it)
	{
		radius += it->second;
	}
	radius /= this->AngleRadiusRecord->size();
	return radius;
}

//----------------------------------------------------------------------------
int vtkOpenVRInteractorStyleSwipeDial::GetSwipeDirection()
{
	if (AngleRadiusRecord->size() < MAX_REC)
	{
		return 0;
	}

	int dir = 0;
	std::deque<AngleRadius>::reverse_iterator it1 = ++(AngleRadiusRecord->rbegin());
	std::deque<AngleRadius>::reverse_iterator it2 = AngleRadiusRecord->rbegin();

	//Instantaneus stop when pausing the finger.
	if(fabs(it1->first - it2->first) < 1)
	{
		this->FlushValues();
		return 0;
	}

	vtkErrorMacro(<< "Number of points: " << AngleRadiusRecord->size());

	for (it1, it2; it1 != AngleRadiusRecord->rend(); ++it1, ++it2)
	{
		if (it1->first - it2->first < -1) dir++;
		else if (it2->first - it1->first < -1) dir--;
		//else, difference of 1 degree is too close to consider movement.
	}

	//Normalize to {-1, 0, 1}
	if (dir != 0) dir /= abs(dir);
	return dir;
}

/*
//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::DecValue()
{
	double AvgRadius = this->GetAvgRadius();
	double AvgDiffAngle = this->GetAvgDiffAngle();
	
	//Modification can be fine or rough, depending on avg radius and diff angle.
	//Think about an algorithm.
}
//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::IncValue()
{

	if(this->TextActor)
	{
		//Ensure there is a number
		if (this->TextDefaultMsg)
		{
			this->TextActor->SetInput("1");		//Set to 0 in the future. This is only to check buttons. Also, create field with message (avoid hardcoding)
			TextDefaultMsg = false;
			TextHasUnsavedChanges = true;
		}

		double AvgRadius = this->GetAvgRadius();
		double AvgDiffAngle = this->GetAvgDiffAngle();

		double newNum = vtkVariant(this->TextActor->GetInput()).ToDouble();

		//Debug purposes
		vtkErrorMacro(<< "AvgRadius:    " << AvgRadius);
		vtkErrorMacro(<< "AvgDiffAngle: " << AvgDiffAngle);


		//Modification can be fine or rough, depending on avg radius and avg diff angle.
		//Think about an algorithm.

		if (AvgRadius > 0.5)	//Outer circle. Decimal adjust
		{
			if (AvgDiffAngle > 20.)	//TODO adjust values.
			{	//Fast swipe
				newNum += 0.1;
			}
			else if (AvgDiffAngle > 1.)
			{	//Slow swipe
				newNum += 0.01;
			}
			//else no swipe
		}
		else	//Inner circle. Integer adjust.
		{
			if (AvgDiffAngle > 25.)	//TODO adjust values.
			{	//Fast swipe
				newNum += 10;
			}
			else if (AvgDiffAngle > 1.)
			{	//Slow swipe
				newNum += 1;
			}
			//else no swipe
		}
		//else, too close to the center. Do nothing.
		this->TextActor->SetInput(vtkVariant(newNum).ToString());

		//Start tracking next set of movements
		this->FlushValues();
	}
}
*/

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::UpdateValue()
{

	if (this->TextFeedback->GetTextActor())
	{
		//Ensure there is a number
		if (this->TextFeedback->GetDefaultMsgOn())
		{
			this->TextFeedback->GetTextActor()->SetInput("1");
			this->TextFeedback->SetDefaultMsgOn(false);
			this->TextFeedback->SetHasUnsavedChanges(true);
		}

		double AvgRadius = this->GetAvgRadius();
		double AvgDiffAngle = this->GetAvgDiffAngle();
		int swipeDir = this->GetSwipeDirection();

		double newNum = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToDouble();

		//Debug purposes
		vtkErrorMacro(<< "AvgRadius:    " << AvgRadius);
		vtkErrorMacro(<< "AvgDiffAngle: " << AvgDiffAngle);

		//Modification can be fine or rough, depending on avg radius and avg diff angle.
		if(this->AbsoluteInc)	//(A)bsolute Increments
		{
			if (AvgRadius > 0.5)	//Outer circle. (D)ecimal adjust
			{
				if (AvgDiffAngle > 20.)
				{	//Fast swipe
					newNum += swipeDir*ADF;
				}
				else if (AvgDiffAngle > 1.)
				{	//Slow swipe
					newNum += swipeDir*ADS;
				}
				//else no swipe
			}
			else	//Inner circle. (I)nteger adjust
			{
				if (AvgDiffAngle > 25.)
				{	//Fast swipe
					newNum += swipeDir*AIF;
				}
				else if (AvgDiffAngle > 1.)
				{	//Slow swipe
					newNum += swipeDir*AIS;
				}
				//else no swipe
			}
		}
		else	//(R)elative Increments
		{
			if (AvgDiffAngle > 20.)
			{	//(F)ast swipe
				newNum *= (1+swipeDir*RF);
			}
			else if (AvgDiffAngle > 1.)
			{	//(S)low swipe
				newNum *= (1+swipeDir*RS);
			}
			//else no swipe
		}

		//Finally, update value
		this->TextFeedback->GetTextActor()->SetInput(vtkVariant(newNum).ToString());
		this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
		this->TextFeedback->SetHasUnsavedChanges(true);

		//Start tracking next set of movements
		this->FlushValues();
	}
}

void vtkOpenVRInteractorStyleSwipeDial::FlushValues()
{
	AngleRadiusRecord->erase(AngleRadiusRecord->begin(), AngleRadiusRecord->end());
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}


