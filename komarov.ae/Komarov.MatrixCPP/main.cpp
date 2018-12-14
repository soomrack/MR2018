#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "functions.h"
#include <cstdlib>



int main() {
    double test1[3][3] = {{3876.0, -224.0, -8454.0},
                          {-17262.0, -137.0, -5770.0},
                          {5879.0, -285.0, -1366.0}};
    Matrix A(3);
    A.data = *test1;

    A.matrix_print();
    A.matrix_trace();
    std::cout<<A.matrix_determinant()<<std::endl;
    A.matrix_trans();
    Matrix B(20);
    B.matrix_one(4,5);
   // B.matrix_zero(4,5);
   // B.matrix_print();
}