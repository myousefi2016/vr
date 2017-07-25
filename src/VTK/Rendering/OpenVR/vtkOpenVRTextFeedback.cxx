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
#include "vtkOpenVRCamera.h"

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

void vtkOpenVRTextFeedback::Reset()
{
	if (this->TextActor)
	{
		//Restore initial values
		this->TextActor->SetInput(this->TextDefaultMsg);
		this->DefaultMsgOn = true;
		this->TextIsVisible = false;
		this->HasUnsavedChanges = false;
	}

	if (this->TextRenderer)
	{
		//Remove actor from renderer
		this->TextRenderer->RemoveViewProp(this->TextActor);
		this->TextRenderer = NULL;
	}
}

void vtkOpenVRTextFeedback::PlaceInScene(vtkOpenVRCamera * cam)
{
	double wScale = cam->GetDistance();			//World scale
	double *camPos = cam->GetPosition();         //Camera Position
	double *camOri = cam->GetOrientation();		//Camera Orientation: rotation in (X,Y,Z)

	const double d2c = 1.25;		//Text distance to camera.

															//3D Rotation and Translation Maths
	double cosw = cos(vtkMath::RadiansFromDegrees(camOri[1]));
	double sinw = sin(vtkMath::RadiansFromDegrees(camOri[1]));
	double projection[3] = { sinw, 0, -cosw };
	vtkMath::Normalize(projection);

	double txtPos[3];

	for (int i = 0; i < 3; i++)
		txtPos[i] = camPos[i] + projection[i] * d2c  * wScale;

	//Place text
	this->GetTextActor()->SetScale(0.00125 * wScale);	//Default scale is ridiculously big
	this->GetTextActor()->SetOrientation(0, -camOri[1], 0);
	this->GetTextActor()->SetPosition(txtPos);
	this->GetTextActor()->GetTextProperty()->SetFontSize(60);
}
