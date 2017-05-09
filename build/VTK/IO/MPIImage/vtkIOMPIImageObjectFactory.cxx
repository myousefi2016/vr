/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkIOMPIImageObjectFactory.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "vtkIOMPIImageObjectFactory.h"
#include "vtkVersion.h"

// Include all of the classes we want to create overrides for.

#include "vtkPNrrdReader.h"

vtkStandardNewMacro(vtkIOMPIImageObjectFactory)

// Now create the functions to create overrides with.

  VTK_CREATE_CREATE_FUNCTION(vtkPNrrdReader)

vtkIOMPIImageObjectFactory::vtkIOMPIImageObjectFactory()
{

    this->RegisterOverride("vtkNrrdReader",
                           "vtkPNrrdReader",
                           "Override for vtkIOMPIImage module", 1,
                           vtkObjectFactoryCreatevtkPNrrdReader);
}

const char * vtkIOMPIImageObjectFactory::GetVTKSourceVersion()
{
  return VTK_SOURCE_VERSION;
}

void vtkIOMPIImageObjectFactory::PrintSelf(ostream &os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

// Registration of object factories.
static unsigned int vtkIOMPIImageCount;

VTKIOMPIIMAGE_EXPORT void vtkIOMPIImage_AutoInit_Construct()
{
  if(++vtkIOMPIImageCount == 1)
    {
    
    vtkIOMPIImageObjectFactory* factory = vtkIOMPIImageObjectFactory::New();
    if (factory)
      {
      // vtkObjectFactory keeps a reference to the "factory",
      vtkObjectFactory::RegisterFactory(factory);
      factory->Delete();
      }
    }
}

VTKIOMPIIMAGE_EXPORT void vtkIOMPIImage_AutoInit_Destruct()
{
  if(--vtkIOMPIImageCount == 0)
    {
    // Do not call vtkObjectFactory::UnRegisterFactory because
    // vtkObjectFactory.cxx statically unregisters all factories.
    }
}
