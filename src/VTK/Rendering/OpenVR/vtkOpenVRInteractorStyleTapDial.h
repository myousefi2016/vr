/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleTapDial.h

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRInteractorStyleTapDial
 * @brief   extended from vtkOpenVRInteractorStyle to override command methods on Touchpad.
 *          Divides touchpad in circular crown sectors for numbers 0-9.
*/

#ifndef vtkOpenVRInteractorStyleTapDial_h
#define vtkOpenVRInteractorStyleTapDial_h

#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkOpenVRInteractorStyleInputData.h"

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

class vtkOpenVRTextFeedback;

class vtkOpenVRCFDFilterer;

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleTapDial : public vtkOpenVRInteractorStyleInputData
{
public:
  static vtkOpenVRInteractorStyleTapDial *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleTapDial, vtkOpenVRInteractorStyleInputData);
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
  * Override Middle Button (Grip) which will enable a text to input data.
  * Also, for test purposes select Prop and attribute to modify.
  */
  void OnMiddleButtonDown() VTK_OVERRIDE;
  void OnMiddleButtonUp() VTK_OVERRIDE;
  //@}



	//@{
	/**
	* Override Left Button (Trigger) to try to get properties from the actor picked.
	*/
	void OnLeftButtonDown() VTK_OVERRIDE;
	void OnLeftButtonUp() VTK_OVERRIDE;
	//@}




protected:
  vtkOpenVRInteractorStyleTapDial();
  ~vtkOpenVRInteractorStyleTapDial() VTK_OVERRIDE;


	//CFD integration try
	vtkOpenVRCFDFilterer *CFDFilterer;


private:
  vtkOpenVRInteractorStyleTapDial(const vtkOpenVRInteractorStyleTapDial&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStyleTapDial&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif
