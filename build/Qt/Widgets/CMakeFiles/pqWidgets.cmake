set(pqWidgets_LOADED 1)
set(pqWidgets_DEPENDS "vtkGUISupportQt;vtkPVServerManagerCore;vtkqttesting")
set(pqWidgets_LIBRARIES "pqWidgets")
set(pqWidgets_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/paraview-5.3")
set(pqWidgets_LIBRARY_DIRS "")
set(pqWidgets_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(pqWidgets_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/pqWidgetsHierarchy.txt")
set(pqWidgets_KIT "")
set(pqWidgets_EXCLUDE_FROM_WRAPPING 1)
include(${ParaView_CMAKE_DIR}/ParaViewQt.cmake)
  pv_find_package_qt(__pqWidgets_qt_targets REQUIRED QUIET
    QT4_COMPONENTS QtGui
    QT5_COMPONENTS Core;Gui;Widgets)
if(NOT Qt5_DIR)
  set(Qt5_DIR "C:/Qt/5.8/msvc2015_64/lib/cmake/Qt5")
endif()
find_package(Qt5 REQUIRED QUIET COMPONENTS Core Gui Widgets)


