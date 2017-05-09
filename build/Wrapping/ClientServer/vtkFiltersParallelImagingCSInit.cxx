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
extern "C" void real_initvtkFiltersParallelImagingPython(const char *modulename);

void initvtkFiltersParallelImagingPython()
{
  static const char modulename[] = "vtkFiltersParallelImagingPython";
  real_initvtkFiltersParallelImagingPython(modulename);
}
#endif

extern void vtkPComputeHistogram2DOutliers_Init(vtkClientServerInterpreter* csi);
extern void vtkPExtractHistogram2D_Init(vtkClientServerInterpreter* csi);
extern void vtkPPairwiseExtractHistogram2D_Init(vtkClientServerInterpreter* csi);
extern void vtkExtractPiece_Init(vtkClientServerInterpreter* csi);
extern void vtkMemoryLimitImageDataStreamer_Init(vtkClientServerInterpreter* csi);
extern void vtkTransmitImageDataPiece_Init(vtkClientServerInterpreter* csi);


extern "C" void VTK_WRAP_CS_EXPORT vtkFiltersParallelImagingCS_Initialize(
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
    PyImport_AppendInittab("vtkFiltersParallelImagingPython", initvtkFiltersParallelImagingPython);
    }

  csi->Load("vtkFiltersParallelImaging");
#endif

  vtkPComputeHistogram2DOutliers_Init(csi);
  vtkPExtractHistogram2D_Init(csi);
  vtkPPairwiseExtractHistogram2D_Init(csi);
  vtkExtractPiece_Init(csi);
  vtkMemoryLimitImageDataStreamer_Init(csi);
  vtkTransmitImageDataPiece_Init(csi);

}
