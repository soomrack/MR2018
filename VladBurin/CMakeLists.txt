cmake_minimum_required(VERSION 3.9)
project(VladBurin)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB Library.c)

add_executable(main main.c)

add_library(Library STATIC ${SOURCE_LIB})

target_link_libraries(main Library)