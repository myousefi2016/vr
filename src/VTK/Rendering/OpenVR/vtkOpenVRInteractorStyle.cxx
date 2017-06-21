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

#include "vtkOpenVRCamera.h"
#include "vtkOpenVRRenderer.h"
#include "vtkCommand.h"
#include "vtkCallbackCommand.h"
#include "vtkRenderer.h"
#include "vtkPolyDataMapper.h"
#include "vtkSphereSource.h"
#include "vtkProperty.h"
#include "vtkActor.h"
#include "vtkMatrix4x4.h"
#include "vtkMatrix3x3.h"
#include "vtkOpenVRModel.h"

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


//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyle::OnTap()
{
	int x = this->Interactor->GetEventPosition()[0];
	int y = this->Interactor->GetEventPosition()[1];

	this->FindPokedRenderer(x, y);
	if (this->CurrentRenderer == NULL)
	{
		return;
	}

	this->SetTouchPadPointer(true);

	this->GrabFocus(this->EventCallbackCommand);
	this->StartTap();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyle::OnUntap()
{
	this->SetTouchPadPointer(false);

	switch (this->State)
	{
	case VTKIS_TAP:
		this->EndTap();
		break;
	}

	if (this->Interactor)
	{
		this->ReleaseFocus();
	}
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
		//check if it is already active
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

		//Get world scale!!!

		vtkOpenVRRenderWindowInteractor *rwi =
			static_cast<vtkOpenVRRenderWindowInteractor *>(this->Interactor);
		vtkOpenVRRenderWindow *win =
			vtkOpenVRRenderWindow::SafeDownCast(rwi->GetRenderWindow());
		vtkOpenVRRenderer *ren = vtkOpenVRRenderer::SafeDownCast(this->CurrentRenderer);
		vtkOpenVRCamera *camera =
			vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());
		vr::IVRSystem *pHMD = win->GetHMD();
		
/*
		vtkMatrix4x4 *WCVCMatrix = vtkMatrix4x4::New();
		vtkMatrix3x3 *normalMatrix = vtkMatrix3x3::New();
		vtkMatrix4x4 *VCDCMatrix = vtkMatrix4x4::New();
		vtkMatrix4x4 *WCDCMatrix = vtkMatrix4x4::New();
		camera->GetKeyMatrices(ren,WCVCMatrix,normalMatrix,VCDCMatrix,WCDCMatrix);
		
		double scaleWCVC = WCVCMatrix->GetElement(3, 3);
		double scaleVCDC = VCDCMatrix->GetElement(3, 3);
		double scaleWCDC = WCDCMatrix->GetElement(3, 3);

		//double wExpl = (camera->GetExplicitProjectionTransformMatrix())->GetElement(3,3);

		int pointer = this->Interactor->GetPointerIndex();

		this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
														this->Interactor->GetEventPositions(pointer)[1]);

		double sc = rwi->GetScale();
		double lsc = rwi->GetLastScale();

		//-------------------------------------------------------------------------

		//https://github.com/ValveSoftware/openvr/blob/master/samples/hellovr_opengl/hellovr_opengl_main.cpp
		// Process SteamVR controller state
		for (vr::TrackedDeviceIndex_t unDevice = 0; unDevice < vr::k_unMaxTrackedDeviceCount; unDevice++)
		{
			vr::VRControllerState_t state;
			if (m_pHMD->GetControllerState(unDevice, &state, sizeof(state)))
			{
				m_rbShowTrackedDevice[unDevice] = state.ulButtonPressed == 0;
			}
		}

			//vr::TrackedDeviceIndex_t




		//Other try from https://github.com/ValveSoftware/openvr/wiki/IVRSystem::GetControllerState
//		for (vr::TrackedDeviceIndex_t unDevice = 0; unDevice < vr::k_unMaxTrackedDeviceCount; unDevice++)
//		{
			vr::TrackedDeviceIndex_t unDevice = 0;	//Lets assume that there is only one controller.
			vr::TrackingUniverseOrigin eOrigin = vr::TrackingUniverseOrigin::TrackingUniverseStanding;
			vr::VRControllerState_t	pControllerState;
			vr::TrackedDevicePose_t pTrackedDevicePose;
			pHMD->GetControllerStateWithPose(eOrigin, unDevice, &pControllerState, sizeof(pControllerState), &pTrackedDevicePose);
			if(pControllerState.ulButtonTouched == 1 &&
				vr::ButtonMaskFromId(vr::EVRButtonId::k_EButton_SteamVR_Touchpad))	//If I am touching that button.
			{
				//pTrackedDevicePose.mDeviceToAbsoluteTracking
				//See vtkOVRRWI (72).
				//not this way....
				//------------
				//-----------
	
			}
//		}

		
*/
		//-------------------------------------------------------------------------




		//Got the controller
		/*vtkOpenVRModel *controller = win->GetTrackedDeviceModel(vr::TrackedDeviceClass_Controller);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				double scaleController = controller->GetPoseMatrix()->Get()->GetElement(i, j);
			}
		}*/


		/*
		double unitV[4] = { 0, 0, 0, 1 };
		double scaleFactor =
			vtkMath::Norm(poseMatrix->MultiplyDoublePoint(unitV));
*/


		/*
		int k = 0;
		double *ppos = rwi->GetPhysicalTranslation(camera);
		for (int i = 0; i < 3; i++) {
			k = ppos[i];
		}
		k += 1;
		*/

		vtkMatrix4x4 *tcdc;
		camera->GetTrackingToDCMatrix(tcdc);
		vtkErrorMacro(<< "tcdc matrix");
		for (int i = 0; i < 16; i+=4) vtkErrorMacro(<< tcdc[i] << " " << tcdc[i+1] << " " << tcdc[i+2] << " " << tcdc[i+3]);

		double wscale = 1;

		double *wpos = rwi->GetWorldEventPosition(rwi->GetPointerIndex());
		double *wori = rwi->GetWorldEventOrientation(rwi->GetPointerIndex());
		float *tpos = rwi->GetTouchPadPosition();
		double r = 0.02 * wscale;

		//3D Rotation and Translation Maths
		double d = 0.05;	// Distance from center of controller to center of touchpad. TODO adjust value
		double cosw = cos(wori[0] * vtkMath::Pi() / 180);
		double sinw = sin(wori[0] * vtkMath::Pi() / 180);
		
		double ptrpos[3];
		
		//Transformation matrix (X' = R · T · X)
		//ptrpos = controller position + translate to touchpad
		ptrpos[0] = wpos[0] + wscale*((d-r*tpos[1]) * (wori[1] * wori[3] * (1 - cosw) + wori[2] * sinw) + r*tpos[0] * (cosw + wori[1]*wori[1]*(1-cosw)));
		ptrpos[1] = wpos[1] + wscale*((d-r*tpos[1]) * (wori[2] * wori[3] * (1 - cosw) - wori[1] * sinw) + r*tpos[0] * (wori[1]*wori[2]*(1-cosw)+wori[3]*sinw));
		ptrpos[2] = wpos[2] + wscale*((d-r*tpos[1]) * (cosw + wori[3] * wori[3] * (1 - cosw)) + r*tpos[0] * (wori[1]*wori[3]*(1-cosw)-wori[2]*sinw));

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
