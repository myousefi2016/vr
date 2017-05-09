set(vtkParallelMPI_LOADED 1)
set(vtkParallelMPI_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkParallelCore")
set(vtkParallelMPI_LIBRARIES "vtkParallelMPI")
set(vtkParallelMPI_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/paraview-5.3;C:/Program Files (x86)/Microsoft SDKs/MPI/include")
set(vtkParallelMPI_LIBRARY_DIRS "")
set(vtkParallelMPI_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkParallelMPI_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkParallelMPIHierarchy.txt")
set(vtkParallelMPI_KIT "vtkParallel")


