/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleTapDial.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStyleTapDial.h"

#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"
#include <valarray>
#include "vtkRenderWindowInteractor3D.h"

#include "vtkTextActor3D.h"
#include "vtkTextProperty.h"
#include "vtkRenderer.h"
#include "vtkTextSource.h"
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

vtkStandardNewMacro(vtkOpenVRInteractorStyleTapDial);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleTapDial::vtkOpenVRInteractorStyleTapDial()
{
	//Text3D to modify Props' attributes.
	this->TextFeedback = vtkOpenVRTextFeedback::New();

	this->FieldModifier = vtkOpenVRPropertyModifier::New();

	//Images
	/*//https://gist.github.com/waldyrious/c3be68f0682543ee0ae2
	this->ImgReader = vtkPNGReader::New();
	this->HasImage = true;
	this->NextImage = 0;

	//In this class, only one image needed.
	this->ImgReader->SetFileName("..\\..\\..\\VTK\\Rendering\\OpenVR\\PressDial_Image0.png");
	ImgReader->Update();

	this->ImgActor = vtkImageActor::New();
	this->ImgActor->GetMapper()->SetInputData(this->ImgReader->GetOutput());
	this->ImgActor->PickableOff();
	this->ImgActor->DragableOff();
	this->ImgRenderer = NULL;*/
	this->TouchPadImage = vtkOpenVRTouchPadImage::New();
	this->TouchPadImage->LoadSingleImage("..\\..\\..\\VTK\\Rendering\\OpenVR\\TapDial_Image0.png");
	this->TouchPadImage->Init();


	//TouchPad Pointer
	this->TouchPadPointer = vtkOpenVRTouchPadPointer::New();


	//https://www.researchgate.net/publication/45338891_A_Multimodal_Virtual_Reality_Interface_for_VTK
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleTapDial::~vtkOpenVRInteractorStyleTapDial()
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
	/*this->SetTouchPadImage(false);
	if (this->ImgActor)
	{
		this->ImgActor->Delete();
	}
	if (this->ImgReader)
	{
		this->ImgReader->Delete();
	}
	//It may cause problems (deleted in other places). Think about removing :
	if (this->ImgRenderer)
	{
		this->ImgRenderer->Delete();
	}*/
	if (this->TouchPadImage)
	{
		this->TouchPadImage->Delete();
	}

	//Remove pointer
	if (this->TouchPadPointer)
	{
		this->TouchPadPointer->Delete();
	}

}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleTapDial::OnRightButtonDown()
{
	if (this->TextFeedback->GetTextIsVisible() && this->TextFeedback->GetTextActor())
	{
		//Downcast to a 3D Interactor.
		vtkRenderWindowInteractor3D *rwi =
			static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

		float x = rwi->GetTouchPadPosition()[0];	// Values between -1 and 1.
		float y = rwi->GetTouchPadPosition()[1];

		float radius = sqrt(x*x + y*y);

		int region = int(5. * atan2(x, y) / vtkMath::Pi());		// Clockwise values, starting in (x,y) = (0,1)
		region = (x > 0) ? region : (region + 9);				// 10 regions. Integer values in range [0, 9]

		if (this->TextFeedback->GetDefaultMsgOn())
		{
			this->TextFeedback->GetTextActor()->SetInput("");
			this->TextFeedback->SetDefaultMsgOn(false);
			this->TextFeedback->SetHasUnsavedChanges(true);
		}

		if (radius > .6)
		{
			//Display number, which is equal to region number
			vtkErrorMacro(<< "Number pressed: " << region);	// Just for debugging purposes.

			//Actual code:
			vtkStdString newText = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToString() + vtkVariant(region).ToString();
			this->TextFeedback->GetTextActor()->SetInput(newText);
			this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
			this->TextFeedback->SetHasUnsavedChanges(true);

		}
		else if(radius > .2)
		{
			if (region <= 4)
			{
				vtkErrorMacro(<< "\"Validate number\" pressed. Region: " << region);	// Just for debugging purposes.

				//Actual code:
				vtkStdString newText = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToString();
				if (newText.compare("") == 0)
				{
					this->TextFeedback->GetTextActor()->SetInput(" ");		//Avoids unexpected errors
				}
				this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOff();
				this->TextFeedback->SetHasUnsavedChanges(false);

				//test:
				vtkSphereSource *testSource = this->FieldModifier->GetTestSource();
				this->FieldModifier->ModifyProperty(testSource, vtkField::Radius, this->TextFeedback->GetTextActor()->GetInput());
			}
			else	// region in range [5,9]
			{
				vtkErrorMacro(<< "\"Remove last digit\" pressed. Region: " << region);	// Just for debugging purposes.

				//Actual code:
				vtkStdString newText = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToString();
				if (newText.length() <= 1)
				{
					this->TextFeedback->GetTextActor()->SetInput(" ");		//Avoids unexpected errors
					this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOff();
					this->TextFeedback->SetHasUnsavedChanges(false);
				}
				else
				{
					newText.pop_back();
					this->TextFeedback->GetTextActor()->SetInput(newText);
					this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
					this->TextFeedback->SetHasUnsavedChanges(true);
				}
			}
		}
		else
		{
			vtkStdString newText = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToString() + ".";
			this->TextFeedback->GetTextActor()->SetInput(newText);
			this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
			this->TextFeedback->SetHasUnsavedChanges(true);
		}
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleTapDial::OnRightButtonUp()
{
	// do nothing except overriding the default OnRightButtonDown behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleTapDial::OnMiddleButtonDown()
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
			this->ShowTestActor(false);
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
			this->ShowTestActor(true);
		}

	}
	
	vtkOpenVRRenderer *ren = vtkOpenVRRenderer::SafeDownCast(this->CurrentRenderer);
	vtkOpenVRCamera *camera = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());
	
	double wScale = camera->GetDistance();			//World scale
	double *camPos = camera->GetPosition();         //Camera Position
	double *camOri = camera->GetOrientation();		//Camera Orientation: rotation in (X,Y,Z)
	
	const double d2c = 1.25;		//Text distance to camera.
	
	//3D Rotation and Translation Maths
	double cosw = cos(vtkMath::RadiansFromDegrees(camOri[1]));
	double sinw = sin(vtkMath::RadiansFromDegrees(camOri[1]));
	double projection[3] = {sinw, 0, -cosw};
	vtkMath::Normalize(projection);

	double txtPos[3];

	for (int i = 0; i < 3; i++)
		txtPos[i] = camPos[i] + projection[i] * d2c  * wScale;

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
void vtkOpenVRInteractorStyleTapDial::OnMiddleButtonUp()
{
	// do nothing except overriding the default OnMiddleButtonUp behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleTapDial::ShowTestActor(bool on)
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
void vtkOpenVRInteractorStyleTapDial::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
