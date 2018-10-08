# Install script for directory: C:/Users/prog/CLionProjects/MR2018

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/MR2018")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/5555/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/AndreyCH/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/Elizaveta/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/komarov.ae/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/ksenya/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/kurshakov.ga/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/librarypk/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/marias/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/Maxim/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/natalia/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/Nenahov/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/NikitaKhalyavin/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/Schebnev/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/shayahmetov.rh/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/Sibiryakov.va/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/VladBurin/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/Vlbager/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/VolkAl/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/vorobieva.vb/cmake_install.cmake")
  include("C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/zamorin.ns/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/prog/CLionProjects/MR2018/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
