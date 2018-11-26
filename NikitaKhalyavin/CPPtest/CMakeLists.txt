cmake_minimum_required(VERSION 3.9)
project(test)

set(CMAKE_CPP_STANDARD 14)

enable_testing()

add_executable(NKhInvertTest tests/testInvert.cpp)

add_test(NAME NKhInvert COMMAND NKhInvertTest)


add_executable(NKhCPPtest testex.cpp)
add_library(NKhMatrLib MatrLib.cpp MatrLib.h)


target_link_libraries(NKhCPPtest NKhMatrLib)
target_link_libraries(NKhInvertTest NKhMatrLib)