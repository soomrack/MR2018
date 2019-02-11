cmake_minimum_required(VERSION 3.9)
project(test)

set(CMAKE_C_STANDARD 11)


add_executable(NKhfind NKhMainFind.cpp)
add_library(NKhfindArray findInArray.cpp findInArray.h)
add_library(NKhsortArray ArraySort.cpp ArraySort.h)

target_link_libraries(NKhfind NKhfindArray NKhsortArray)
