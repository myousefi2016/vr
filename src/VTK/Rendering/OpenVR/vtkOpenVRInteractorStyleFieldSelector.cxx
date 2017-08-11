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
#include "vtkOpenVROverlay.h"
#include <valarray>
#include "vtkRenderWindowInteractor3D.h"

#include "vtkTextActor3D.h"
#include "vtkTextProperty.h"
#include "vtkRenderer.h"
#include "vtkTextSource.h"
#include "vtkOpenVRRenderer.h"
#include "vtkOpenVRRenderWindowInteractor.h"
#include "vtkOpenVRCamera.h"
#include "vtkSphereSource.h"
#include "vtkProperty.h"
#include "vtkPolyDataMapper.h"

#include "vtkOpenVRFieldModifier.h"


#include "vtkOpenVRTextFeedback.h"
#include "vtkOpenVRTouchPadImage.h"
#include "vtkOpenVRTouchPadPointer.h"

#include "vtkOpenVRInteractorStyleSwitchInput.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyleFieldSelector);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleFieldSelector::vtkOpenVRInteractorStyleFieldSelector()
{
	//Text3D to modify Props' attributes.
	this->TextFeedback = vtkOpenVRTextFeedback::New();
	this->TextFeedback->SetTextDefaultMsg(
		"Press Grip:\n -Inside Object: Iterate to next Object.\n -Outside Object: Toggle Object ON/OFF.\nPress Touchpad: Select Field to modify.");

	//Properties' Modifier
//	this->FieldModifier = vtkOpenVRFieldModifier::New();	//Starts with a Sphere
	this->ModifyProp = true;

	//Images:
	this->TouchPadImage = vtkOpenVRTouchPadImage::New();
	this->TouchPadImage->LoadImages(3, "..\\..\\..\\VTK\\Rendering\\OpenVR\\FieldSelector_Image");	//0: Sphere; 1: Cylinder; 2: Cube;
	this->TouchPadImage->Init();


	//TouchPad Pointer
	this->TouchPadPointer = vtkOpenVRTouchPadPointer::New();

}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleFieldSelector::~vtkOpenVRInteractorStyleFieldSelector()
{
	//Remove Text3D
	if (this->TextFeedback)
	{
		this->TextFeedback->Delete();
		this->TextFeedback = NULL;
	}

	//Remove FieldModifier
	//if(this->FieldModifier)
	//{
	//	this->FieldModifier->Delete();
	//}

	//Remove images
	if (this->TouchPadImage)
	{
		this->TouchPadImage->Delete();
		this->TouchPadImage = NULL;
	}

	//Remove pointer
	if (this->TouchPadPointer)
	{
		this->TouchPadPointer->Delete();
		this->TouchPadPointer = NULL;
	}
}

