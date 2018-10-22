cmake_minimum_required(VERSION 3.12)
project(matrix C)

set(CMAKE_C_STANDARD 11)

add_executable(matrix main.c matrix.h matrix.c matrix2.c)