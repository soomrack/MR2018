cmake_minimum_required(VERSION 3.9)
project(C)

link_libraries(ws2_32 wsock32)
set(CMAKE_C_STANDARD 11)

add_executable(kurshakovmain webserverkurshakov.c)