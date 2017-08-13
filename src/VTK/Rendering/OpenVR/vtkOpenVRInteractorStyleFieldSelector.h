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
 * @see vtkOpenVRInteractorStyleInputData vtkOpenVRFieldModifier
 */

#ifndef vtkOpenVRInteractorStyleFieldSelector_h
#define vtkOpenVRInteractorStyleFieldSelector_h

#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkOpenVRInteractorStyleInputData.h"

#define MAX_IMG 3

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleFieldSelector : public vtkOpenVRInteractorStyleInputData
{
public:
  static vtkOpenVRInteractorStyleFieldSelector *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleFieldSelector, vtkOpenVRInteractorStyleInputData);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;


	// Override Right Button (Touchpad) to select a field.
  void OnRightButtonUp() VTK_OVERRIDE;

	// Override Middle Button (Grip):
	// - Inside a prop, iterates over sources
	// - Outside a prop, uses superclass implementation
  void OnMiddleButtonDown() VTK_OVERRIDE;

	//Images handling
	virtual void ChangeImage();

protected:
	vtkOpenVRInteractorStyleFieldSelector();
  ~vtkOpenVRInteractorStyleFieldSelector() VTK_OVERRIDE;

private:
	vtkOpenVRInteractorStyleFieldSelector(const vtkOpenVRInteractorStyleFieldSelector&) VTK_DELETE_FUNCTION;
  void operator=(const vtkOpenVRInteractorStyleFieldSelector&) VTK_DELETE_FUNCTION;
};

#endif
