/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleFieldSelector.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStyleFieldSelector.h"

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
#include "vtkPolyDataMapper.h"

#include "vtkOpenVRPropertyModifier.h"


#include "vtkOpenVRTextFeedback.h"
#include "vtkOpenVRTouchPadImage.h"
#include "vtkOpenVRTouchPadPointer.h"

#include "vtkOpenVRInteractorStyleSwitchInput.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyleFieldSelector);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleFieldSelector::vtkOpenVRInteractorStyleFieldSelector()
{
	//Text3D to modify Props' attributes.
	this->TextFeedback = vtkOpenVRTextFeedback::New();
	this->TextFeedback->SetTextDefaultMsg(
		"Press Grip:\n -Inside Object: Iterate to next Object.\n -Outside Object: Toggle Object ON/OFF.\nPress Touchpad: Select Field to modify.");

	//Properties' Modifier
//	this->FieldModifier = vtkOpenVRPropertyModifier::New();	//Starts with a Sphere
	this->ModifyProp = true;

	//Images:
	this->TouchPadImage = vtkOpenVRTouchPadImage::New();
	this->TouchPadImage->LoadImages(3, "..\\..\\..\\VTK\\Rendering\\OpenVR\\FieldSelector_Image");	//0: Sphere; 1: Cylinder; 2: Cube;
	this->TouchPadImage->Init();


	//TouchPad Pointer
	this->TouchPadPointer = vtkOpenVRTouchPadPointer::New();

}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleFieldSelector::~vtkOpenVRInteractorStyleFieldSelector()
{
	//Remove Text3D
	if (this->TextFeedback)
	{
		this->TextFeedback->Delete();
	}

	//Remove FieldModifier
	//if(this->FieldModifier)
	//{
	//	this->FieldModifier->Delete();
	//}

	//Remove images
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
void vtkOpenVRInteractorStyleFieldSelector::OnRightButtonDown()
{


}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::OnRightButtonUp()
{
	// do nothing except overriding the default OnRightButtonDown behavior

	if (this->TextFeedback->GetTextIsVisible() && this->TextFeedback->GetTextActor())
	{
		//Downcast to a 3D Interactor.
		vtkRenderWindowInteractor3D *rwi =
			static_cast<vtkRenderWindowInteractor3D *>(this->Interactor);

		float x = rwi->GetTouchPadPosition()[0];	// Values between -1 and 1.
		float y = rwi->GetTouchPadPosition()[1];


		//Find out the Field selected by the user:
		switch (this->ISSwitch->GetFieldModifier()->GetCurrentSourceType())
		{
		case vtkSourceType::Sphere:
			if (x <= 0 && y >= 0)			//Upper left quadrant (+ boundaries).
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::ThetaResolution);
			else if (x > 0 && y > 0)	//Upper right quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::Radius);
			else if (x < 0 && y < 0)	//Lower left quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::PhiResolution);
			else											//Lower right quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::None);
			break;
		case vtkSourceType::Cylinder:
			if (x <= 0 && y >= 0)			//Upper left quadrant (+ boundaries).
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::Height);
			else if (x > 0 && y > 0)	//Upper right quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::Radius);
			else if (x < 0 && y < 0)	//Lower left quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::None);
			else											//Lower right quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::None);
			break;
		case vtkSourceType::Cube:
			if (x <= 0 && y >= 0)			//Upper left quadrant (+ boundaries).
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::XLength);
			else if (x > 0 && y > 0)	//Upper right quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::YLength);
			else if (x < 0 && y < 0)	//Lower left quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::ZLength);
			else											//Lower right quadrant.
				this->ISSwitch->GetFieldModifier()->SetSelectedField(vtkField::None);
			break;
		}



		/*
		// Specify also if the field owner is an algorithm (sources)
		// or a data object (props / actors)
		switch (this->ISSwitch->GetFieldModifier()->GetSelectedField())
		{
			//Algorithms (sources):
		case vtkField::Radius:
		case vtkField::ThetaResolution:
		case vtkField::PhiResolution:
		case vtkField::Height:
		case vtkField::XLength:
		case vtkField::YLength:
		case vtkField::ZLength:
			this->ISSwitch->GetFieldModifier()->Set(vtkField::None);
			break;
			//TapBool (booleans):
		case vtkField::Visibility:
			this->ISSwitch->SetCurrentStyleToTapBool();
			break;
			//TapKeyboard (letters):
			//Nothing, by now...
			//SwipeDial (numbers):
		case vtkField::Scale:
		case vtkField::Opacity:
			this->ISSwitch->SetCurrentStyleToSwipeDial();
			break;
			//None:
		case vtkField::None:
			break;
		default:
			vtkErrorMacro(<< "Unrecognised vtkField. No IS Selected to modify it.");
			break;
		}*/



		//Decide which IS class will handle the value change (according to the field selected):
		switch (this->ISSwitch->GetFieldModifier()->GetSelectedField())
		{
			//TapDial (numbers):
		case vtkField::ThetaResolution:
		case vtkField::PhiResolution:
		case vtkField::XLength:
		case vtkField::YLength:
		case vtkField::ZLength:
			this->ISSwitch->SetCurrentStyleToTapDial();
			break;
			//TapBool (booleans):
		case vtkField::Visibility:
			this->ISSwitch->SetCurrentStyleToTapBool();
			break;
			//TapKeyboard (letters):
			//Nothing, by now...
			//SwipeDial (numbers):
		case vtkField::Scale:
		case vtkField::Opacity:
		case vtkField::Radius:
		case vtkField::Height:
			this->ISSwitch->SetCurrentStyleToSwipeDial();
			break;
			//None:
		case vtkField::None:
			break;
		default:
			vtkErrorMacro(<< "Unrecognised vtkField. No IS Selected to modify it.");
			break;
		}


		/*
		float radius = sqrt(x*x + y*y);
		char newChar = '\0';

		int region = int(5. * atan2(x, y) / vtkMath::Pi());		// Clockwise values, starting in (x,y) = (0,1)
		region = (x > 0) ? region : (region + 9);				// 10 regions. Integer values in range [0, 9]


		if (this->TextFeedback->GetDefaultMsgOn())
		{
		this->TextFeedback->GetTextActor()->SetInput("");
		this->TextFeedback->SetDefaultMsgOn(false);
		this->TextFeedback->SetHasUnsavedChanges(true);
		}


		if (radius > .65)	//External radius buttons
		{
		switch (this->TouchPadImage->GetNextImage())
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
		case 2:	this->IncNextImage(); break;
		case 7: this->DecNextImage(); break;
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
		case 2:	this->IncNextImage(); break;
		case 7: this->DecNextImage(); break;
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
		case 2:	this->IncNextImage(); break;
		case 7: this->DecNextImage(); break;
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
		case 2:	this->IncNextImage(); break;
		case 7: this->DecNextImage(); break;
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
		case 2:	this->IncNextImage(); break;
		case 7: this->DecNextImage(); break;
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
		case 2:	this->IncNextImage(); break;
		case 7: this->DecNextImage(); break;
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
		case 2:	this->IncNextImage(); break;
		case 7: this->DecNextImage(); break;
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
		case 2:	this->IncNextImage(); break;
		case 7: this->DecNextImage(); break;
		default:
		vtkErrorMacro(<< "region out of boundaries");
		}
		break;
		default:
		vtkErrorMacro(<< "NextImage out of boundaries");
		}
		vtkStdString newText = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToString();
		if (newText.compare("") == 0 && newChar == '\0')
		{
		this->TextFeedback->GetTextActor()->SetInput(" ");		//Avoids unexpected errors
		}
		if (newChar != '\0')
		{
		newText += vtkVariant(newChar).ToString();
		this->TextFeedback->GetTextActor()->SetInput(newText);
		this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
		this->TextFeedback->SetHasUnsavedChanges(true);
		}
		}
		else {
		if (x <= 0 && y <= 0)		//Caps
		{
		vtkStdString newText = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToString();
		if (newText.compare("") == 0)
		{
		this->TextFeedback->GetTextActor()->SetInput(" ");		//Avoids unexpected errors
		this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOff();
		this->TextFeedback->SetHasUnsavedChanges(false);
		}
		this->SwitchCaps();
		}
		else if (x < 0 && y>0)		//Delete last
		{
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
		else if (x > 0 && y < 0)	//Whitespace
		{
		newChar = ' ';
		vtkStdString newText = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToString() + vtkVariant(newChar).ToString();
		this->TextFeedback->GetTextActor()->SetInput(newText);
		this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOn();
		this->TextFeedback->SetHasUnsavedChanges(true);

		}
		else	//Accept value.
		{				vtkStdString newText = vtkVariant(this->TextFeedback->GetTextActor()->GetInput()).ToString();
		if (newText.compare("") == 0)
		{
		this->TextFeedback->GetTextActor()->SetInput(" ");		//Avoids unexpected errors
		}
		this->TextFeedback->GetTextActor()->GetTextProperty()->BoldOff();
		this->TextFeedback->SetHasUnsavedChanges(false);
		}
		}

		//Has the image changed?
		this->TouchPadImage->UpdateImage();
		*/
	}

}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::OnMiddleButtonDown()
{
	//Get current renderer (if is not got already)
	if (this->Interactor)
	{
		int pointer = this->Interactor->GetPointerIndex();
		this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
														this->Interactor->GetEventPositions(pointer)[1]);

		vtkRenderWindowInteractor3D *vriren = vtkRenderWindowInteractor3D::SafeDownCast(this->Interactor);
		double *wpos = vriren->GetWorldEventPosition(vriren->GetPointerIndex());
		this->FindPickedActor(wpos[0], wpos[1], wpos[2]);
	}


	//Click Inside. If I have the controller inside the object, iterate to next object.
	if (this->InteractionProp != NULL && this->InteractionProp == this->ISSwitch->GetFieldModifier()->GetTestActor())
	{
		this->ISSwitch->GetFieldModifier()->IterateSourceType();
		this->ChangeImage();
		return;
	}


	bool TextEmpty = false;
	if (this->TextFeedback->GetTextActor())
		TextEmpty = !bool(vtkStdString(" ").compare(this->TextFeedback->GetTextActor()->GetInput()));

	//Second Click. Already created and changes saved: can be hidden.
	if (this->TextFeedback->GetTextActor() && this->TextFeedback->GetTextRenderer() != NULL
			&& (!this->TextFeedback->GetHasUnsavedChanges() || TextEmpty))
	{
		this->TextFeedback->Reset();
		//Test:
		if (this->ModifyProp)
		{
			this->ISSwitch->GetFieldModifier()->HideTest();
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
			if (this->ModifyProp)
			{
				this->ISSwitch->GetFieldModifier()->ShowTest(vtkOpenVRRenderWindowInteractor::SafeDownCast(this->Interactor));
			}
		}
	}

	//Place in scene
	vtkOpenVRRenderer *ren = vtkOpenVRRenderer::SafeDownCast(this->CurrentRenderer);
	vtkOpenVRCamera *camera = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());
	this->TextFeedback->PlaceInScene(camera);

	//Render Scene
	if (this->Interactor)
	{
		this->Interactor->Render();
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::OnMiddleButtonUp()
{
	// do nothing except overriding the default OnMiddleButtonUp behavior
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::SwitchCaps()
{
	int currentImg = this->TouchPadImage->GetNextImage();
	this->TouchPadImage->SetNextImage( (currentImg += 4) %= this->TouchPadImage->GetMaxNumImg());
}

void vtkOpenVRInteractorStyleFieldSelector::ChangeImage()
{
	switch (this->ISSwitch->GetFieldModifier()->GetCurrentSourceType())
	{
	case vtkSourceType::Sphere:
		this->TouchPadImage->SetNextImage(0); break;
	case vtkSourceType::Cylinder:
		this->TouchPadImage->SetNextImage(1); break;
	case vtkSourceType::Cube:
		this->TouchPadImage->SetNextImage(2); break;
	default:
		vtkErrorMacro(<< "SourceType not Handled. No image for that sourceType."); break;
	}
	this->TouchPadImage->UpdateImage();

}

/*
vtkField vtkOpenVRInteractorStyleFieldSelector::GetSelectedField()
{
	return SelectedField;
}
*/


/*
void vtkOpenVRInteractorStyleFieldSelector::Reset()
{
	Superclass::Reset();

	if (this->FieldModifier)
	{
		this->FieldModifier->HideTest();
	}
}*/

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::IncNextImage()
{
	int nextImg = this->TouchPadImage->GetNextImage();
	if ((nextImg == (MAX_IMG / 2 - 1)) || (nextImg == (MAX_IMG - 1)))
	{
		nextImg -= (MAX_IMG / 2 - 1);
	}
	else
	{
		++nextImg;
	}
	this->TouchPadImage->SetNextImage(nextImg);
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::DecNextImage()
{
	int nextImg = this->TouchPadImage->GetNextImage();
	if (nextImg == 0 || nextImg == (MAX_IMG / 2))
	{
		nextImg += (MAX_IMG / 2 - 1);
	}
	else
	{
		--nextImg;
	}
	this->TouchPadImage->SetNextImage(nextImg);
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleFieldSelector::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
