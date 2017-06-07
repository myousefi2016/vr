/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleDialTouchpad.cxx

Copyright (c) Ventura Romero
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStyleDialTouchpad.h"

#include "vtkNew.h"
#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"
#include <valarray>

vtkStandardNewMacro(vtkOpenVRInteractorStyleDialTouchpad);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleDialTouchpad::vtkOpenVRInteractorStyleDialTouchpad()
{
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleDialTouchpad::~vtkOpenVRInteractorStyleDialTouchpad()
{
}

//----------------------------------------------------------------------------
//TODO add behaviour if needed
void vtkOpenVRInteractorStyleDialTouchpad::OnRightButtonDown()
{
	int x = this->Interactor->GetEventPosition()[0];
	int y = this->Interactor->GetEventPosition()[1];

	this->FindPokedRenderer(x, y);
	if (this->CurrentRenderer == NULL)
	{
		return;
	}

	double radius = sqrt(x*x + y*y);
	int region = int(5. * atan2(x, y) / vtkMath::Pi);	// 10 regions. Integer values in range [0, 9]
														// Clockwise, starting in (x,y) = (0,1)
	if(radius > .75)
	{
        //Display number, which is equal to region number
		vtkDebugMacro(<< "Number pressed: " << region);	// Just for debugging purposes.
	}
	else
	{
		if(region <= 4)
		{
			vtkDebugMacro(<< "\"Validate number\" pressed. Region: " << region);	// Just for debugging purposes.
		}
		else	// region in range [5,9]
		{
			vtkDebugMacro(<< "\"Remove last digit\" pressed. Region: " << region);	// Just for debugging purposes.
		}
	}
}

//----------------------------------------------------------------------------
//TODO add behaviour
void vtkOpenVRInteractorStyleDialTouchpad::OnRightButtonUp()
{
	// do nothing except overriding the default OnRightButtonDown behavior

	/* PREVIOUS CODE.
	  vtkOpenVRRenderWindow* renWin = vtkOpenVRRenderWindow::SafeDownCast(this->Interactor->GetRenderWindow());
	  if (!renWin)
	  {
	    return;
	  }
	  vtkOpenVROverlay *ovl = renWin->GetDashboardOverlay();
	  ovl->LoadNextCameraPose();
	*/
}

void vtkOpenVRInteractorStyleDialTouchpad::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
