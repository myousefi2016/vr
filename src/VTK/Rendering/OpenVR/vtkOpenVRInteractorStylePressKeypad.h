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
 * @class   vtkOpenVRInteractorStylePressDialTouchpad
 * @brief   extended from vtkOpenVRInteractorStyle to override command methods on Touchpad.
 *          Divides touchpad in squared sectors for numbers 0-9.
*/

#ifndef vtkOpenVRInteractorStylePressKeypad_h
#define vtkOpenVRInteractorStylePressKeypad_h

#include "vtkRenderingOpenVRModule.h" // For export macro

#include "vtkOpenVRInteractorStyle.h"

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStylePressKeypad : public vtkOpenVRInteractorStyle
{
public:
  static vtkOpenVRInteractorStylePressKeypad *New();
  vtkTypeMacro(vtkOpenVRInteractorStylePressKeypad, vtkInteractorStyle3D);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;


 
  //@{
  /**
  * Override Right Button (Touchpad) to input numbers.
  */
  void OnRightButtonDown() VTK_OVERRIDE;
  void OnRightButtonUp() VTK_OVERRIDE;
  //@}

protected:
  vtkOpenVRInteractorStylePressKeypad();
  ~vtkOpenVRInteractorStylePressKeypad() VTK_OVERRIDE;

private:
  vtkOpenVRInteractorStylePressKeypad(const vtkOpenVRInteractorStylePressKeypad&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStylePressKeypad&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif
