set(vtkPVClientServerCoreCore_LOADED 1)
set(vtkPVClientServerCoreCore_DEPENDS "vtkCommonCore;vtkCommonSystem;vtkFiltersExtraction;vtkFiltersParallel;vtkIOLegacy;vtkPVCommon;vtkPVCommon;vtkPVVTKExtensionsCore;vtkParallelMPI;vtkUtilitiesWrapClientServer;vtksys")
set(vtkPVClientServerCoreCore_LIBRARIES "vtkPVClientServerCoreCore")
set(vtkPVClientServerCoreCore_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/paraview-5.3")
set(vtkPVClientServerCoreCore_LIBRARY_DIRS "")
set(vtkPVClientServerCoreCore_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkPVClientServerCoreCore_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkPVClientServerCoreCoreHierarchy.txt")
set(vtkPVClientServerCoreCore_KIT "vtkPVClientServer")

set(vtkPVClientServerCoreCore_WRAP_HINTS "${CMAKE_CURRENT_LIST_DIR}/vtkPVClientServerCoreCore_hints")

