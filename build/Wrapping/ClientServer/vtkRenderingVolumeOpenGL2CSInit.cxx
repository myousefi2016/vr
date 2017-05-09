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
extern "C" void real_initvtkRenderingVolumeOpenGL2Python(const char *modulename);

void initvtkRenderingVolumeOpenGL2Python()
{
  static const char modulename[] = "vtkRenderingVolumeOpenGL2Python";
  real_initvtkRenderingVolumeOpenGL2Python(modulename);
}
#endif

extern void vtkMultiBlockVolumeMapper_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLGPUVolumeRayCastMapper_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLProjectedTetrahedraMapper_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLRayCastImageDisplayHelper_Init(vtkClientServerInterpreter* csi);
extern void vtkSmartVolumeMapper_Init(vtkClientServerInterpreter* csi);


extern "C" void VTK_WRAP_CS_EXPORT vtkRenderingVolumeOpenGL2CS_Initialize(
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
    PyImport_AppendInittab("vtkRenderingVolumeOpenGL2Python", initvtkRenderingVolumeOpenGL2Python);
    }

  csi->Load("vtkRenderingVolumeOpenGL2");
#endif

  vtkMultiBlockVolumeMapper_Init(csi);
  vtkOpenGLGPUVolumeRayCastMapper_Init(csi);
  vtkOpenGLProjectedTetrahedraMapper_Init(csi);
  vtkOpenGLRayCastImageDisplayHelper_Init(csi);
  vtkSmartVolumeMapper_Init(csi);

}
