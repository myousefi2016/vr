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
 * @brief   extended from vtkOpenVRInteractorStyleInputData to override command methods on Touchpad.
 *          TODO description.
*/

#ifndef vtkOpenVRInteractorStyleSwipeDial_h
#define vtkOpenVRInteractorStyleSwipeDial_h

#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkOpenVRInteractorStyleInputData.h"

class vtkDequeAngleRadius;
class vtkOpenVRTextFeedback;

#define MAX_REC 5

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleSwipeDial : public vtkOpenVRInteractorStyleInputData
{
public:
  static vtkOpenVRInteractorStyleSwipeDial *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleSwipeDial, vtkOpenVRInteractorStyleInputData);
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
  */
  void OnMiddleButtonDown() VTK_OVERRIDE;
  void OnMiddleButtonUp() VTK_OVERRIDE;
  //@}


	void OnUntap() VTK_OVERRIDE;


  void TrackFinger() VTK_OVERRIDE;

	//Manage finger position values
  virtual double GetAngle(int pos = 0);
  virtual double GetRadius(int pos = 0);
  virtual double GetAvgDiffAngle();
  virtual double GetAvgRadius();
  virtual int GetSwipeDirection();	//Idea: -1: antiCW; 1:CW; 0: undefined.
	virtual void UpdateValue();	

	virtual void FlushValues();	//Empty records.
protected:
  vtkOpenVRInteractorStyleSwipeDial();
  ~vtkOpenVRInteractorStyleSwipeDial() VTK_OVERRIDE;
  


	//Values storage: AngleRadius.first: Angle |  AngleRadius.second: Radius
	vtkDequeAngleRadius *AngleRadiusRecord;
	bool AbsoluteInc;	//absolute/relative increments


private:
  vtkOpenVRInteractorStyleSwipeDial(const vtkOpenVRInteractorStyleSwipeDial&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStyleSwipeDial&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif