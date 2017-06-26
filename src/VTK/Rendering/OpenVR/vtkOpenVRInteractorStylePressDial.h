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

class vtkTextActor3D;
class vtkBillboardTextActor3D;
class vtkTextMapper;
class vtkTextSource;

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStylePressDial : public vtkOpenVRInteractorStyle
{
public:
  static vtkOpenVRInteractorStylePressDial *New();
  vtkTypeMacro(vtkOpenVRInteractorStylePressDial, vtkOpenVRInteractorStyle);
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

  //Delete trigger behaviour from base class.
  //void OnLeftButtonDown() VTK_OVERRIDE {};
  //void OnLeftButtonUp() VTK_OVERRIDE {};



  //Launch touchpad touched event
  //void OnTap() VTK_OVERRIDE;	//moved to its superclass

  
  /*To do in the future for all the properties:
  void AssignTextToProperty(vtkProperty);	-->>   NO!!! Create a class which handles all that stuff.
	*/

protected:
  vtkOpenVRInteractorStylePressDial();
  ~vtkOpenVRInteractorStylePressDial() VTK_OVERRIDE;

  //Text3D to modify Props' attributes.
  vtkTextActor3D *TextActor;
  vtkRenderer *TextRenderer;
  bool TextHasUnsavedChanges;
  bool TextDefaultMsg;

private:
  vtkOpenVRInteractorStylePressDial(const vtkOpenVRInteractorStylePressDial&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStylePressDial&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif
