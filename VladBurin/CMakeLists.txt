cmake_minimum_required(VERSION 3.9)
project(VladBurin)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB Library.c)

add_executable(webserverVB webserverVB.c)

add_executable(mainV mainV.c)

add_library(VladBurinlib STATIC ${SOURCE_LIB})

target_link_libraries(mainV VladBurinlib)