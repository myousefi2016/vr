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
#include "vtkInteractorStyleMultiTouchCamera.h"
#include "vtkObjectFactory.h"
#include "vtkRenderWindowInteractor.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyleSwitchInput);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwitchInput::vtkOpenVRInteractorStyleSwitchInput()
{
  this->TapDial = vtkOpenVRInteractorStyleTapDial::New();
  this->TapKeyboard = vtkOpenVRInteractorStyleTapKeyboard::New();
	this->TapBool = vtkOpenVRInteractorStyleTapBool::New();
  this->SwipeDial = vtkOpenVRInteractorStyleSwipeDial::New();
  this->MultiTouchCamera = vtkInteractorStyleMultiTouchCamera::New();

  this->Gesture = VTKIS_TAP;
  this->Layout = VTKIS_DIAL;
  this->MultiTouch = false;
  this->CurrentStyle = 0;
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwitchInput::~vtkOpenVRInteractorStyleSwitchInput()
{
  this->TapDial->Delete();
  this->TapDial = NULL;

  this->TapKeyboard->Delete();
  this->TapKeyboard = NULL;

	this->TapBool->Delete();
	this->TapBool = NULL;

  this->SwipeDial->Delete();
  this->SwipeDial = NULL;

  this->MultiTouchCamera->Delete();
  this->MultiTouchCamera = NULL;
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetAutoAdjustCameraClippingRange( int value )
{
  if ( value == this->AutoAdjustCameraClippingRange )
  {
    return;
  }

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
  this->MultiTouchCamera->SetAutoAdjustCameraClippingRange( value );

  this->Modified();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyleToTapDial()
{
  this->Gesture = VTKIS_TAP;
  this->Layout = VTKIS_DIAL;
  this->MultiTouch = false;
  this->SetCurrentStyle();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyleToTapKeyboard()
{
  this->Gesture = VTKIS_TAP;
  this->Layout = VTKIS_KEYBOARD;
  this->MultiTouch = false;
  this->SetCurrentStyle();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyleToTapBool()
{
	this->Gesture = VTKIS_SWIPE;
	this->Layout = VTKIS_KEYBOARD;
	this->MultiTouch = false;
	this->SetCurrentStyle();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyleToSwipeDial()
{
  this->Gesture = VTKIS_SWIPE;
  this->Layout = VTKIS_DIAL;
  this->MultiTouch = false;
  this->SetCurrentStyle();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyleToMultiTouchCamera()
{
  this->MultiTouch = true;
  this->SetCurrentStyle();
}

//----------------------------------------------------------------------------
// This will cycle over all the Interactor Styles defined in the class 
// (except Multitouch).
void vtkOpenVRInteractorStyleSwitchInput::OnLeftButtonDown()
{
	// Cycle order:
	// (def) TapDial -> TapKeyboard -> TapBool -> SwipeDial -> (def)
	if (this->Gesture == VTKIS_TAP && this->Layout == VTKIS_DIAL)
	{
		//TODO First, disable all active elements in the current IS
		vtkOpenVRInteractorStyleTapDial::SafeDownCast(this->CurrentStyle)->Reset();

		this->Gesture = VTKIS_TAP;
		this->Layout = VTKIS_KEYBOARD;
		this->MultiTouch = false;
		this->EventCallbackCommand->SetAbortFlag(1);
	}
	else if (this->Gesture == VTKIS_TAP && this->Layout == VTKIS_KEYBOARD)
	{
		this->Gesture = VTKIS_TAP;
		this->Layout = VTKIS_BOOL;
		this->MultiTouch = false;
		this->EventCallbackCommand->SetAbortFlag(1);
	}
	else if (this->Gesture == VTKIS_TAP && this->Layout == VTKIS_BOOL)
	{
		this->Gesture = VTKIS_SWIPE;
		this->Layout = VTKIS_DIAL;
		this->MultiTouch = false;
		this->EventCallbackCommand->SetAbortFlag(1);
	}
	else if (this->Gesture == VTKIS_SWIPE && this->Layout == VTKIS_DIAL)
	{
		this->Gesture = VTKIS_TAP;
		this->Layout = VTKIS_DIAL;
		this->MultiTouch = false;
		this->EventCallbackCommand->SetAbortFlag(1);
	}
	// Set the CurrentStyle pointer to the picked style
	this->SetCurrentStyle();
}

void vtkOpenVRInteractorStyleSwitchInput::OnLeftButtonUp()
{
	//Do nothing, just override parent's behaviour.
}

//----------------------------------------------------------------------------
// this will do nothing if the CurrentStyle matchs
// Gesture and Layout
// It should! If the this->Interactor was changed (using SetInteractor()),
// and the currentstyle should not change.
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyle()
{
  // if the currentstyle does not match Gesture
  // and Layout ivars, then call SetInteractor(0)
  // on the Currentstyle to remove all of the observers.
  // Then set the Currentstyle and call SetInteractor with
  // this->Interactor so the callbacks are set for the
  // currentstyle.
  if (this->MultiTouch)
  {
    if(this->CurrentStyle != this->MultiTouchCamera)
    {
      if(this->CurrentStyle)
      {
        this->CurrentStyle->SetInteractor(0);
      }
      this->CurrentStyle = this->MultiTouchCamera;
    }
  }
  else if (this->Gesture == VTKIS_TAP &&
      this->Layout == VTKIS_DIAL)
  {
    if(this->CurrentStyle != this->TapDial)
    {
      if(this->CurrentStyle)
      {
        this->CurrentStyle->SetInteractor(0);
      }
      this->CurrentStyle = this->TapDial;
    }
  }
  else if (this->Gesture == VTKIS_TAP &&
           this->Layout == VTKIS_KEYBOARD)
  {
    if(this->CurrentStyle != this->TapKeyboard)
    {
      if(this->CurrentStyle)
      {
        this->CurrentStyle->SetInteractor(0);
      }
      this->CurrentStyle = this->TapKeyboard;
    }
  }
  else if (this->Gesture == VTKIS_TAP &&
           this->Layout == VTKIS_BOOL)
  {
    if(this->CurrentStyle != this->TapBool)
    {
      if(this->CurrentStyle)
      {
        this->CurrentStyle->SetInteractor(0);
      }
      this->CurrentStyle = this->TapBool;
    }
  }
  else if (this->Gesture == VTKIS_SWIPE &&
           this->Layout == VTKIS_DIAL)
  {
      if(this->CurrentStyle != this->SwipeDial)
      {
        if(this->CurrentStyle)
        {
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

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetInteractor(vtkRenderWindowInteractor *iren)
{
  if(iren == this->Interactor)
  {
    return;
  }
  // if we already have an Interactor then stop observing it
  if(this->Interactor)
  {
    this->Interactor->RemoveObserver(this->EventCallbackCommand);
  }
  this->Interactor = iren;
  // add observers for each of the events handled in ProcessEvents
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
void vtkOpenVRInteractorStyleSwitchInput::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
  os << indent << "CurrentStyle " << this->CurrentStyle << "\n";
  if (this->CurrentStyle)
  {
    vtkIndent next_indent = indent.GetNextIndent();
    os << next_indent << this->CurrentStyle->GetClassName() << "\n";
    this->CurrentStyle->PrintSelf(os, indent.GetNextIndent());
  }
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetDefaultRenderer(vtkRenderer* renderer)
{
  this->vtkInteractorStyle::SetDefaultRenderer(renderer);
  this->TapDial->SetDefaultRenderer(renderer);
  this->TapKeyboard->SetDefaultRenderer(renderer);
	this->TapBool->SetDefaultRenderer(renderer);
  this->SwipeDial->SetDefaultRenderer(renderer);
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentRenderer(vtkRenderer* renderer)
{
  this->vtkInteractorStyle::SetCurrentRenderer(renderer);
  this->TapDial->SetCurrentRenderer(renderer);
  this->TapKeyboard->SetCurrentRenderer(renderer);
	this->TapBool->SetCurrentRenderer(renderer);
  this->SwipeDial->SetCurrentRenderer(renderer);
}
