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
#include "vtkProperty.h"
#include "vtkPolyDataMapper.h"	//For test. Might be removed if tests are moved avay.

#include "vtkInformation.h"

#include "vtkOpenVRFieldModifier.h"
#include "vtkOpenVRTextFeedback.h"
#include "vtkOpenVRTouchPadImage.h"
#include "vtkOpenVRTouchPadPointer.h"


#include "vtkShrinkPolyData.h"
//#include "vtkPVLODActor.h"
#include "vtkOpenVRCFDFilterer.h"
#include "vtkOpenVRInteractorStyleSwitchInput.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyleTapDial);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleTapDial::vtkOpenVRInteractorStyleTapDial()
{
	//Text3D to modify Props' attributes.
	this->TextFeedback = vtkOpenVRTextFeedback::New();

	//Prop to modify:
	this->ModifyProp = true;

	//Images
	//https://gist.github.com/waldyrious/c3be68f0682543ee0ae2
	this->TouchPadImage = vtkOpenVRTouchPadImage::New();
	this->TouchPadImage->LoadSingleImage("..\\..\\..\\VTK\\Rendering\\OpenVR\\TapDial_Image0.png");
	this->TouchPadImage->Init();


	//TouchPad Pointer
	this->TouchPadPointer = vtkOpenVRTouchPadPointer::New();


	//https://www.researchgate.net/publication/45338891_A_Multimodal_Virtual_Reality_Interface_for_VTK

}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleTapDial::~vtkOpenVRInteractorStyleTapDial()
{
	//Remove Text3D
	if (this->TextFeedback)
	{
		this->TextFeedback->Delete();
	}

	//Remove Image:
	if (this->TouchPadImage)
	{
		this->TouchPadImage->Delete();
	}

	//Remove pointer
	if (this->TouchPadPointer)
	{
		this->TouchPadPointer->Delete();
	}
}

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

		int region = int(5. * atan2(x, y) / vtkMath::Pi());		// Clockwise values, starting in (x,y) = (0,1)
		region = (x > 0) ? region : (region + 9);				// 10 regions. Integer values in range [0, 9]

		if (this->TextFeedback->GetDefaultMsgOn())
		{
			this->TextFeedback->GetTextActor()->SetInput("");
			this->TextFeedback->SetDefaultMsgOn(false);
			this->TextFeedback->SetHasUnsavedChanges(true);
		}

		if (radius > .6)
		{
			//Display number, which is equal to region number
			vtkStdString newText = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToString() + vtkVariant(region).ToString();
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

				//test:
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
void vtkOpenVRInteractorStyleTapDial::OnRightButtonUp()
{
	// do nothing except overriding the default OnRightButtonDown behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleTapDial::OnMiddleButtonDown()
{
	//Get current renderer (if is not got already)
	if (this->Interactor)
	{
		int pointer = this->Interactor->GetPointerIndex();
		this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
		                        this->Interactor->GetEventPositions(pointer)[1]);

		vtkRenderWindowInteractor3D *vriren = vtkRenderWindowInteractor3D::SafeDownCast(this->Interactor);
		double *wpos = vriren->GetWorldEventPosition( vriren->GetPointerIndex());
		this->FindPickedActor(wpos[0], wpos[1], wpos[2]);
	}

	//TestActor is a mandatory condition for me because I dont know how to get the Source from other objects.
	if (this->InteractionProp != NULL && this->InteractionProp == this->ISSwitch->GetFieldModifier()->GetTestActor())
	{
		if (this->Interactor->GetInteractorStyle()->IsA("vtkOpenVRInteractorStyleSwitchInput"))
		{
			vtkOpenVRInteractorStyleSwitchInput *ISSwitch =
				vtkOpenVRInteractorStyleSwitchInput::SafeDownCast(this->Interactor->GetInteractorStyle());
			
			ISSwitch->SetCurrentStyleToFieldSelector();
			return;
		}
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

	vtkOpenVRRenderer *ren = vtkOpenVRRenderer::SafeDownCast(this->CurrentRenderer);
	vtkOpenVRCamera *camera = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());
	this->TextFeedback->PlaceInScene(camera);

	//Render Scene
	if (this->Interactor)
	{
		this->Interactor->Render();
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleTapDial::OnMiddleButtonUp()
{
	// do nothing except overriding the default OnMiddleButtonUp behavior
}


//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleTapDial::OnLeftButtonDown()
{
	//Common code...
	int x = this->Interactor->GetEventPosition()[0];
	int y = this->Interactor->GetEventPosition()[1];

	vtkRenderWindowInteractor3D *vriren =
		vtkRenderWindowInteractor3D::SafeDownCast(this->Interactor);

	double *wpos = vriren->GetWorldEventPosition(
		vriren->GetPointerIndex());

	this->FindPokedRenderer(x, y);
	this->FindPickedActor(wpos[0], wpos[1], wpos[2]);

	if (this->CurrentRenderer == NULL || this->InteractionProp == NULL)
	{
		return;
	}

	//Specific code...
	//First Click ever. Not created yet: create it and place it properly.
	if (!this->TextFeedback->GetTextActor())
	{
		this->TextFeedback->Init();
	}
	//Created but not shown. Check if used different renderer to previous visualization.
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
	}

	vtkOpenVRRenderer *ren = vtkOpenVRRenderer::SafeDownCast(this->CurrentRenderer);
	vtkOpenVRCamera *camera = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());

	this->TextFeedback->PlaceInScene(camera);


	//CFD readers from ParaView: (to Tilerature review)
	//		https://www.paraview.org/fluid-dynamics/
	//		https://www.paraview.org/Wiki/ParaView/Users_Guide/List_of_readers#OpenFOAMReader
	//		http://www.openfoam.com/documentation/user-guide/paraview.php
	//		http://vtk.1045678.n5.nabble.com/Help-with-vtkOpenFOAMReader-and-extraction-td3370753.html

}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleTapDial::OnLeftButtonUp()
{
	//Already created and changes saved: can be hidden.
	if (this->TextFeedback->GetTextActor() && this->TextFeedback->GetTextRenderer() != NULL
		&& !this->TextFeedback->GetHasUnsavedChanges())
	{
		this->TextFeedback->Reset();
	}
}


//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleTapDial::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
