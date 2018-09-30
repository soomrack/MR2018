cmake_minimum_required(VERSION 3.9)
project(Sibiryakov.va)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB SVAlibrary.c)

link_libraries(ws2_32 wsock32)

add_executable(SVAmaintarget SVAmaintarget.c)
add_executable(SVAwebserver SVAwebserver.c)

add_library(SVAlibrary STATIC ${SOURCE_LIB})

target_link_libraries(SVAmaintarget SVAlibrary)