/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStylePressDial.h

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
 *          Divides touchpad in circular crown sectors for numbers 0-9.
*/

#ifndef vtkOpenVRInteractorStylePressDial_h
#define vtkOpenVRInteractorStylePressDial_h

#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkOpenVRInteractorStyle.h"

class vtkTextActor3D;
class vtkBillboardTextActor3D;
class vtkTextMapper;
class vtkTextSource;

class vtkOpenVRPropertyModifier;

class vtkImageActor;
class vtkImageSliceMapper;
class vtkImageReader2;
class vtkImageMapper3D;
class vtkActor2D;
class vtkImageMapper;
class vtkImageData;
class vtkJPEGReader;
class vtkPNGReader;

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStylePressDial : public vtkOpenVRInteractorStyle
{
public:
  static vtkOpenVRInteractorStylePressDial *New();
  vtkTypeMacro(vtkOpenVRInteractorStylePressDial, vtkOpenVRInteractorStyle);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;



//TODO add interactions on touchpad 
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

  //Delete trigger behaviour from base class.
  //void OnLeftButtonDown() VTK_OVERRIDE {};
  //void OnLeftButtonUp() VTK_OVERRIDE {};



  //Launch touchpad touched event
  //void OnTap() VTK_OVERRIDE;	//moved to its superclass

  //Images:
  void SetTouchPadImage(bool activate) VTK_OVERRIDE;



protected:
  vtkOpenVRInteractorStylePressDial();
  ~vtkOpenVRInteractorStylePressDial() VTK_OVERRIDE;

  //Text3D to modify Props' attributes.
  vtkTextActor3D *TextActor;
  vtkRenderer *TextRenderer;
  bool TextHasUnsavedChanges;
  bool TextDefaultMsg;
  bool TextIsVisible;

  vtkOpenVRPropertyModifier *FieldModifier;
  //Used along with vtkOpenVRPropertyModifier:
  virtual void ShowTestActor(bool on);

	//TODO add images
  vtkImageActor *ImgActor;
	//vtkActor *ImgActor;
  vtkRenderer *ImgRenderer;
  vtkImageReader2 *ImgReader;
	vtkImageMapper3D *ImgMapper;		//vtkImageSliceMapper *ImgMapper;
	// Lets try with an overlay:
	//vtkOpenVROverlay *Overlay;
	//Other try:
	vtkPNGReader *reader;
	vtkImageSliceMapper *mapper;
	//vtkActor2D *ImgActor;
	//vtkRenderer *render;

private:
  vtkOpenVRInteractorStylePressDial(const vtkOpenVRInteractorStylePressDial&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRInteractorStylePressDial&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif
