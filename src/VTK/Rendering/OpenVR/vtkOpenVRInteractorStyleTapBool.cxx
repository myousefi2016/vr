/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleTapBool.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStyleTapBool.h"

#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderWindowInteractor3D.h"
#include "vtkTextActor3D.h"
#include "vtkTextProperty.h"
#include "vtkTextSource.h"
#include "vtkOpenVRFieldModifier.h"
#include "vtkOpenVRTextFeedback.h"
#include "vtkOpenVRTouchPadImage.h"
#include "vtkActor.h"
#include "vtkOpenVRInteractorStyleSwitchInput.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyleTapBool);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleTapBool::vtkOpenVRInteractorStyleTapBool()
{
	this->TextFeedback->SetTextDefaultMsg("Select Bool");
	this->ModifyProp = true;

	//Images
	this->TouchPadImage->LoadSingleImage( "..\\..\\..\\VTK\\Rendering\\OpenVR\\TapBool_Image0.png");
	this->TouchPadImage->Init();
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleTapBool::~vtkOpenVRInteractorStyleTapBool()
{}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleTapBool::OnRightButtonDown()
{
	if (this->TextFeedback->GetTextIsVisible() && this->TextFeedback->GetTextActor())
	{
		//Downcast to a 3D Interactor.
		vtkRenderWindowInteractor3D *rwi =
			static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

		float x = rwi->GetTouchPadPosition()[0];	// Values between -1 and 1.
		float y = rwi->GetTouchPadPosition()[1];

		float radius = sqrt(x*x + y*y);

		//2 regions: right->0(False); left->1(True)
		char *selBool = (x > 0) ? "false" : "true";
				
		if (this->TextFeedback->GetDefaultMsgOn())
		{
			this->TextFeedback->GetTextActor()->SetInput("");
			this->TextFeedback->SetDefaultMsgOn(false);
			this->TextFeedback->SetHasUnsavedChanges(true);
		}

		if (radius > .3)
		{
			//Display number, which is equal to region number
			this->TextFeedback->GetTextActor()->SetInput(selBool);
			this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
			this->TextFeedback->SetHasUnsavedChanges(true);
		}
		else
		{
			vtkStdString newText = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToString();
			if (newText.compare("") == 0)
			{
				this->TextFeedback->GetTextActor()->SetInput(" ");	//Avoids unexpected errors
			}
			this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOff();
			this->TextFeedback->SetHasUnsavedChanges(false);
				
			//Test (proof of concept)
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
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleTapBool::OnMiddleButtonDown()
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
void vtkOpenVRInteractorStyleTapBool::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
