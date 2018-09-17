cmake_minimum_required(VERSION 3.9)
project(Credit C)

set(CMAKE_C_STANDARD 11)

add_library(mylibrary STATIC library1.c)

add_executable(Credit CMakeLists.txt)
target_link_libraries(Credit mylibrary)