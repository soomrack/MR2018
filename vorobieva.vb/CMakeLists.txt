cmake_minimum_required(VERSION 3.9)
project(C)

set(CMAKE_C_STANDARD 11)

add_executable(vorobieva notesvb.c)

add_library(libraryvb STATIC libraryvb.c)

target_link_libraries(vorobieva libraryvb)
