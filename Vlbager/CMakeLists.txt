cmake_minimum_required(VERSION 3.9)
project(Vlbager)

set(CMAKE_C_STANDARD 11)

set(ENABLETESTS TRUE)

add_executable(VlbagerWebserver webserver.c)

if(ENABLETESTS)
    enable_testing()

    add_executable(VlbagerPseudoTest tests/pseudotest1.c)
    add_executable(VlbagerSimpleTest tests/simpletest.c)
    add_executable(VlbagerTransposePseudoTest tests/pseudotest2.c)

    add_test(NAME VlbagerTest01 COMMAND VlbagerSimpleTest)
    add_test(NAME VlbagerTest02 COMMAND VlbagerPseudoTest)
    add_test(NAME VlbagerTest03 COMMAND VlbagerTransposePseudoTest)

    add_library(Vlbagerlib EXCLUDE_FROM_ALL STATIC  Testlib.c)

    target_link_libraries(VlbagerSimpleTest Vlbagerlib)
    target_link_libraries(VlbagerPseudoTest Vlbagerlib)
    target_link_libraries(VlbagerTransposePseudoTest Vlbagerlib)
endif()







