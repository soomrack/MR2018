cmake_minimum_required(VERSION 3.12)
project(untitled10 C)

set(CMAKE_C_STANDARD 99)

add_library(untitled10 ksenya.c ksenya.h)

add_executable(main ksenya.c)
