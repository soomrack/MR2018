cmake_minimum_required(VERSION 3.9)
project(Sibiryakov.va)

set(CMAKE_C_STANDARD 11)
set(ENABLETESTS TRUE)

set(SOURCE_LIB SVAlibrary.c)

add_subdirectory(MatrixMultiplication)

link_libraries(ws2_32 wsock32)

if(ENABLETESTS)
    enable_testing()

    add_executable(SibiryakovTestTrace SVAtests/test_trace.c)
    add_executable(SibiryakovTestMult SVAtests/test_multiplication.c)
    add_executable(SibiryakovTestDeterm SVAtests/test_determinant)
    add_executable(SibiryakovTestSum SVAtests/test_summatrix.c)
    add_executable(SibiryakovTestMultScalar SVAtests/test_mult_scalar.c)
    add_executable(SibiryakovTestTrans SVAtests/test_trans_matrix.c)
    add_executable(SibiryakovTestInvert SVAtests/test_invert.c)

    add_test(NAME SibiryakovTest01 COMMAND SibiryakovTestTrace)
    add_test(NAME SibiryakovTest02 COMMAND SibiryakovTestMult)
    add_test(NAME SibiryakovTest03 COMMAND SibiryakovTestDeterm)
    add_test(NAME SibiryakovTest04 COMMAND SibiryakovTestSum)
    add_test(NAME SibiryakovTest05 COMMAND SibiryakovTestMultScalar)
    add_test(NAME SibiryakovTest06 COMMAND SibiryakovTestTrans)
    add_test(NAME SibiryakovTest07 COMMAND SibiryakovTestInvert)


    add_library(SibiryakovMatrix EXCLUDE_FROM_ALL STATIC  matrix.c)
    target_link_libraries(SibiryakovTestTrace SibiryakovMatrix)
    target_link_libraries(SibiryakovTestMult SibiryakovMatrix)
    target_link_libraries(SibiryakovTestDeterm SibiryakovMatrix)
    target_link_libraries(SibiryakovTestSum SibiryakovMatrix)
    target_link_libraries(SibiryakovTestMultScalar SibiryakovMatrix)
    target_link_libraries(SibiryakovTestTrans SibiryakovMatrix)
    target_link_libraries(SibiryakovTestInvert SibiryakovMatrix)
endif()


add_executable(SVAmaintarget SVAmaintarget.c)
add_executable(SVAwebserver SVAwebserver.c)
add_executable(SVAMatrix matrix.c)

add_library(SVAlibrary STATIC ${SOURCE_LIB})

target_link_libraries(SVAmaintarget SVAlibrary)


