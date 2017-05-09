set(vtkRenderingParallelLIC_LOADED 1)
set(vtkRenderingParallelLIC_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkIOLegacy;vtkParallelCore;vtkParallelMPI;vtkRenderingCore;vtkRenderingLICOpenGL2;vtkRenderingOpenGL2")
set(vtkRenderingParallelLIC_LIBRARIES "vtkRenderingParallelLIC")
set(vtkRenderingParallelLIC_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/paraview-5.3")
set(vtkRenderingParallelLIC_LIBRARY_DIRS "")
set(vtkRenderingParallelLIC_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkRenderingParallelLIC_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkRenderingParallelLICHierarchy.txt")
set(vtkRenderingParallelLIC_KIT "vtkParallel")
set(vtkRenderingParallelLIC_IMPLEMENTS "vtkRenderingLICOpenGL2")


