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


//#define TEST
#ifdef TEST
		rwi->SetWorldEventPosition(0.0, 0.0, -2.0, rwi->GetPointerIndex());
		rwi->SetWorldEventOrientation(90.0, 0.0, 1.0, 0.0, rwi->GetPointerIndex());
#endif


		double *wpos = rwi->GetWorldEventPosition(rwi->GetPointerIndex());
		double *wori = rwi->GetWorldEventOrientation(rwi->GetPointerIndex());
		float *tpos = rwi->GetTouchPadPosition();

		vtkErrorMacro(<< "Position: " << wpos[0] << ", " << wpos[1] << ", " << wpos[2]);
		vtkErrorMacro(<< "Orientation: " << wori[0] << ", " << wori[1] << ", " << wori[2] << ", " << wori[3]);
	//	vtkErrorMacro(<< "Touchpad: " << tpos[0] << ", " << tpos[1]);


		//3D Rotation and Translation Maths
		double d = 0.05;	// Distance from center of controller to center of touchpad. TODO adjust value
		double r = 0.02;		// Radius of touchpad, for a proper adjustment. TODO adjust value
											//TODO add touchpad position
		double cosw = cos(wori[0] * vtkMath::Pi() / 180);
		double sinw = sin(wori[0] * vtkMath::Pi() / 180);
		vtkErrorMacro(<< "(cosw, sinw) = : (" << cosw << ", " << sinw << ")");

		double ptrpos[3];
		//ptrpos = controller position + center to touchpad + adjustment to exact point touched.
		//TODO test first only with first two sumands and check that it is placed on the middle of the touchpad.

		//vtkMatrix4x4 *c2t = vtkMatrix4x4::New();		//Controller to Touchpad coordinates
		//vtkMatrix4x4::DeepCopy(c2t, {})
		

		//Assuming d in x-axis (touchpad coordinates)
		//ptrpos[0] = wpos[0] + d * (cosw + wori[1] * wori[1] * (1 - cosw)); 
		//ptrpos[1] = wpos[1] + d * (wori[1] * wori[2] * (1 - cosw) - wori[3] * sinw);
		//ptrpos[2] = wpos[2] + d * (wori[1] * wori[3] * (1 - cosw) + wori[2] * sinw);


		//Assuming d in y-axis (touchpad coordinates)
		//ptrpos[0] = wpos[0] + d * (wori[1] * wori[2] * (1 - cosw) + wori[3] * sinw);
		//ptrpos[1] = wpos[1] + d * (cosw + wori[2] * wori[2] * (1 - cosw));
		//ptrpos[2] = wpos[2] + d * (wori[2] * wori[3] * (1 - cosw) - wori[1] * sinw);


		//Assuming d in z-axis (touchpad coordinates)
//		ptrpos[0] = wpos[0] + d * (wori[1] * wori[3] * (1 - cosw) - wori[2] * sinw);// +r * (wori[1] * wori[2] * (1 - cosw) + wori[3] * sinw);
//		ptrpos[1] = wpos[1] + d * (wori[2] * wori[3] * (1 - cosw) + wori[1] * sinw);// +r * (cosw + wori[2] * wori[2] * (1 - cosw));
//		ptrpos[2] = wpos[2] + d * (cosw + wori[3] * wori[3] * (1 - cosw));// +r * (wori[2] * wori[3] * (1 - cosw) + wori[1] * sinw);

		//Using result from sheet B1
		//ptrpos[0] = 

		//Using columns (A2):
		ptrpos[0] = wpos[0] + d * (wori[1] * wori[3] * (1 - cosw) + wori[2] * sinw);
		ptrpos[1] = wpos[1] + d * (wori[2] * wori[3] * (1 - cosw) - wori[1] * sinw);
		ptrpos[2] = wpos[2] + d * (cosw + wori[3] * wori[3] * (1 - cosw));

		//Doing nothing, points to the origin of controller:
		//ptrpos[0] = wpos[0]; ptrpos[1] = wpos[1]; ptrpos[2] = wpos[2];

		vtkErrorMacro(<< "Pointer: " << ptrpos[0] << ", " << ptrpos[1] << ", " << ptrpos[2]);
		this->Pointer->SetCenter(ptrpos[0], ptrpos[1], ptrpos[2]);
		//this->Pointer->SetCenter(0.,0.,0.);
#ifdef TEST
		vtkErrorMacro(<< "Pointer: should be -0.5, 0, -2");
#endif
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
