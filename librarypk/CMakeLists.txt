cmake_minimum_required(VERSION 3.12)
project(librarypk C)

set(CMAKE_C_STANDARD 99)

add_library(mylibrary STATIC library.c note.c)

add_executable(main note.c)
target_link_libraries(main mylibrary)
