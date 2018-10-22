cmake_minimum_required(VERSION 3.9)
project(test)

set(CMAKE_C_STANDARD 11)



add_executable(ArtyrrrMatrix Determinant.c)
add_library(ArtyrrrMatrixLib matrix.h MatrixLib.c)

target_link_libraries(ArtyrrrMatrixLib NKhMatrixLib)