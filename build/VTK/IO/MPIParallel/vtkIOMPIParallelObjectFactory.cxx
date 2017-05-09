/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkIOMPIParallelObjectFactory.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "vtkIOMPIParallelObjectFactory.h"
#include "vtkVersion.h"

// Include all of the classes we want to create overrides for.


vtkStandardNewMacro(vtkIOMPIParallelObjectFactory)

// Now create the functions to create overrides with.


vtkIOMPIParallelObjectFactory::vtkIOMPIParallelObjectFactory()
{

}

const char * vtkIOMPIParallelObjectFactory::GetVTKSourceVersion()
{
  return VTK_SOURCE_VERSION;
}

void vtkIOMPIParallelObjectFactory::PrintSelf(ostream &os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

// Registration of object factories.
static unsigned int vtkIOMPIParallelCount;

VTKIOMPIPARALLEL_EXPORT void vtkIOMPIParallel_AutoInit_Construct()
{
  if(++vtkIOMPIParallelCount == 1)
    {
    
    vtkIOMPIParallelObjectFactory* factory = vtkIOMPIParallelObjectFactory::New();
    if (factory)
      {
      // vtkObjectFactory keeps a reference to the "factory",
      vtkObjectFactory::RegisterFactory(factory);
      factory->Delete();
      }
    }
}

VTKIOMPIPARALLEL_EXPORT void vtkIOMPIParallel_AutoInit_Destruct()
{
  if(--vtkIOMPIParallelCount == 0)
    {
    // Do not call vtkObjectFactory::UnRegisterFactory because
    // vtkObjectFactory.cxx statically unregisters all factories.
    }
}
