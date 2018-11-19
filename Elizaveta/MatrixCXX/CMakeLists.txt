cmake_minimum_required(VERSION 3.12)

project(Elizaveta CPP)

set(CMAKE_CXX_STANDARD 17)

set(ENABLETESTS TRUE)


if (ENABLETESTS)

    enable_testing()

    add_executable(LizaTestMatrix MatrixC++/Matrix2.cpp)

    add_test(NAME LizaTest03 COMMAND LizaTestMatrix)


    add_library(lizalib2 STATIC "MatrixC++/Elib2.cpp")

    target_link_libraries(LizaTestMatrix lizalib2)


endif()