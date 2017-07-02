/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStylePressKeyboard.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStylePressKeyboard.h"

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

vtkStandardNewMacro(vtkOpenVRInteractorStylePressKeyboard);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStylePressKeyboard::vtkOpenVRInteractorStylePressKeyboard()
{
	//Text3D to modify Props' attributes.
	this->TextActor = NULL;
	this->TextRenderer = NULL;
	this->TextHasUnsavedChanges = false;
	this->TextDefaultMsg = true;
	this->TextIsVisible = false;

	//Images:
	this->ActiveImage = 0;
	for(int i=0; i< MAX_IMG; i++)
	{
		//Init images properly.
	}

	//Properties' Modifier
	this->FieldModifier = vtkOpenVRPropertyModifier::New();
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStylePressKeyboard::~vtkOpenVRInteractorStylePressKeyboard()
{
	//Remove Text3D
	if(this->TextActor)
	{
		this->TextActor->Delete();
	}

	if(this->FieldModifier)
	{
		this->FieldModifier->Delete();
	}

	//Remove images
	for (int i = 0; i< MAX_IMG; i++)
	{
		//Remove images properly.
	}
}

//----------------------------------------------------------------------------
//TODO add behaviour if needed
void vtkOpenVRInteractorStylePressKeyboard::OnRightButtonDown()
{
	if (this->TextIsVisible)
	{
		//Downcast to a 3D Interactor.
		vtkRenderWindowInteractor3D *rwi =
			static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

		float x = rwi->GetTouchPadPosition()[0];	// Values between -1 and 1.
		float y = rwi->GetTouchPadPosition()[1];

		float radius = sqrt(x*x + y*y);
		char newChar = '\0';

		int region = int(5. * atan2(x, y) / vtkMath::Pi());		// Clockwise values, starting in (x,y) = (0,1)
		region = (x > 0) ? region : (region + 9);				// 10 regions. Integer values in range [0, 9]


		if (this->TextActor && TextDefaultMsg)
		{
			this->TextActor->SetInput("");
			TextDefaultMsg = false;
			TextHasUnsavedChanges = true;
		}

		if(this->TextActor)
		{
			if (radius > .65)	//External radius buttons
			{
				switch (this->ActiveImage)
				{
				case 0:	//Small, abcdefgh
					switch (region)
					{
					case 8: newChar = 'a'; break;
					case 9: newChar = 'b'; break;
					case 0: newChar = 'c'; break;
					case 1: newChar = 'd'; break;
					case 6: newChar = 'e'; break;
					case 5: newChar = 'f'; break;
					case 4: newChar = 'g'; break;
					case 3: newChar = 'h'; break;
					case 2:	//Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == (MAX_IMG/2-1) || this->ActiveImage == (MAX_IMG-1)) this->ActiveImage -= (MAX_IMG / 2 - 1);
						else this->ActiveImage++;
						break;
					case 7: //Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == 0 || this->ActiveImage == (MAX_IMG / 2)) this->ActiveImage += (MAX_IMG / 2 - 1);
						else this->ActiveImage--;
						break;
					default: vtkErrorMacro(<< "region out of boundaries");
					}
					break;
				case 1:	//Small, ijklmnop
					switch (region)
					{
					case 8: newChar = 'i'; break;
					case 9: newChar = 'j'; break;
					case 0: newChar = 'k'; break;
					case 1: newChar = 'l'; break;
					case 6: newChar = 'm'; break;
					case 5: newChar = 'n'; break;
					case 4: newChar = 'o'; break;
					case 3: newChar = 'p'; break;
					case 2:	//Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == (MAX_IMG / 2 - 1) || this->ActiveImage == (MAX_IMG - 1)) this->ActiveImage -= (MAX_IMG / 2 - 1);
						else this->ActiveImage++;
						break;
					case 7: //Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == 0 || this->ActiveImage == (MAX_IMG / 2)) this->ActiveImage += (MAX_IMG / 2 - 1);
						else this->ActiveImage--;
						break;
					default: vtkErrorMacro(<< "region out of boundaries");
					}
					break;
				case 2:	//Small, qrstuvwx
					switch (region)
					{
					case 8: newChar = 'q'; break;
					case 9: newChar = 'r'; break;
					case 0: newChar = 's'; break;
					case 1: newChar = 't'; break;
					case 6: newChar = 'u'; break;
					case 5: newChar = 'v'; break;
					case 4: newChar = 'w'; break;
					case 3: newChar = 'x'; break;
					case 2:	//Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == (MAX_IMG / 2 - 1) || this->ActiveImage == (MAX_IMG - 1)) this->ActiveImage -= (MAX_IMG / 2 - 1);
						else this->ActiveImage++;
						break;
					case 7: //Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == 0 || this->ActiveImage == (MAX_IMG / 2)) this->ActiveImage += (MAX_IMG / 2 - 1);
						else this->ActiveImage--;
						break;
					default: vtkErrorMacro(<< "region out of boundaries");
					}
					break;
				case 3:	//Small, yz!?.,:;
					switch (region)
					{
					case 8: newChar = 'y'; break;
					case 9: newChar = 'z'; break;
					case 0: newChar = '!'; break;
					case 1: newChar = '?'; break;
					case 6: newChar = '.'; break;
					case 5: newChar = ','; break;
					case 4: newChar = ':'; break;
					case 3: newChar = ';'; break;
					case 2:	//Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == (MAX_IMG / 2 - 1) || this->ActiveImage == (MAX_IMG - 1)) this->ActiveImage -= (MAX_IMG / 2 - 1);
						else this->ActiveImage++;
						break;
					case 7: //Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == 0 || this->ActiveImage == (MAX_IMG / 2)) this->ActiveImage += (MAX_IMG / 2 - 1);
						else this->ActiveImage--;
						break;
					default: vtkErrorMacro(<< "region out of boundaries");
					}
					break;
				case 4:	//Caps, ABCDEFGH
					switch (region)
					{
					case 8: newChar = 'A'; break;
					case 9: newChar = 'B'; break;
					case 0: newChar = 'C'; break;
					case 1: newChar = 'D'; break;
					case 6: newChar = 'E'; break;
					case 5: newChar = 'F'; break;
					case 4: newChar = 'G'; break;
					case 3: newChar = 'H'; break;
					case 2:	//Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == (MAX_IMG / 2 - 1) || this->ActiveImage == (MAX_IMG - 1)) this->ActiveImage -= (MAX_IMG / 2 - 1);
						else this->ActiveImage++;
						break;
					case 7: //Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == 0 || this->ActiveImage == (MAX_IMG / 2)) this->ActiveImage += (MAX_IMG / 2 - 1);
						else this->ActiveImage--;
						break;
					default: vtkErrorMacro(<< "region out of boundaries");
					}
					break;
				case 5:	//Caps, IJKLMNOP
					switch (region)
					{
					case 8: newChar = 'I'; break;
					case 9: newChar = 'J'; break;
					case 0: newChar = 'K'; break;
					case 1: newChar = 'L'; break;
					case 6: newChar = 'M'; break;
					case 5: newChar = 'N'; break;
					case 4: newChar = 'O'; break;
					case 3: newChar = 'P'; break;
					case 2:	//Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == (MAX_IMG / 2 - 1) || this->ActiveImage == (MAX_IMG - 1)) this->ActiveImage -= (MAX_IMG / 2 - 1);
						else this->ActiveImage++;
						break;
					case 7: //Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == 0 || this->ActiveImage == (MAX_IMG / 2)) this->ActiveImage += (MAX_IMG / 2 - 1);
						else this->ActiveImage--;
						break;
					default: vtkErrorMacro(<< "region out of boundaries");
					}
					break;
				case 6:	//Caps, QRSTUVWX
					switch (region)
					{
					case 8: newChar = 'Q'; break;
					case 9: newChar = 'R'; break;
					case 0: newChar = 'S'; break;
					case 1: newChar = 'T'; break;
					case 6: newChar = 'U'; break;
					case 5: newChar = 'V'; break;
					case 4: newChar = 'W'; break;
					case 3: newChar = 'X'; break;
					case 2:	//Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == (MAX_IMG / 2 - 1) || this->ActiveImage == (MAX_IMG - 1)) this->ActiveImage -= (MAX_IMG / 2 - 1);
						else this->ActiveImage++;
						break;
					case 7: //Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == 0 || this->ActiveImage == (MAX_IMG / 2)) this->ActiveImage += (MAX_IMG / 2 - 1);
						else this->ActiveImage--;
						break;
					default: vtkErrorMacro(<< "region out of boundaries");
					}
					break;
				case 7:	//Caps, YZ!?.,:;
					switch (region)
					{
					case 8: newChar = 'Y'; break;
					case 9: newChar = 'Z'; break;
					case 0: newChar = '!'; break;
					case 1: newChar = '?'; break;
					case 6: newChar = '.'; break;
					case 5: newChar = ','; break;
					case 4: newChar = ':'; break;
					case 3: newChar = ';'; break;
					case 2:	//Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == (MAX_IMG / 2 - 1) || this->ActiveImage == (MAX_IMG - 1)) this->ActiveImage -= (MAX_IMG / 2 - 1);
						else this->ActiveImage++;
						break;
					case 7: //Returns 0 - 3 OR 4 - 7
						if (this->ActiveImage == 0 || this->ActiveImage == (MAX_IMG / 2)) this->ActiveImage += (MAX_IMG / 2 - 1);
						else this->ActiveImage--;
						break;
					default: vtkErrorMacro(<< "region out of boundaries");
					}
					break;
				}

				vtkErrorMacro(<< "Letter pressed: " << newChar);	// Just for debugging purposes.

				vtkStdString newText = vtkVariant(this->TextActor->GetInput()).ToString() + vtkVariant(newChar).ToString();
				this->TextActor->SetInput(newText);
				this->TextActor->GetTextProperty()->BoldOn();
				TextHasUnsavedChanges = true;
			}
			else {
				if (x <= 0 && y <= 0)		//Caps
				{
					vtkErrorMacro(<< "\"Caps\" pressed");	// Just for debugging purposes.

					(this->ActiveImage += 4) %= MAX_IMG;
				}
				else if (x < 0 && y>0)		//Delete last
				{
					vtkErrorMacro(<< "\"Remove last digit\" pressed");	// Just for debugging purposes.

					vtkStdString newText = vtkVariant(this->TextActor->GetInput()).ToString();
					if (newText.length() <= 1)
					{
						this->TextActor->SetInput(" ");		//Avoids unexpected errors
						this->TextActor->GetTextProperty()->BoldOff();
						TextHasUnsavedChanges = false;
					}
					else
					{
						newText.pop_back();
						this->TextActor->SetInput(newText);
						this->TextActor->GetTextProperty()->BoldOn();
						TextHasUnsavedChanges = true;
					}
				}
				else if (x > 0 && y < 0)	//Whitespace
				{
					newChar = ' ';

					vtkErrorMacro(<< "\"Whitespace\" pressed");	// Just for debugging purposes.

					vtkStdString newText = vtkVariant(this->TextActor->GetInput()).ToString() + vtkVariant(newChar).ToString();
					this->TextActor->SetInput(newText);
					this->TextActor->GetTextProperty()->BoldOn();
					TextHasUnsavedChanges = true;

				}
				else	//Accept value.
				{
					vtkErrorMacro(<< "\"Validate number\" pressed. Region: " << region);	// Just for debugging purposes.
					
					vtkStdString newText = vtkVariant(this->TextActor->GetInput()).ToString();
					if (newText.compare("") == 0)
					{
						this->TextActor->SetInput(" ");		//Avoids unexpected errors
					}
					this->TextActor->GetTextProperty()->BoldOff();
					TextHasUnsavedChanges = false;
				}
			}
		}
		
		//Has the image changed?
		this->UpdateImage();
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressKeyboard::OnRightButtonUp()
{
	// do nothing except overriding the default OnRightButtonDown behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStylePressKeyboard::OnMiddleButtonDown()
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
			this->TextActor->SetInput("Input data");
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
			this->TextActor->SetInput("Input data");
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
void vtkOpenVRInteractorStylePressKeyboard::OnMiddleButtonUp()
{
	// do nothing except overriding the default OnMiddleButtonUp behavior
}


void vtkOpenVRInteractorStylePressKeyboard::ShowTestActor(bool on)
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
void vtkOpenVRInteractorStylePressKeyboard::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
