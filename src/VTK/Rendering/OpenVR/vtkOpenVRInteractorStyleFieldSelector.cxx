/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleFieldSelector.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStyleFieldSelector.h"

#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderWindowInteractor3D.h"
#include "vtkTextSource.h"
#include "vtkActor.h"
#include "vtkOpenVRFieldModifier.h"
#include "vtkOpenVRTextFeedback.h"
#include "vtkOpenVRTouchPadImage.h"
#include "vtkOpenVRInteractorStyleSwitchInput.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyleFieldSelector);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleFieldSelector::vtkOpenVRInteractorStyleFieldSelector()
{
	this->TextFeedback->SetTextDefaultMsg(
		"Press Grip:\n -Inside Object: Iterate to next Object.\n"
		"-Outside Object: Toggle Object ON/OFF.\n"
		"Press Touchpad: Select Field to modify.");
	this->ModifyProp = true;

	//Images (0:Sphere; 1:Cylinder; 2:Cube):
	this->TouchPadImage->LoadImages(3, "..\\..\\..\\VTK\\Rendering\\OpenVR\\FieldSelector_Image");
	this->TouchPadImage->Init();
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleFieldSelector::~vtkOpenVRInteractorStyleFieldSelector()
{}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::OnRightButtonUp()
{
	if (this->TextFeedback->GetTextIsVisible() && this->TextFeedback->GetTextActor())
	{
		// Downcast to a 3D Interactor.
		vtkRenderWindowInteractor3D *rwi =
			static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

		float x = rwi->GetTouchPadPosition()[0];	// Values between -1 and 1.
		float y = rwi->GetTouchPadPosition()[1];

		// Find out the Field selected by the user:
		switch (this->ISSwitch->GetFieldModifier()->GetCurrentSourceType())
		{
		case vtkSourceType::Sphere:
			if (x <= 0 && y >= 0)			//2nd quadrant (+ boundaries).
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::ThetaResolution);
			else if (x > 0 && y > 0)	//1st quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::Radius);
			else if (x < 0 && y < 0)	//3rd quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::PhiResolution);
			else											//4th quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::None);
			break;
		case vtkSourceType::Cylinder:
			if (x <= 0 && y >= 0)			//2nd quadrant (+ boundaries).
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::Height);
			else if (x > 0 && y > 0)	//1st quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::Radius);
			else if (x < 0 && y < 0)	//3rd quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::None);
			else											//4th quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::None);
			break;
		case vtkSourceType::Cube:
			if (x <= 0 && y >= 0)			//2nd quadrant (+ boundaries).
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::XLength);
			else if (x > 0 && y > 0)	//1st quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::YLength);
			else if (x < 0 && y < 0)	//3rd quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::ZLength);
			else											//4th quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::None);
			break;
		}

		// Decide which IS class will handle the change (according to the field):
		switch (this->ISSwitch->GetFieldModifier()->GetSelectedField())
		{
		//TapDial (numbers):
		case vtkField::ThetaResolution:
		case vtkField::PhiResolution:
		case vtkField::XLength:
		case vtkField::YLength:
		case vtkField::ZLength:
			this->ISSwitch->SetCurrentStyleToTapDial();
			break;
		//TapBool (booleans):
		case vtkField::Visibility:
			this->ISSwitch->SetCurrentStyleToTapBool();
			break;
		//TapKeyboard (letters):
			//Nothing, by now...
		//SwipeDial (numbers):
		case vtkField::Scale:
		case vtkField::Opacity:
		case vtkField::Radius:
		case vtkField::Height:
			this->ISSwitch->SetCurrentStyleToSwipeDial();
			break;
		//None:
		case vtkField::None:
			break;
		default:
			vtkErrorMacro(<< "Unrecognised vtkField. No IS Selected to modify it.");
			break;
		}
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::OnMiddleButtonDown()
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
			// so we change the TestActor source.
			this->ISSwitch->GetFieldModifier()->IterateSourceType();
			this->ChangeImage();

			if (this->Interactor) this->Interactor->Render();
		}
		return;
	}

	// Controller outside TestActor or there is no Switch,
	// so we run its base class' method.
	Superclass::OnMiddleButtonDown();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::ChangeImage()
{
	switch (this->ISSwitch->GetFieldModifier()->GetCurrentSourceType())
	{
	case vtkSourceType::Sphere:
		this->TouchPadImage->SetNextImage(0); break;
	case vtkSourceType::Cylinder:
		this->TouchPadImage->SetNextImage(1); break;
	case vtkSourceType::Cube:
		this->TouchPadImage->SetNextImage(2); break;
	default:
		vtkErrorMacro(<< "SourceType not Handled. No image for that sourceType."); break;
	}
	this->TouchPadImage->UpdateImage();

}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
