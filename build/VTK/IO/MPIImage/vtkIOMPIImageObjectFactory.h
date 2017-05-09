/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkIOMPIImageObjectFactory.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef __vtkIOMPIImageObjectFactory_h
#define __vtkIOMPIImageObjectFactory_h

#include "vtkIOMPIImageModule.h" // For export macro
#include "vtkObjectFactory.h"

class VTKIOMPIIMAGE_EXPORT vtkIOMPIImageObjectFactory : public vtkObjectFactory
{
public:
  static vtkIOMPIImageObjectFactory * New();
  vtkTypeMacro(vtkIOMPIImageObjectFactory, vtkObjectFactory)

  const char * GetDescription() VTK_OVERRIDE { return "vtkIOMPIImage factory overrides."; }

  const char * GetVTKSourceVersion() VTK_OVERRIDE;

  void PrintSelf(ostream &os, vtkIndent indent) VTK_OVERRIDE;

protected:
  vtkIOMPIImageObjectFactory();

private:
  vtkIOMPIImageObjectFactory(const vtkIOMPIImageObjectFactory&) VTK_DELETE_FUNCTION;
  void operator=(const vtkIOMPIImageObjectFactory&) VTK_DELETE_FUNCTION;
};

#endif // __vtkIOMPIImageObjectFactory_h
