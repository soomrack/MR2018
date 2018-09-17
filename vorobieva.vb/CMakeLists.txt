cmake_minimum_required(VERSION 3.9)
project(C)

set(CMAKE_C_STANDARD 11)

add_library(mylibrary STATIC libraryvb.c)

add_executable(main notesvb.c)
target_link_libraries(main mylibrary)

