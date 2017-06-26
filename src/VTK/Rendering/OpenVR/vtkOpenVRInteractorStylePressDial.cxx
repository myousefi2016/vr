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
#include "vtkOpenVRRenderer.h"
#include "vtkOpenVRRenderWindowInteractor.h"
#include "vtkOpenVRCamera.h"
#include "vtkMatrixToHomogeneousTransform.h"

vtkStandardNewMacro(vtkOpenVRInteractorStylePressDial);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStylePressDial::vtkOpenVRInteractorStylePressDial()
{
	//Text3D to modify Props' attributes.
	this->TextActor = NULL;
	this->TextRenderer = NULL;
	this->TextHasUnsavedChanges = false;
	this->TextDefaultMsg = true;
	this->TextIsVisible = false;
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStylePressDial::~vtkOpenVRInteractorStylePressDial()
{
	//Remove Text3D
	if(this->TextActor)
	{
		this->TextActor->Delete();
	}
}

//----------------------------------------------------------------------------
//TODO add behaviour if needed
void vtkOpenVRInteractorStylePressDial::OnRightButtonDown()
{
	if (this->TextIsVisible)
	{
		//Downcast to a 3D Interactor.
		vtkRenderWindowInteractor3D *rwi =
			static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

		float x = rwi->GetTouchPadPosition()[0];	// Values between -1 and 1.
		float y = rwi->GetTouchPadPosition()[1];

		float radius = sqrt(x*x + y*y);

		int region = int(5. * atan2(x, y) / vtkMath::Pi());		// Clockwise values, starting in (x,y) = (0,1)
		region = (x > 0) ? region : (region + 9);				// 10 regions. Integer values in range [0, 9]


		if (this->TextActor && TextDefaultMsg)
		{
			this->TextActor->SetInput("");
			TextDefaultMsg = false;
			TextHasUnsavedChanges = true;
		}


		if (radius > .75)
		{
			//Display number, which is equal to region number
			vtkErrorMacro(<< "Number pressed: " << region);	// Just for debugging purposes.

			//Actual code:
			if (this->TextActor)
			{
				vtkStdString newText = vtkVariant(this->TextActor->GetInput()).ToString() + vtkVariant(region).ToString();
				this->TextActor->SetInput(newText);
				this->TextActor->GetTextProperty()->BoldOn();
				TextHasUnsavedChanges = true;
			}
		}
		else
		{
			if (region <= 4)
			{
				vtkErrorMacro(<< "\"Validate number\" pressed. Region: " << region);	// Just for debugging purposes.

				//Actual code:
				if (this->TextActor)
				{
					vtkStdString newText = vtkVariant(this->TextActor->GetInput()).ToString();
					if (newText.compare("") == 0)
					{
						this->TextActor->SetInput(" ");		//Avoids unexpected errors
					}
					this->TextActor->GetTextProperty()->BoldOff();
					TextHasUnsavedChanges = false;
				}
			}
			else	// region in range [5,9]
			{
				vtkErrorMacro(<< "\"Remove last digit\" pressed. Region: " << region);	// Just for debugging purposes.

				//Actual code:
				if (this->TextActor)
				{
					vtkStdString newText = vtkVariant(this->TextActor->GetInput()).ToString();
					if (newText.length() <= 1)
					{
						this->TextActor->SetInput(" ");		//Avoids unexpected errors
						this->TextActor->GetTextProperty()->BoldOff();
						TextHasUnsavedChanges = false;
					}
					else
					{
						newText.pop_back();
						this->TextActor->SetInput(newText);
						this->TextActor->GetTextProperty()->BoldOn();
						TextHasUnsavedChanges = true;
					}
				}
			}
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
	//Get current renderer (if is not got already)
	if (this->Interactor)
	{
		int pointer = this->Interactor->GetPointerIndex();
		this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
		                        this->Interactor->GetEventPositions(pointer)[1]);
	}

	bool TextEmpty = false;
	if(this->TextActor) TextEmpty = !bool(vtkStdString(" ").compare(this->TextActor->GetInput()));

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
			this->TextActor->SetInput("Input data");
			this->TextDefaultMsg = true;
			this->TextIsVisible = false;
			//this->TextHasUnsavedChanges = false;
		}
	}
	//Either or is not created or has changes or is not shown
	else
	{
		//First Click ever. Not created yet: create it and place it properly.
		if (!this->TextActor)
		{
			this->TextActor = vtkTextActor3D::New();
			this->TextActor->SetInput("Input data");
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
		}

	}
	
	vtkOpenVRRenderer *ren = vtkOpenVRRenderer::SafeDownCast(this->CurrentRenderer);
	vtkOpenVRCamera *camera = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());

	double *camPos = camera->GetPosition();         //Camera Position
	double *camOri = camera->GetOrientation();		//Camera Orientation: rotation in (X,Y,Z)
	
	const double d2c = 0.5;		//Text distance to camera.
	
	//3D Rotation and Translation Maths
	double cosw = cos(vtkMath::RadiansFromDegrees(camOri[1]));
	double sinw = sin(vtkMath::RadiansFromDegrees(camOri[1]));
	double projection[3] = {sinw, 0, -cosw};
	vtkMath::Normalize(projection);

	double txtPos[3];

	for (int i = 0; i < 3; i++)
		txtPos[i] = camPos[i] + projection[i] * d2c;

	//Place text
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
void vtkOpenVRInteractorStylePressDial::OnMiddleButtonUp()
{
	// do nothing except overriding the default OnMiddleButtonUp behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressDial::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
