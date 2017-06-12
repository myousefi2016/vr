/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStylePressDial.h

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRInteractorStylePressDial
 * @brief   extended from vtkOpenVRInteractorStyle to override command methods on Touchpad.
 *          Divides touchpad in circular crown sectors for numbers 0-9.
*/

#ifndef vtkOpenVRInteractorStylePressDial_h
#define vtkOpenVRInteractorStylePressDial_h

#include "vtkRenderingOpenVRModule.h" // For export macro

#include "vtkOpenVRInteractorStyle.h"

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStylePressDial : public vtkOpenVRInteractorStyle
{
public:
  static vtkOpenVRInteractorStylePressDial *New();
  vtkTypeMacro(vtkOpenVRInteractorStylePressDial, vtkInteractorStyle3D);
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
  vtkOpenVRInteractorStylePressDial();
  ~vtkOpenVRInteractorStylePressDial() VTK_OVERRIDE;

private:
  vtkOpenVRInteractorStylePressDial(const vtkOpenVRInteractorStylePressDial&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStylePressDial&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif
