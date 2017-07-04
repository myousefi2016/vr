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
class vtkTextActor3D;

#define MAX_REC 10

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleSwipeDial : public vtkOpenVRInteractorStyle
{
public:
  static vtkOpenVRInteractorStyleSwipeDial *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleSwipeDial, vtkInteractorStyle3D);
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
  //TODO move all this to Superclass
  vtkTextActor3D *TextActor;
  vtkRenderer *TextRenderer;
  bool TextHasUnsavedChanges;
  bool TextDefaultMsg;
  bool TextIsVisible;


  void TrackFinger() VTK_OVERRIDE;

	//Manage finger position values
  virtual double GetAngle(int pos = 0);
  virtual double GetRadius(int pos = 0);
  virtual double GetDiffAngle();
  virtual double GetAvgRadius();
  virtual int GetSwipeDirection();	//Idea: -1: antiCW; 1:CW; 0: undefined.
  virtual void DecValue();	//Inc and Dec may be merged.
  virtual void IncValue();
protected:
  vtkOpenVRInteractorStyleSwipeDial();
  ~vtkOpenVRInteractorStyleSwipeDial() VTK_OVERRIDE;
  


	//Values storage: AngleRadius.first: Angle |  AngleRadius.second: Radius
	vtkDequeAngleRadius *AngleRadiusRecord;


private:
  vtkOpenVRInteractorStyleSwipeDial(const vtkOpenVRInteractorStyleSwipeDial&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStyleSwipeDial&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif

//List, **queue**, stack