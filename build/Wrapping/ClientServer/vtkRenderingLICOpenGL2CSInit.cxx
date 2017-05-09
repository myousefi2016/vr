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
extern "C" void real_initvtkRenderingLICOpenGL2Python(const char *modulename);

void initvtkRenderingLICOpenGL2Python()
{
  static const char modulename[] = "vtkRenderingLICOpenGL2Python";
  real_initvtkRenderingLICOpenGL2Python(modulename);
}
#endif

extern void vtkImageDataLIC2D_Init(vtkClientServerInterpreter* csi);
extern void vtkLineIntegralConvolution2D_Init(vtkClientServerInterpreter* csi);
extern void vtkStructuredGridLIC2D_Init(vtkClientServerInterpreter* csi);
extern void vtkSurfaceLICInterface_Init(vtkClientServerInterpreter* csi);
extern void vtkSurfaceLICMapper_Init(vtkClientServerInterpreter* csi);
extern void vtkCompositeSurfaceLICMapper_Init(vtkClientServerInterpreter* csi);


extern "C" void VTK_WRAP_CS_EXPORT vtkRenderingLICOpenGL2CS_Initialize(
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
    PyImport_AppendInittab("vtkRenderingLICOpenGL2Python", initvtkRenderingLICOpenGL2Python);
    }

  csi->Load("vtkRenderingLICOpenGL2");
#endif

  vtkImageDataLIC2D_Init(csi);
  vtkLineIntegralConvolution2D_Init(csi);
  vtkStructuredGridLIC2D_Init(csi);
  vtkSurfaceLICInterface_Init(csi);
  vtkSurfaceLICMapper_Init(csi);
  vtkCompositeSurfaceLICMapper_Init(csi);

}
