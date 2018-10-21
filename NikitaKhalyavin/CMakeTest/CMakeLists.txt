cmake_minimum_required(VERSION 3.9)
project(test)

set(CMAKE_C_STANDARD 11)



add_executable(NKhTestMatrix NKhTestMatrix.c)
target_link_libraries(NKhTestMatrix NKhLibMatrix)

