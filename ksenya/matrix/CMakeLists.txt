cmake_minimum_required(VERSION 3.12)
project(matrix)

set(CMAKE_C_STANDARD 17)

add_executable(matrix main.cpp)

add_library(functionslib STATIC matrix.cpp)

target_link_libraries(matrix functionslib)


