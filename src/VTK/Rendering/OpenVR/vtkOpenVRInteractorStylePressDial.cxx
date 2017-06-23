/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStylePressDial.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStylePressDial.h"

#include "vtkNew.h"
#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"
#include <valarray>
#include "vtkRenderWindowInteractor3D.h"

#include "vtkTextActor3D.h"
#include "vtkBillboardTextActor3D.h"
#include "vtkTextProperty.h"
#include "vtkTextMapper.h"
#include "vtkRenderer.h"
#include "vtkTextSource.h"
#include "vtkOpenVRRenderer.h"
#include "vtkOpenVRRenderWindowInteractor.h"
#include "vtkOpenVRCamera.h"
#include "vtkMatrixToHomogeneousTransform.h"

vtkStandardNewMacro(vtkOpenVRInteractorStylePressDial);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStylePressDial::vtkOpenVRInteractorStylePressDial()
{
	//Text3D to modify Props' attributes.
	this->TextActor = NULL;
	this->TextRenderer = NULL;
	this->TextHasUnsavedChanges = false;
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStylePressDial::~vtkOpenVRInteractorStylePressDial()
{
	//Remove Text3D
	if(this->TextActor)
	{
		this->TextActor->Delete();
	}
}

//----------------------------------------------------------------------------
//TODO add behaviour if needed
void vtkOpenVRInteractorStylePressDial::OnRightButtonDown()
{
	//Downcast to a 3D Interactor.
	vtkRenderWindowInteractor3D *rwi =
		static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

	float x = rwi->GetTouchPadPosition()[0];	// Values between -1 and 1.
	float y = rwi->GetTouchPadPosition()[1];
	
	float radius = sqrt(x*x + y*y);

	int region = int(5. * atan2(x, y) / vtkMath::Pi());		// Clockwise values, starting in (x,y) = (0,1)
	region = (x > 0) ? region : (region + 9);				// 10 regions. Integer values in range [0, 9]
	
	if(radius > .75)
	{
		//Display number, which is equal to region number
		vtkErrorMacro(<< "Number pressed: " << region);	// Just for debugging purposes.

		//Actual code:
		//if(this->TextActor) this->TextActor->SetInput(this->TextActor->GetInput() + region);
	}
	else
	{
		if(region <= 4)
		{
			vtkErrorMacro(<< "\"Validate number\" pressed. Region: " << region);	// Just for debugging purposes.
		}
		else	// region in range [5,9]
		{
			//Negative angles
			vtkErrorMacro(<< "\"Remove last digit\" pressed. Region: " << region);	// Just for debugging purposes.
		}
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressDial::OnRightButtonUp()
{
	// do nothing except overriding the default OnRightButtonDown behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressDial::OnMiddleButtonDown()
{
	//Get current renderer (if is not got already)
	if (this->Interactor)
	{
		int pointer = this->Interactor->GetPointerIndex();
		this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
		                        this->Interactor->GetEventPositions(pointer)[1]);
	}

	//Second Click. Already created and changes saved: can be destroyed.
	if (this->TextActor && !this->TextHasUnsavedChanges && this->TextRenderer != NULL)
	{
		//Remove from renderer
		if (this->TextRenderer != NULL && this->TextActor)
		{
			this->TextRenderer->RemoveViewProp(this->TextActor);
			this->TextRenderer = NULL;
		}
	}
	//Either or is not created or has changes
	else
	{
		//First Click ever. Not created yet: create it and place it properly.
		if (!this->TextActor)
		{
			this->TextActor = vtkTextActor3D::New();
			this->TextActor->SetInput("Input data madafaka");
			this->TextActor->PickableOff();
			this->TextActor->DragableOff();
			
		}

		//First Click. Created but not shown. Check if used different renderer to previous visualization.
		if (this->CurrentRenderer != this->TextRenderer)
		{
			if (this->TextRenderer != NULL && this->TextActor)
			{
				this->TextRenderer->RemoveViewProp(this->TextActor);
			}
			if (this->CurrentRenderer != 0)
			{
				this->CurrentRenderer->AddViewProp(this->TextActor);
			}
			else
			{
				vtkWarningMacro(<< "no current renderer on the interactor style.");
			}
			this->TextRenderer = this->CurrentRenderer;
		}
	}
	


	//vtkOpenVRRenderWindowInteractor *rwi =
	//	static_cast<vtkOpenVRRenderWindowInteractor *>(this->Interactor);
	vtkOpenVRRenderer *ren = vtkOpenVRRenderer::SafeDownCast(this->CurrentRenderer);
	vtkOpenVRCamera *camera = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());

	double wscale = camera->GetDistance();          //World Scale
	double *camPos = camera->GetPosition();         //Camera Position
	double *camOri = camera->GetOrientation();		//Camera Orientation

	vtkErrorMacro(<< "camPos (x, y, z):");
	vtkErrorMacro(<< "(" << camPos[0] << ", " << camPos[1] << ", " << camPos[2] << ")");
	vtkErrorMacro(<< "camOri (w, ux, uy, uz)");
	vtkErrorMacro(<< "(" << camOri[0] << ", " << camOri[1] << ", " << camOri[2] << ", " << camOri[3] << ")");
	vtkErrorMacro(<< "------------------------------------------------------------");

	const double d2c = 0.5;		//Distance to camera. MAy be needed to multiply by scale.
	
	
	//3D Rotation and Translation Maths
	double cosw = cos(camOri[0] * vtkMath::Pi() / 180);
	double sinw = sin(camOri[0] * vtkMath::Pi() / 180);
	double ptrPos[3];
	double ptrOri[4];
	
/*	//To try:
	vtkMatrix4x4 *m_d2t = vtkMatrix4x4::New();
	m_d2t->SetElement(0, 3, d2c);		// Apply traslation on x-axis.
	m_d2t->SetElement(0, 0, -1);		// Apply rotation of 180� on y-axis.
	m_d2t->SetElement(2, 2, -1);
	camera->SetUserViewTransform(vtkHomogeneousTransform::SafeDownCast(m_d2t));
	//camera->SetUserTransform();
	*/

	//Transformation matrix (X' = R � T � X)
	vtkMatrix4x4 *w2d = vtkMatrix4x4::New();	//World to device
	camera->GetTrackingToDCMatrix(w2d);	//Go from world coordinates to device coordinates?
	vtkMatrix4x4 *d2t = vtkMatrix4x4::New();	//Device to text
	d2t->SetElement(0, 3, d2c);		// Apply traslation on x-axis.
	d2t->SetElement(0, 0, -1);		// Apply rotation of 180� on y-axis.
	d2t->SetElement(2, 2, -1);

	vtkMatrix4x4 *w2t = vtkMatrix4x4::New();	//World to text
	vtkMatrix4x4::Multiply4x4(w2d, d2t, w2t);
	
	vtkErrorMacro(<< "W2D:");
	for(int i=0;i<4;i++)
	vtkErrorMacro(<< "(" << w2d[0] << ", " << w2d[1] << ", " << w2d[2] << ", " << w2d[3] << ")");
	
	
	
	/*
	vtkOpenVRRenderWindow *renWin =
		vtkOpenVRRenderWindow::SafeDownCast(this->Interactor->GetRenderWindow());
	if (!renWin)
	{
		return;
	}

	vr::IVRSystem *pHMD = renWin->GetHMD();
	if (!pHMD)
	{
		return;
	}
	//pHMD->GetPo
	*/





	if (this->Interactor)
	{
		this->Interactor->Render();
	}
}


//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressDial::OnMiddleButtonUp()
{
	// do nothing except overriding the default OnMiddleButtonUp behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressDial::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
