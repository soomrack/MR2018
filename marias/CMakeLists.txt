cmake_minimum_required(VERSION 3.12)
project(untitled5 C)

set(CMAKE_C_STANDARD 11)

add_library(mylibrary STATIC library.c)

add_executable(main notes.c)
target_link_libraries(main mylibrary)
