cmake_minimum_required(VERSION 3.12)
project(kredit C)

set(CMAKE_C_STANDARD 11)

add_library(mylibrary STATIC biblioteka.c)

add_executable(kredit glavnii.c)
target_link_libraries(kredit mylibrary)