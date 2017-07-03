/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStylePressBool.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStylePressBool.h"

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
#include "vtkSphereSource.h"
#include "vtkProperty.h"
#include "vtkPolyDataMapper.h"

#include "vtkOpenVRPropertyModifier.h"

#include "vtkImageActor.h"
#include "vtkImageReader2.h"
#include "vtkImageSliceMapper.h"
#include "vtkJPEGReader.h"
#include "vtkPNGReader.h"
#include "vtkImageMapper.h"
#include "vtkActor2D.h"
#include "vtkImageProperty.h"
#include "vtkStringArray.h"

vtkStandardNewMacro(vtkOpenVRInteractorStylePressBool);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStylePressBool::vtkOpenVRInteractorStylePressBool()
{
	//Text3D to modify Props' attributes.
	this->TextActor = NULL;
	this->TextRenderer = NULL;
	this->TextHasUnsavedChanges = false;
	this->TextDefaultMsg = true;
	this->TextIsVisible = false;

	this->FieldModifier = vtkOpenVRPropertyModifier::New();

	//Images
	//https://gist.github.com/waldyrious/c3be68f0682543ee0ae2
	this->HasImage = true;
	this->NextImage = 0;
	this->ImgReader = vtkPNGReader::New();
	ImgReader->SetFileName("..\\..\\..\\VTK\\Rendering\\OpenVR\\PressDial_Image");
	//ImgReader->SetFilePrefix();
	ImgReader->Update();

	this->ImgActor = vtkImageActor::New();
	this->ImgActor->GetMapper()->SetInputData(this->ImgReader->GetOutput());
	this->ImgActor->PickableOff();
	this->ImgActor->DragableOff();
	this->ImgRenderer = NULL;

	//https://www.researchgate.net/publication/45338891_A_Multimodal_Virtual_Reality_Interface_for_VTK
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStylePressBool::~vtkOpenVRInteractorStylePressBool()
{
	//Remove Text3D
	if(this->TextActor)
	{
		this->TextActor->Delete();
	}

	//Remove Field Modifier:
	if(this->FieldModifier)
	{
		this->FieldModifier->Delete();
	}

	//Remove Image:
	this->SetTouchPadImage(false);
	if (this->ImgActor)
	{
		this->ImgActor->Delete();
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressBool::OnRightButtonDown()
{
	if (this->TextIsVisible)
	{
		//Downcast to a 3D Interactor.
		vtkRenderWindowInteractor3D *rwi =
			static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

		float x = rwi->GetTouchPadPosition()[0];	// Values between -1 and 1.
		float y = rwi->GetTouchPadPosition()[1];

		float radius = sqrt(x*x + y*y);

		bool region = (x>0)?false:true;		//2 regions: right->0(False); left->1(True)
		
		//TODO check if it is convinient to add here if(this->TextActor) and wrap everything.
		
		if (this->TextActor && TextDefaultMsg)
		{
			this->TextActor->SetInput("");
			TextDefaultMsg = false;
			TextHasUnsavedChanges = true;
		}

		if (radius > .3)
		{
			//Display number, which is equal to region number
			vtkErrorMacro(<< "Bool pressed: " << region);	// Just for debugging purposes.

			//Actual code:
			if (this->TextActor)
			{
				//vtkStdString newText = vtkVariant(region).ToString();
				//this->TextActor->SetInput(newText);
				//this->TextActor->GetTextProperty()->BoldOn();
				//TextHasUnsavedChanges = true;
				this->TextActor->SetInput(vtkVariant(region).ToString());
				this->TextActor->GetTextProperty()->BoldOn();
				TextHasUnsavedChanges = true;
			}
		}
		else
		{
			vtkErrorMacro(<< "\"Validate bool\" pressed.");	// Just for debugging purposes.

			//Actual code:
			if (this->TextActor)
			{
				vtkStdString newText = vtkVariant(this->TextActor->GetInput()).ToString();
				if (newText.compare("") == 0)
				{
					this->TextActor->SetInput(" ");		//Avoids unexpected errors
				}
				this->TextActor->GetTextProperty()->BoldOff();
				TextHasUnsavedChanges = false;
				
				//TODO test with SetVisibility!!:
				//vtkSphereSource *testSource = this->FieldModifier->GetTestSource();
				//this->FieldModifier->ModifyProperty(testSource, vtkField::Radius, //this->TextActor->GetInput());
			}
		}
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressBool::OnRightButtonUp()
{
	// do nothing except overriding the default OnRightButtonDown behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressBool::OnMiddleButtonDown()
{
	//Get current renderer (if is not got already)
	if (this->Interactor)
	{
		int pointer = this->Interactor->GetPointerIndex();
		this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
		                        this->Interactor->GetEventPositions(pointer)[1]);
	}

	bool TextEmpty = false;
	if(this->TextActor) TextEmpty = !bool(vtkStdString(" ").compare(this->TextActor->GetInput()));

	//Second Click. Already created and changes saved: can be hidden.
	if (this->TextActor && this->TextRenderer != NULL &&
		(!this->TextHasUnsavedChanges || TextEmpty))
	{
		if (this->TextRenderer != NULL && this->TextActor)
		{
			//Remove from renderer
			this->TextRenderer->RemoveViewProp(this->TextActor);
			this->TextRenderer = NULL;
			//Restore initial values
			this->TextActor->SetInput("Select Bool");
			this->TextDefaultMsg = true;
			this->TextIsVisible = false;
			//this->TextHasUnsavedChanges = false;

			//Test:
			//this->ShowTestActor(false);
		}
	}
	//Either or is not created or has changes or is not shown
	else
	{
		//First Click ever. Not created yet: create it and place it properly.
		if (!this->TextActor)
		{
			this->TextActor = vtkTextActor3D::New();
			this->TextActor->SetInput("Select Bool");
			this->TextActor->PickableOff();
			this->TextActor->DragableOff();
			this->TextActor->GetTextProperty()->SetBackgroundOpacity(1.0);
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
			this->TextIsVisible = true;
			this->TextHasUnsavedChanges = false;

			//Test:
			//this->ShowTestActor(true);
		}

	}
	
	vtkOpenVRRenderer *ren = vtkOpenVRRenderer::SafeDownCast(this->CurrentRenderer);
	vtkOpenVRCamera *camera = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());

	double *camPos = camera->GetPosition();         //Camera Position
	double *camOri = camera->GetOrientation();		//Camera Orientation: rotation in (X,Y,Z)
	
	const double d2c = 0.5;		//Text distance to camera.
	
	//3D Rotation and Translation Maths
	double cosw = cos(vtkMath::RadiansFromDegrees(camOri[1]));
	double sinw = sin(vtkMath::RadiansFromDegrees(camOri[1]));
	double projection[3] = {sinw, 0, -cosw};
	vtkMath::Normalize(projection);

	double txtPos[3];

	for (int i = 0; i < 3; i++)
		txtPos[i] = camPos[i] + projection[i] * d2c;

	//Place text
	this->TextActor->SetScale(0.01);	//Default scale is ridiculously big.
	this->TextActor->SetOrientation(0, -camOri[1], 0);
	this->TextActor->SetPosition(txtPos);

	//Render Scene
	if (this->Interactor)
	{
		this->Interactor->Render();
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressBool::OnMiddleButtonUp()
{
	// do nothing except overriding the default OnMiddleButtonUp behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressBool::ShowTestActor(bool on)
{
	//Get prop data:
	vtkSphereSource *testSource = this->FieldModifier->GetTestSource();
	vtkRenderer *testRenderer = this->FieldModifier->GetTestRenderer();
	vtkPolyDataMapper *testMapper = this->FieldModifier->GetTestMapper();
	vtkActor *testActor = this->FieldModifier->GetTestActor();


		//current renderer
		if (this->Interactor)
		{
			int pointer = this->Interactor->GetPointerIndex();
			this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
				this->Interactor->GetEventPositions(pointer)[1]);
		}

	//to disable it
	if (!on)
	{
		if (testRenderer != NULL && testActor)
		{
			testRenderer->RemoveActor(testActor);
			this->FieldModifier->SetTestRenderer(NULL);
		}
	}
	//to enable it
	else
	{
		//check if it is already active
		if (!testActor)
		{
			//create and place in coordinates.
			testSource->SetPhiResolution(50);
			testSource->SetThetaResolution(50);
			testActor = vtkActor::New();
			this->FieldModifier->SetTestActor(testActor);
			testActor->PickableOff();
			testActor->DragableOff();
			testActor->SetMapper(testMapper);
			testActor->GetProperty()->SetAmbient(1.0);
			testActor->GetProperty()->SetDiffuse(0.0);
		}

		//check if used different renderer to previous visualization
		if (this->CurrentRenderer != testRenderer)
		{
			if (testRenderer != NULL && testActor)
			{
				testRenderer->RemoveActor(testActor);
			}
			if (this->CurrentRenderer != 0)
			{
				this->CurrentRenderer->AddActor(testActor);
			}
			else
			{
				vtkWarningMacro(<< "no current renderer on the interactor style.");
			}
			this->FieldModifier->SetTestRenderer(this->CurrentRenderer);
		}

		vtkOpenVRRenderWindowInteractor *rwi =
			static_cast<vtkOpenVRRenderWindowInteractor *>(this->Interactor);
		vtkOpenVRRenderer *ren = vtkOpenVRRenderer::SafeDownCast(this->CurrentRenderer);
		vtkOpenVRCamera *camera = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());

		double wscale = camera->GetDistance();                                 //Scale
		this->Pointer->SetRadius(.01*wscale);	//Pointer radius

		this->Pointer->SetCenter(0.,0.,0.);
	}

	if (this->Interactor)
	{
		this->Interactor->Render();
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressBool::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
