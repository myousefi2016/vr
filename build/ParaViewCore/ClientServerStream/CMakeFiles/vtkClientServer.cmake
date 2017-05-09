set(vtkClientServer_LOADED 1)
set(vtkClientServer_DEPENDS "vtkCommonCore")
set(vtkClientServer_LIBRARIES "vtkClientServer")
set(vtkClientServer_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/paraview-5.3")
set(vtkClientServer_LIBRARY_DIRS "")
set(vtkClientServer_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkClientServer_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkClientServerHierarchy.txt")
set(vtkClientServer_KIT "vtkPVCore")
set(vtkClientServer_EXCLUDE_FROM_WRAPPING 1)


