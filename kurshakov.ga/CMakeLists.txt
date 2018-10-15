cmake_minimum_required(VERSION 3.9)
project(C)

link_libraries(ws2_32 wsock32)
set(CMAKE_C_STANDARD 11)

add_executable(kurshakovmain kurshakov_main.c)

add_library(kurshakovlib matrixkga.c)

target_link_libraries(kurshakovmain kurshakovlib)