cmake_minimum_required(VERSION 3.9)
project(VladBurin)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB Library.c mainVB2.c)

add_executable(webserverVB webserverVB.c)

add_executable(mainV mainV.c)
add_executable(mainVB2 mainVB2.c)


add_library(VladBurinlib STATIC ${SOURCE_LIB})

target_link_libraries(mainV VladBurinlib)
target_link_libraries(mainVB2 VladBurinlib)