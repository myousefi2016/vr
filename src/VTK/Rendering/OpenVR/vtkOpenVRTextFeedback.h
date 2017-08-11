/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRTextFeedback.h

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRTextFeedback
 * @brief   utility to be used on VR environments. It allows the user to
 * have real time feedback of the values of the variables that are being
 * modified.
 */

#ifndef vtkOpenVRTextFeedback_h
#define vtkOpenVRTextFeedback_h

#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkObject.h"

class vtkTextActor3D;
class vtkRenderer;
class vtkOpenVRCamera;

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRTextFeedback : public vtkObject
{
public:
  static vtkOpenVRTextFeedback *New();
  vtkTypeMacro(vtkOpenVRTextFeedback, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  virtual void Init();
	virtual void Reset();
	virtual void PlaceInScene(vtkOpenVRCamera* cam);

	vtkGetMacro(TextActor, vtkTextActor3D*);
	vtkSetMacro(TextActor, vtkTextActor3D*);
	vtkGetMacro(TextRenderer, vtkRenderer*);
	vtkSetMacro(TextRenderer, vtkRenderer*);
	vtkGetMacro(TextIsVisible, bool);
	vtkSetMacro(TextIsVisible, bool);
	vtkGetMacro(HasUnsavedChanges, bool);
	vtkSetMacro(HasUnsavedChanges, bool);
	vtkGetMacro(DefaultMsgOn, bool);
	vtkSetMacro(DefaultMsgOn, bool);
	vtkGetMacro(TextDefaultMsg, char*);
	vtkSetMacro(TextDefaultMsg, char*);

protected:
	vtkOpenVRTextFeedback();
  ~vtkOpenVRTextFeedback() VTK_OVERRIDE;

	vtkTextActor3D *TextActor;
  vtkRenderer *TextRenderer;
  bool HasUnsavedChanges;
  bool DefaultMsgOn;
  bool TextIsVisible;
  char* TextDefaultMsg;

private:
	vtkOpenVRTextFeedback(const vtkOpenVRTextFeedback&) VTK_DELETE_FUNCTION;
  void operator=(const vtkOpenVRTextFeedback&) VTK_DELETE_FUNCTION;
};

#endif
