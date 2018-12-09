cmake_minimum_required(VERSION 3.12)
project(Matrix_library)

set(CMAKE_CXX_STANDARD 17)

add_executable(Matrix_library main.cpp)

add_library(matrix_cpp STATIC matrix.cpp)

target_link_libraries(Matrix_library matrix_cpp)