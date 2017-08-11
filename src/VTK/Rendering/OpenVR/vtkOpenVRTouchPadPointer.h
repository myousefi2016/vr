/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRTouchPadPointer.h

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRTouchPadPointer
 * @brief   utility to be used on VR environments. It allows the user to
 * have a pointer fixed to the position of the touchpad that the user is
 * touching, so interaction with this button is easier.
 */

#ifndef vtkOpenVRTouchPadPointer_h
#define vtkOpenVRTouchPadPointer_h

#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkObject.h"

class vtkPolyDataMapper;
class vtkSphereSource;
class vtkActor;
class vtkRenderer;
class vtkOpenVRRenderWindowInteractor;

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRTouchPadPointer : public vtkObject
{
public:
  static vtkOpenVRTouchPadPointer *New();
  vtkTypeMacro(vtkOpenVRTouchPadPointer, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  virtual void Init();
  virtual void Attach(vtkOpenVRRenderWindowInteractor *rwi);	//If Tap
  virtual void Move(vtkOpenVRRenderWindowInteractor *rwi);		//If moved when is Tapped
  virtual void Detach();																			//If Untap
  
	vtkGetMacro(PointerSource, vtkSphereSource*)
	vtkSetMacro(PointerSource, vtkSphereSource*)
	vtkGetMacro(PointerMapper, vtkPolyDataMapper*)
	vtkSetMacro(PointerMapper, vtkPolyDataMapper*)
	vtkGetMacro(PointerActor, vtkActor*)
	vtkSetMacro(PointerActor, vtkActor*)
	vtkGetMacro(PointerRenderer, vtkRenderer*)
	vtkSetMacro(PointerRenderer, vtkRenderer*)
	
protected:
	vtkOpenVRTouchPadPointer();
  ~vtkOpenVRTouchPadPointer() VTK_OVERRIDE;

	vtkSphereSource *PointerSource;
	vtkPolyDataMapper *PointerMapper;
	vtkActor *PointerActor;
	vtkRenderer *PointerRenderer;

private:
	vtkOpenVRTouchPadPointer(const vtkOpenVRTouchPadPointer&) VTK_DELETE_FUNCTION;
  void operator=(const vtkOpenVRTouchPadPointer&) VTK_DELETE_FUNCTION;
};

#endif
