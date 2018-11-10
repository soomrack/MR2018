cmake_minimum_required(VERSION 3.9)



set(CMAKE_C_STANDARD 11)

add_executable(MatrixOperations MatrixOperations.c)
add_library(MatrixLibVB MatrixOperations.c)

target_link_libraries(MatrixOperations m)