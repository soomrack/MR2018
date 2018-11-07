cmake_minimum_required(VERSION 3.12)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

<<<<<<< HEAD
#include library pathes
include_directories (MatrixDir PUBLIC "${PROJECT_SOURCE_DIR}/libraries")
include_directories (GTestDir PUBLIC "../../../../googletest-master/googletest")

#add libraries's function implementation files
add_library(untitled EXCLUDE_FROM_ALL STATIC libraries/ClassMatrix.cpp)
add_library(gtestLib EXCLUDE_FROM_ALL STATIC ../../../../googletest-master/googletest/src/gtest-all.cc)

#add target with google tests
add_executable(MatrixTest
        ../../../../googletest-master/googletest/include/gtest/gtest.h
        ../../../../googletest-master/googletest/src/gtest-all.cc
        tests/src/basic_check.cpp
        ${PROJECT_SOURCE_DIR}/libraries/ClassMatrix.h)
#add libraries to target
target_link_libraries(MatrixTest gtestLib)
target_link_libraries(MatrixTest untitled)

#add target with working program
add_executable(runmyapp tests/src/main.cpp
        ${PROJECT_SOURCE_DIR}/libraries/ClassMatrix.h)
#add libraries to target
target_link_libraries (runmyapp untitled)
=======
add_library(untitled library.cpp library.h)
>>>>>>> 33a26d8985261ae7bf72b981c6f43d46ceae23be
