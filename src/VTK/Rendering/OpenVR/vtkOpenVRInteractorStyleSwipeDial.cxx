/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleSwipeDial.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStyleSwipeDial.h"

#include "vtkNew.h"
#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"
#include <valarray>
#include "vtkRenderWindowInteractor3D.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyleSwipeDial);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwipeDial::vtkOpenVRInteractorStyleSwipeDial()
{
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwipeDial::~vtkOpenVRInteractorStyleSwipeDial()
{
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::OnSwipe()	//adapted from vtkInteractorStyle3D::OnMouseMove()
{
	//NOTE May be useful on the future: vr::VREvent_ButtonTouch

	//Do I need another function where to set state == VTKIS_SWIPE ? I think so.
	switch(this->State)
	{
		//case VTKIS_ ...
	}

}

void vtkOpenVRInteractorStyleSwipeDial::OnLongTap()
{
	int x = this->Interactor->GetEventPosition()[0];
	int y = this->Interactor->GetEventPosition()[1];
	this->FindPokedRenderer(x, y);
	if (this->CurrentRenderer == NULL)
	{
		return;
	}



	//
	/*this->GrabFocus(this->EventCallbackCommand);
	vtkCamera* cam = this->CurrentRenderer->GetActiveCamera();
	switch (this->State)
	{
	case VTKIS_REVERSEFLY:
		this->State = VTKIS_FORWARDFLY;
		break;
	default:
		this->SetupMotionVars(cam);
		this->StartForwardFly();
		break;
	}*/
}

void vtkOpenVRInteractorStyleSwipeDial::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
