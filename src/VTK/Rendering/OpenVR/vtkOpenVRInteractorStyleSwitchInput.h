/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkOpenVRInteractorStyleSwitchInput.h

  Copyright (c) Ventura Romero Mendo
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRInteractorStyleSwitchInput
 * @brief   class to swap between interactory styles in OpenVR
 *
 * The class vtkOpenVRInteractorStyleSwitchInput allows handles interactively
 * switching between OpenVR interactor styles used to input data -- 
 * TO END DESCRIPTION, USE TEMPLATE FROM vtkInteractorStyleSwitch
 * @sa
 * vtkOpenVRInteractorStylePressDial vtkOpenVRInteractorStylePressKeypad
 * vtkOpenVRInteractorStyleSwipeDial vtkOpenVRInteractorStyleSwipeKeypad
*/

#ifndef vtkOpenVRInteractorStyleSwitchInput_h
#define vtkOpenVRInteractorStyleSwitchInput_h

#include "vtkInteractionStyleModule.h" // For export macro
#include "vtkInteractorStyleSwitchBase.h"

#define VTKIS_DIAL  0
#define VTKIS_KEYPAD 1

#define VTKIS_PRESS    0
#define VTKIS_SWIPE     1

class vtkOpenVRInteractorStylePressDial;
class vtkOpenVRInteractorStylePressKeypad;
class vtkOpenVRInteractorStyleSwipeDial;
class vtkOpenVRInteractorStyleSwipeKeypad;
class vtkInteractorStyleMultiTouchCamera;

class VTKINTERACTIONSTYLE_EXPORT vtkOpenVRInteractorStyleSwitchInput
  : public vtkInteractorStyleSwitchBase
{
public:
  static vtkOpenVRInteractorStyleSwitchInput *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleSwitchInput, vtkInteractorStyleSwitchBase);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  /**
   * The sub styles need the interactor too.
   */
  void SetInteractor(vtkRenderWindowInteractor *iren) VTK_OVERRIDE;

  /**
   * We must override this method in order to pass the setting down to
   * the underlying styles
   */
  void SetAutoAdjustCameraClippingRange( int value ) VTK_OVERRIDE;

  //@{
  /**
   * Set/Get current style
   */
  vtkGetObjectMacro(CurrentStyle, vtkInteractorStyle);
  void SetCurrentStyleToPressDial();
  void SetCurrentStyleToPressKeypad();
  void SetCurrentStyleToSwipeDial();	// FW/RW
  void SetCurrentStyleToSwipeKeypad();	// Draw numbers, letters.
  void SetCurrentStyleToMultiTouchCamera();
  //@}

  /**
   * Only care about the char event, which is used to switch between
   * different styles.
   */
  void OnChar() VTK_OVERRIDE;

  //@{
  /**
   * Overridden from vtkInteractorObserver because the interactor styles
   * used by this class must also be updated.
   */
  void SetDefaultRenderer(vtkRenderer*) VTK_OVERRIDE;
  void SetCurrentRenderer(vtkRenderer*) VTK_OVERRIDE;
  //@}

protected:
  vtkOpenVRInteractorStyleSwitchInput();
  ~vtkOpenVRInteractorStyleSwitchInput() VTK_OVERRIDE;

  void SetCurrentStyle();

  vtkOpenVRInteractorStylePressDial *PressDial;
  vtkOpenVRInteractorStylePressKeypad *PressKeypad;
  vtkOpenVRInteractorStyleSwipeDial *SwipeDial;
  vtkOpenVRInteractorStyleSwipeKeypad *SwipeKeypad;
  vtkInteractorStyleMultiTouchCamera *MultiTouchCamera;
  vtkInteractorStyle* CurrentStyle;

  int PressOrSwipe;
  int DialOrKeypad;
  bool MultiTouch;

private:
  vtkOpenVRInteractorStyleSwitchInput(const vtkOpenVRInteractorStyleSwitchInput&) VTK_DELETE_FUNCTION;
  void operator=(const vtkOpenVRInteractorStyleSwitchInput&) VTK_DELETE_FUNCTION;
};

#endif
