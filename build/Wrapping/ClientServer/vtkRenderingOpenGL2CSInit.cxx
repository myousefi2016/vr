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
extern "C" void real_initvtkRenderingOpenGL2Python(const char *modulename);

void initvtkRenderingOpenGL2Python()
{
  static const char modulename[] = "vtkRenderingOpenGL2Python";
  real_initvtkRenderingOpenGL2Python(modulename);
}
#endif

extern void vtkCameraPass_Init(vtkClientServerInterpreter* csi);
extern void vtkClearRGBPass_Init(vtkClientServerInterpreter* csi);
extern void vtkClearZPass_Init(vtkClientServerInterpreter* csi);
extern void vtkCompositePolyDataMapper2_Init(vtkClientServerInterpreter* csi);
extern void vtkDefaultPass_Init(vtkClientServerInterpreter* csi);
extern void vtkDepthOfFieldPass_Init(vtkClientServerInterpreter* csi);
extern void vtkDepthImageProcessingPass_Init(vtkClientServerInterpreter* csi);
extern void vtkDepthPeelingPass_Init(vtkClientServerInterpreter* csi);
extern void vtkDualDepthPeelingPass_Init(vtkClientServerInterpreter* csi);
extern void vtkEDLShading_Init(vtkClientServerInterpreter* csi);
extern void vtkGaussianBlurPass_Init(vtkClientServerInterpreter* csi);
extern void vtkGenericOpenGLRenderWindow_Init(vtkClientServerInterpreter* csi);
extern void vtkHiddenLineRemovalPass_Init(vtkClientServerInterpreter* csi);
extern void vtkImageProcessingPass_Init(vtkClientServerInterpreter* csi);
extern void vtkLightingMapPass_Init(vtkClientServerInterpreter* csi);
extern void vtkLightsPass_Init(vtkClientServerInterpreter* csi);
extern void vtkOpaquePass_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLActor_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLBillboardTextActor3D_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLCamera_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLFXAAFilter_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLHardwareSelector_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLImageAlgorithmHelper_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLImageMapper_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLImageSliceMapper_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLLabeledContourMapper_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLLight_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLPointGaussianMapper_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLPolyDataMapper_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLPolyDataMapper2D_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLProperty_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLRenderPass_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLRenderUtilities_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLRenderWindow_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLRenderer_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLSphereMapper_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLStickMapper_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLTextActor_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLTextActor3D_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLTextMapper_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLTexture_Init(vtkClientServerInterpreter* csi);
extern void vtkOpenGLVertexBufferObjectGroup_Init(vtkClientServerInterpreter* csi);
extern void vtkOverlayPass_Init(vtkClientServerInterpreter* csi);
extern void vtkPointFillPass_Init(vtkClientServerInterpreter* csi);
extern void vtkRenderPassCollection_Init(vtkClientServerInterpreter* csi);
extern void vtkRenderStepsPass_Init(vtkClientServerInterpreter* csi);
extern void vtkSSAAPass_Init(vtkClientServerInterpreter* csi);
extern void vtkSequencePass_Init(vtkClientServerInterpreter* csi);
extern void vtkShader_Init(vtkClientServerInterpreter* csi);
extern void vtkShaderProgram_Init(vtkClientServerInterpreter* csi);
extern void vtkShadowMapBakerPass_Init(vtkClientServerInterpreter* csi);
extern void vtkShadowMapPass_Init(vtkClientServerInterpreter* csi);
extern void vtkSobelGradientMagnitudePass_Init(vtkClientServerInterpreter* csi);
extern void vtkTranslucentPass_Init(vtkClientServerInterpreter* csi);
extern void vtkValuePass_Init(vtkClientServerInterpreter* csi);
extern void vtkVolumetricPass_Init(vtkClientServerInterpreter* csi);
extern void vtkDataTransferHelper_Init(vtkClientServerInterpreter* csi);
extern void vtkDummyGPUInfoList_Init(vtkClientServerInterpreter* csi);
extern void vtkWin32RenderWindowInteractor_Init(vtkClientServerInterpreter* csi);
extern void vtkWin32OpenGLRenderWindow_Init(vtkClientServerInterpreter* csi);


extern "C" void VTK_WRAP_CS_EXPORT vtkRenderingOpenGL2CS_Initialize(
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
    PyImport_AppendInittab("vtkRenderingOpenGL2Python", initvtkRenderingOpenGL2Python);
    }

  csi->Load("vtkRenderingOpenGL2");
#endif

  vtkCameraPass_Init(csi);
  vtkClearRGBPass_Init(csi);
  vtkClearZPass_Init(csi);
  vtkCompositePolyDataMapper2_Init(csi);
  vtkDefaultPass_Init(csi);
  vtkDepthOfFieldPass_Init(csi);
  vtkDepthImageProcessingPass_Init(csi);
  vtkDepthPeelingPass_Init(csi);
  vtkDualDepthPeelingPass_Init(csi);
  vtkEDLShading_Init(csi);
  vtkGaussianBlurPass_Init(csi);
  vtkGenericOpenGLRenderWindow_Init(csi);
  vtkHiddenLineRemovalPass_Init(csi);
  vtkImageProcessingPass_Init(csi);
  vtkLightingMapPass_Init(csi);
  vtkLightsPass_Init(csi);
  vtkOpaquePass_Init(csi);
  vtkOpenGLActor_Init(csi);
  vtkOpenGLBillboardTextActor3D_Init(csi);
  vtkOpenGLCamera_Init(csi);
  vtkOpenGLFXAAFilter_Init(csi);
  vtkOpenGLHardwareSelector_Init(csi);
  vtkOpenGLImageAlgorithmHelper_Init(csi);
  vtkOpenGLImageMapper_Init(csi);
  vtkOpenGLImageSliceMapper_Init(csi);
  vtkOpenGLLabeledContourMapper_Init(csi);
  vtkOpenGLLight_Init(csi);
  vtkOpenGLPointGaussianMapper_Init(csi);
  vtkOpenGLPolyDataMapper_Init(csi);
  vtkOpenGLPolyDataMapper2D_Init(csi);
  vtkOpenGLProperty_Init(csi);
  vtkOpenGLRenderPass_Init(csi);
  vtkOpenGLRenderUtilities_Init(csi);
  vtkOpenGLRenderWindow_Init(csi);
  vtkOpenGLRenderer_Init(csi);
  vtkOpenGLSphereMapper_Init(csi);
  vtkOpenGLStickMapper_Init(csi);
  vtkOpenGLTextActor_Init(csi);
  vtkOpenGLTextActor3D_Init(csi);
  vtkOpenGLTextMapper_Init(csi);
  vtkOpenGLTexture_Init(csi);
  vtkOpenGLVertexBufferObjectGroup_Init(csi);
  vtkOverlayPass_Init(csi);
  vtkPointFillPass_Init(csi);
  vtkRenderPassCollection_Init(csi);
  vtkRenderStepsPass_Init(csi);
  vtkSSAAPass_Init(csi);
  vtkSequencePass_Init(csi);
  vtkShader_Init(csi);
  vtkShaderProgram_Init(csi);
  vtkShadowMapBakerPass_Init(csi);
  vtkShadowMapPass_Init(csi);
  vtkSobelGradientMagnitudePass_Init(csi);
  vtkTranslucentPass_Init(csi);
  vtkValuePass_Init(csi);
  vtkVolumetricPass_Init(csi);
  vtkDataTransferHelper_Init(csi);
  vtkDummyGPUInfoList_Init(csi);
  vtkWin32RenderWindowInteractor_Init(csi);
  vtkWin32OpenGLRenderWindow_Init(csi);

}
