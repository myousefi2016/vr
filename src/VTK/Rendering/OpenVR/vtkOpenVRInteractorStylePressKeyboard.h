/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStylePressKeyboard.h

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRInteractorStylePressKeyboard
 * @brief   extended from vtkOpenVRInteractorStyleInputData to override command methods on Touchpad.
 *          Divides touchpad in sectors allowing to convert it into a keyboard for text writing
*/

#ifndef vtkOpenVRInteractorStylePressKeyboard_h
#define vtkOpenVRInteractorStylePressKeyboard_h

#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkOpenVRInteractorStyleInputData.h"

#define MAX_IMG 8

class vtkTextActor3D;
class vtkBillboardTextActor3D;
class vtkTextMapper;
class vtkTextSource;
class vtkImageActor;

class vtkOpenVRPropertyModifier;

class vtkOpenVRTextFeedback;
class vtkOpenVRTouchPadImage;

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStylePressKeyboard : public vtkOpenVRInteractorStyleInputData
{
public:
  static vtkOpenVRInteractorStylePressKeyboard *New();
  vtkTypeMacro(vtkOpenVRInteractorStylePressKeyboard, vtkOpenVRInteractorStyle);
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
/*	void IncNextImage() VTK_OVERRIDE;
	void DecNextImage() VTK_OVERRIDE;*/
	virtual void SwitchCaps();
 

protected:
	vtkOpenVRInteractorStylePressKeyboard();
  ~vtkOpenVRInteractorStylePressKeyboard() VTK_OVERRIDE;

  //Text3D to modify Props' attributes.
//  vtkOpenVRTextFeedback *TextFeedback;
  //Images
 // vtkOpenVRTouchPadImage *TouchPadImage;

  vtkOpenVRPropertyModifier *FieldModifier;
  //Used along with vtkOpenVRPropertyModifier:
  virtual void ShowTestActor(bool on);

private:
	vtkOpenVRInteractorStylePressKeyboard(const vtkOpenVRInteractorStylePressKeyboard&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStylePressKeyboard&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif
