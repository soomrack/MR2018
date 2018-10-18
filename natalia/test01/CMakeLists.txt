cmake_minimum_required(VERSION 3.12)
project(test01)

set(CMAKE_CXX_STANDARD 14)

    enable_testing()

    add_executable(Test01 mytests.c)

    add_test(NAME mytest01 COMMAND Test01)

    add_library(Natalialib STATIC  library.c)

    target_link_libraries(Test01 Natalialib)
