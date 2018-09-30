cmake_minimum_required(VERSION 3.12)
project(ksenya)

set(CMAKE_C_STANDARD 99)

add_executable(ksenya main.c)

add_library(untitled10 STATIC mylibrary.c)

target_link_libraries(ksenya untitled10)
