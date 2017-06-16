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
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyle);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyle::vtkOpenVRInteractorStyle()
{
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyle::~vtkOpenVRInteractorStyle()
{
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









//TODO get a white pointer over the touchpad.
void vtkOpenVRInteractorStyle::OnTap()	//touch touchpad
{
	vtkErrorMacro(<< "Touchpad tapped!");	// Just for debugging purposes.

																				//TODO test this. Continue developing here.
	vtkOpenVRRenderWindow* renWin = vtkOpenVRRenderWindow::SafeDownCast(this->Interactor->GetRenderWindow());
	if (!renWin)
	{
		return;
	}

	this->SetTouchPadPointer(true);


	/*int pointer = this->Interactor->GetPointerIndex();

	this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
	this->Interactor->GetEventPositions(pointer)[1]);*/

}

void vtkOpenVRInteractorStyle::OnUntap()
{
	vtkErrorMacro(<< "Touchpad untapped!");	// Just for debugging purposes.

//	this->SetTouchPadPointer(false);		//Uncomment in final version. Commented to allow testing

	/*int pointer = this->Interactor->GetPointerIndex();

	this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
	this->Interactor->GetEventPositions(pointer)[1]);*/

}









void vtkOpenVRInteractorStyle::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}
