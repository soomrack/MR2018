#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include "matrix.h"

int main() {
    double matrix_work[3][3] = {{45.0, -89.0, -123.0},
                                {-7.0, -513.0, 12.0},
                                {10.0,  0.0,   80.0}};
    Matrix A(3);
    A.data = *matrix_work;

    A.matrix_print();
    A.matrix_trace();
    A.matrix_trans();
}