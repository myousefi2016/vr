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

#include "vtkOpenVRPropertyModifier.h"	//For vtkField. In the future, move the enum to a new file and include it here.

class vtkOpenVRTextFeedback;
class vtkOpenVRTouchPadImage;
class vtkOpenVRTouchPadPointer;
class vtkOpenVRPropertyModifier;
class vtkOpenVRInteractorStyleSwitchInput;

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleInputData : public vtkOpenVRInteractorStyle
{
public:
  static vtkOpenVRInteractorStyleInputData *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleInputData, vtkOpenVRInteractorStyleInputData);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  //@{
  /**
  * Override Middle Button to load an auxiliary text
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

	//@{
	/**
	* Override OnMouseMove to be able to use functions from
	* TouchPadImage and TouchPadPointer.
	*/
	void OnMouseMove() VTK_OVERRIDE;
	//@}

	virtual void IncNextImage();
	virtual void DecNextImage();

	//Swiping
	virtual void TrackFinger() {}

	//Disable all external elements active on the IS
	virtual void Reset();


	void ModifyProperty(vtkObject * obj, vtkField field, char** value);
	vtkSetMacro(ISSwitch, vtkOpenVRInteractorStyleSwitchInput *);


	//Enable or disable Properties modification:
	bool ModifyProp;

protected:
  vtkOpenVRInteractorStyleInputData();
  ~vtkOpenVRInteractorStyleInputData() VTK_OVERRIDE;

	vtkOpenVRTouchPadPointer *TouchPadPointer;
	vtkOpenVRTouchPadImage *TouchPadImage;
	vtkOpenVRTextFeedback *TextFeedback;
//////	vtkOpenVRPropertyModifier *FieldModifier;

	vtkOpenVRInteractorStyleSwitchInput *ISSwitch;


private:
	vtkOpenVRInteractorStyleInputData(const vtkOpenVRInteractorStyleInputData&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStyleInputData&) VTK_DELETE_FUNCTION;  // Not implemented.
  	
};

#endif
