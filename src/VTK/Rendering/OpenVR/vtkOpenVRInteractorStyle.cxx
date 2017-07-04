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

#include "vtkImageActor.h"
#include "vtkImageReader2.h"
#include "vtkImageSliceMapper.h"
#include "vtkJPEGReader.h"
#include "vtkImageMapper.h"
#include "vtkActor2D.h"
#include "vtkImageProperty.h"
#include "vtkStringArray.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyle);

void vtkOpenVRInteractorStyle::UpdateImage()
{
	//TODO test
	if(this->GetHasImage())
	{
		if (this->ImgActor->GetZSlice() != this->NextImage)
		{
			//Change image. Need to update both Mapper and Actor:
			//To test
			if(this->NextImage <= ImgActor->GetWholeZMax() && this->NextImage >= ImgActor->GetWholeZMin())
			{
				ImgActor->SetZSlice(this->NextImage);
			}
			else
			{
				vtkErrorMacro(<< "ImgActor: Image slice number is out of bounds");
			}
			
			vtkImageSliceMapper *sliceMapper = vtkImageSliceMapper::SafeDownCast(ImgActor->GetMapper());
			if(this->NextImage <= sliceMapper->GetSliceNumberMaxValue() && this->NextImage >= sliceMapper->GetSliceNumberMinValue())
			{
				sliceMapper->SetSliceNumber(this->NextImage);
			}
			else
			{
				vtkErrorMacro(<< "ImgMapper: Image slice number is out of bounds");
			}
		}
	}
}

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
	}

	this->PointerRenderer = NULL;
	this->PointerColor[0] = 0.0;
	this->PointerColor[1] = 1.0;
	this->PointerColor[2] = 0.0;
	//this->PointerActive = false;
	//-----------------------------------------------------------

	//Images:
	this->HasImage = false;
	this->NextImage = 0;
	ImgReader = NULL;
	ImgActor = NULL;
	ImgRenderer = NULL;
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
	this->SetTouchPadImage(false);

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
	if(this->GetHasImage())
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
			this->Pointer->SetPhiResolution(50);
			this->Pointer->SetThetaResolution(50);
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
		vtkOpenVRRenderer *ren = vtkOpenVRRenderer::SafeDownCast(this->CurrentRenderer);
		vtkOpenVRCamera *camera = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());
		
		//Get world information
		double wscale = camera->GetDistance();                                 //Scale
		double *wpos = rwi->GetWorldEventPosition(rwi->GetPointerIndex());     //Position
		double *wori = rwi->GetWorldEventOrientation(rwi->GetPointerIndex());  //Orientation

		//Get/Set touchpad information
		const double r = 0.02;	//Touchpad radius
		const double d = 0.05;	// Distance from center of controller to center of touchpad
		float *tpos = rwi->GetTouchPadPosition();
		this->Pointer->SetRadius(.0075*wscale);	//Pointer radius

		//3D Rotation and Translation Maths
		double cosw = cos(vtkMath::RadiansFromDegrees(wori[0]));
		double sinw = sin(vtkMath::RadiansFromDegrees(wori[0]));
		double ptrpos[3];
		
		//Transformation matrix (X' = R · T · X)
		//ptrpos = controller position + translate to touchpad
		ptrpos[0] = wpos[0] + wscale*((d-r*tpos[1]) * (wori[1] * wori[3] * (1 - cosw) + wori[2] * sinw) + r*tpos[0] * (cosw + wori[1]*wori[1]*(1-cosw)));
		ptrpos[1] = wpos[1] + wscale*((d-r*tpos[1]) * (wori[2] * wori[3] * (1 - cosw) - wori[1] * sinw) + r*tpos[0] * (wori[1]*wori[2]*(1-cosw)+wori[3]*sinw));
		ptrpos[2] = wpos[2] + wscale*((d-r*tpos[1]) * (cosw + wori[3] * wori[3] * (1 - cosw)) + r*tpos[0] * (wori[1]*wori[3]*(1-cosw)-wori[2]*sinw));

		this->Pointer->SetCenter(ptrpos);
	}

	if (this->Interactor)
	{
		this->Interactor->Render();
	}	
	}
}

