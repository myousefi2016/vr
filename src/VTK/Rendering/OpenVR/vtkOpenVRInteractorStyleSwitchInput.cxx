/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkOpenVRInteractorStyleSwitchInput.cxx

  Copyright (c) Ventura Romero Mendo
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStyleSwitchInput.h"

#include "vtkOpenVRRenderWindowInteractor.h"
#include "vtkCallbackCommand.h"
#include "vtkCommand.h"
#include "vtkOpenVRInteractorStyleTapDial.h"
#include "vtkOpenVRInteractorStyleTapKeyboard.h"
#include "vtkOpenVRInteractorStyleTapBool.h"
#include "vtkOpenVRInteractorStyleSwipeDial.h"
#include "vtkOpenVRInteractorStyleFieldSelector.h"
#include "vtkObjectFactory.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVRFieldModifier.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyleSwitchInput);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwitchInput::vtkOpenVRInteractorStyleSwitchInput()
{
  this->TapDial = vtkOpenVRInteractorStyleTapDial::New();
  this->TapKeyboard = vtkOpenVRInteractorStyleTapKeyboard::New();
	this->TapBool = vtkOpenVRInteractorStyleTapBool::New();
  this->SwipeDial = vtkOpenVRInteractorStyleSwipeDial::New();
	this->FieldSelector = vtkOpenVRInteractorStyleFieldSelector::New();
	this->SetISSwitch();

	this->CurrentGesture = Gesture::NONE;
	this->CurrentLayout = Layout::NONE;
  this->CurrentStyle = NULL;
	this->FieldModifier = vtkOpenVRFieldModifier::New();
	CycleOverStyles = false;
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwitchInput::~vtkOpenVRInteractorStyleSwitchInput()
{
	if(this->TapDial != NULL)
	{
		this->TapDial->Reset();
		this->TapDial->Delete();
		this->TapDial = NULL;
	}
	if (this->TapKeyboard != NULL)
	{
		this->TapKeyboard->Reset();
		this->TapKeyboard->Delete();
		this->TapKeyboard = NULL;
	}
	if (this->TapBool != NULL)
	{
		this->TapBool->Reset();
		this->TapBool->Delete();
		this->TapBool = NULL;
	}
	if (this->SwipeDial != NULL)
	{
		this->SwipeDial->Reset();
		this->SwipeDial->Delete();
		this->SwipeDial = NULL;
	}
	if (this->FieldSelector != NULL)
	{
		this->FieldSelector->Reset();
		this->FieldSelector->Delete();
		this->FieldSelector = NULL;
	}
	if (this->FieldModifier != NULL)
	{
		this->FieldModifier->Delete();
		this->FieldModifier = NULL;
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetAutoAdjustCameraClippingRange( int value )
{
  if ( value == this->AutoAdjustCameraClippingRange ) return;

  if ( value < 0 || value > 1 )
  {
    vtkErrorMacro("Value must be between 0 and 1 for" <<
                  " SetAutoAdjustCameraClippingRange");
    return;
  }

  this->AutoAdjustCameraClippingRange = value;
  this->TapDial->SetAutoAdjustCameraClippingRange( value );
  this->TapKeyboard->SetAutoAdjustCameraClippingRange( value );
  this->SwipeDial->SetAutoAdjustCameraClippingRange( value );
  this->TapBool->SetAutoAdjustCameraClippingRange(value);
	this->FieldSelector->SetAutoAdjustCameraClippingRange(value);

  this->Modified();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyleToTapDial()
{
  this->CurrentGesture = Gesture::TAP;
  this->CurrentLayout = Layout::DIAL;
  this->SetCurrentStyle();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyleToTapKeyboard()
{
  this->CurrentGesture = Gesture::TAP;
  this->CurrentLayout = Layout::KEYBOARD;
  this->SetCurrentStyle();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyleToTapBool()
{
	this->CurrentGesture = Gesture::SWIPE;
	this->CurrentLayout = Layout::KEYBOARD;
	this->SetCurrentStyle();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyleToSwipeDial()
{
  this->CurrentGesture = Gesture::SWIPE;
  this->CurrentLayout = Layout::DIAL;
  this->SetCurrentStyle();
}

void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyleToFieldSelector()
{
	this->CurrentGesture = Gesture::NONE;
	this->CurrentLayout = Layout::NONE;
	this->SetCurrentStyle();
}

void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyleTo(Gesture g, Layout l)
{
	this->CurrentGesture = g;
	this->CurrentLayout = l;
	this->SetCurrentStyle();
}

//----------------------------------------------------------------------------
// This will either:
//  - cycle over all the Interactor Styles defined in the class
//  - behave as its base class (grab objects)
void vtkOpenVRInteractorStyleSwitchInput::OnLeftButtonDown()
{
	if (!this->CycleOverStyles)
	{
		Superclass::OnLeftButtonDown();
	}
	else
	{
		// Cycle order, only if CurrentStyle != FieldSelector (proof of concept):
		// (def) TapDial -> TapKeyboard -> TapBool -> SwipeDial -> (def)
		if (this->CurrentGesture == Gesture::TAP && this->CurrentLayout == Layout::DIAL)
		{
			// First, disable all active elements in the current IS
			vtkOpenVRInteractorStyleTapDial::SafeDownCast(this->CurrentStyle)->Reset();
			this->CurrentGesture = Gesture::TAP;
			this->CurrentLayout = Layout::KEYBOARD;
			this->EventCallbackCommand->SetAbortFlag(1);
		}
		else if (this->CurrentGesture == Gesture::TAP && this->CurrentLayout == Layout::KEYBOARD)
		{
			vtkOpenVRInteractorStyleTapKeyboard::SafeDownCast(this->CurrentStyle)->Reset();
			this->CurrentGesture = Gesture::TAP;
			this->CurrentLayout = Layout::BOOL;
			this->EventCallbackCommand->SetAbortFlag(1);
		}
		else if (this->CurrentGesture == Gesture::TAP && this->CurrentLayout == Layout::BOOL)
		{
			vtkOpenVRInteractorStyleTapBool::SafeDownCast(this->CurrentStyle)->Reset();
			this->CurrentGesture = Gesture::SWIPE;
			this->CurrentLayout = Layout::DIAL;
			this->EventCallbackCommand->SetAbortFlag(1);
		}
		else if (this->CurrentGesture == Gesture::SWIPE && this->CurrentLayout == Layout::DIAL)
		{
			vtkOpenVRInteractorStyleSwipeDial::SafeDownCast(this->CurrentStyle)->Reset();
			this->CurrentGesture = Gesture::TAP;
			this->CurrentLayout = Layout::DIAL;
			this->EventCallbackCommand->SetAbortFlag(1);
		}
		// Set the CurrentStyle pointer to the picked style
		this->SetCurrentStyle();
	}
}

void vtkOpenVRInteractorStyleSwitchInput::OnLeftButtonUp()
{
	// Do nothing, just override parent's behaviour.
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyle()
{
  // If CurrentStyle does not match Gesture and Layout,
	// then call SetInteractor(0) to remove the observers.
  // Then set the Currentstyle and call SetInteractor with
  // this->Interactor so the callbacks are set for the
  // CurrentStyle.
	if (this->CurrentGesture == Gesture::NONE &&
					 this->CurrentLayout == Layout::NONE)
	{
		if (this->CurrentStyle != this->FieldSelector)
		{
			if (this->CurrentStyle)
			{
				if (this->CurrentStyle->IsA("vtkOpenVRInteractorStyleInputData"))
				{
					vtkOpenVRInteractorStyleInputData::SafeDownCast(this->CurrentStyle)->Reset();
				}
				this->CurrentStyle->SetInteractor(0);
			}
			this->CurrentStyle = this->FieldSelector;
		}
	}
  else if (this->CurrentGesture == Gesture::TAP &&
      this->CurrentLayout == Layout::DIAL)
  {
    if(this->CurrentStyle != this->TapDial)
    {
      if(this->CurrentStyle)
      {
				if (this->CurrentStyle->IsA("vtkOpenVRInteractorStyleInputData"))
				{
					vtkOpenVRInteractorStyleInputData::SafeDownCast(this->CurrentStyle)->Reset();
				}
        this->CurrentStyle->SetInteractor(0);
      }
      this->CurrentStyle = this->TapDial;
    }
  }
  else if (this->CurrentGesture == Gesture::TAP &&
           this->CurrentLayout == Layout::KEYBOARD)
  {
    if(this->CurrentStyle != this->TapKeyboard)
    {
      if(this->CurrentStyle)
      {
				if (this->CurrentStyle->IsA("vtkOpenVRInteractorStyleInputData"))
				{
					vtkOpenVRInteractorStyleInputData::SafeDownCast(this->CurrentStyle)->Reset();
				}
        this->CurrentStyle->SetInteractor(0);
      }
      this->CurrentStyle = this->TapKeyboard;
    }
  }
  else if (this->CurrentGesture == Gesture::TAP &&
           this->CurrentLayout == Layout::BOOL)
  {
    if(this->CurrentStyle != this->TapBool)
    {
      if(this->CurrentStyle)
      {
				if (this->CurrentStyle->IsA("vtkOpenVRInteractorStyleInputData"))
				{
					vtkOpenVRInteractorStyleInputData::SafeDownCast(this->CurrentStyle)->Reset();
				}
        this->CurrentStyle->SetInteractor(0);
      }
      this->CurrentStyle = this->TapBool;
    }
  }
  else if (this->CurrentGesture == Gesture::SWIPE &&
           this->CurrentLayout == Layout::DIAL)
  {
      if(this->CurrentStyle != this->SwipeDial)
      {
        if(this->CurrentStyle)
        {
					if (this->CurrentStyle->IsA("vtkOpenVRInteractorStyleInputData"))
					{
						vtkOpenVRInteractorStyleInputData::SafeDownCast(this->CurrentStyle)->Reset();
					}
          this->CurrentStyle->SetInteractor(0);
        }
        this->CurrentStyle = this->SwipeDial;
      }
  }
  if (this->CurrentStyle)
  {
    this->CurrentStyle->SetInteractor(this->Interactor);
    this->CurrentStyle->SetTDxStyle(this->TDxStyle);
  }
}

void vtkOpenVRInteractorStyleSwitchInput::SetISSwitch()
{
	this->TapDial->SetISSwitch(this);
	this->TapKeyboard->SetISSwitch(this);
	this->TapBool->SetISSwitch(this);
	this->SwipeDial->SetISSwitch(this);
	this->FieldSelector->SetISSwitch(this);
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetInteractor(vtkRenderWindowInteractor *iren)
{
  if(iren == this->Interactor) return;

  // If we already have an Interactor then stop observing it
  if(this->Interactor)
    this->Interactor->RemoveObserver(this->EventCallbackCommand);

  this->Interactor = iren;
  // Add observers for each of the events handled in ProcessEvents
  if(iren)
  {
		iren->AddObserver(vtkCommand::LeftButtonPressEvent,
											this->EventCallbackCommand,
											this->Priority);

		iren->AddObserver(vtkCommand::LeftButtonReleaseEvent,
											this->EventCallbackCommand,
											this->Priority);

    iren->AddObserver(vtkCommand::DeleteEvent,
                      this->EventCallbackCommand,
                      this->Priority);
  }
  this->SetCurrentStyle();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetDefaultRenderer(vtkRenderer* renderer)
{
  this->vtkInteractorStyle::SetDefaultRenderer(renderer);
  this->TapDial->SetDefaultRenderer(renderer);
  this->TapKeyboard->SetDefaultRenderer(renderer);
	this->TapBool->SetDefaultRenderer(renderer);
  this->SwipeDial->SetDefaultRenderer(renderer);
	this->FieldSelector->SetDefaultRenderer(renderer);
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentRenderer(vtkRenderer* renderer)
{
  this->vtkInteractorStyle::SetCurrentRenderer(renderer);
  this->TapDial->SetCurrentRenderer(renderer);
  this->TapKeyboard->SetCurrentRenderer(renderer);
	this->TapBool->SetCurrentRenderer(renderer);
  this->SwipeDial->SetCurrentRenderer(renderer);
	this->FieldSelector->SetCurrentRenderer(renderer);
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os, indent);
	os << indent << "CurrentStyle " << this->CurrentStyle << "\n";
	if (this->CurrentStyle)
	{
		vtkIndent next_indent = indent.GetNextIndent();
		os << next_indent << this->CurrentStyle->GetClassName() << "\n";
		this->CurrentStyle->PrintSelf(os, indent.GetNextIndent());
	}
}