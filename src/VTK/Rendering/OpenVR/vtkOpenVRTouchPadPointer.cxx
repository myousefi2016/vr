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
	this->PointerSource = vtkSphereSource::New();
	this->PointerActor = NULL;
	this->PointerMapper = vtkPolyDataMapper::New();

	if (this->PointerMapper && this->PointerSource)
		this->PointerMapper->SetInputConnection(this->PointerSource->GetOutputPort());

	this->PointerRenderer = NULL;
}

//----------------------------------------------------------------------------
vtkOpenVRTouchPadPointer::~vtkOpenVRTouchPadPointer()
{
	if (this->PointerActor)
	{
		this->PointerActor->Delete();
		this->PointerActor = NULL;
	}
	if (this->PointerMapper)
	{
		this->PointerMapper->Delete();
		this->PointerMapper = NULL;
	}
	if (this->PointerSource)
	{
		this->PointerSource->Delete();
		this->PointerSource = NULL;
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadPointer::Init()
{
	// Create sphere and place in coordinates.
	this->PointerSource->SetPhiResolution(8);
	this->PointerSource->SetThetaResolution(8);
	this->PointerActor = vtkActor::New();
	this->PointerActor->PickableOff();
	this->PointerActor->DragableOff();
	this->PointerActor->SetMapper(this->PointerMapper);
	this->PointerActor->GetProperty()->SetColor(0.25, 0.25, 0.25);
	this->PointerActor->GetProperty()->SetAmbient(0.8);
	this->PointerActor->GetProperty()->SetDiffuse(0.8);
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadPointer::Attach(vtkOpenVRRenderWindowInteractor *rwi)
{
	vtkOpenVRRenderer *ren = NULL;
	if (rwi)
	{
		int pointer = rwi->GetPointerIndex();
		// This will return the current renderer:
		ren = vtkOpenVRRenderer::SafeDownCast(rwi->FindPokedRenderer(
			rwi->GetEventPositions(pointer)[0], rwi->GetEventPositions(pointer)[1]));
	}

	// Check if the actor is already active
	if (!this->PointerActor) this->Init();
	
	// Check if used different renderer to previous visualization
	if (ren != this->PointerRenderer)
	{
		if (this->PointerRenderer != NULL && this->PointerActor)
			this->PointerRenderer->RemoveActor(this->PointerActor);

		if (ren != 0) ren->AddActor(this->PointerActor);
		else vtkWarningMacro(<< "no current renderer on the interactor style.");

		this->PointerRenderer = ren;
	}

	this->Move(rwi);
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadPointer::Move(vtkOpenVRRenderWindowInteractor *rwi)
{
	vtkOpenVRRenderer *ren = NULL;
	vtkInteractorStyle3D *ist = NULL;
	vtkOpenVRCamera *cam = NULL;
	int pointer;
	if (rwi)
	{
		pointer = rwi->GetPointerIndexLastTouchpad();
		// This will return the current renderer:
		ren = vtkOpenVRRenderer::SafeDownCast(
			rwi->FindPokedRenderer(rwi->GetEventPositions(pointer)[0], rwi->GetEventPositions(pointer)[1]));
		ist = vtkOpenVRInteractorStyleInputData::SafeDownCast(rwi->GetInteractorStyle());
		cam = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());
	}
	else return;

	// Get world information
	double wscale = cam->GetDistance();											// Scale
	double *wpos = rwi->GetWorldEventPosition(pointer);			// Position
	double *wori = rwi->GetWorldEventOrientation(pointer);	// Orientation


	// Get/Set touchpad information
	const double r = 0.02;		// Touchpad radius
	const double d = 0.05;		// Distance from center of controller to center of touchpad
	const double h = 0.01;		// Separation pointer-touchpad
	const double a = 0.16;		// Weight of the angle touchpad-controller
	float *tpos = rwi->GetTouchPadPosition();
	this->PointerSource->SetRadius(.0025*wscale);

	// 3D Rotation and Translation Maths
	double cosw = cos(vtkMath::RadiansFromDegrees(wori[0]));
	double sinw = sin(vtkMath::RadiansFromDegrees(wori[0]));
	double ptrpos[3];

	// Transformation matrix:
	// ptrpos = controller position + translate to touchpad + translate to finger
	double cpos[3], ttrans[3], ftrans[3];
	cpos[0] = (d - r*tpos[1]) * (wori[1] * wori[3] * (1 - cosw) + wori[2] * sinw);
	cpos[1] = (d - r*tpos[1]) * (wori[2] * wori[3] * (1 - cosw) - wori[1] * sinw);
	cpos[2] = (d - r*tpos[1]) * (cosw + wori[3] * wori[3] * (1 - cosw));
	ttrans[0] = r*tpos[0] * (cosw + wori[1] * wori[1] * (1 - cosw));
	ttrans[1] = r*tpos[0] * (wori[1] * wori[2] * (1 - cosw) + wori[3] * sinw);
	ttrans[2] = r*tpos[0] * (wori[1] * wori[3] * (1 - cosw) - wori[2] * sinw);
	ftrans[0] = (h *(1 + a*tpos[1])) * (wori[1] * wori[2] * (1 - cosw) - wori[3] * sinw);
	ftrans[1] = (h *(1 + a*tpos[1])) * (cosw + wori[2] * wori[2] * (1 - cosw));
	ftrans[2] = (h *(1 + a*tpos[1])) * (wori[2] * wori[3] * (1 - cosw) + wori[1] * sinw);
	
	ptrpos[0] = wpos[0] + wscale*(cpos[0] + ttrans[0] + ftrans[0]);
	ptrpos[1] = wpos[1] + wscale*(cpos[1] + ttrans[1] + ftrans[1]);
	ptrpos[2] = wpos[2] + wscale*(cpos[2] + ttrans[2] + ftrans[2]);
	this->PointerSource->SetCenter(ptrpos);

	if (rwi) rwi->Render();
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