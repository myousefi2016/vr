/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRTouchpadImage.h

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRTouchPadImage
 * @brief   utility to be used on VR environments. It allows the user to
 * have images fixed to the touchpad, so interaction with this button is
 * easier.
 */

#ifndef vtkOpenVRTouchPadImage_h
#define vtkOpenVRTouchPadImage_h

#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkObject.h"

class vtkPNGReader;
class vtkImageActor;
class vtkRenderer;
class vtkOpenVRRenderWindowInteractor;

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRTouchPadImage : public vtkObject
{
public:
  static vtkOpenVRTouchPadImage *New();
  vtkTypeMacro(vtkOpenVRTouchPadImage, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  virtual void LoadImages(int imgNum, char *prefix);	//Load several images
  virtual void LoadSingleImage(char *fullName);				//Load a single image
	virtual void UpdateImage();

  virtual void Init();
	virtual void Attach(vtkOpenVRRenderWindowInteractor *rwi);	//If Tap.
	virtual void Move(vtkOpenVRRenderWindowInteractor *rwi);		//If moved when is Tapped.
	virtual void Detach();																			//If Untap
  
  vtkGetMacro(ImgReader, vtkPNGReader*)
  vtkSetMacro(ImgReader, vtkPNGReader*)
  vtkGetMacro(ImgActor, vtkImageActor*)
  vtkSetMacro(ImgActor, vtkImageActor*)
  vtkGetMacro(ImgRenderer, vtkRenderer*)
  vtkSetMacro(ImgRenderer, vtkRenderer*)
  vtkGetMacro(HasImage, bool)
  vtkSetMacro(HasImage, bool)
  vtkGetMacro(NextImage, int)
  vtkSetMacro(NextImage, int)
  vtkGetMacro(MaxNumImg, int)
  vtkSetMacro(MaxNumImg, int)

protected:
	vtkOpenVRTouchPadImage();
  ~vtkOpenVRTouchPadImage() VTK_OVERRIDE;

  vtkPNGReader *ImgReader;
  vtkImageActor *ImgActor;
  vtkRenderer *ImgRenderer;
  bool HasImage;
  int NextImage;
  int MaxNumImg;

private:
	vtkOpenVRTouchPadImage(const vtkOpenVRTouchPadImage&) VTK_DELETE_FUNCTION;
  void operator=(const vtkOpenVRTouchPadImage&) VTK_DELETE_FUNCTION;
};

#endif