/*
//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::OnRightButtonDown()
{}
*/

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::OnRightButtonUp()
{
	// do nothing except overriding the default OnRightButtonDown behavior

	if (this->TextFeedback->GetTextIsVisible() && this->TextFeedback->GetTextActor())
	{
		//Downcast to a 3D Interactor.
		vtkRenderWindowInteractor3D *rwi =
			static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

		float x = rwi->GetTouchPadPosition()[0];	// Values between -1 and 1.
		float y = rwi->GetTouchPadPosition()[1];


		//Find out the Field selected by the user:
		switch (this->ISSwitch->GetFieldModifier()->GetCurrentSourceType())
		{
		case vtkSourceType::Sphere:
			if (x <= 0 && y >= 0)			//Upper left quadrant (+ boundaries).
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::ThetaResolution);
			else if (x > 0 && y > 0)	//Upper right quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::Radius);
			else if (x < 0 && y < 0)	//Lower left quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::PhiResolution);
			else											//Lower right quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::None);
			break;
		case vtkSourceType::Cylinder:
			if (x <= 0 && y >= 0)			//Upper left quadrant (+ boundaries).
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::Height);
			else if (x > 0 && y > 0)	//Upper right quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::Radius);
			else if (x < 0 && y < 0)	//Lower left quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::None);
			else											//Lower right quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::None);
			break;
		case vtkSourceType::Cube:
			if (x <= 0 && y >= 0)			//Upper left quadrant (+ boundaries).
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::XLength);
			else if (x > 0 && y > 0)	//Upper right quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::YLength);
			else if (x < 0 && y < 0)	//Lower left quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::ZLength);
			else											//Lower right quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::None);
			break;
		}

		//Decide which IS class will handle the value change (according to the field selected):
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
	//Get current renderer (if is not got already)
	if (this->Interactor)
	{
		int pointer = this->Interactor->GetPointerIndex();
		this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
														this->Interactor->GetEventPositions(pointer)[1]);

		vtkRenderWindowInteractor3D *vriren = vtkRenderWindowInteractor3D::SafeDownCast(this->Interactor);
		double *wpos = vriren->GetWorldEventPosition(vriren->GetPointerIndex());
		this->FindPickedActor(wpos[0], wpos[1], wpos[2]);
	}


	//Click Inside. If I have the controller inside the object, iterate to next object.
	if (this->InteractionProp != NULL && this->InteractionProp == this->ISSwitch->GetFieldModifier()->GetTestActor())
	{
		this->ISSwitch->GetFieldModifier()->IterateSourceType();
		this->ChangeImage();
		return;
	}


	bool TextEmpty = false;
	if (this->TextFeedback->GetTextActor())
		TextEmpty = !bool(vtkStdString(" ").compare(this->TextFeedback->GetTextActor()->GetInput()));

	//Second Click. Already created and changes saved: can be hidden.
	if (this->TextFeedback->GetTextActor() && this->TextFeedback->GetTextRenderer() != NULL
			&& (!this->TextFeedback->GetHasUnsavedChanges() || TextEmpty))
	{
		this->TextFeedback->Reset();
		//Test:
		if (this->ModifyProp)
		{
			this->ISSwitch->GetFieldModifier()->HideTest();
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
			if (this->ModifyProp)
			{
				this->ISSwitch->GetFieldModifier()->ShowTest(vtkOpenVRRenderWindowInteractor::SafeDownCast(this->Interactor));
			}
		}
	}

	//Place in scene
	vtkOpenVRRenderer *ren = vtkOpenVRRenderer::SafeDownCast(this->CurrentRenderer);
	vtkOpenVRCamera *camera = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());
	this->TextFeedback->PlaceInScene(camera);

	//Render Scene
	if (this->Interactor)
	{
		this->Interactor->Render();
	}
}

/*
//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::OnMiddleButtonUp()
{
	// do nothing except overriding the default OnMiddleButtonUp behavior
}
*/

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::SwitchCaps()
{
	int currentImg = this->TouchPadImage->GetNextImage();
	this->TouchPadImage->SetNextImage( (currentImg += 4) %= this->TouchPadImage->GetMaxNumImg());
}

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

/*
vtkField vtkOpenVRInteractorStyleFieldSelector::GetSelectedField()
{
	return SelectedField;
}
*/


/*
void vtkOpenVRInteractorStyleFieldSelector::Reset()
{
	Superclass::Reset();

	if (this->FieldModifier)
	{
		this->FieldModifier->HideTest();
	}
}*/

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::IncNextImage()
{
	int nextImg = this->TouchPadImage->GetNextImage();
	if ((nextImg == (MAX_IMG / 2 - 1)) || (nextImg == (MAX_IMG - 1)))
	{
		nextImg -= (MAX_IMG / 2 - 1);
	}
	else
	{
		++nextImg;
	}
	this->TouchPadImage->SetNextImage(nextImg);
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::DecNextImage()
{
	int nextImg = this->TouchPadImage->GetNextImage();
	if (nextImg == 0 || nextImg == (MAX_IMG / 2))
	{
		nextImg += (MAX_IMG / 2 - 1);
	}
	else
	{
		--nextImg;
	}
	this->TouchPadImage->SetNextImage(nextImg);
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
