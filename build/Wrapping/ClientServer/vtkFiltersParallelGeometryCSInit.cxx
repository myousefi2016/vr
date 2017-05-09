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
extern "C" void real_initvtkFiltersParallelGeometryPython(const char *modulename);

void initvtkFiltersParallelGeometryPython()
{
  static const char modulename[] = "vtkFiltersParallelGeometryPython";
  real_initvtkFiltersParallelGeometryPython(modulename);
}
#endif

extern void vtkPDataSetGhostGenerator_Init(vtkClientServerInterpreter* csi);
extern void vtkPStructuredGridConnectivity_Init(vtkClientServerInterpreter* csi);
extern void vtkPStructuredGridGhostDataGenerator_Init(vtkClientServerInterpreter* csi);
extern void vtkPUniformGridGhostDataGenerator_Init(vtkClientServerInterpreter* csi);
extern void vtkPUnstructuredGridGhostCellsGenerator_Init(vtkClientServerInterpreter* csi);
extern void vtkPUnstructuredGridConnectivity_Init(vtkClientServerInterpreter* csi);
extern void vtkPUnstructuredGridGhostDataGenerator_Init(vtkClientServerInterpreter* csi);


extern "C" void VTK_WRAP_CS_EXPORT vtkFiltersParallelGeometryCS_Initialize(
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
    PyImport_AppendInittab("vtkFiltersParallelGeometryPython", initvtkFiltersParallelGeometryPython);
    }

  csi->Load("vtkFiltersParallelGeometry");
#endif

  vtkPDataSetGhostGenerator_Init(csi);
  vtkPStructuredGridConnectivity_Init(csi);
  vtkPStructuredGridGhostDataGenerator_Init(csi);
  vtkPUniformGridGhostDataGenerator_Init(csi);
  vtkPUnstructuredGridGhostCellsGenerator_Init(csi);
  vtkPUnstructuredGridConnectivity_Init(csi);
  vtkPUnstructuredGridGhostDataGenerator_Init(csi);

}
