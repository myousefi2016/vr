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

#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"
#include <valarray>
#include "vtkRenderWindowInteractor3D.h"

#include "vtkTextActor3D.h"
#include "vtkTextProperty.h"
#include "vtkRenderer.h"
#include "vtkOpenVRRenderer.h"
#include "vtkOpenVRRenderWindowInteractor.h"
#include "vtkOpenVRCamera.h"
#include "vtkSphereSource.h"
#include "vtkProperty.h"
#include "vtkPolyDataMapper.h"	//For test. Might be removed if tests are moved avay.

#include "vtkOpenVRPropertyModifier.h"

#include "vtkImageActor.h"
#include "vtkImageReader2.h"
#include "vtkImageSliceMapper.h"
#include "vtkPNGReader.h"
#include "vtkActor2D.h"
#include "vtkStringArray.h"

#include "vtkOpenVRTextFeedback.h"
#include "vtkOpenVRTouchPadImage.h"
#include "vtkOpenVRTouchPadPointer.h"

vtkStandardNewMacro(vtkOpenVRInteractorStylePressBool);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStylePressBool::vtkOpenVRInteractorStylePressBool()
{
	//Text3D to modify Props' attributes.
	this->TextFeedback = vtkOpenVRTextFeedback::New();
	this->TextFeedback->SetTextDefaultMsg("Select Bool");

	this->FieldModifier = vtkOpenVRPropertyModifier::New();

	//Images
	//https://gist.github.com/waldyrious/c3be68f0682543ee0ae2
	this->TouchPadImage = vtkOpenVRTouchPadImage::New();
	this->TouchPadImage->LoadSingleImage( "..\\..\\..\\VTK\\Rendering\\OpenVR\\PressDial_Image0.png");
	this->TouchPadImage->Init();

	//TouchPad Pointer
	this->TouchPadPointer = vtkOpenVRTouchPadPointer::New();



	//https://www.researchgate.net/publication/45338891_A_Multimodal_Virtual_Reality_Interface_for_VTK
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStylePressBool::~vtkOpenVRInteractorStylePressBool()
{
	//Remove Text3D
	if (this->TextFeedback)
	{
		this->TextFeedback->Delete();
	}

	//Remove Field Modifier:
	if(this->FieldModifier)
	{
		this->FieldModifier->Delete();
	}

	//Remove Image:
	if (this->TouchPadImage)
	{
		this->TouchPadImage->Delete();
	}

	//Remove Pointer
	if (this->TouchPadPointer)
	{
		this->TouchPadPointer->Delete();
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressBool::OnRightButtonDown()
{
	if (this->TextFeedback->GetTextIsVisible() && this->TextFeedback->GetTextActor())
	{
		//Downcast to a 3D Interactor.
		vtkRenderWindowInteractor3D *rwi =
			static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

		float x = rwi->GetTouchPadPosition()[0];	// Values between -1 and 1.
		float y = rwi->GetTouchPadPosition()[1];

		float radius = sqrt(x*x + y*y);

		//bool region = (x>0)?false:true;		//2 regions: right->0(False); left->1(True)
		char *selBool = (x > 0) ? "false" : "true";
		
		//TODO check if it is convinient to add here if(this->TextActor) and wrap everything.
		
		if (this->TextFeedback->GetDefaultMsgOn())
		{
			this->TextFeedback->GetTextActor()->SetInput("");
			this->TextFeedback->SetDefaultMsgOn(false);
			this->TextFeedback->SetHasUnsavedChanges(true);
		}

		if (radius > .3)
		{
			//Display number, which is equal to region number
			vtkErrorMacro(<< "Bool pressed: " << selBool);	// Just for debugging purposes.

			//Actual code:
			this->TextFeedback->GetTextActor()->SetInput(selBool);
			this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
			this->TextFeedback->SetHasUnsavedChanges(true);
		}
		else
		{
			vtkErrorMacro(<< "\"Validate bool\" pressed.");	// Just for debugging purposes.

			//Actual code:
			vtkStdString newText = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToString();
			if (newText.compare("") == 0)
			{
				this->TextFeedback->GetTextActor()->SetInput(" ");		//Avoids unexpected errors
			}
			this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOff();
			this->TextFeedback->SetHasUnsavedChanges(false);
				
			//TODO test with SetVisibility!!:
			//vtkSphereSource *testSource = this->FieldModifier->GetTestSource();
			//this->FieldModifier->ModifyProperty(testSource, vtkField::Radius, //this->TextActor->GetInput());
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
	if (this->TextFeedback->GetTextActor())
		TextEmpty = !bool(vtkStdString(" ").compare(this->TextFeedback->GetTextActor()->GetInput()));

	//Second Click. Already created and changes saved: can be hidden.
	if (this->TextFeedback->GetTextActor() && this->TextFeedback->GetTextRenderer() != NULL
			&& (!this->TextFeedback->GetHasUnsavedChanges() || TextEmpty))
	{
		if (this->TextFeedback->GetTextRenderer() != NULL && this->TextFeedback->GetTextActor())
		{
			//Remove from renderer
			this->TextFeedback->GetTextRenderer()->RemoveViewProp(this->TextFeedback->GetTextActor());
			this->TextFeedback->SetTextRenderer(NULL);
			//Restore initial values
			this->TextFeedback->GetTextActor()->SetInput(this->TextFeedback->GetTextDefaultMsg());
			this->TextFeedback->SetDefaultMsgOn(true);
			this->TextFeedback->SetTextIsVisible(false);

			//Test:
			//this->ShowTestActor(false);
		}
	}
	//Either or is not created or has changes or is not shown
	else
	{
		//First Click ever. Not created yet: create it and place it properly.
		if (!this->TextFeedback->GetTextActor())
		{
			this->TextFeedback->Init();
		}

		//First Click. Created but not shown. Check if used different renderer to previous visualization.
		if (this->CurrentRenderer != this->TextFeedback->GetTextRenderer())
		{
			if (this->TextFeedback->GetTextRenderer() != NULL && this->TextFeedback->GetTextActor())
			{
				this->TextFeedback->GetTextRenderer()->RemoveViewProp(this->TextFeedback->GetTextActor());
			}
			if (this->CurrentRenderer != 0)
			{
				this->CurrentRenderer->AddViewProp(this->TextFeedback->GetTextActor());
			}
			else
			{
				vtkWarningMacro(<< "no current renderer on the interactor style.");
			}
			this->TextFeedback->SetTextRenderer(this->CurrentRenderer);
			this->TextFeedback->SetTextIsVisible(true);
			this->TextFeedback->SetHasUnsavedChanges(false);

			//Test:
			//this->ShowTestActor(true);
		}

	}
	
	vtkOpenVRRenderer *ren = vtkOpenVRRenderer::SafeDownCast(this->CurrentRenderer);
	vtkOpenVRCamera *camera = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());

	double wScale = camera->GetDistance();			//World scale
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
	this->TextFeedback->GetTextActor()->SetScale(0.00125 * wScale);	//Default scale is ridiculously big
	this->TextFeedback->GetTextActor()->SetOrientation(0, -camOri[1], 0);
	this->TextFeedback->GetTextActor()->SetPosition(txtPos);
	this->TextFeedback->GetTextActor()->GetTextProperty()->SetFontSize(60);

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
		this->TouchPadPointer->GetPointerSource()->SetRadius(.01*wscale);	//Pointer radius

		this->TouchPadPointer->GetPointerSource()->SetCenter(0.,0.,0.);
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
