# Install script for directory: C:/Users/vr/Desktop/ParaView-v5.3.0-VR/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/ParaView")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/bin/.plugins")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/VTK/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Wrapping/ClientServer/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Wrapping/Python/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/AcceleratedAlgorithms/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/AnalyzeNIfTIReaderWriter/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/ArrowGlyph/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/EyeDomeLighting/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/GMVReader/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/GeodesicMeasurementPlugin/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/H5PartReader/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/LagrangianParticleTracker/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/Moments/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/NonOrthogonalSource/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/SLACTools/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/SierraPlotTools/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/StreamLinesRepresentation/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/StreamingParticles/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/SurfaceLIC/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/TestPlugin/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/ThickenLayeredCells/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Plugins/VR/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/CommandLineExecutables/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/Applications/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
