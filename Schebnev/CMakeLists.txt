cmake_minimum_required(VERSION 3.9)
project(Credit C)

set(CMAKE_C_STANDARD 11)

add_library(Schebnevlib STATIC lybrary1.c)

add_executable(Credit main.c)
target_link_libraries(Credit Schebnevlib)