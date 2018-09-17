cmake_minimum_required(VERSION 3.9)
project(C)

set(CMAKE_C_STANDARD 11)

add_library(mylibrary STATIC librain.c)

add_executable(main main.c)
target_link_libraries(main mylibrary)

