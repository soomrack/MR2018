cmake_minimum_required(VERSION 3.12)
project(1)

set(CMAKE_CXX_STANDARD 17)

add_library(Matrix_lib STATIC Matrix.cpp)

add_executable(1 Matrix_main.cpp)

target_link_libraries(1 Matrix_lib)