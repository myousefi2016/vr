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

void vtkOpenVRInteractorStyle::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}
