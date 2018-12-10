cmake_minimum_required(VERSION 3.9)
project(C)

set(CMAKE_C_STANDARD 11)

add_executable(vorobieva evbmatrix.cpp)

add_library(libraryvb vbmatrix.cpp vbmatrix.h)

target_link_libraries(vorobieva libraryvb)