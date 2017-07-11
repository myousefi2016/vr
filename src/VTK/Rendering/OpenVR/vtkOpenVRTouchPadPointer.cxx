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


#include "vtkPolyDataMapper.h";
#include "vtkSphereSource.h";

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