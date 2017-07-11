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

#include "vtkTextActor3D.h"
#include "vtkTextProperty.h"
#include "vtkRenderer.h"
#include "vtkTextSource.h"
#include "vtkStringArray.h"

#include "vtkProperty.h"

#include "vtkPolyDataMapper.h";
#include "vtkSphereSource.h";
#include "vtkOpenVRRenderer.h"
#include "vtkOpenVRRenderWindowInteractor.h"
#include "vtkOpenVRCamera.h"
#include "vtkOpenVRInteractorStyleInputData.h"
#include "vtkQuaternion.h"

vtkStandardNewMacro(vtkOpenVRTouchPadPointer);

//----------------------------------------------------------------------------
vtkOpenVRTouchPadPointer::vtkOpenVRTouchPadPointer()
{
	this->PointerSource = vtkSphereSource::New();
	this->PointerActor = NULL;
	this->PointerMapper = vtkPolyDataMapper::New();

	if (this->PointerMapper && this->PointerSource)
	{
		this->PointerMapper->SetInputConnection(this->PointerSource->GetOutputPort());
	}

	this->PointerRenderer = NULL;
	this->PointerColor[0] = 0.0;
	this->PointerColor[1] = 1.0;
	this->PointerColor[2] = 0.0;
}

//----------------------------------------------------------------------------
vtkOpenVRTouchPadPointer::~vtkOpenVRTouchPadPointer()
{
	/*if (this->ImgActor)
	{
		this->ImgActor->Delete();
	}
	if (this->ImgReader)
	{
		this->ImgReader->Delete();
	}*/


	//this->SetTouchPadPointer(false);
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
void vtkOpenVRTouchPadPointer::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}

void vtkOpenVRTouchPadPointer::Init()
{
	/*this->ImgActor->GetMapper()->SetInputData(this->ImgReader->GetOutput());
	this->ImgActor->SetInputData(this->ImgReader->GetOutput());
	this->ImgActor->PickableOff();
	this->ImgActor->DragableOff();*/


	//TODO subsitute by vtkOVRTPPointer::Init()
	//create and place in coordinates.
	this->PointerSource->SetPhiResolution(50);
	this->PointerSource->SetThetaResolution(50);
	//TODO move the New() to th constructor, and also delete from the destructor.
	this->PointerActor = vtkActor::New();
	this->PointerActor->PickableOff();
	this->PointerActor->DragableOff();
	this->PointerActor->SetMapper(this->PointerMapper);
	this->PointerActor->GetProperty()->SetColor(PointerColor);
	this->PointerActor->GetProperty()->SetAmbient(1.0);
	this->PointerActor->GetProperty()->SetDiffuse(0.0);
}

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

	vtkOpenVRCamera *cam = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());

	//Get world information
	double wscale = cam->GetDistance();                                 //Scale
	double *wpos = rwi->GetWorldEventPosition(rwi->GetPointerIndex());     //Position
	double *wori = rwi->GetWorldEventOrientation(rwi->GetPointerIndex());  //Orientation

	//Get/Set touchpad information
	const double r = 0.02;	//Touchpad radius
	const double d = 0.05;	// Distance from center of controller to center of touchpad
	float *tpos = rwi->GetTouchPadPosition();
	this->PointerSource->SetRadius(.0075*wscale);	//Pointer radius

	//3D Rotation and Translation Maths
	double cosw = cos(vtkMath::RadiansFromDegrees(wori[0]));
	double sinw = sin(vtkMath::RadiansFromDegrees(wori[0]));
	double ptrpos[3];

	//Transformation matrix (X' = R · T · X)
	//ptrpos = controller position + translate to touchpad
	ptrpos[0] = wpos[0] + wscale*((d - r*tpos[1]) * (wori[1] * wori[3] * (1 - cosw) + wori[2] * sinw) + r*tpos[0] * (cosw + wori[1] * wori[1] * (1 - cosw)));
	ptrpos[1] = wpos[1] + wscale*((d - r*tpos[1]) * (wori[2] * wori[3] * (1 - cosw) - wori[1] * sinw) + r*tpos[0] * (wori[1] * wori[2] * (1 - cosw) + wori[3] * sinw));
	ptrpos[2] = wpos[2] + wscale*((d - r*tpos[1]) * (cosw + wori[3] * wori[3] * (1 - cosw)) + r*tpos[0] * (wori[1] * wori[3] * (1 - cosw) - wori[2] * sinw));

	this->PointerSource->SetCenter(ptrpos);
}

