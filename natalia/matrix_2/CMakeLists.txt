cmake_minimum_required(VERSION 3.12)
project(matrix_2 C)

add_subdirectory(src)
add_subdirectory(test_matrix)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)



add_executable(matrix_2 src/main.c)


