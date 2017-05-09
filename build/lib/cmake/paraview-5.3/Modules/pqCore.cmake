set(pqCore_LOADED 1)
set(pqCore_DEPENDS "pqWidgets;vtkGUISupportQt;vtkPVAnimation;vtkPVClientServerCoreDefault;vtkPVServerManagerApplication;vtkPVServerManagerDefault;vtkTestingRendering;vtksys")
set(pqCore_LIBRARIES "pqCore")
set(pqCore_INCLUDE_DIRS "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Qt/Core/;C:/Users/vr/Desktop/ParaView-v5.3.0-VR/src/Qt/Core/")
set(pqCore_LIBRARY_DIRS "")
set(pqCore_RUNTIME_LIBRARY_DIRS "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/bin")
set(pqCore_WRAP_HIERARCHY_FILE "")
set(pqCore_KIT "")
set(pqCore_EXCLUDE_FROM_WRAPPING 1)
include(${ParaView_CMAKE_DIR}/ParaViewQt.cmake)
    pv_find_package_qt(__pqCore_qt_targets REQUIRED QUIET
      QT4_COMPONENTS QtHelp
      QT5_COMPONENTS Help)

