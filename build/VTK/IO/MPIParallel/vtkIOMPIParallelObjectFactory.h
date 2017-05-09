/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkIOMPIParallelObjectFactory.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef __vtkIOMPIParallelObjectFactory_h
#define __vtkIOMPIParallelObjectFactory_h

#include "vtkIOMPIParallelModule.h" // For export macro
#include "vtkObjectFactory.h"

class VTKIOMPIPARALLEL_EXPORT vtkIOMPIParallelObjectFactory : public vtkObjectFactory
{
public:
  static vtkIOMPIParallelObjectFactory * New();
  vtkTypeMacro(vtkIOMPIParallelObjectFactory, vtkObjectFactory)

  const char * GetDescription() VTK_OVERRIDE { return "vtkIOMPIParallel factory overrides."; }

  const char * GetVTKSourceVersion() VTK_OVERRIDE;

  void PrintSelf(ostream &os, vtkIndent indent) VTK_OVERRIDE;

protected:
  vtkIOMPIParallelObjectFactory();

private:
  vtkIOMPIParallelObjectFactory(const vtkIOMPIParallelObjectFactory&) VTK_DELETE_FUNCTION;
  void operator=(const vtkIOMPIParallelObjectFactory&) VTK_DELETE_FUNCTION;
};

#endif // __vtkIOMPIParallelObjectFactory_h
