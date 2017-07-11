/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleInputData.h

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRInteractorStyleInputData
 * @brief   extended from vtkOpenVRInteractorStyle to provide support for
 * data modification and user interaction for inputtiong data.
*/

#ifndef vtkOpenVRInteractorStyleInputData_h
#define vtkOpenVRInteractorStyleInputData_h

#include "vtkRenderingOpenVRModule.h" // For export macro

#include "vtkOpenVRInteractorStyle.h"

class vtkSphereSource;
class vtkPNGReader;
class vtkImageActor;

class vtkOpenVRTextFeedback;
class vtkOpenVRTouchPadImage;
class vtkOpenVRTouchPadPointer;

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleInputData : public vtkOpenVRInteractorStyle
{
public:
  static vtkOpenVRInteractorStyleInputData *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleInputData, vtkOpenVRInteractorStyleInputData);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;



  //@{
  /**
  * Override Middle Button to load next camera position
  */
  void OnMiddleButtonDown() VTK_OVERRIDE;
  void OnMiddleButtonUp() VTK_OVERRIDE;
  //@}

	//@{
	/**
	* Override Tap to show pointer on touchpad.
	*/
	void OnTap() VTK_OVERRIDE;
	void OnUntap() VTK_OVERRIDE;
	//@}

	//Pointer:
	void SetTouchPadPointer(bool activate) VTK_OVERRIDE;

	//Images:
	void SetTouchPadImage(bool activate) VTK_OVERRIDE;

	

protected:
  vtkOpenVRInteractorStyleInputData();
  ~vtkOpenVRInteractorStyleInputData() VTK_OVERRIDE;

	//Touchpad Pointer.
	//*//
	/*vtkSphereSource *Pointer;
	vtkPolyDataMapper *PointerMapper;
	vtkActor *PointerActor;
	vtkRenderer *PointerRenderer;
	double PointerColor[3];*/
	//*//
	vtkOpenVRTouchPadPointer *TouchPadPointer;

	/*//Images (implemented in inherited classes):
	bool HasImage;
	int NextImage;
	vtkPNGReader *ImgReader;
	vtkImageActor *ImgActor;
	vtkRenderer *ImgRenderer;*/
	vtkOpenVRTouchPadImage *TouchPadImage;

	//Text 3D
	vtkOpenVRTextFeedback *TextFeedback;


private:
	vtkOpenVRInteractorStyleInputData(const vtkOpenVRInteractorStyleInputData&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStyleInputData&) VTK_DELETE_FUNCTION;  // Not implemented.
  	
};

#endif
