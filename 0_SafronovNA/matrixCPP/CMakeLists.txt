cmake_minimum_required(VERSION 3.12)
project(matrix)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp matrix.h matrix.cpp)