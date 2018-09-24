cmake_minimum_required(VERSION 3.9)
project(Sibiryakov.va)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB mylibrary.c)

add_executable(maintarget maintarget.c)
add_executable(webserver webserver.c)

add_library(mylibrary STATIC ${SOURCE_LIB})

target_link_libraries(maintarget mylibrary)