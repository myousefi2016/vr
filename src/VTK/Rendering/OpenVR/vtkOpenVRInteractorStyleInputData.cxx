/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleInputData.cxx

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStyleInputData.h"

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

#include "vtkOpenVRTouchPadImage.h"
#include "vtkOpenVRTouchPadPointer.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyleInputData);


//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleInputData::vtkOpenVRInteractorStyleInputData()
{
	//pointers will be constructed in inherited classes, this is an interface class.
	this->TouchPadPointer = NULL;
	this->TouchPadImage = NULL;
	this->TextFeedback = NULL;	
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleInputData::~vtkOpenVRInteractorStyleInputData()
{
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleInputData::OnMiddleButtonDown()
{
  // do nothing except overriding the default MiddleButtonPressEvent behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleInputData::OnMiddleButtonUp()
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
void vtkOpenVRInteractorStyleInputData::OnTap()
{
	int x = this->Interactor->GetEventPosition()[0];
	int y = this->Interactor->GetEventPosition()[1];

	this->FindPokedRenderer(x, y);
	if (this->CurrentRenderer == NULL)
	{
		return;
	}

	//this->SetTouchPadPointer(true);
	vtkOpenVRRenderWindowInteractor *rwi = vtkOpenVRRenderWindowInteractor::SafeDownCast(this->Interactor);
	this->TouchPadPointer->Attach(rwi);
	this->TouchPadImage->Attach(rwi);
	//Maybe need to ad here Move() also?? to avoid jumps at the beginning

	this->GrabFocus(this->EventCallbackCommand);
	this->StartTap();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleInputData::OnUntap()
{
	this->TouchPadPointer->Detach();
	this->TouchPadImage->Detach();

	this->EndTap();

	if (this->Interactor)
	{
		this->ReleaseFocus();
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleInputData::OnMouseMove()
{
	int x = this->Interactor->GetEventPosition()[0];
	int y = this->Interactor->GetEventPosition()[1];

	switch (this->State)
	{
	case VTKIS_ROTATE:
		this->FindPokedRenderer(x, y);
		this->Rotate();
		this->InvokeEvent(vtkCommand::InteractionEvent, NULL);
		break;
	case VTKIS_DOLLY:
		this->FindPokedRenderer(x, y);
		this->Dolly();
		this->InvokeEvent(vtkCommand::InteractionEvent, NULL);
		break;
	case VTKIS_CLIP:
		this->FindPokedRenderer(x, y);
		this->Clip();
		this->InvokeEvent(vtkCommand::InteractionEvent, NULL);
		break;
	case VTKIS_TAP:
		this->FindPokedRenderer(x, y);
		vtkOpenVRRenderWindowInteractor *rwi = vtkOpenVRRenderWindowInteractor::SafeDownCast(this->Interactor);
		this->TouchPadPointer->Move(rwi);
		this->TouchPadImage->Move(rwi);
		this->TrackFinger();
		this->InvokeEvent(vtkCommand::InteractionEvent, NULL);
		break;
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleInputData::IncNextImage()
{
	int nextImg = this->TouchPadImage->GetNextImage();
	if (nextImg == (this->TouchPadImage->GetMaxNumImg() - 1))
	{
		this->TouchPadImage->SetNextImage(0);
	}
	else
	{
		this->TouchPadImage->SetNextImage(++nextImg);
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleInputData::DecNextImage()
{
	int nextImg = this->TouchPadImage->GetNextImage();
	if (nextImg == 0)
	{
		this->TouchPadImage->SetNextImage(this->TouchPadImage->GetMaxNumImg() - 1);
	}
	else
	{
		this->TouchPadImage->SetNextImage(--nextImg);
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleInputData::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}
