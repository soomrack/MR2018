cmake_minimum_required(VERSION 3.12)
project(NikitaKhalyavin)

<<<<<<< HEAD
enable_testing()

add_subdirectory(win_webserver)
add_subdirectory(CMakeTestLib)
add_subdirectory(CMakeTest)
add_subdirectory(NewProg)
add_subdirectory(CPPtest)

add_test(test1 NKhTestMatrix)
=======
set(CMAKE_CXX_STANDARD 14)
link_libraries(Ws2_32 wsock32)
add_executable(M win_webserver.c)
>>>>>>> библиотека с тестом

