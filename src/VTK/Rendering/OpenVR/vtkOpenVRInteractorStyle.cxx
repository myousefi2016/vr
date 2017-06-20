/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyle.cxx

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStyle.h"

#include "vtkNew.h"
#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindow.h"
#include "vtkOpenVRRenderWindowInteractor.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"

#include "vtkCommand.h"
#include "vtkRenderer.h"
#include "vtkPolyDataMapper.h"
#include "vtkSphereSource.h"
#include "vtkProperty.h"
#include "vtkActor.h"
#include "vtkMatrix4x4.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyle);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyle::vtkOpenVRInteractorStyle()
{
	//-----------------------------------------------------------
	//Touch pointer
	this->Pointer = vtkSphereSource::New();
	this->PointerActor = NULL;
	this->PointerMapper = vtkPolyDataMapper::New();

	if (this->PointerMapper && this->Pointer)
	{
		this->PointerMapper->SetInputConnection(this->Pointer->GetOutputPort());
		//this->PointerActor->SetMapper(PointerMapper);
	}

	this->PointerRenderer = NULL;
	this->PointerColor[0] = 0.0;
	this->PointerColor[1] = 1.0;
	this->PointerColor[2] = 0.0;
	//this->PointerActive = false;
	//-----------------------------------------------------------
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyle::~vtkOpenVRInteractorStyle()
{
	//Remove pointer
	this->SetTouchPadPointer(false);

	if (this->PointerActor)
	{
		this->PointerActor->Delete();
	}

	if (this->PointerMapper)
	{
		this->PointerMapper->Delete();
	}

	this->Pointer->Delete();
	this->Pointer = NULL;
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyle::OnMiddleButtonDown()
{
  // do nothing except overriding the default MiddleButtonPressEvent behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyle::OnMiddleButtonUp()
{
  vtkOpenVRRenderWindow* renWin = vtkOpenVRRenderWindow::SafeDownCast(this->Interactor->GetRenderWindow());
  if (!renWin)
  {
    return;
  }
  vtkOpenVROverlay *ovl = renWin->GetDashboardOverlay();
  ovl->LoadNextCameraPose();
}

//-----------------------------------------------------------------------------
// Pointer on Touchpad
//-----------------------------------------------------------------------------
void vtkOpenVRInteractorStyle::SetTouchPadPointer(bool activate)
{
	//current renderer
	if (this->Interactor)
	{
		int pointer = this->Interactor->GetPointerIndex();
		this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
														this->Interactor->GetEventPositions(pointer)[1]);
	}

	//to disable it
	if (!activate)
	{
		if (this->PointerRenderer != NULL && this->PointerActor)
		{
			this->PointerRenderer->RemoveActor(this->PointerActor);
			this->PointerRenderer = NULL;
		}
	}
	//to enable it
	else
	{
		//chech if it is already active
		if (!this->PointerActor)
		{
			//create and place in coordinates.
			this->Pointer->SetRadius(.008);
			this->PointerActor = vtkActor::New();
			this->PointerActor->PickableOff();
			this->PointerActor->DragableOff();
			this->PointerActor->SetMapper(this->PointerMapper);
			this->PointerActor->GetProperty()->SetColor(this->PointerColor);
			this->PointerActor->GetProperty()->SetAmbient(1.0);
			this->PointerActor->GetProperty()->SetDiffuse(0.0);
		}

		//check if used different renderer to previous visualization
		if (this->CurrentRenderer != this->PointerRenderer)
		{
			if (this->PointerRenderer != NULL && this->PointerActor)
			{
				this->PointerRenderer->RemoveActor(this->PointerActor);
			}
			if (this->CurrentRenderer != 0)
			{
				this->CurrentRenderer->AddActor(this->PointerActor);
			}
			else
			{
				vtkWarningMacro(<< "no current renderer on the interactor style.");
			}
			this->PointerRenderer = this->CurrentRenderer;
		}

		vtkOpenVRRenderWindowInteractor *rwi =
			static_cast<vtkOpenVRRenderWindowInteractor *>(this->Interactor);

		double *wpos = rwi->GetWorldEventPosition(rwi->GetPointerIndex());
		double *wori = rwi->GetWorldEventOrientation(rwi->GetPointerIndex());

		//3D Rotation and Translation Maths
		double d = 0.05;	// Distance from center of controller to center of touchpad. TODO adjust value
		double cosw = cos(wori[0] * vtkMath::Pi() / 180);
		double sinw = sin(wori[0] * vtkMath::Pi() / 180);

		double ptrpos[3];
		
		//Transformation matrix (X' = R · T · X)
		//ptrpos = controller position + translate to touchpad
		ptrpos[0] = wpos[0] + d * (wori[1] * wori[3] * (1 - cosw) + wori[2] * sinw);
		ptrpos[1] = wpos[1] + d * (wori[2] * wori[3] * (1 - cosw) - wori[1] * sinw);
		ptrpos[2] = wpos[2] + d * (cosw + wori[3] * wori[3] * (1 - cosw));

		this->Pointer->SetCenter(ptrpos[0], ptrpos[1], ptrpos[2]);

	}

	if (this->Interactor)
	{
		this->Interactor->Render();
	}
}

void vtkOpenVRInteractorStyle::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}
