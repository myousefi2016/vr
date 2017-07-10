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
 * @class   vtkOpenVRInteractorStylePressDial
 * @brief   extended from vtkOpenVRInteractorStyle to override command methods on Touchpad.
 *          Divides touchpad in two concentric circles.  Swiping clockwise on the outer circular
 *          crown will increment the value of the number, while swiping anti-clockwise will
 *          decrease its value. Inner circle will implement two buttons for deleting and
 *          accepting the value.
*/

#ifndef vtkOpenVRInteractorStyleSwipeDial_h
#define vtkOpenVRInteractorStyleSwipeDial_h

#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkOpenVRInteractorStyle.h"

class vtkDequeAngleRadius;
class vtkOpenVRTextFeedback;

#define MAX_REC 5

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleSwipeDial : public vtkOpenVRInteractorStyle
{
public:
  static vtkOpenVRInteractorStyleSwipeDial *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleSwipeDial, vtkOpenVRInteractorStyle);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  //@{
  /** 04/07 - I remove this because I am using TAP for everything.
   *          May be interesting to switch from tap to SWIPE.
  * Override Swiping (Touchpad) to increment/decrement numbers.
  */
//  void OnSwipe() VTK_OVERRIDE;
//  void OnLongTap() VTK_OVERRIDE;	//May be useful to detct start of gesture.
  //@}

  //Text3D to modify Props' attributes.
  vtkOpenVRTextFeedback *TextFeedback;


  //Repeated code from PressDial:
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
  //virtual void DecValue();	//Inc and Dec may be merged.
  //virtual void IncValue();

	virtual void UpdateValue();	

	virtual void FlushValues();	//Empty records.
protected:
  vtkOpenVRInteractorStyleSwipeDial();
  ~vtkOpenVRInteractorStyleSwipeDial() VTK_OVERRIDE;
  


	//Values storage: AngleRadius.first: Angle |  AngleRadius.second: Radius
	vtkDequeAngleRadius *AngleRadiusRecord;
	bool AbsoluteInc;	//absolute/relative increments
//	bool PositiveInc;	//positive/negative increments 


private:
  vtkOpenVRInteractorStyleSwipeDial(const vtkOpenVRInteractorStyleSwipeDial&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStyleSwipeDial&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif

//List, **queue**, stack