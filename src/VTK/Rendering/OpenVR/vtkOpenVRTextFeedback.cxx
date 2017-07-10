/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRTextFeedback.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRTextFeedback.h"

#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"

#include "vtkTextActor3D.h"
#include "vtkTextProperty.h"
#include "vtkRenderer.h"
#include "vtkTextSource.h"

vtkStandardNewMacro(vtkOpenVRTextFeedback);

//----------------------------------------------------------------------------
vtkOpenVRTextFeedback::vtkOpenVRTextFeedback()
{
	this->TextActor = NULL;
	this->TextRenderer = NULL;
	this->HasUnsavedChanges = false;
	this->DefaultMsgOn = true;
	this->TextIsVisible = false;
	this->TextDefaultMsg = "Input data";
}

//----------------------------------------------------------------------------
vtkOpenVRTextFeedback::~vtkOpenVRTextFeedback()
{
	if (this->TextActor)
	{
		this->TextActor->Delete();
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRTextFeedback::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}

void vtkOpenVRTextFeedback::Init()
{
	this->TextActor = vtkTextActor3D::New();
	this->GetTextActor()->SetInput(this->TextDefaultMsg);
	this->GetTextActor()->PickableOff();
	this->GetTextActor()->DragableOff();
	this->GetTextActor()->GetTextProperty()->SetBackgroundOpacity(0.25);
}
