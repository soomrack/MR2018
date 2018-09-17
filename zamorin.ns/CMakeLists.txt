cmake_minimum_required(VERSION 3.9)
project(C)

set(CMAKE_C_STANDARD 11)

add_library(mylibrary STATIC library_zam.c)

add_executable(main notes.c)
target_link_libraries(main mylibrary)