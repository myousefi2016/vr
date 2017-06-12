/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleSwipeKeypad.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStyleSwipeKeypad.h"

#include "vtkNew.h"
#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"
#include <valarray>
#include "vtkRenderWindowInteractor3D.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyleSwipeKeypad);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwipeKeypad::vtkOpenVRInteractorStyleSwipeKeypad()
{
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwipeKeypad::~vtkOpenVRInteractorStyleSwipeKeypad()
{
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeKeypad::OnSwipe()	//adapted from vtkInteractorStyle3D::OnMouseMove()
{
	//TODO INTERACTION 
	//NOTE May be useful on the future: vr::VREvent_ButtonTouch

	//Do I need another function where to set state == VTKIS_SWIPE ? I think so.
	switch (this->State)
	{
		//case VTKIS_ ...
	}
}

void vtkOpenVRInteractorStyleSwipeKeypad::OnLongTap()
{
	//TODO INTERACTION

	int x = this->Interactor->GetEventPosition()[0];
	int y = this->Interactor->GetEventPosition()[1];
	this->FindPokedRenderer(x, y);
	if (this->CurrentRenderer == NULL)
	{
		return;
	}

}

void vtkOpenVRInteractorStyleSwipeKeypad::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
