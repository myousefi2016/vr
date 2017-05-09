/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkIOParallelExodusObjectFactory.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef __vtkIOParallelExodusObjectFactory_h
#define __vtkIOParallelExodusObjectFactory_h

#include "vtkIOParallelExodusModule.h" // For export macro
#include "vtkObjectFactory.h"

class VTKIOPARALLELEXODUS_EXPORT vtkIOParallelExodusObjectFactory : public vtkObjectFactory
{
public:
  static vtkIOParallelExodusObjectFactory * New();
  vtkTypeMacro(vtkIOParallelExodusObjectFactory, vtkObjectFactory)

  const char * GetDescription() VTK_OVERRIDE { return "vtkIOParallelExodus factory overrides."; }

  const char * GetVTKSourceVersion() VTK_OVERRIDE;

  void PrintSelf(ostream &os, vtkIndent indent) VTK_OVERRIDE;

protected:
  vtkIOParallelExodusObjectFactory();

private:
  vtkIOParallelExodusObjectFactory(const vtkIOParallelExodusObjectFactory&) VTK_DELETE_FUNCTION;
  void operator=(const vtkIOParallelExodusObjectFactory&) VTK_DELETE_FUNCTION;
};

#endif // __vtkIOParallelExodusObjectFactory_h
