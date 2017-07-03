/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStylePressBool.h

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRInteractorStylePressBool
 * @brief   extended from vtkOpenVRInteractorStyle to override command methods on Touchpad.
 *          Divides touchpad in sections to input boolean values.
*/

#ifndef vtkOpenVRInteractorStylePressBool_h
#define vtkOpenVRInteractorStylePressBool_h

#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkOpenVRInteractorStyle.h"

class vtkTextActor3D;
class vtkBillboardTextActor3D;
class vtkTextMapper;
class vtkTextSource;

class vtkOpenVRPropertyModifier;

class vtkImageActor;
class vtkImageSliceMapper;
class vtkImageReader2;
class vtkImageMapper3D;
class vtkActor2D;
class vtkImageMapper;
class vtkImageData;
class vtkJPEGReader;
class vtkPNGReader;

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStylePressBool : public vtkOpenVRInteractorStyle
{
public:
  static vtkOpenVRInteractorStylePressBool *New();
  vtkTypeMacro(vtkOpenVRInteractorStylePressBool, vtkOpenVRInteractorStyle);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;



//TODO add interactions on touchpad 
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



protected:
  vtkOpenVRInteractorStylePressBool();
  ~vtkOpenVRInteractorStylePressBool() VTK_OVERRIDE;

  //Text3D to modify Props' attributes.
  vtkTextActor3D *TextActor;
  vtkRenderer *TextRenderer;
  bool TextHasUnsavedChanges;
  bool TextDefaultMsg;
  bool TextIsVisible;

  vtkOpenVRPropertyModifier *FieldModifier;
  //Used along with vtkOpenVRPropertyModifier:
  virtual void ShowTestActor(bool on);

private:
  vtkOpenVRInteractorStylePressBool(const vtkOpenVRInteractorStylePressBool&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStylePressBool&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif
