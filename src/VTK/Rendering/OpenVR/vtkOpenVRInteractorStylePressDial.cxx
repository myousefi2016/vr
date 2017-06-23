/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStylePressDial.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStylePressDial.h"

#include "vtkNew.h"
#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"
#include <valarray>
#include "vtkRenderWindowInteractor3D.h"

#include "vtkTextActor3D.h"
#include "vtkBillboardTextActor3D.h"
#include "vtkTextProperty.h"
#include "vtkTextMapper.h"
#include "vtkRenderer.h"
#include "vtkTextSource.h"

vtkStandardNewMacro(vtkOpenVRInteractorStylePressDial);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStylePressDial::vtkOpenVRInteractorStylePressDial()
{
	//this->Interactor->SetRecognizeGestures(false);

	//Text3D to modify Props' attributes.
	this->TextActor = NULL;
	this->TextRenderer = NULL;
	this->TextHasUnsavedChanges = false;

	this->Text = vtkTextSource::New();
	this->TextMapper = vtkTextMapper::New();

	if (this->TextMapper && this->Text)
	{
		this->TextMapper->SetInputConnection(this->Text->GetOutputPort());
	}
	
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStylePressDial::~vtkOpenVRInteractorStylePressDial()
{
	//Remove Text3D
	if(this->TextActor)
	{
		this->TextActor->Delete();
	}

	if(this->TextMapper)
	{
		this->TextMapper->Delete();
	}

	this->Text->Delete();
	this->Text = NULL;
}

//----------------------------------------------------------------------------
//TODO add behaviour if needed
void vtkOpenVRInteractorStylePressDial::OnRightButtonDown()
{
	//Downcast to a 3D Interactor.
	vtkRenderWindowInteractor3D *rwi =
		static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

	//int x = this->Interactor->GetEventPosition()[0];
	//int y = this->Interactor->GetEventPosition()[1];
	float x = rwi->GetTouchPadPosition()[0];	// Values between -1 and 1.
	float y = rwi->GetTouchPadPosition()[1];

	//this->FindPokedRenderer(x, y);
	//if (this->CurrentRenderer == NULL)
	//{
	//	return;
	//}

	float radius = sqrt(x*x + y*y);
	//int region = int(5. * atan2(x, y) / vtkMath::Pi());
	//(x > 0 ? x : (2 * vtkMath::Pi() + x)) * 360 / (2 * vtkMath::Pi());

	int region = int(5. * atan2(x, y) / vtkMath::Pi());		// Clockwise values, starting in (x,y) = (0,1)
	region = (x > 0) ? region : (region + 9);				// 10 regions. Integer values in range [0, 9]
	
	if(radius > .75)
	{
		//Display number, which is equal to region number
		vtkErrorMacro(<< "Number pressed: " << region);	// Just for debugging purposes.

		//Actual code:
		if(this->TextActor) this->TextActor->SetInput(this->TextActor->GetInput() + region);
	}
	else
	{
		if(region <= 4)
		{
			vtkErrorMacro(<< "\"Validate number\" pressed. Region: " << region);	// Just for debugging purposes.
		}
		else	// region in range [5,9]
		{
			//Negative angles
			vtkErrorMacro(<< "\"Remove last digit\" pressed. Region: " << region);	// Just for debugging purposes.
		}
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressDial::OnRightButtonUp()
{
	// do nothing except overriding the default OnRightButtonDown behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressDial::OnMiddleButtonDown()
{
	//Second Click. Already created and changes saved: can be destroyed.
	if (this->TextActor && !this->TextHasUnsavedChanges)
	//if(this->TextRenderer != NULL && this->TextActor)
	{
		//Remove from renderer
		if (this->TextRenderer != NULL && this->TextActor)
		{
			//this->TextRenderer->RemoveActor(this->TextActor);
			this->TextRenderer->RemoveViewProp(this->TextActor);
			this->TextRenderer = NULL;
		}
	}
	//Either or is not created or has changes
	else
	{
		//First Click. Not created yet: create it and place it properly.
		if (!this->TextActor)
		{
			//this->TextActor = vtkBillboardTextActor3D::New();
			////this->Text->SetText("Input data madafaka");
			this->TextActor = vtkTextActor3D::New();
			this->TextActor->SetInput("Input data madafaka");
			this->TextActor->PickableOff();
			this->TextActor->DragableOff();
			//this->TextActor->GetTextProperty()->
			//this->TextActor->SetMapper(this->textMapper);
			
		}

		//check if used different renderer to previous visualization
		if (this->CurrentRenderer != this->TextRenderer)
		{
			if (this->TextRenderer != NULL && this->TextActor)
			{
				//this->TextRenderer->RemoveActor(this->TextActor);
				this->TextRenderer->RemoveViewProp(this->TextActor);
			}
			if (this->CurrentRenderer != 0)
			{
				//this->CurrentRenderer->AddActor(this->TextActor);
				this->CurrentRenderer->AddViewProp(this->TextActor);
			}
			else
			{
				vtkWarningMacro(<< "no current renderer on the interactor style.");
			}
			this->TextRenderer = this->CurrentRenderer;
		}
	}




/*
	//First Click. Not created yet: create it.
	if(!this->TextActor)
	{
		//this->TextActor = vtkTextActor3D::New();
		this->TextActor = vtkBillboardTextActor3D::New();
		this->TextActor->SetInput("Input data madafaka");
		this->TextActor->PickableOff();
		//this->TextActor->DragableOff();this->TextActor->Set
		this->CurrentRenderer->AddActor(this->TextActor);
	}
	//Second Click. Already created: check if can be destroyed.
	else
	{
		//Unsaved changes: don't delete.
		if(this->TextHasUnsavedChanges)
		{
			//Right now, we delete it anyway.
			this->CurrentRenderer->RemoveActor(this->TextActor);
			this->TextActor->Delete();
			this->TextActor = NULL;
		}
		//Changes save: can be deleted.
		else
		{
			this->CurrentRenderer->RemoveActor(this->TextActor);
			this->TextActor->Delete();
			this->TextActor = NULL;
		}
	}
*/


	if (this->Interactor)
	{
		this->Interactor->Render();
	}
}


//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressDial::OnMiddleButtonUp()
{
	// do nothing except overriding the default OnMiddleButtonUp behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressDial::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
