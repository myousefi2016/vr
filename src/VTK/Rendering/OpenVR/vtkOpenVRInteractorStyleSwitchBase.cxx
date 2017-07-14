/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkOpenVRInteractorStyleSwitchBase.cxx

  Copyright (c) Ventura Romero Mendo
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStyleSwitchBase.h"

#include "vtkObjectFactory.h"

// This is largely here to confirm the approach works, and will be replaced
// with standard factory override logic in the modularized source tree.
//----------------------------------------------------------------------------
vtkObjectFactoryNewMacro(vtkOpenVRInteractorStyleSwitchBase)

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwitchBase::vtkOpenVRInteractorStyleSwitchBase()
{
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwitchBase::~vtkOpenVRInteractorStyleSwitchBase()
{
}

//----------------------------------------------------------------------------
vtkRenderWindowInteractor* vtkOpenVRInteractorStyleSwitchBase::GetInteractor()
{
	static bool warned = false;
	if (!warned &&
			strcmp(this->GetClassName(), "vtkOpenVRInteractorStyleSwitchBase") == 0)
	{
		vtkWarningMacro(
			"Warning: Link to vtkOpenVRInteractionStyle for default style selection.");
		warned = true;
	}
	return NULL;
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchBase::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os, indent);
}