void vtkOpenVRInteractorStyle::SetTouchPadImage(bool activate)
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
		if (this->ImgRenderer != NULL && this->ImgActor)
		{
			this->ImgRenderer->RemoveActor(this->ImgActor);
			this->ImgRenderer = NULL;
		}
	}
	//to enable it
	else
	{
		//Load next image. Just to test functionality.
		//this->NextImage = (++NextImage) % (ImgActor->GetSliceNumberMax() + 1);
		//this->UpdateImage();


		//check if used different renderer to previous visualization
		if (this->CurrentRenderer != this->ImgRenderer)
		{
			if (this->ImgRenderer != NULL && this->ImgActor)
			{
				this->ImgRenderer->RemoveActor(this->ImgActor);
			}
			if (this->CurrentRenderer != 0)
			{
				this->CurrentRenderer->AddActor(this->ImgActor);
			}
			else
			{
				vtkWarningMacro(<< "no current renderer on the interactor style.");
			}
			this->ImgRenderer = this->CurrentRenderer;
		}

		vtkOpenVRRenderWindowInteractor *rwi =
			static_cast<vtkOpenVRRenderWindowInteractor *>(this->Interactor);
		vtkOpenVRRenderer *ren = vtkOpenVRRenderer::SafeDownCast(this->CurrentRenderer);
		vtkOpenVRCamera *camera = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());

		//Get world information
		double wscale = camera->GetDistance();                                 //Scale
		double *wpos = rwi->GetWorldEventPosition(rwi->GetPointerIndex());     //Position
		double *wori = rwi->GetWorldEventOrientation(rwi->GetPointerIndex());  //Orientation
		wori[0] = vtkMath::RadiansFromDegrees(wori[0]);

		//Get/Set touchpad information
		const double d = 0.05;	// Distance from center of controller to center of touchpad
		const double h = 0.007;	// Separation image-touchpad.

								//ROTATION
		ImgActor->SetOrientation(0, 0, 0);
		ImgActor->RotateWXYZ(vtkMath::DegreesFromRadians(wori[0]), wori[1], wori[2], wori[3]);
		ImgActor->RotateX(-85);		//Adjust to the touchpad's inclination.

									//SCALE
		double *imgBounds = this->ImgActor->GetMapper()->GetBounds();
		//It is supposed to be a squared image (image of a circle), so xScale == yScale
		double imgScale = 0.0475 / (++imgBounds[1]);
		this->ImgActor->SetScale(imgScale);

		//TRANSLATION
		double imgPos[3];
		double cosw = cos(wori[0]);
		double sinw = sin(wori[0]);
		//Will place a corner of the image in the center of the touchpad.
		imgPos[0] = wpos[0] + wscale * (d * (wori[1] * wori[3] * (1 - cosw) + wori[2] * sinw) + h * (wori[1] * wori[2] * (1 - cosw) - wori[3] * sinw));
		imgPos[1] = wpos[1] + wscale * (d * (wori[2] * wori[3] * (1 - cosw) - wori[1] * sinw) + h * (cosw + wori[2] * wori[2] * (1 - cosw)));
		imgPos[2] = wpos[2] + wscale * (d * (cosw + wori[3] * wori[3] * (1 - cosw)) + h * (wori[2] * wori[3] * (1 - cosw) + wori[1] * sinw));
		this->ImgActor->SetPosition(imgPos);
		this->ImgActor->Update();
		//Now, center the image to the center of touchpad (can't be done before because "position" might not be set.
		double *imgCtr = this->ImgActor->GetCenter();
		//Move center if the image to the corner (which is center of touchpad)
		for (int i = 0; i < 3; i++) imgPos[i] += (imgPos[i] - imgCtr[i]);
		this->ImgActor->SetPosition(imgPos);
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