void vtkOpenVRTouchPadPointer::Move(vtkOpenVRRenderWindowInteractor *rwi)
{
	//Current renderer
	vtkOpenVRRenderer *ren = NULL;
	vtkInteractorStyle3D *ist = NULL;
	if (rwi)
	{
		int pointer = rwi->GetPointerIndex();
		//This will return the current renderer:
		ren = vtkOpenVRRenderer::SafeDownCast(rwi->FindPokedRenderer(rwi->GetEventPositions(pointer)[0],
		                                                             rwi->GetEventPositions(pointer)[1]));
		ist = vtkOpenVRInteractorStyleInputData::SafeDownCast(rwi->GetInteractorStyle());
	}



	// this->InteractionProp  -->> this->PointerActor

	if (ren == NULL || this->PointerActor == NULL)
	{
		return;
	}

	//Highlight current Prop.
	if (this->PointerActor != NULL)
	{
		ist->HighlightProp(this->PointerActor);
	}

	/*	vtkRenderWindowInteractor3D *rwi3D =
			static_cast<vtkRenderWindowInteractor3D *>(rwi);*/

	double *wpos = rwi->GetWorldEventPosition(
		rwi->GetPointerIndex());

	double *lwpos = rwi->GetLastWorldEventPosition(
		rwi->GetPointerIndex());

	double trans[3];
	for (int i = 0; i < 3; i++)
	{
		trans[i] = wpos[i] - lwpos[i];
	}

	if (this->PointerActor->GetUserMatrix() != NULL)
	{
		//Conseguir TempTransfrm o algo parecido de PointerActor!!
		vtkTransform *t = this->TempTransform;
		t->PostMultiply();
		t->SetMatrix(this->PointerActor->GetUserMatrix());
		t->Translate(trans);
		this->PointerActor->SetUserMatrix(t->GetMatrix());
	}
	else
	{
		this->PointerActor->AddPosition(trans);
	}

	double *wori = rwi->GetWorldEventOrientation(
		rwi->GetPointerIndex());

	double *lwori = rwi->GetLastWorldEventOrientation(
		rwi->GetPointerIndex());

	// compute the net rotation
	vtkQuaternion<double> q1;
	q1.SetRotationAngleAndAxis(
		vtkMath::RadiansFromDegrees(lwori[0]), lwori[1], lwori[2], lwori[3]);
	vtkQuaternion<double> q2;
	q2.SetRotationAngleAndAxis(
		vtkMath::RadiansFromDegrees(wori[0]), wori[1], wori[2], wori[3]);
	q1.Conjugate();
	q2 = q2*q1;
	double axis[4];
	axis[0] = vtkMath::DegreesFromRadians(q2.GetRotationAngleAndAxis(axis + 1));

	double scale[3];
	scale[0] = scale[1] = scale[2] = 1.0;

	double *rotate = axis;
	this->Prop3DTransform(this->InteractionProp,
	                      wpos,
	                      1,
	                      &rotate,
	                      scale);

	if (this->AutoAdjustCameraClippingRange)
	{
		this->CurrentRenderer->ResetCameraClippingRange();
	}




}

void vtkOpenVRTouchPadPointer::Detach()
{
	if (this->PointerRenderer != NULL && this->PointerActor)
	{
		this->PointerRenderer->RemoveActor(this->PointerActor);
		this->PointerRenderer = NULL;
	}
}

/*
void vtkOpenVRTouchPadImage::UpdateImage()
{
	//TODO test
	if (this->GetHasImage())
	{
		if (this->ImgActor->GetZSlice() != this->NextImage)
		{
			//Change image. Need to update both Mapper and Actor:
			//To test
			if (this->NextImage <= ImgActor->GetWholeZMax() && this->NextImage >= ImgActor->GetWholeZMin())
			{
				ImgActor->SetZSlice(this->NextImage);
				//this->ImgActor->Update();
			}
			else
			{
				vtkErrorMacro(<< "ImgActor: Image slice number is out of bounds");
			}

			vtkImageSliceMapper *sliceMapper = vtkImageSliceMapper::SafeDownCast(ImgActor->GetMapper());
			if (this->NextImage <= sliceMapper->GetSliceNumberMaxValue() && this->NextImage >= sliceMapper->GetSliceNumberMinValue())
			{
				sliceMapper->SetSliceNumber(this->NextImage);
				//sliceMapper->Update();
			}
			else
			{
				vtkErrorMacro(<< "ImgMapper: Image slice number is out of bounds");
			}
		}
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadImage::IncNextImage()
{
	if (this->NextImage == (MAX_IMG / 2 - 1) || this->NextImage == (MAX_IMG - 1))
	{
		this->NextImage -= (MAX_IMG / 2 - 1);
	}
	else
	{
		this->NextImage++;
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadImage::DecNextImage()
{
	if (this->NextImage == 0 || this->NextImage == (MAX_IMG / 2))
	{
		this->NextImage += (MAX_IMG / 2 - 1);
	}
	else
	{
		this->NextImage--;
	}
}
*/