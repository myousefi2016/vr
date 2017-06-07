/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleDialTouchpad.h

Copyright (c) Ventura Romero
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRInteractorStyleDialTouchpad
 * @brief   extended from vtkInteractorStyle3D to override command methods
*/

#ifndef vtkOpenVRInteractorStyleDialTouchpad_h
#define vtkOpenVRInteractorStyleDialTouchpad_h

#include "vtkRenderingOpenVRModule.h" // For export macro

#include "vtkInteractorStyle3D.h"

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleDialTouchpad : public vtkInteractorStyle3D
{
public:
  static vtkOpenVRInteractorStyleDialTouchpad *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleDialTouchpad, vtkInteractorStyle3D);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;



//TODO add interactions on touchpad 
  //@{
  /**
  * Override Right Button (Touchpad) to input numbers.
  */
  void OnRightButtonDown() VTK_OVERRIDE;
  void OnRightButtonUp() VTK_OVERRIDE;
  //@}

protected:
  vtkOpenVRInteractorStyleDialTouchpad();
  ~vtkOpenVRInteractorStyleDialTouchpad() VTK_OVERRIDE;

private:
  vtkOpenVRInteractorStyleDialTouchpad(const vtkOpenVRInteractorStyleDialTouchpad&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStyleDialTouchpad&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif
