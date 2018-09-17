cmake_minimum_required(VERSION 3.9)
project(C)

set(CMAKE_C_STANDARD 11)

add_library(mylibrary STATIC kurshakov.ga/kurshakov_lib.c kurshakov.ga/kurshakov_lib.h)

add_executable(main kurshakov.ga/kurshakov_main.c)
target_link_libraries(main mylibrary)

