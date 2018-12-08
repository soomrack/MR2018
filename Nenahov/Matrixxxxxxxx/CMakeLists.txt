# cmake_minimum_required(VERSION <specify CMake version here>)
project(matrix C)

set(CMAKE_C_STANDARD 11)

add_executable(matrix main.c Matrixbiblio.c Matrixbiblio.h Matrixcpp.cpp Matrixcpp.h matrixcppmain.cpp)