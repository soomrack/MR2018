#add_library(shayahmetov.rh_matrix STATIC sourse/matrix.c)
#add_executable(shayahmetov.rh sourse/main.c)
#target_link_libraries(shayahmetov.rh shayahmetov.rh_matrix)
#Testing
#enable_testing()
#add_executable(TestMatrixLib test/TestMatrixLib.c)
#add_test(NAME TestMatrixLib_1 COMMAND TestMatrixLib)
#target_link_libraries(TestMatrixLib shayahmetov.rh_matrix)

add_subdirectory(Matrix_library)
