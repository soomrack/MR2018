cmake_minimum_required(VERSION 3.12)
project(untitled42)

set(CMAKE_CXX_STANDARD 14)

add_executable( main.cpp )
add_library(function_matrix.cpp matrixlib.h)
target_link_libraries(Schebnevmain Schebnevlib)
