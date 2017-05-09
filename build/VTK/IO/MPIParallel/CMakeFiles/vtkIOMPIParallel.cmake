set(vtkIOMPIParallel_LOADED 1)
set(vtkIOMPIParallel_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkCommonMisc;vtkIOGeometry;vtkIOGeometry;vtkIOParallel;vtkIOParallel;vtkParallelMPI;vtksys")
set(vtkIOMPIParallel_LIBRARIES "vtkIOMPIParallel")
set(vtkIOMPIParallel_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/paraview-5.3")
set(vtkIOMPIParallel_LIBRARY_DIRS "")
set(vtkIOMPIParallel_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkIOMPIParallel_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkIOMPIParallelHierarchy.txt")
set(vtkIOMPIParallel_KIT "vtkParallel")
set(vtkIOMPIParallel_IMPLEMENTS "vtkIOGeometry;vtkIOParallel")


