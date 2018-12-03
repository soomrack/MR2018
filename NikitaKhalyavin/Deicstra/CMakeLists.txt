cmake_minimum_required(VERSION 3.9)
project(test)

set(CMAKE_CPP_STANDARD 14)



add_executable(NKhDeicstra NKhDeicstra.cpp)
add_library(NKhDeicstraLib NKhDeicstraLib.cpp NKhDeicstraLib.h)
add_library(NKhMatrixLibFD ../CPPtest/MatrLib.cpp ../CPPtest/MatrLib.h)

target_link_libraries(NKhDeicstra NKhDeicstraLib NKhMatrixLibFD)
