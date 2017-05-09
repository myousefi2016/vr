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
extern "C" void real_initvtkFiltersImagingPython(const char *modulename);

void initvtkFiltersImagingPython()
{
  static const char modulename[] = "vtkFiltersImagingPython";
  real_initvtkFiltersImagingPython(modulename);
}
#endif

extern void vtkPairwiseExtractHistogram2D_Init(vtkClientServerInterpreter* csi);
extern void vtkExtractHistogram2D_Init(vtkClientServerInterpreter* csi);
extern void vtkComputeHistogram2DOutliers_Init(vtkClientServerInterpreter* csi);


extern "C" void VTK_WRAP_CS_EXPORT vtkFiltersImagingCS_Initialize(
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
    PyImport_AppendInittab("vtkFiltersImagingPython", initvtkFiltersImagingPython);
    }

  csi->Load("vtkFiltersImaging");
#endif

  vtkPairwiseExtractHistogram2D_Init(csi);
  vtkExtractHistogram2D_Init(csi);
  vtkComputeHistogram2DOutliers_Init(csi);

}
