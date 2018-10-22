cmake_minimum_required(VERSION 3.9)
project(Artyrrr)

set(CMAKE_C_STANDARD 11)

add_library(Artyrrrlib STATIC mylibrary.c)

add_executable(Artyrrr main.c)

target_link_libraries(Artyrrr Artyrrrlib)