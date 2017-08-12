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

#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVRRenderWindowInteractor.h"
#include "vtkTextActor3D.h"
#include "vtkTextProperty.h"
#include "vtkTextSource.h"
#include "vtkOpenVRFieldModifier.h"
#include "vtkOpenVRTextFeedback.h"
#include "vtkOpenVRTouchPadImage.h"
#include "vtkActor.h"
#include "vtkOpenVRInteractorStyleSwitchInput.h"
#include <deque>
#include <utility>	//std::pair

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

//PIMPL to use STL
typedef std::pair<double, double> AngleRadius;
typedef std::deque<AngleRadius> AngleRadiusBase;
class vtkDequeAngleRadius:
	public AngleRadiusBase {};
	
//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwipeDial::vtkOpenVRInteractorStyleSwipeDial()
	: AbsoluteInc(true)
{
	this->AngleRadiusRecord = new vtkDequeAngleRadius;
	this->ModifyProp = true;

	//Images
	this->TouchPadImage->LoadSingleImage("..\\..\\..\\VTK\\Rendering\\OpenVR\\SwipeDial_Image0.png");
	this->TouchPadImage->Init();
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwipeDial::~vtkOpenVRInteractorStyleSwipeDial()
{
	delete this->AngleRadiusRecord;
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::OnRightButtonDown()
{
	if (this->TextFeedback->GetTextIsVisible() && this->TextFeedback->GetTextActor())
	{
		// Downcast to a 3D Interactor.
		vtkRenderWindowInteractor3D *rwi =
			static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

		float x = rwi->GetTouchPadPosition()[0];	// Values between -1 and 1.
		float y = rwi->GetTouchPadPosition()[1];

		float radius = sqrt(x*x + y*y);

		int region = int(8. * atan2(x, y) / vtkMath::Pi());	// Clockwise, starting in (x,y) = (0,1)
		region = (x > 0) ? region : (region + 15);					// 16 regions. Integer values in [0, 15]

		if (this->TextFeedback->GetDefaultMsgOn())
		{
			this->TextFeedback->GetTextActor()->SetInput("1");
			this->TextFeedback->SetDefaultMsgOn(false);
			this->TextFeedback->SetHasUnsavedChanges(true);
		}

		double newValue = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToDouble();

		if (radius > .5 && region == 3)	AbsoluteInc = true;
		else if (radius > .5 && region == 12)	AbsoluteInc = false;

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
			if(region >+ 4 && region <= 7)	// Accept value
			{
				this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOff();
				this->TextFeedback->SetHasUnsavedChanges(false);
			}
			else if(region >= 8 && region <= 11)			// Restore default: 0
			{
				newValue = 0;	//Add field with the value (as a string?)
				this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
				this->TextFeedback->SetHasUnsavedChanges(true);
			}
		}

		this->TextFeedback->GetTextActor()->SetInput(vtkVariant(newValue).ToString());

		// Test (proof of concept)
		if (this->ModifyProp)
		{
			vtkObject *Object = this->ISSwitch->GetFieldModifier()->GetfieldOwnerAsObject();
			vtkField Field = this->ISSwitch->GetFieldModifier()->GetSelectedField();
			char *Value = this->TextFeedback->GetTextActor()->GetInput();
			char **pValue = &Value;

			this->ISSwitch->GetFieldModifier()->ModifyProperty(Object, Field, pValue);
		}
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::OnMiddleButtonDown()
{
	// Get current renderer
	if (this->Interactor)
	{
		int pointer = this->Interactor->GetPointerIndex();
		this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
														this->Interactor->GetEventPositions(pointer)[1]);

		vtkRenderWindowInteractor3D *vriren = vtkRenderWindowInteractor3D::SafeDownCast(this->Interactor);
		double *wpos = vriren->GetWorldEventPosition(vriren->GetPointerIndex());
		this->FindPickedActor(wpos[0], wpos[1], wpos[2]);
	}

	if (this->InteractionProp != NULL && this->InteractionProp == this->ISSwitch->GetFieldModifier()->GetTestActor())
	{
		if (this->Interactor->GetInteractorStyle()->IsA("vtkOpenVRInteractorStyleSwitchInput"))
		{
			// Controller inside TestActor and we have a ISSwitch,
			// so we switch to ISFieldSelector
			this->ISSwitch->SetCurrentStyleToFieldSelector();

			if (this->Interactor) this->Interactor->Render();
		}
		return;
	}

	// Controller outside TestActor or there is no Switch,
	// so we run its base class' method.
	Superclass::OnMiddleButtonDown();
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
	if (this->TextFeedback->GetTextIsVisible())
	{
		// Current renderer
		if (this->Interactor)
		{
			int pointer = this->Interactor->GetPointerIndex();
			this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
				this->Interactor->GetEventPositions(pointer)[1]);
		}

		// Touchpad position (-1,1)
		vtkOpenVRRenderWindowInteractor *rwi =
			static_cast<vtkOpenVRRenderWindowInteractor *>(this->Interactor);
		float *tpos = rwi->GetTouchPadPosition();
		float angle = 180. * atan2(tpos[0], tpos[1]) / vtkMath::Pi();	//Angle in degrees.
		float radius = sqrt(tpos[0] * tpos[0] + tpos[1] * tpos[1]);

		// Update record: Add new values and remove old values if maximum is reached:
		if (this->AngleRadiusRecord->size() == MAX_REC)
			this->AngleRadiusRecord->pop_front();

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
	// Sum all of them (always incremental values)
	// and get average (used to get swiping speed)
	double diffAngle = 0;
	std::deque<AngleRadius>::iterator it1 = AngleRadiusRecord->begin();
	std::deque<AngleRadius>::iterator it2 = ++(AngleRadiusRecord->begin());
	for (it1, it2; it2 != AngleRadiusRecord->end(); ++it1, ++it2)
		diffAngle += fabs(it1->first - it2->first);

	diffAngle /= this->AngleRadiusRecord->size();
	return diffAngle;
}

//----------------------------------------------------------------------------
double vtkOpenVRInteractorStyleSwipeDial::GetAvgRadius()
{
	double radius = 0.0;
	std::deque<AngleRadius>::iterator it = AngleRadiusRecord->begin();
	for (it; it != AngleRadiusRecord->end(); ++it)
		radius += it->second;

	radius /= this->AngleRadiusRecord->size();
	return radius;
}

//----------------------------------------------------------------------------
int vtkOpenVRInteractorStyleSwipeDial::GetSwipeDirection()
{
	if (AngleRadiusRecord->size() < MAX_REC) return 0;

	int dir = 0;
	std::deque<AngleRadius>::reverse_iterator it1 = ++(AngleRadiusRecord->rbegin());
	std::deque<AngleRadius>::reverse_iterator it2 = AngleRadiusRecord->rbegin();

	//Instantaneus stop when pausing the finger.
	if(fabs(it1->first - it2->first) < 1)
	{
		this->FlushValues();
		return 0;
	}

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

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::UpdateValue()
{
	if (this->TextFeedback->GetTextActor())
	{
		// Ensure there is a number
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

		//Modification can be fine or rough, depending on avgRadius and avgDiffAngle.
		if(this->AbsoluteInc)	//(A)bsolute Increments
		{
			if (AvgRadius > 0.5)	//Outer circle. (D)ecimal adjust
			{
				if (AvgDiffAngle > 20.)	//(F)ast swipe
					newNum += swipeDir*ADF;
				else if (AvgDiffAngle > 1.)	//(S)low swipe
					newNum += swipeDir*ADS;
				//else no swipe
			}
			else	//Inner circle. (I)nteger adjust
			{
				if (AvgDiffAngle > 25.)	//(F)ast swipe
					newNum += swipeDir*AIF;
				else if (AvgDiffAngle > 1.)	//(S)low swipe
					newNum += swipeDir*AIS;
				//else no swipe
			}
		}
		else	//(R)elative Increments
		{
			if (AvgDiffAngle > 20.)	//(F)ast swipe
				newNum *= (1+swipeDir*RF);
			else if (AvgDiffAngle > 1.)	//(S)low swipe
				newNum *= (1+swipeDir*RS);
			//else no swipe
		}

		// Finally, update value
		this->TextFeedback->GetTextActor()->SetInput(vtkVariant(newNum).ToString());
		this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
		this->TextFeedback->SetHasUnsavedChanges(true);

		// Test (proof of concept)
		if (this->ModifyProp)
		{
			vtkObject *Object = this->ISSwitch->GetFieldModifier()->GetfieldOwnerAsObject();
			vtkField Field = this->ISSwitch->GetFieldModifier()->GetSelectedField();
			char *Value = this->TextFeedback->GetTextActor()->GetInput();
			char **pValue = &Value;

			this->ISSwitch->GetFieldModifier()->ModifyProperty(Object, Field, pValue);
		}

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
