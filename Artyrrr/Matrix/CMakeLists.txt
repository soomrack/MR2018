cmake_minimum_required(VERSION 3.9)
project(Matrix)

set(CMAKE_C_STANDARD 11)

add_library(ArtyrrrMatrixLib matrixlib.h Determinant.c)

add_executable(Matrix_Solve Matrix_Solve.c)

target_link_libraries(Matrix_Solve ArtyrrrMatrixLib)