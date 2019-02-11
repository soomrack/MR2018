cmake_minimum_required(VERSION 3.12)
project(untitled5 C)

set(CMAKE_CXX_STANDARD 17)

add_library(mariaslib matrix.h matrix.cpp)

add_executable(marias main.cpp)
target_link_libraries(marias mariaslib)



