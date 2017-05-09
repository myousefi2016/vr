/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkRenderingParallelLICObjectFactory.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "vtkRenderingParallelLICObjectFactory.h"
#include "vtkVersion.h"

// Include all of the classes we want to create overrides for.

#include "vtkPSurfaceLICInterface.h"
#include "vtkPLineIntegralConvolution2D.h"
#include "vtkPSurfaceLICComposite.h"

vtkStandardNewMacro(vtkRenderingParallelLICObjectFactory)

// Now create the functions to create overrides with.

  VTK_CREATE_CREATE_FUNCTION(vtkPSurfaceLICInterface)
  VTK_CREATE_CREATE_FUNCTION(vtkPLineIntegralConvolution2D)
  VTK_CREATE_CREATE_FUNCTION(vtkPSurfaceLICComposite)

vtkRenderingParallelLICObjectFactory::vtkRenderingParallelLICObjectFactory()
{

    this->RegisterOverride("vtkSurfaceLICInterface",
                           "vtkPSurfaceLICInterface",
                           "Override for vtkRenderingParallelLIC module", 1,
                           vtkObjectFactoryCreatevtkPSurfaceLICInterface);
    this->RegisterOverride("vtkLineIntegralConvolution2D",
                           "vtkPLineIntegralConvolution2D",
                           "Override for vtkRenderingParallelLIC module", 1,
                           vtkObjectFactoryCreatevtkPLineIntegralConvolution2D);
    this->RegisterOverride("vtkSurfaceLICComposite",
                           "vtkPSurfaceLICComposite",
                           "Override for vtkRenderingParallelLIC module", 1,
                           vtkObjectFactoryCreatevtkPSurfaceLICComposite);
}

const char * vtkRenderingParallelLICObjectFactory::GetVTKSourceVersion()
{
  return VTK_SOURCE_VERSION;
}

void vtkRenderingParallelLICObjectFactory::PrintSelf(ostream &os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

// Registration of object factories.
static unsigned int vtkRenderingParallelLICCount;

VTKRENDERINGPARALLELLIC_EXPORT void vtkRenderingParallelLIC_AutoInit_Construct()
{
  if(++vtkRenderingParallelLICCount == 1)
    {
    
    vtkRenderingParallelLICObjectFactory* factory = vtkRenderingParallelLICObjectFactory::New();
    if (factory)
      {
      // vtkObjectFactory keeps a reference to the "factory",
      vtkObjectFactory::RegisterFactory(factory);
      factory->Delete();
      }
    }
}

VTKRENDERINGPARALLELLIC_EXPORT void vtkRenderingParallelLIC_AutoInit_Destruct()
{
  if(--vtkRenderingParallelLICCount == 0)
    {
    // Do not call vtkObjectFactory::UnRegisterFactory because
    // vtkObjectFactory.cxx statically unregisters all factories.
    }
}
