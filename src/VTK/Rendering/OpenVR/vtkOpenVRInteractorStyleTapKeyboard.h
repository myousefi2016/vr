/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleTapKeyboard.h

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRInteractorStyleTapKeyboard
 * @brief   extended from vtkOpenVRInteractorStyleInputData to override command methods on Touchpad.
 *          Divides touchpad in sectors allowing to convert it into a keyboard for text writing
*/

#ifndef vtkOpenVRInteractorStyleTapKeyboard_h
#define vtkOpenVRInteractorStyleTapKeyboard_h

#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkOpenVRInteractorStyleInputData.h"

#define MAX_IMG 8

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleTapKeyboard : public vtkOpenVRInteractorStyleInputData
{
public:
  static vtkOpenVRInteractorStyleTapKeyboard *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleTapKeyboard, vtkOpenVRInteractorStyleInputData);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  // Override Right Button (Touchpad) to input letters.
  void OnRightButtonDown() VTK_OVERRIDE;

	// Override Middle Button (Grip):
	// - Inside a prop, goes into the FieldSelector
	// - Outsade a prop, uses superclass implementation
	void OnMiddleButtonDown() VTK_OVERRIDE;

	//Images handling
	void IncNextImage() VTK_OVERRIDE;
	void DecNextImage() VTK_OVERRIDE;
	virtual void SwitchCaps();
 
protected:
	vtkOpenVRInteractorStyleTapKeyboard();
  ~vtkOpenVRInteractorStyleTapKeyboard() VTK_OVERRIDE;

private:
	vtkOpenVRInteractorStyleTapKeyboard(const vtkOpenVRInteractorStyleTapKeyboard&) VTK_DELETE_FUNCTION;
  void operator=(const vtkOpenVRInteractorStyleTapKeyboard&) VTK_DELETE_FUNCTION;
};

#endif
