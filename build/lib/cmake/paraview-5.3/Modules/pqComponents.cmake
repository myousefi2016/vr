set(pqComponents_LOADED 1)
set(pqComponents_DEPENDS "pqCore;vtkChartsCore;vtkIOImage;vtkPVAnimation;vtkPVServerManagerDefault;vtkPVServerManagerRendering;vtkjsoncpp;vtksys")
set(pqComponents_LIBRARIES "pqComponents")
set(pqComponents_INCLUDE_DIRS "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Qt/Components/;C:/Users/vr/Desktop/ParaView-v5.3.0-VR/src/Qt/Components/")
set(pqComponents_LIBRARY_DIRS "")
set(pqComponents_RUNTIME_LIBRARY_DIRS "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/bin")
set(pqComponents_WRAP_HIERARCHY_FILE "")
set(pqComponents_KIT "")
set(pqComponents_EXCLUDE_FROM_WRAPPING 1)
include(${ParaView_CMAKE_DIR}/ParaViewQt.cmake)
  pv_find_package_qt(__pqComponents_qt_targets REQUIRED QUIET
    QT4_COMPONENTS QtNetwork
    QT5_COMPONENTS Widgets Network)

