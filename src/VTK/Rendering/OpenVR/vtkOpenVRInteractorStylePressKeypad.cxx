/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStylePressKeypad.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStylePressKeypad.h"

#include "vtkNew.h"
#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"
#include <valarray>
#include "vtkRenderWindowInteractor3D.h"

vtkStandardNewMacro(vtkOpenVRInteractorStylePressKeypad);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStylePressKeypad::vtkOpenVRInteractorStylePressKeypad()
{
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStylePressKeypad::~vtkOpenVRInteractorStylePressKeypad()
{
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressKeypad::OnRightButtonDown()
{
	//Downcast to a 3D Interactor.
	vtkRenderWindowInteractor3D *rwi =
		static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

	//int x = this->Interactor->GetEventPosition()[0];
	//int y = this->Interactor->GetEventPosition()[1];
	float x = rwi->GetTouchPadPosition()[0];
	float y = rwi->GetTouchPadPosition()[1];

	//this->FindPokedRenderer(x, y);
	//if (this->CurrentRenderer == NULL)
	//{
	//	return;
	//}

	int xRegion = 3 * x;		// Values between 0-2.
	int yRegion = 4 * y;		// Values between 0-3.
	int region = 3 * yRegion + xRegion;		// Value between 0-11.

	if(region < 9)
	{
		//Display number
		vtkDebugMacro(<< "Number pressed: " << region+1);	// Just for debugging purposes.
	}
	else if(region == 10)
	{
		//Display number 0
		vtkDebugMacro(<< "Number pressed: 0");	// Just for debugging purposes.
	}
	else if (region == 9)
	{
		//Remove last digit
		vtkDebugMacro(<< "\"Remove last digit\" pressed. Region: " << region);	// Just for debugging purposes.
	}
	else if (region == 11)
	{
		//Validate number
		vtkDebugMacro(<< "\"Validate number\" pressed. Region: " << region);	// Just for debugging purposes.
	}
}

//----------------------------------------------------------------------------
//TODO add behaviour if needed
void vtkOpenVRInteractorStylePressKeypad::OnRightButtonUp()
{
	// do nothing except overriding the default OnRightButtonUp behavior
}

void vtkOpenVRInteractorStylePressKeypad::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
