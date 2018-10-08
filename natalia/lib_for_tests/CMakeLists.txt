cmake_minimum_required(VERSION 3.12)
project(lib_for_tests C)

set(CMAKE_C_STANDARD 99)

add_library(lib_for_tests library.c library.h)
target_link_libraries(nata lib_for_tests library.c)
include(CTest)
if(BUILD_TESTING)
    enable_testing()
    add_test(NAME mytests COMMAND library.c)
    add_executable(tests library.c)
endif()