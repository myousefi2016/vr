set(vtkPVAnimation_LOADED 1)
set(vtkPVAnimation_DEPENDS "vtkIOMovie;vtkPVServerManagerCore;vtkPVServerManagerDefault;vtkPVVTKExtensionsDefault;vtksys")
set(vtkPVAnimation_LIBRARIES "vtkPVAnimation")
set(vtkPVAnimation_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/paraview-5.3")
set(vtkPVAnimation_LIBRARY_DIRS "")
set(vtkPVAnimation_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkPVAnimation_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkPVAnimationHierarchy.txt")
set(vtkPVAnimation_KIT "")


