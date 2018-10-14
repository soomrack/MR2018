cmake_minimum_required(VERSION 3.12)
project(test C)

set(CMAKE_C_STANDARD 99)

set(ENABLETESTS TRUE)

add_executable(testing main.c)

if(ENABLETESTS)
    enable_testing()

    add_executable(natalia mytests.c)

    add_test(NAME mytests COMMAND natalia)

    add_library(natalialib EXCLUDE_FROM_ALL STATIC library.c)

    target_link_libraries(natalia natalialib)
    target_link_libraries(testing natalialib)

endif()