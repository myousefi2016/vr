/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRTouchPadPointer.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRTouchPadPointer.h"

#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"

#include "vtkProperty.h"

#include "vtkPolyDataMapper.h"
#include "vtkSphereSource.h"
#include "vtkOpenVRRenderer.h"
#include "vtkOpenVRRenderWindowInteractor.h"
#include "vtkOpenVRCamera.h"
#include "vtkOpenVRInteractorStyleInputData.h"

vtkStandardNewMacro(vtkOpenVRTouchPadPointer);

//----------------------------------------------------------------------------
vtkOpenVRTouchPadPointer::vtkOpenVRTouchPadPointer()
{
	this->PointerSource = vtkSphereSource::New();			//this->PointerSource = vtkSphereSource::New();
	this->PointerActor = NULL;
	this->PointerMapper = vtkPolyDataMapper::New();

	if (this->PointerMapper && this->PointerSource)
	{
		this->PointerMapper->SetInputConnection(this->PointerSource->GetOutputPort());
	}

	this->PointerRenderer = NULL;
}

//----------------------------------------------------------------------------
vtkOpenVRTouchPadPointer::~vtkOpenVRTouchPadPointer()
{
	if (this->PointerActor)
	{
		this->PointerActor->Delete();
	}

	if (this->PointerMapper)
	{
		this->PointerMapper->Delete();
	}
	this->PointerSource->Delete();
	this->PointerSource = NULL;
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadPointer::Init()
{
	//create and place in coordinates.
	this->PointerSource->SetPhiResolution(8);
	this->PointerSource->SetThetaResolution(8);

	this->PointerActor = vtkActor::New();
	this->PointerActor->PickableOff();
	this->PointerActor->DragableOff();
	this->PointerActor->SetMapper(this->PointerMapper);
	this->PointerActor->GetProperty()->SetColor(0.7,0.7,0.7);
	this->PointerActor->GetProperty()->SetAmbient(0.8);
	this->PointerActor->GetProperty()->SetDiffuse(0.8);
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadPointer::Attach(vtkOpenVRRenderWindowInteractor *rwi)
{
	//Current renderer
	vtkOpenVRRenderer *ren = NULL;
	if (rwi)
	{
		int pointer = rwi->GetPointerIndex();
		//This will return the current renderer:
		ren = vtkOpenVRRenderer::SafeDownCast(rwi->FindPokedRenderer(rwi->GetEventPositions(pointer)[0],
		                                                             rwi->GetEventPositions(pointer)[1]));
	}

	//check if it is already active
	if (!this->PointerActor)
	{
		this->Init();
	}
	
	//check if used different renderer to previous visualization
	if (ren != this->PointerRenderer)
	{
		if (this->PointerRenderer != NULL && this->PointerActor)
		{
			this->PointerRenderer->RemoveActor(this->PointerActor);
		}
		if (ren != 0)
		{
			ren->AddActor(this->PointerActor);
		}
		else
		{
			vtkWarningMacro(<< "no current renderer on the interactor style.");
		}
		this->PointerRenderer = ren;
	}

	this->Move(rwi);
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadPointer::Move(vtkOpenVRRenderWindowInteractor *rwi)
{
	//Current renderer
	vtkOpenVRRenderer *ren = NULL;
	vtkInteractorStyle3D *ist = NULL;
	vtkOpenVRCamera *cam = NULL;
	int pointer;
	if (rwi)
	{
		pointer = rwi->GetPointerIndexLastTouchpad();
		//This will return the current renderer:
		ren = vtkOpenVRRenderer::SafeDownCast(rwi->FindPokedRenderer(rwi->GetEventPositions(pointer)[0],
		                                                             rwi->GetEventPositions(pointer)[1]));
		ist = vtkOpenVRInteractorStyleInputData::SafeDownCast(rwi->GetInteractorStyle());
		cam = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());
	}
	else return;

	//Get world information
	double wscale = cam->GetDistance();																			//Scale
	double *wpos = rwi->GetWorldEventPosition(pointer);			//Position
	double *wori = rwi->GetWorldEventOrientation(pointer);		//Orientation


	//Get/Set touchpad information
	const double r = 0.02;												//Touchpad radius
	const double d = 0.05;												// Distance from center of controller to center of touchpad
	const double h = 0.007;	// Separation pointer-touchpad.
	float *tpos = rwi->GetTouchPadPosition();
	this->PointerSource->SetRadius(.0025*wscale);	//Pointer radius

	//3D Rotation and Translation Maths
	double cosw = cos(vtkMath::RadiansFromDegrees(wori[0]));
	double sinw = sin(vtkMath::RadiansFromDegrees(wori[0]));
	double ptrpos[3];

	//Transformation matrix (X' = R · T · X)
	//ptrpos = controller position + translate to touchpad + translate to finger
	ptrpos[0] = wpos[0] + wscale*((d - r*tpos[1]) * (wori[1] * wori[3] * (1 - cosw) + wori[2] * sinw) + r*tpos[0] * (cosw + wori[1] * wori[1] * (1 - cosw)) + (h *(1+ 0.16*tpos[1])) * (wori[1] * wori[2] * (1 - cosw) - wori[3] * sinw) );
	ptrpos[1] = wpos[1] + wscale*((d - r*tpos[1]) * (wori[2] * wori[3] * (1 - cosw) - wori[1] * sinw) + r*tpos[0] * (wori[1] * wori[2] * (1 - cosw) + wori[3] * sinw) + (h *(1 + 0.16*tpos[1])) * (cosw + wori[2] * wori[2] * (1 - cosw)));
	ptrpos[2] = wpos[2] + wscale*((d - r*tpos[1]) * (cosw + wori[3] * wori[3] * (1 - cosw)) + r*tpos[0] * (wori[1] * wori[3] * (1 - cosw) - wori[2] * sinw) + (h *(1 + 0.16*tpos[1])) * (wori[2] * wori[3] * (1 - cosw) + wori[1] * sinw));

	this->PointerSource->SetCenter(ptrpos);

	if (rwi)
	{
		rwi->Render();
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadPointer::Detach()
{
	if (this->PointerRenderer != NULL && this->PointerActor)
	{
		this->PointerRenderer->RemoveActor(this->PointerActor);
		this->PointerRenderer = NULL;
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadPointer::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os, indent);
}