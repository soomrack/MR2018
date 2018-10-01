cmake_minimum_required(VERSION 3.12)
project(librarypk C)

set(CMAKE_C_STANDARD 99)

add_library(librarypklib STATIC library.c)

add_executable(librarypk note.c)
target_link_libraries(librarypk librarypklib)
