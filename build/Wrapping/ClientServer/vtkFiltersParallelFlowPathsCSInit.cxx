/* #undef PARAVIEW_USE_UNIFIED_BINDINGS */
#define NO_PYTHON_BINDINGS_AVAILABLE
#ifdef NO_PYTHON_BINDINGS_AVAILABLE
#undef PARAVIEW_USE_UNIFIED_BINDINGS
#endif
#ifdef PARAVIEW_USE_UNIFIED_BINDINGS
#include "vtkPython.h"
#include "vtkPythonInterpreter.h"
#endif

#include "vtkClientServerInterpreter.h"

#ifndef PARAVIEW_BUILD_SHARED_LIBS
#define PARAVIEW_BUILD_SHARED_LIBS
#endif
#if defined(PARAVIEW_BUILD_SHARED_LIBS) && defined(_WIN32)
# define VTK_WRAP_CS_EXPORT __declspec(dllexport)
#else
# define VTK_WRAP_CS_EXPORT
#endif

#ifdef PARAVIEW_USE_UNIFIED_BINDINGS
extern "C" void real_initvtkFiltersParallelFlowPathsPython(const char *modulename);

void initvtkFiltersParallelFlowPathsPython()
{
  static const char modulename[] = "vtkFiltersParallelFlowPathsPython";
  real_initvtkFiltersParallelFlowPathsPython(modulename);
}
#endif

extern void vtkPLagrangianParticleTracker_Init(vtkClientServerInterpreter* csi);
extern void vtkPTemporalStreamTracer_Init(vtkClientServerInterpreter* csi);
extern void vtkPStreamTracer_Init(vtkClientServerInterpreter* csi);
extern void vtkPParticleTracer_Init(vtkClientServerInterpreter* csi);
extern void vtkPParticlePathFilter_Init(vtkClientServerInterpreter* csi);
extern void vtkPStreaklineFilter_Init(vtkClientServerInterpreter* csi);
extern void vtkPParticleTracerBase_Init(vtkClientServerInterpreter* csi);


extern "C" void VTK_WRAP_CS_EXPORT vtkFiltersParallelFlowPathsCS_Initialize(
  vtkClientServerInterpreter *csi)
{
#ifdef PARAVIEW_USE_UNIFIED_BINDINGS
  if (!vtkPythonInterpreter::IsInitialized())
    {
    vtkPythonInterpreter::Initialize();
    }

  static bool initialized = false;

  if (!initialized)
    {
    initialized = true;
    PyImport_AppendInittab("vtkFiltersParallelFlowPathsPython", initvtkFiltersParallelFlowPathsPython);
    }

  csi->Load("vtkFiltersParallelFlowPaths");
#endif

  vtkPLagrangianParticleTracker_Init(csi);
  vtkPTemporalStreamTracer_Init(csi);
  vtkPStreamTracer_Init(csi);
  vtkPParticleTracer_Init(csi);
  vtkPParticlePathFilter_Init(csi);
  vtkPStreaklineFilter_Init(csi);
  vtkPParticleTracerBase_Init(csi);

}
