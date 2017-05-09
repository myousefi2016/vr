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
extern "C" void real_initvtkFiltersParallelMPIPython(const char *modulename);

void initvtkFiltersParallelMPIPython()
{
  static const char modulename[] = "vtkFiltersParallelMPIPython";
  real_initvtkFiltersParallelMPIPython(modulename);
}
#endif

extern void vtkDistributedDataFilter_Init(vtkClientServerInterpreter* csi);
extern void vtkPExtractGrid_Init(vtkClientServerInterpreter* csi);
extern void vtkPExtractRectilinearGrid_Init(vtkClientServerInterpreter* csi);
extern void vtkPExtractVOI_Init(vtkClientServerInterpreter* csi);
extern void vtkStructuredImplicitConnectivity_Init(vtkClientServerInterpreter* csi);


extern "C" void VTK_WRAP_CS_EXPORT vtkFiltersParallelMPICS_Initialize(
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
    PyImport_AppendInittab("vtkFiltersParallelMPIPython", initvtkFiltersParallelMPIPython);
    }

  csi->Load("vtkFiltersParallelMPI");
#endif

  vtkDistributedDataFilter_Init(csi);
  vtkPExtractGrid_Init(csi);
  vtkPExtractRectilinearGrid_Init(csi);
  vtkPExtractVOI_Init(csi);
  vtkStructuredImplicitConnectivity_Init(csi);

}
