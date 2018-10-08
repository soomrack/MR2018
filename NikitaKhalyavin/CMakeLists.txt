cmake_minimum_required(VERSION 3.9)
project(test)

set(CMAKE_C_STANDARD 11)

enable_testing()

add_subdirectory(win_webserver)
add_subdirectory(CMakeTestLib)
add_subdirectory(CMakeTest)

add_test(test1 NKhTestMatrix)

