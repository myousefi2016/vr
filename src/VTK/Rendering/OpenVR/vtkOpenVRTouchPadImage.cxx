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
//#include "vtkImageMapper3D.h"
#include "vtkImageSliceMapper.h"

vtkStandardNewMacro(vtkOpenVRTouchPadImage);

//----------------------------------------------------------------------------
vtkOpenVRTouchPadImage::vtkOpenVRTouchPadImage()
{
	//This class contains several images:
	/*vtkStringArray *FileNames = vtkStringArray::New();
	for (int i = 0; i< MAX_IMG; i++)
	{
		FileNames->InsertNextValue("..\\..\\..\\VTK\\Rendering\\OpenVR\\PressKeyboard_Image" + vtkVariant(i).ToString() + ".png");
	}*/
	this->ImgReader = vtkPNGReader::New();
	/*this->ImgReader->SetFileNames(FileNames);
	this->ImgReader->Update();
	FileNames->Delete();*/

	this->ImgActor = vtkImageActor::New();
	/*this->ImgActor->GetMapper()->SetInputData(this->ImgReader->GetOutput());
	this->ImgActor->SetInputData(this->ImgReader->GetOutput());
	this->ImgActor->PickableOff();
	this->ImgActor->DragableOff();*/ //Moved to Init()
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
void vtkOpenVRTouchPadImage::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}

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

void vtkOpenVRTouchPadImage::LoadSingleImage(char * fullName)
{
	this->MaxNumImg = 1;

	this->ImgReader->SetFileName(fullName);
	this->ImgReader->Update();
}

void vtkOpenVRTouchPadImage::Init()
{
	this->ImgActor->GetMapper()->SetInputData(this->ImgReader->GetOutput());
	this->ImgActor->SetInputData(this->ImgReader->GetOutput());
	this->ImgActor->PickableOff();
	this->ImgActor->DragableOff();
}

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
