cmake_minimum_required(VERSION 3.9)
project(test)

set(CMAKE_C_STANDARD 11)



add_executable(NKhNewProg NKhNewProg.c)
add_library(NKhMatrixLib ../../matrix.h MatrixLib.c)

target_link_libraries(NKhNewProg NKhMatrixLib)
