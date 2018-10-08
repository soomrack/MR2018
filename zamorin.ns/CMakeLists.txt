cmake_minimum_required(VERSION 3.9)
project(C)

set(CMAKE_C_STANDARD 11)

add_library(zamorin.nslib STATIC library_zam.c)

add_executable(zamorin.ns notes.c)
target_link_libraries(zamorin.ns zamorin.nslib)