set(pqApplicationComponents_LOADED 1)
set(pqApplicationComponents_DEPENDS "pqComponents;vtkGUISupportQt;vtkPVAnimation;vtkPVServerManagerDefault;vtkPVServerManagerRendering;vtkUtilitiesLegacyColorMapXMLToJSON;vtkjsoncpp;vtksys")
set(pqApplicationComponents_LIBRARIES "pqApplicationComponents")
set(pqApplicationComponents_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/paraview-5.3")
set(pqApplicationComponents_LIBRARY_DIRS "")
set(pqApplicationComponents_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(pqApplicationComponents_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/pqApplicationComponentsHierarchy.txt")
set(pqApplicationComponents_KIT "")
set(pqApplicationComponents_EXCLUDE_FROM_WRAPPING 1)
include(${ParaView_CMAKE_DIR}/ParaViewQt.cmake)
    pv_find_package_qt(__pqApplicationComponents_qt_targets REQUIRED QUIET
      QT4_COMPONENTS QtHelp
      QT5_COMPONENTS Widgets Help)

