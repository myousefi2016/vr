/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStylePressKeypad.h

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRInteractorStyleSwipeKeypad
 * @brief   extended from vtkOpenVRInteractorStyle to override command methods on Touchpad.
 *          Allows the user to write numbers and letters on the Touchpad.
 *          TODO THE WHOLE CLASS INTERACTIONS
*/

#ifndef vtkOpenVRInteractorStyleSwipeKeypad_h
#define vtkOpenVRInteractorStyleSwipeKeypad_h

#include "vtkRenderingOpenVRModule.h" // For export macro

#include "vtkOpenVRInteractorStyle.h"

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleSwipeKeypad : public vtkOpenVRInteractorStyle
{
public:
  static vtkOpenVRInteractorStyleSwipeKeypad *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleSwipeKeypad, vtkInteractorStyle3D);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;


 
  //@{
  /**
  * Override Right Button (Touchpad) to input numbers.
  */
  void OnSwipe() VTK_OVERRIDE;
  void OnLongTap() VTK_OVERRIDE;
  //@}

protected:
  vtkOpenVRInteractorStyleSwipeKeypad();
  ~vtkOpenVRInteractorStyleSwipeKeypad() VTK_OVERRIDE;

private:
  vtkOpenVRInteractorStyleSwipeKeypad(const vtkOpenVRInteractorStyleSwipeKeypad&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStyleSwipeKeypad&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif
