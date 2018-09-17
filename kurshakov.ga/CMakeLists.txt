cmake_minimum_required(VERSION 3.9)
project(C)

set(CMAKE_C_STANDARD 11)

add_library(kurshakovlib STATIC kurshakov_lib.c)

add_executable(kurshakovmain kurshakov_main.c)

target_link_libraries(kurshakovmain mylib)
message("Отлично поработали!")