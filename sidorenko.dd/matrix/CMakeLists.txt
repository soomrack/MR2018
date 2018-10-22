cmake_minimum_required(VERSION 3.9)
project(sidorenko.dd)

set(CMAKE_C_STANDARD 11)

add_library(sid_matrix STATIC sid_matrix.c)

add_executable(sidorenko.dd sid_main.c)
target_link_libraries(sidorenko.dd sid_matrix)