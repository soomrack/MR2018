cmake_minimum_required(VERSION 3.12)
project(untitled C)

set(CMAKE_C_STANDARD 11)
link_libraries(Ws2_32 wsock32)
add_executable(untitled webserver.c ../Matrixlib.h)