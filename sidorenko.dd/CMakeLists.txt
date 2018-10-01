cmake_minimum_required(VERSION 3.12)

project(lesson_4 C)

set(CMAKE_C_STANDARD 99)

link_libraries(Ws2_32 wsock32)

add_executable(lesson_4 sd_main.c)

