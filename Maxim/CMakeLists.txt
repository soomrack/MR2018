cmake_minimum_required(VERSION 3.9)
project(untitled)

set(CMAKE_C_STANDARD 11)

add_executable(untitled mainMatr.c Matrixlib.c)

add_library(Maximlib STATIC Matrixlib.h Matrixlib.c)

target_link_libraries(untitled Maximlib)