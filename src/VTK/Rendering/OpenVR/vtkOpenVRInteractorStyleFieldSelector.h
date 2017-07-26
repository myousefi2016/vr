/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleFieldSelector.h

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRInteractorStyleFieldSelector
 * @brief   extended from vtkOpenVRInteractorStyleInputData as a proof of concept
 * intended to show an alternative to modify porperty fields on vtkProps and sources.
 * 
 * @see vtkOpenVRInteractorStyleInputData vtkOpenVRPropertyModifier
 * 
 */

#ifndef vtkOpenVRInteractorStyleFieldSelector_h
#define vtkOpenVRInteractorStyleFieldSelector_h

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

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleFieldSelector : public vtkOpenVRInteractorStyleInputData
{
public:
  static vtkOpenVRInteractorStyleFieldSelector *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleFieldSelector, vtkOpenVRInteractorStyleInputData);
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

	//Images handling METHODS FROM PREVIOUS CLASS. delete!
	void IncNextImage() VTK_OVERRIDE;
	void DecNextImage() VTK_OVERRIDE;
	virtual void SwitchCaps();

	virtual void ChangeImage();

	vtkField GetSelectedField();

	void Reset();

protected:
	vtkOpenVRInteractorStyleFieldSelector();
  ~vtkOpenVRInteractorStyleFieldSelector() VTK_OVERRIDE;

	vtkOpenVRPropertyModifier *FieldModifier;
	vtkField SelectedField;	//Field to be modified next;

private:
	vtkOpenVRInteractorStyleFieldSelector(const vtkOpenVRInteractorStyleFieldSelector&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStyleFieldSelector&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif
