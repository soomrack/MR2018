cmake_minimum_required(VERSION 3.12)
project(cppproverka)

#cmake_minimum_required(VERSION 3.9)
#project(C)

#set(CMAKE_C_STANDARD 11)

add_executable(matrix main.cpp)

add_library(functionslib STATIC functions.cpp)

target_link_libraries(matrix functionslib)