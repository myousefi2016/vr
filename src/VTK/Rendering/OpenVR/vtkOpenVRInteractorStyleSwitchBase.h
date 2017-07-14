/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkOpenVRInteractorStyleSwitchBase.h

  Copyright (c) Ventura Romero Mendo
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRInteractorStyleSwitchBase
 * @brief   dummy interface class.
 *
 * The class vtkOpenVRInteractorStyleSwitchBase is here to allow the
 * vtkRenderWindowInteractor to instantiate a default interactor style and
 * preserve backward compatible behavior when the object factory is overridden
 * and vtkOpenVRInteractorStyleSwitch[name] is returned.
 *
 * @sa
 * vtkOpenVRInteractorStyleSwitchBase vtkRenderWindowInteractor
 */

#ifndef vtkOpenVRInteractorStyleSwitchBase_h
#define vtkOpenVRInteractorStyleSwitchBase_h

#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkOpenVRInteractorStyle.h"

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRInteractorStyleSwitchBase
  : public vtkOpenVRInteractorStyle
{
public:
  static vtkOpenVRInteractorStyleSwitchBase *New();
  vtkTypeMacro(vtkOpenVRInteractorStyleSwitchBase, vtkOpenVRInteractorStyle);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

	vtkRenderWindowInteractor* GetInteractor() VTK_OVERRIDE;

protected:
	vtkOpenVRInteractorStyleSwitchBase();
  ~vtkOpenVRInteractorStyleSwitchBase() VTK_OVERRIDE;

private:
	vtkOpenVRInteractorStyleSwitchBase(const vtkOpenVRInteractorStyleSwitchBase&) VTK_DELETE_FUNCTION;
  void operator=(const vtkOpenVRInteractorStyleSwitchBase&) VTK_DELETE_FUNCTION;
};

#endif
