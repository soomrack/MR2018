cmake_minimum_required(VERSION 3.12)
project(Elizaveta C)

set(CMAKE_C_STANDARD 99)

set(ENABLETESTS TRUE)

link_libraries(Ws2_32 wsock32)

add_executable(lizaweb webserver.c)


if (ENABLETESTS)

    enable_testing()

    add_executable(LizaTestMultiply tests/testmultiply.c)
    add_executable(LizaTestTrace tests/new.c)


    add_test(NAME LizaTest01 COMMAND LizaTestMultiply)
    add_test(NAME LizaTest02 COMMAND LizaTestTrace)


    add_library(lizalib STATIC Elib.c)

    target_link_libraries(LizaTestMultiply lizalib)
    target_link_libraries(LizaTestTrace lizalib)

endif()