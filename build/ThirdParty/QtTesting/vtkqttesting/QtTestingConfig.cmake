
if(NOT QtTesting_EXPORTS_INCLUDED)
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/ThirdParty/QtTesting/vtkqttesting/QtTestingExports.cmake")
  set(QtTesting_EXPORTS_INCLUDED 1)
endif()

set(QtTesting_INCLUDE_DIRS "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/src/ThirdParty/QtTesting/vtkqttesting;C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/ThirdParty/QtTesting/vtkqttesting")
set(QtTesting_LIBRARY_DIR "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/ThirdParty/QtTesting/vtkqttesting")
set(QtTesting_LIBRARIES QtTesting)
include("${CMAKE_CURRENT_LIST_DIR}/QtTestingExports.cmake")
