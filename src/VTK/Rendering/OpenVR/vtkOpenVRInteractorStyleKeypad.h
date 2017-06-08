/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleKeypad.h

Copyright (c) Ventura Romero
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRInteractorStyleDialTouchpad
 * @brief   extended from vtkInteractorStyle3D to override command methods on Touchpad.
 *          Divides touchpad in squared sectors for numbers 0-9.
*/

#ifndef vtkOpenVRInteractorStyleKeypad_h
#define vtkOpenVRInteractorStyleKeypad_h

#include "vtkRenderingOpenVRModule.h" // For export macro

#include "vtkInteractorStyle3D.h"

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleKeypad : public vtkInteractorStyle3D
{
public:
  static vtkOpenVRInteractorStyleKeypad *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleKeypad, vtkInteractorStyle3D);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;


 
  //@{
  /**
  * Override Right Button (Touchpad) to input numbers.
  */
  void OnRightButtonDown() VTK_OVERRIDE;
  void OnRightButtonUp() VTK_OVERRIDE;
  //@}

protected:
  vtkOpenVRInteractorStyleKeypad();
  ~vtkOpenVRInteractorStyleKeypad() VTK_OVERRIDE;

private:
  vtkOpenVRInteractorStyleKeypad(const vtkOpenVRInteractorStyleKeypad&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStyleKeypad&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif
