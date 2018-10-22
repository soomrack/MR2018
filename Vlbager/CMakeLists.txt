cmake_minimum_required(VERSION 3.9)
project(Vlbager)

set(CMAKE_C_STANDARD 11)

set(BUILDWEBSERVER FALSE)

if(BUILDWEBSERBER)

    add_executable(VlbagerWebserver webserver.c)

endif()

set(ENABLETESTS TRUE)

if(ENABLETESTS)
    enable_testing()

    add_executable(VlbagerMatrixDeterminantTest matrixtests/determinant.c)
    add_executable(VlbagerMatrixTraceTest matrixtests/trace.c)
    add_executable(VlbagerMatrixOneTest matrixtests/one.c)
    add_executable(VlbagerMatrixZeroTest matrixtests/zero.c)
    add_executable(VlbagerMatrixSumTest matrixtests/sum.c)

    add_test(NAME DeterminantTest COMMAND VlbagerMatrixDeterminantTest)
    add_test(NAME TraceTest COMMAND VlbagerMatrixTraceTest)
    add_test(NAME OneTest COMMAND VlbagerMatrixOneTest)
    add_test(NAME ZeroTest COMMAND VlbagerMatrixZeroTest)
    add_test(NAME SumTest COMMAND VlbagerMatrixSumTest)

    add_library(VlbagerMatrixLib EXCLUDE_FROM_ALL STATIC matrix.c)

    target_link_libraries(VlbagerMatrixDeterminantTest VlbagerMatrixLib)
    target_link_libraries(VlbagerMatrixTraceTest VlbagerMatrixLib)
    target_link_libraries(VlbagerMatrixOneTest VlbagerMatrixLib)
    target_link_libraries(VlbagerMatrixZeroTest VlbagerMatrixLib)
    target_link_libraries(VlbagerMatrixSumTest VlbagerMatrixLib)

endif()
