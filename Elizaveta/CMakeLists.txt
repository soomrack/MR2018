cmake_minimum_required(VERSION 3.12)
project(Elizaveta C CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

set(ENABLETESTS TRUE)

link_libraries(Ws2_32 wsock32)

add_executable(lizaweb webserver.c)



if (ENABLETESTS)

    enable_testing()

    add_executable(LizaTestMultiply MatrixCL/testmultiply.c)
    add_executable(LizaTestTrace MatrixCL/MatrixL.c)
    add_executable(LizaTestMatrix MatrixCXX/Matrix2.cpp MatrixCXX/Elib2.h)


    add_test(NAME LizaTest01 COMMAND LizaTestMultiply)
    add_test(NAME LizaTest02 COMMAND LizaTestTrace)
    add_test(NAME LizaTest03 COMMAND LizaTestMatrix)

    add_library(lizalib STATIC "MatrixCL/Elib.c")
    add_library(lizalib2 STATIC "MatrixCXX/Elib2.cpp")

    target_link_libraries(LizaTestMultiply lizalib)
    target_link_libraries(LizaTestTrace lizalib)
    target_link_libraries(LizaTestMatrix lizalib2)

    add_executable(algorithms algorithms/main.cpp algorithms/lib.cpp algorithms/lib.h)

endif()
