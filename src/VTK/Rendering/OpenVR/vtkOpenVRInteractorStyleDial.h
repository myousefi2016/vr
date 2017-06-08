/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleDial.h

Copyright (c) Ventura Romero
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRInteractorStyleDial
 * @brief   extended from vtkInteractorStyle3D to override command methods on Touchpad.
 *          Divides touchpad in circular crown sectors for numbers 0-9.
*/

#ifndef vtkOpenVRInteractorStyleDial_h
#define vtkOpenVRInteractorStyleDial_h

#include "vtkRenderingOpenVRModule.h" // For export macro

#include "vtkInteractorStyle3D.h"

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleDial : public vtkInteractorStyle3D
{
public:
  static vtkOpenVRInteractorStyleDial *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleDial, vtkInteractorStyle3D);
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
  vtkOpenVRInteractorStyleDial();
  ~vtkOpenVRInteractorStyleDial() VTK_OVERRIDE;

private:
  vtkOpenVRInteractorStyleDial(const vtkOpenVRInteractorStyleDial&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStyleDial&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif
