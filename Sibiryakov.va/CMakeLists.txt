cmake_minimum_required(VERSION 3.9)
project(Sibiryakov.va)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB mylibrary.c)

add_executable(main main.c)

add_library(newlibrary STATIC ${SOURCE_LIB})

target_link_libraries(main mylibrary)