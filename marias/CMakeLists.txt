cmake_minimum_required(VERSION 3.12)
project(untitled5 C)

set(CMAKE_C_STANDARD 11)

add_library(mariaslib STATIC library.c)

add_executable(marias notes.c)
target_link_libraries(marias mariaslib)
