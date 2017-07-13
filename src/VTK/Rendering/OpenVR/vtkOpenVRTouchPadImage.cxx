/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRTouchpadImage.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRTouchPadImage.h"

#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"

#include "vtkTextActor3D.h"
#include "vtkTextProperty.h"
#include "vtkRenderer.h"
#include "vtkTextSource.h"
#include "vtkStringArray.h"

#include "vtkPNGReader.h"
#include "vtkImageActor.h"
#include "vtkImageSliceMapper.h"
#include "vtkOpenVRRenderWindowInteractor.h"
#include "vtkOpenVRRenderer.h"
#include "vtkOpenVRInteractorStyle.h"
#include "vtkOpenVRInteractorStyleInputData.h"
#include "vtkOpenVRCamera.h"

vtkStandardNewMacro(vtkOpenVRTouchPadImage);

//----------------------------------------------------------------------------
vtkOpenVRTouchPadImage::vtkOpenVRTouchPadImage()
{
	this->ImgReader = vtkPNGReader::New();
	this->ImgActor = vtkImageActor::New();
	this->ImgRenderer = NULL;

	this->HasImage = true;
	this->NextImage = 0;
	this->MaxNumImg = -1;
}

//----------------------------------------------------------------------------
vtkOpenVRTouchPadImage::~vtkOpenVRTouchPadImage()
{
	if (this->ImgActor)
	{
		this->ImgActor->Delete();
	}
	if (this->ImgReader)
	{
		this->ImgReader->Delete();
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadImage::LoadImages(int imgNum, char *prefix)
{
	this->MaxNumImg = imgNum;

	vtkStringArray *FileNames = vtkStringArray::New();
	for (int i = 0; i< imgNum; i++)
	{
		FileNames->InsertNextValue(prefix + vtkVariant(i).ToString() + ".png");
	}
	this->ImgReader->SetFileNames(FileNames);
	this->ImgReader->Update();
	FileNames->Delete();
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadImage::LoadSingleImage(char * fullName)
{
	this->MaxNumImg = 1;

	this->ImgReader->SetFileName(fullName);
	this->ImgReader->Update();
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadImage::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadImage::Init()
{
	this->ImgActor->GetMapper()->SetInputData(this->ImgReader->GetOutput());
	this->ImgActor->SetInputData(this->ImgReader->GetOutput());
	this->ImgActor->PickableOff();
	this->ImgActor->DragableOff();
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadImage::Attach(vtkOpenVRRenderWindowInteractor * rwi)
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

	//check if used different renderer to previous visualization
	if (ren != this->ImgRenderer)
	{
		if (this->ImgRenderer != NULL && this->ImgActor)
		{
			this->ImgRenderer->RemoveActor(this->ImgActor);
		}
		if (ren != 0)
		{
			ren->AddActor(this->ImgActor);
		}
		else
		{
			vtkWarningMacro(<< "no current renderer on the interactor style.");
		}
		this->ImgRenderer = ren;
	}

	this->Move(rwi);
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadImage::Move(vtkOpenVRRenderWindowInteractor * rwi)
{
	//Current renderer
	vtkOpenVRRenderer *ren = NULL;
	vtkOpenVRInteractorStyle *ist = NULL;
	vtkOpenVRCamera *cam = NULL;
	int pointer;
	if (rwi)
	{
		pointer = rwi->GetPointerIndexLastTouchpad();
		//This will return the current renderer:
		ren = vtkOpenVRRenderer::SafeDownCast(rwi->FindPokedRenderer(rwi->GetEventPositions(pointer)[0],
																																 rwi->GetEventPositions(pointer)[1]));
		ist = vtkOpenVRInteractorStyleInputData::SafeDownCast(rwi->GetInteractorStyle());
		cam = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());
	}
	else return;

	//Get world information
	double wscale = cam->GetDistance();																		//Scale
	double *wpos = rwi->GetWorldEventPosition(pointer);    //Position
	double *wori = rwi->GetWorldEventOrientation(pointer); //Orientation
	wori[0] = vtkMath::RadiansFromDegrees(wori[0]);

	//Get/Set touchpad information
	const double d = 0.05;	// Distance from center of controller to center of touchpad
	const double h = 0.007;	// Separation image-touchpad.

	//ROTATION
	this->ImgActor->SetOrientation(0, 0, 0);
	this->ImgActor->RotateWXYZ(vtkMath::DegreesFromRadians(wori[0]), wori[1], wori[2], wori[3]);
	this->ImgActor->RotateX(-85);		//Adjust to the touchpad's inclination.

	//SCALE
	double *imgBounds = this->ImgActor->GetMapper()->GetBounds();
	//It is supposed to be a squared image (image of a circle), so xScale == yScale
	double imgScale = 0.0475 / (++imgBounds[1]);
	this->ImgActor->SetScale(wscale*imgScale);

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

	if (rwi)
	{
		rwi->Render();
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadImage::Detach()
{
	if (this->ImgRenderer != NULL && this->ImgActor)
	{
		this->ImgRenderer->RemoveActor(this->ImgActor);
		this->ImgRenderer = NULL;
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRTouchPadImage::UpdateImage()
{
	if (this->GetHasImage())
	{
		if (this->ImgActor->GetZSlice() != this->NextImage)
		{
			//Change image. Need to update both Mapper and Actor.
			if (this->NextImage <= ImgActor->GetWholeZMax() && this->NextImage >= ImgActor->GetWholeZMin())
			{
				ImgActor->SetZSlice(this->NextImage);
			}
			else
			{
				vtkErrorMacro(<< "ImgActor: Image slice number is out of bounds");
			}

			vtkImageSliceMapper *sliceMapper = vtkImageSliceMapper::SafeDownCast(ImgActor->GetMapper());
			if (this->NextImage <= sliceMapper->GetSliceNumberMaxValue() && this->NextImage >= sliceMapper->GetSliceNumberMinValue())
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