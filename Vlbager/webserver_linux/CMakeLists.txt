cmake_minimum_required(VERSION 3.9)
project(VlbagerWebserver_linux)

set(CMAKE_C_STANDARD 11)

set(BUILDWEBSERVER FALSE)

if(BUILDWEBSERBER)

    add_executable(VlbagerWebserver webserver.c)

endif()