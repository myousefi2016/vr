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

#include "vtkCallbackCommand.h"
#include "vtkCommand.h"
#include "vtkOpenVRInteractorStylePressDial.h"
#include "vtkOpenVRInteractorStylePressKeypad.h"
#include "vtkOpenVRInteractorStyleSwipeDial.h"
#include "vtkOpenVRInteractorStyleSwipeKeypad.h"
#include "vtkInteractorStyleMultiTouchCamera.h"
#include "vtkObjectFactory.h"
#include "vtkRenderWindowInteractor.h"

vtkStandardNewMacro(vtkOpenVRInteractorStyleSwitchInput);

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwitchInput::vtkOpenVRInteractorStyleSwitchInput()
{
  this->PressDial = vtkOpenVRInteractorStylePressDial::New();
  this->PressKeypad = vtkOpenVRInteractorStylePressKeypad::New();
  this->SwipeDial = vtkOpenVRInteractorStyleSwipeDial::New();
  this->SwipeKeypad = vtkOpenVRInteractorStyleSwipeKeypad::New();
  this->MultiTouchCamera = vtkInteractorStyleMultiTouchCamera::New();

  this->PressOrSwipe = VTKIS_PRESS;
  this->DialOrKeypad = VTKIS_DIAL;
  this->MultiTouch = false;
  this->CurrentStyle = 0;
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwitchInput::~vtkOpenVRInteractorStyleSwitchInput()
{
  this->PressDial->Delete();
  this->PressDial = NULL;

  this->PressKeypad->Delete();
  this->PressKeypad = NULL;

  this->SwipeDial->Delete();
  this->SwipeDial = NULL;

  this->SwipeKeypad->Delete();
  this->SwipeKeypad = NULL;

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
  this->PressDial->SetAutoAdjustCameraClippingRange( value );
  this->PressKeypad->SetAutoAdjustCameraClippingRange( value );
  this->SwipeDial->SetAutoAdjustCameraClippingRange( value );
  this->SwipeKeypad->SetAutoAdjustCameraClippingRange(value);
  this->MultiTouchCamera->SetAutoAdjustCameraClippingRange( value );

  this->Modified();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyleToPressDial()
{
  this->PressOrSwipe = VTKIS_PRESS;
  this->DialOrKeypad = VTKIS_DIAL;
  this->MultiTouch = false;
  this->SetCurrentStyle();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyleToPressKeypad()
{
  this->PressOrSwipe = VTKIS_PRESS;
  this->DialOrKeypad = VTKIS_KEYPAD;
  this->MultiTouch = false;
  this->SetCurrentStyle();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyleToSwipeDial()
{
  this->PressOrSwipe = VTKIS_SWIPE;
  this->DialOrKeypad = VTKIS_DIAL;
  this->MultiTouch = false;
  this->SetCurrentStyle();
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyleToSwipeKeypad()
{
  this->PressOrSwipe = VTKIS_SWIPE;
  this->DialOrKeypad = VTKIS_KEYPAD;
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
void vtkOpenVRInteractorStyleSwitchInput::OnChar()
{
  switch (this->Interactor->GetKeyCode())
  {
    case 'p':
    case 'P':
	  this->PressOrSwipe = VTKIS_PRESS;
      this->MultiTouch = false;
      this->EventCallbackCommand->SetAbortFlag(1);
      break;
    case 's':
    case 'S':
      this->PressOrSwipe = VTKIS_SWIPE;
      this->MultiTouch = false;
      this->EventCallbackCommand->SetAbortFlag(1);
      break;
    case 'd':
    case 'D':
	  this->DialOrKeypad = VTKIS_DIAL;
      this->MultiTouch = false;
      this->EventCallbackCommand->SetAbortFlag(1);
      break;
    case 'k':
    case 'K':
	  this->DialOrKeypad = VTKIS_KEYPAD;
      this->MultiTouch = false;
      this->EventCallbackCommand->SetAbortFlag(1);
      break;
    case 'm':
    case 'M':
      this->MultiTouch = true;
      this->EventCallbackCommand->SetAbortFlag(1);
      break;
  }
  // Set the CurrentStyle pointer to the picked style
  this->SetCurrentStyle();
}

//----------------------------------------------------------------------------
// this will do nothing if the CurrentStyle matchs
// JoystickOrTrackball and CameraOrActor
// It should! If the this->Interactor was changed (using SetInteractor()),
// and the currentstyle should not change.
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentStyle()
{
  // if the currentstyle does not match JoystickOrTrackball
  // and CameraOrActor ivars, then call SetInteractor(0)
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
  else if (this->PressOrSwipe == VTKIS_PRESS &&
      this->DialOrKeypad == VTKIS_DIAL)
  {
    if(this->CurrentStyle != this->PressDial)
    {
      if(this->CurrentStyle)
      {
        this->CurrentStyle->SetInteractor(0);
      }
      this->CurrentStyle = this->PressDial;
    }
  }
  else if (this->PressOrSwipe == VTKIS_PRESS &&
           this->DialOrKeypad == VTKIS_KEYPAD)
  {
    if(this->CurrentStyle != this->PressKeypad)
    {
      if(this->CurrentStyle)
      {
        this->CurrentStyle->SetInteractor(0);
      }
      this->CurrentStyle = this->PressKeypad;
    }
  }
  else if (this->PressOrSwipe == VTKIS_SWIPE &&
           this->DialOrKeypad == VTKIS_DIAL)
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
  else if (this->PressOrSwipe == VTKIS_SWIPE &&
           this->DialOrKeypad == VTKIS_KEYPAD)
  {
      if(this->CurrentStyle != this->SwipeKeypad)
      {
        if(this->CurrentStyle)
        {
          this->CurrentStyle->SetInteractor(0);
        }
        this->CurrentStyle = this->SwipeKeypad;
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
    iren->AddObserver(vtkCommand::CharEvent,
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
  this->PressDial->SetDefaultRenderer(renderer);
  this->PressKeypad->SetDefaultRenderer(renderer);
  this->SwipeDial->SetDefaultRenderer(renderer);
  this->SwipeKeypad->SetDefaultRenderer(renderer);
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwitchInput::SetCurrentRenderer(vtkRenderer* renderer)
{
  this->vtkInteractorStyle::SetCurrentRenderer(renderer);
  this->PressDial->SetCurrentRenderer(renderer);
  this->PressKeypad->SetCurrentRenderer(renderer);
  this->SwipeDial->SetCurrentRenderer(renderer);
  this->SwipeKeypad->SetCurrentRenderer(renderer);
}
