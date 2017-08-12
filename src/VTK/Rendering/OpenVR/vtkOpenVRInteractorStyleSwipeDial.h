/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleSwipeDial.h

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRInteractorStyleSwipeDial
 * @brief   extended from vtkOpenVRInteractorStyleInputData to override command
 * methods on Touchpad. It allows to modify numeric values by swiping inside the
 * touchpad.
*/

#ifndef vtkOpenVRInteractorStyleSwipeDial_h
#define vtkOpenVRInteractorStyleSwipeDial_h

#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkOpenVRInteractorStyleInputData.h"

class vtkDequeAngleRadius;
class vtkOpenVRTextFeedback;
class vtkOpenVRFieldModifier;

#define MAX_REC 5

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleSwipeDial : public vtkOpenVRInteractorStyleInputData
{
public:
  static vtkOpenVRInteractorStyleSwipeDial *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleSwipeDial, vtkOpenVRInteractorStyleInputData);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

	// Override Right Button (Touchpad) to input numbers.
  void OnRightButtonDown() VTK_OVERRIDE;

	// Override Middle Button (Grip):
	// - Inside a prop, goes into the FieldSelector
	// - Outsade a prop, uses superclass implementation
  void OnMiddleButtonDown() VTK_OVERRIDE;

	// Override Untap event
	void OnUntap() VTK_OVERRIDE;

	//Get swiping data.
  void TrackFinger() VTK_OVERRIDE;

	//Manage finger position values
  virtual double GetAngle(int pos = 0);
  virtual double GetRadius(int pos = 0);
  virtual double GetAvgDiffAngle();
  virtual double GetAvgRadius();
  virtual int GetSwipeDirection();	// -1: antiCW; 1:CW; 0: undefined.
	virtual void UpdateValue();	

	virtual void FlushValues();	//Empty records.

protected:
  vtkOpenVRInteractorStyleSwipeDial();
  ~vtkOpenVRInteractorStyleSwipeDial() VTK_OVERRIDE;
  
	// Values storage: AngleRadius.first: Angle |  AngleRadius.second: Radius
	vtkDequeAngleRadius *AngleRadiusRecord;
	bool AbsoluteInc;	// Absolute/relative increments

private:
  vtkOpenVRInteractorStyleSwipeDial(const vtkOpenVRInteractorStyleSwipeDial&) VTK_DELETE_FUNCTION;
  void operator=(const vtkOpenVRInteractorStyleSwipeDial&) VTK_DELETE_FUNCTION;
};

#endif