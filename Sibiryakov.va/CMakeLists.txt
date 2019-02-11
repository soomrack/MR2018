cmake_minimum_required(VERSION 3.9)
project(Sibiryakov.va)

set(CMAKE_C_STANDARD 11)
set(ENABLETESTS TRUE)

set(SOURCE_LIB MatrixOperationC/SVAlibrary.c)

add_subdirectory(MatrixOperationCpp)

add_subdirectory(MatrixOperationC)

link_libraries(ws2_32 wsock32)


