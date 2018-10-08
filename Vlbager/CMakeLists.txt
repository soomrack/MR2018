cmake_minimum_required(VERSION 3.9)
project(Vlbager)

set(CMAKE_C_STANDARD 11)

add_executable(Vlbager webserver.c)
add_executable(VlbagerTest test.c)

add_library(Vlbagerlib EXCLUDE_FROM_ALL STATIC  Testlib.c)

target_link_libraries(VlbagerTest Vlbagerlib)


