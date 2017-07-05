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

vtkStandardNewMacro(vtkOpenVRInteractorStyleSwipeDial);


//PIMPL to use STL (ref: VTKUsersGuide, 303)
typedef std::pair<double, double> AngleRadius;
typedef std::deque<AngleRadius> AngleRadiusBase;
class vtkDequeAngleRadius:
	public AngleRadiusBase {};
		


	

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwipeDial::vtkOpenVRInteractorStyleSwipeDial()
{
	this->AngleRadiusRecord = new vtkDequeAngleRadius;

	//Text3D to modify Props' attributes.
	this->TextActor = NULL;
	this->TextRenderer = NULL;
	this->TextHasUnsavedChanges = false;
	this->TextDefaultMsg = true;
	this->TextIsVisible = false;
	

	//Images
	this->ImgReader = vtkPNGReader::New();
	this->HasImage = true;
	this->NextImage = 0;

	//In this class, only one image needed.
	this->ImgReader->SetFileName("..\\..\\..\\VTK\\Rendering\\OpenVR\\SwipeDial_Image0.png");
	ImgReader->Update();

	this->ImgActor = vtkImageActor::New();
	this->ImgActor->GetMapper()->SetInputData(this->ImgReader->GetOutput());
	this->ImgActor->PickableOff();
	this->ImgActor->DragableOff();
	this->ImgRenderer = NULL;

}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwipeDial::~vtkOpenVRInteractorStyleSwipeDial()
{
	delete this->AngleRadiusRecord;

	//Remove Text3D
	if (this->TextActor)
	{
		this->TextActor->Delete();
	}

	//Remove Image:
	this->SetTouchPadImage(false);
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
	if (this->TextIsVisible && this->TextActor)
	{
		//Downcast to a 3D Interactor.
		vtkRenderWindowInteractor3D *rwi =
			static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

		float x = rwi->GetTouchPadPosition()[0];	// Values between -1 and 1.
		float y = rwi->GetTouchPadPosition()[1];

		float radius = sqrt(x*x + y*y);

		int region = int(8. * atan2(x, y) / vtkMath::Pi());		// Clockwise values, starting in (x,y) = (0,1)
		region = (x > 0) ? region : (region + 15);				// 16 regions. Integer values in range [0, 15]

		if (this->TextDefaultMsg)
		{
			this->TextActor->SetInput("0");
			TextDefaultMsg = false;
			TextHasUnsavedChanges = true;
		}

		double newValue = vtkVariant(this->TextActor->GetInput()).ToDouble();

		if (radius > .65)
		{
			switch(region)
			{
			case 4:		newValue *= 1.02;	break;
			case 5:		newValue *= 1.05;	break;
			case 11:	newValue *= 0.98;	break;
			case 10:	newValue *= 0.95;	break;
			case 6:		newValue *= 4;		break;
			case 7:		newValue *= 8;		break;
			case 9:		newValue /= 4;		break;
			case 8:		newValue /= 8;		break;
			default: break;
			}

			this->TextActor->GetTextProperty()->BoldOn();
			TextHasUnsavedChanges = true;
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

			this->TextActor->GetTextProperty()->BoldOn();
			TextHasUnsavedChanges = true;
		}
		else
		{
			if(region < 8)	// Accept value
			{
				this->TextActor->GetTextProperty()->BoldOff();
				TextHasUnsavedChanges = false;
			}
			else			// Restore default: 0
			{
				newValue = 0;
				this->TextActor->GetTextProperty()->BoldOn();
				TextHasUnsavedChanges = true;
			}
		}

		this->TextActor->SetInput(vtkVariant(newValue).ToString());
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
	if (this->TextActor) TextEmpty = !bool(vtkStdString(" ").compare(this->TextActor->GetInput()));

	//Second Click. Already created and changes saved: can be hidden.
	if (this->TextActor && this->TextRenderer != NULL &&
		(!this->TextHasUnsavedChanges || TextEmpty))
	{

		if (this->TextRenderer != NULL && this->TextActor)
		{
			//Remove from renderer
			this->TextRenderer->RemoveViewProp(this->TextActor);
			this->TextRenderer = NULL;
			//Restore initial values
			this->TextActor->SetInput("Swipe or Press");
			this->TextDefaultMsg = true;
			this->TextIsVisible = false;
			//this->TextHasUnsavedChanges = false;

			//Test:
			//this->ShowTestActor(false);
		}
	}
	//Either or is not created or has changes or is not shown
	else
	{
		//First Click ever. Not created yet: create it and place it properly.
		if (!this->TextActor)
		{
			this->TextActor = vtkTextActor3D::New();
			this->TextActor->SetInput("Swipe or Press");
			this->TextActor->PickableOff();
			this->TextActor->DragableOff();
			this->TextActor->GetTextProperty()->SetBackgroundOpacity(1.0);
		}

		//First Click. Created but not shown. Check if used different renderer to previous visualization.
		if (this->CurrentRenderer != this->TextRenderer)
		{
			if (this->TextRenderer != NULL && this->TextActor)
			{
				this->TextRenderer->RemoveViewProp(this->TextActor);
			}
			if (this->CurrentRenderer != 0)
			{
				this->CurrentRenderer->AddViewProp(this->TextActor);
			}
			else
			{
				vtkWarningMacro(<< "no current renderer on the interactor style.");
			}
			this->TextRenderer = this->CurrentRenderer;
			this->TextIsVisible = true;
			this->TextHasUnsavedChanges = false;

			//Test:
			//this->ShowTestActor(true);
		}

	}

	//Place text opposite to the camera
	vtkOpenVRRenderer *ren = vtkOpenVRRenderer::SafeDownCast(this->CurrentRenderer);
	vtkOpenVRCamera *camera = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());

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

	this->TextActor->SetScale(0.01);	//Default scale is ridiculously big.
	this->TextActor->SetOrientation(0, -camOri[1], 0);
	this->TextActor->SetPosition(txtPos);

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
void vtkOpenVRInteractorStyleSwipeDial::TrackFinger()
{
	if (this->TextIsVisible)
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

		//Update record: Add new values and remove old values if maximum is reached:
		if (this->AngleRadiusRecord->size() == MAX_REC)
		{
			this->AngleRadiusRecord->pop_front();
		}
		this->AngleRadiusRecord->push_back(AngleRadius(tpos[0], tpos[1]));

		// Find out direction of swipe
		switch (this->GetSwipeDirection())
		{
		case -1:	//Anti-clockwise
			this->DecValue();
			break;
		case 1:		//Clockwise
			this->IncValue();
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
	int dir = 0;
	std::deque<AngleRadius>::iterator it1 = AngleRadiusRecord->begin();
	std::deque<AngleRadius>::iterator it2 = ++(AngleRadiusRecord->begin());
	for (it1, it2; it2 != AngleRadiusRecord->end(); ++it1, ++it2)
	{
		//Debug purposes:
		vtkErrorMacro(<< "Swipe direction, diff value: " << it1->first - it2->first);

		if (it1->first - it2->first < -1e-4) dir++;
		else if(it2->first - it1->first < -1e-4) dir--;
		//else, too close to consider movement.
	}

	//Normalize to {-1, 0, 1}
	if(dir != 0) dir /= abs(dir);
	return dir;
}

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
	double AvgRadius = this->GetAvgRadius();
	double AvgDiffAngle = this->GetAvgDiffAngle();

	//Debug purposes
	vtkErrorMacro(<< "AvgRadius:    " << AvgRadius);
	vtkErrorMacro(<< "AvgDiffAngle: " << AvgDiffAngle);


	//TODO FOLLOW HERE!!
	//Modification can be fine or rough, depending on avg radius and diff angle.
	//Think about an algorithm.

	if(AvgRadius > 0.65)	//Outer circle. Decimal adjust
	{
		if(AvgDiffAngle > 20.)	//TODO adjust values.
		{	//Fast swipe
			
		}
		else if(AvgDiffAngle > 5.)
		{	//Normal swipe
			
		}
		else
		{	//Slow swipe
			
		}
	}
	else if(AvgRadius > 0.3)	//Middle circle. Integer adjust.
	{
		if (AvgDiffAngle > 20.)	//TODO adjust values.
		{	//Fast swipe

		}
		else if (AvgDiffAngle > 5.)
		{	//Normal swipe

		}
		else
		{	//Slow swipe

		}
	}
	//else, too close to the center. Do nothing.





}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}


