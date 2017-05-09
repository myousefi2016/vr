# Install script for directory: C:/Users/vr/Desktop/ParaView-v5.3.0-VR/src/VTK/ThirdParty/netcdf/vtknetcdf

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "RuntimeLibraries" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/bin/Debug/vtkNetCDF-pv5.3.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/bin/Release/vtkNetCDF-pv5.3.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/bin/MinSizeRel/vtkNetCDF-pv5.3.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/bin/RelWithDebInfo/vtkNetCDF-pv5.3.dll")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "RuntimeLibraries" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/bin/Debug/vtkNetCDF_cxx-pv5.3.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/bin/Release/vtkNetCDF_cxx-pv5.3.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/bin/MinSizeRel/vtkNetCDF_cxx-pv5.3.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/bin/RelWithDebInfo/vtkNetCDF_cxx-pv5.3.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/VTK/ThirdParty/netcdf/vtknetcdf/liblib/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/VTK/ThirdParty/netcdf/vtknetcdf/libdispatch/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/VTK/ThirdParty/netcdf/vtknetcdf/libsrc/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/VTK/ThirdParty/netcdf/vtknetcdf/libsrc4/cmake_install.cmake")
  include("C:/Users/vr/Desktop/ParaView-v5.3.0-VR/build/VTK/ThirdParty/netcdf/vtknetcdf/cxx/cmake_install.cmake")

endif()

