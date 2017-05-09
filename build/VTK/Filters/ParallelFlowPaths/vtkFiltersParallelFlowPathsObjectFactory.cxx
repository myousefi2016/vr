/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkFiltersParallelFlowPathsObjectFactory.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "vtkFiltersParallelFlowPathsObjectFactory.h"
#include "vtkVersion.h"

// Include all of the classes we want to create overrides for.

#include "vtkPLagrangianParticleTracker.h"
#include "vtkPStreamTracer.h"
#include "vtkPTemporalStreamTracer.h"
#include "vtkPParticleTracer.h"
#include "vtkPParticlePathFilter.h"
#include "vtkPStreaklineFilter.h"

vtkStandardNewMacro(vtkFiltersParallelFlowPathsObjectFactory)

// Now create the functions to create overrides with.

  VTK_CREATE_CREATE_FUNCTION(vtkPLagrangianParticleTracker)
  VTK_CREATE_CREATE_FUNCTION(vtkPStreamTracer)
  VTK_CREATE_CREATE_FUNCTION(vtkPTemporalStreamTracer)
  VTK_CREATE_CREATE_FUNCTION(vtkPParticleTracer)
  VTK_CREATE_CREATE_FUNCTION(vtkPParticlePathFilter)
  VTK_CREATE_CREATE_FUNCTION(vtkPStreaklineFilter)

vtkFiltersParallelFlowPathsObjectFactory::vtkFiltersParallelFlowPathsObjectFactory()
{

    this->RegisterOverride("vtkLagrangianParticleTracker",
                           "vtkPLagrangianParticleTracker",
                           "Override for vtkFiltersParallelFlowPaths module", 1,
                           vtkObjectFactoryCreatevtkPLagrangianParticleTracker);
    this->RegisterOverride("vtkStreamTracer",
                           "vtkPStreamTracer",
                           "Override for vtkFiltersParallelFlowPaths module", 1,
                           vtkObjectFactoryCreatevtkPStreamTracer);
    this->RegisterOverride("vtkTemporalStreamTracer",
                           "vtkPTemporalStreamTracer",
                           "Override for vtkFiltersParallelFlowPaths module", 1,
                           vtkObjectFactoryCreatevtkPTemporalStreamTracer);
    this->RegisterOverride("vtkParticleTracer",
                           "vtkPParticleTracer",
                           "Override for vtkFiltersParallelFlowPaths module", 1,
                           vtkObjectFactoryCreatevtkPParticleTracer);
    this->RegisterOverride("vtkParticlePathFilter",
                           "vtkPParticlePathFilter",
                           "Override for vtkFiltersParallelFlowPaths module", 1,
                           vtkObjectFactoryCreatevtkPParticlePathFilter);
    this->RegisterOverride("vtkStreaklineFilter",
                           "vtkPStreaklineFilter",
                           "Override for vtkFiltersParallelFlowPaths module", 1,
                           vtkObjectFactoryCreatevtkPStreaklineFilter);
}

const char * vtkFiltersParallelFlowPathsObjectFactory::GetVTKSourceVersion()
{
  return VTK_SOURCE_VERSION;
}

void vtkFiltersParallelFlowPathsObjectFactory::PrintSelf(ostream &os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

// Registration of object factories.
static unsigned int vtkFiltersParallelFlowPathsCount;

VTKFILTERSPARALLELFLOWPATHS_EXPORT void vtkFiltersParallelFlowPaths_AutoInit_Construct()
{
  if(++vtkFiltersParallelFlowPathsCount == 1)
    {
    
    vtkFiltersParallelFlowPathsObjectFactory* factory = vtkFiltersParallelFlowPathsObjectFactory::New();
    if (factory)
      {
      // vtkObjectFactory keeps a reference to the "factory",
      vtkObjectFactory::RegisterFactory(factory);
      factory->Delete();
      }
    }
}

VTKFILTERSPARALLELFLOWPATHS_EXPORT void vtkFiltersParallelFlowPaths_AutoInit_Destruct()
{
  if(--vtkFiltersParallelFlowPathsCount == 0)
    {
    // Do not call vtkObjectFactory::UnRegisterFactory because
    // vtkObjectFactory.cxx statically unregisters all factories.
    }
}
