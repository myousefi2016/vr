/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkOpenVRInteractorStyleSwitchInput.h

  Copyright (c) Ventura Romero Mendo
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRInteractorStyleSwitchInput
 * @brief   class to swap between interactory styles in OpenVR
 *
 * The class vtkOpenVRInteractorStyleSwitchInput allows handles interactively
 * switching between OpenVR interactor styles used to input data from VR
 * devices supported by OpenVR.
 * 
 * @sa
 * vtkOpenVRInteractorStyleTapDial vtkOpenVRInteractorStyleTapKeyboard
 * vtkOpenVRInteractorStyleTapBool vtkOpenVRInteractorStyleSwipeDial
*/

#ifndef vtkOpenVRInteractorStyleSwitchInput_h
#define vtkOpenVRInteractorStyleSwitchInput_h

#include "vtkInteractionStyleModule.h" // For export macro
#include "vtkOpenVRInteractorStyleSwitchBase.h"

// Gestures
enum class Gesture
{
	TAP,
	SWIPE,
	NONE
};

// Layouts
enum class Layout
{
	DIAL,
	KEYBOARD,
	BOOL,
	NONE
};

class vtkOpenVRInteractorStyleTapDial;
class vtkOpenVRInteractorStyleTapKeyboard;
class vtkOpenVRInteractorStyleTapBool;
class vtkOpenVRInteractorStyleSwipeDial;
class vtkOpenVRInteractorStyleFieldSelector;
class vtkOpenVRFieldModifier;

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleSwitchInput
  : public vtkOpenVRInteractorStyleSwitchBase
{
public:
  static vtkOpenVRInteractorStyleSwitchInput *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleSwitchInput, vtkOpenVRInteractorStyleSwitchBase);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

   // The sub styles need the interactor too.
  void SetInteractor(vtkRenderWindowInteractor *iren) VTK_OVERRIDE;

   // Pass the setting down to the underlying styles
  void SetAutoAdjustCameraClippingRange( int value ) VTK_OVERRIDE;

  // Set/Get current style
  vtkGetObjectMacro(CurrentStyle, vtkInteractorStyle);
  void SetCurrentStyleToTapDial();
  void SetCurrentStyleToTapKeyboard();
  void SetCurrentStyleToTapBool();
  void SetCurrentStyleToSwipeDial();
  void SetCurrentStyleToFieldSelector();
  void SetCurrentStyleTo(Gesture g, Layout l);

  /**
   * Only care about the Trigger event event, which is used to switch between
   * different styles.
   */
  void OnLeftButtonDown() VTK_OVERRIDE;
	void OnLeftButtonUp() VTK_OVERRIDE;

   // Interactor styles used by this class must also be updated.
  void SetDefaultRenderer(vtkRenderer*) VTK_OVERRIDE;
  void SetCurrentRenderer(vtkRenderer*) VTK_OVERRIDE;

	vtkGetMacro(FieldModifier, vtkOpenVRFieldModifier*);
	vtkSetMacro(CycleOverStyles ,bool);
	vtkGetMacro(CycleOverStyles, bool);

protected:
  vtkOpenVRInteractorStyleSwitchInput();
  ~vtkOpenVRInteractorStyleSwitchInput() VTK_OVERRIDE;

  void SetCurrentStyle();

	// Provides the sub-IS with a pointer to this class
	virtual void SetISSwitch();

	vtkOpenVRInteractorStyleTapDial *TapDial;								//Gesture::TAP		Layout::DIAL
	vtkOpenVRInteractorStyleTapKeyboard *TapKeyboard;				//Gesture::TAP		Layout::KEYBOARD
	vtkOpenVRInteractorStyleTapBool *TapBool;								//Gesture::TAP		Layout::BOOL
  vtkOpenVRInteractorStyleSwipeDial *SwipeDial;						//Gesture::SWIPE	Layout::DIAL
	vtkOpenVRInteractorStyleFieldSelector *FieldSelector;		//Gesture::NONE		Layout::NONE
  vtkInteractorStyle* CurrentStyle;

	vtkOpenVRFieldModifier *FieldModifier;

  Gesture CurrentGesture;
  Layout CurrentLayout;

	bool CycleOverStyles;

private:
  vtkOpenVRInteractorStyleSwitchInput(const vtkOpenVRInteractorStyleSwitchInput&) VTK_DELETE_FUNCTION;
  void operator=(const vtkOpenVRInteractorStyleSwitchInput&) VTK_DELETE_FUNCTION;
};

#endif
