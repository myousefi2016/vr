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

class vtkTextActor3D;
class vtkTextMapper;
class vtkTextSource;
class vtkImageActor;

class vtkOpenVRPropertyModifier;

class vtkOpenVRTextFeedback;
class vtkOpenVRTouchPadImage;

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleTapKeyboard : public vtkOpenVRInteractorStyleInputData
{
public:
  static vtkOpenVRInteractorStyleTapKeyboard *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleTapKeyboard, vtkOpenVRInteractorStyleInputData);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  //@{
  /**
  * Override Right Button (Touchpad) to input numbers.
  */
  void OnRightButtonDown() VTK_OVERRIDE;
  void OnRightButtonUp() VTK_OVERRIDE;
  //@}

  //@{
  /**
  * Override Middle Button (Grip) which will select Prop and attribute to modify.
  */
  void OnMiddleButtonDown() VTK_OVERRIDE;
  void OnMiddleButtonUp() VTK_OVERRIDE;
  //@}

	//Images handling
	void IncNextImage() VTK_OVERRIDE;
	void DecNextImage() VTK_OVERRIDE;
	virtual void SwitchCaps();
 

protected:
	vtkOpenVRInteractorStyleTapKeyboard();
  ~vtkOpenVRInteractorStyleTapKeyboard() VTK_OVERRIDE;

private:
	vtkOpenVRInteractorStyleTapKeyboard(const vtkOpenVRInteractorStyleTapKeyboard&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStyleTapKeyboard&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif
