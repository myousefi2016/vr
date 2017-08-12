/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleTapDial.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStyleTapDial.h"

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
#include "vtkInformation.h"
#include "vtkOpenVRFieldModifier.h"
#include "vtkOpenVRTextFeedback.h"
#include "vtkOpenVRTouchPadImage.h"
#include "vtkOpenVRTouchPadPointer.h"
#include "vtkOpenVRCFDFilterer.h"
#include "vtkOpenVRInteractorStyleSwitchInput.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyleTapDial);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleTapDial::vtkOpenVRInteractorStyleTapDial()
{
	this->ModifyProp = true;

	//Images
	this->TouchPadImage->LoadSingleImage("..\\..\\..\\VTK\\Rendering\\OpenVR\\TapDial_Image0.png");
	this->TouchPadImage->Init();
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleTapDial::~vtkOpenVRInteractorStyleTapDial()
{}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleTapDial::OnRightButtonDown()
{
	if (this->TextFeedback->GetTextIsVisible() && this->TextFeedback->GetTextActor())
	{
		//Downcast to a 3D Interactor.
		vtkRenderWindowInteractor3D *rwi =
			static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

		float x = rwi->GetTouchPadPosition()[0];	// Values between -1 and 1.
		float y = rwi->GetTouchPadPosition()[1];

		float radius = sqrt(x*x + y*y);

		int region = int(5. * atan2(x, y) / vtkMath::Pi());		// Clockwise, starting in (x,y) = (0,1)
		region = (x > 0) ? region : (region + 9);							// 10 regions. Integer values in [0, 9]

		if (this->TextFeedback->GetDefaultMsgOn())
		{
			this->TextFeedback->GetTextActor()->SetInput("");
			this->TextFeedback->SetDefaultMsgOn(false);
			this->TextFeedback->SetHasUnsavedChanges(true);
		}

		if (radius > .6)
		{
			//Display number, which is equal to region number
			vtkStdString newText = vtkVariant(
				this->TextFeedback->GetTextActor()->GetInput()).ToString() + vtkVariant(region).ToString();
			this->TextFeedback->GetTextActor()->SetInput(newText);
			this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
			this->TextFeedback->SetHasUnsavedChanges(true);

		}
		else if(radius > .2)
		{
			if (region <= 4)
			{
				vtkStdString newText = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToString();
				if (newText.compare("") == 0)
				{
					this->TextFeedback->GetTextActor()->SetInput(" ");		//Avoids unexpected errors
				}
				this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOff();
				this->TextFeedback->SetHasUnsavedChanges(false);

				// Test (proof of concept):
				if (this->ModifyProp)
				{
					vtkObject *Object = this->ISSwitch->GetFieldModifier()->GetfieldOwnerAsObject();
					vtkField Field = this->ISSwitch->GetFieldModifier()->GetSelectedField();
					char *Value = this->TextFeedback->GetTextActor()->GetInput();
					char **pValue = &Value;
					
					this->ISSwitch->GetFieldModifier()->ModifyProperty(Object, Field, pValue);
				}
			}
			else	// region in range [5,9]
			{
				vtkStdString newText = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToString();
				if (newText.length() <= 1)
				{
					this->TextFeedback->GetTextActor()->SetInput(" ");		//Avoids unexpected errors
					this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOff();
					this->TextFeedback->SetHasUnsavedChanges(false);
				}
				else
				{
					newText.pop_back();
					this->TextFeedback->GetTextActor()->SetInput(newText);
					this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
					this->TextFeedback->SetHasUnsavedChanges(true);
				}
			}
		}
		else
		{
			vtkStdString newText = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToString() + ".";
			this->TextFeedback->GetTextActor()->SetInput(newText);
			this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
			this->TextFeedback->SetHasUnsavedChanges(true);
		}
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleTapDial::OnMiddleButtonDown()
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
void vtkOpenVRInteractorStyleTapDial::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
