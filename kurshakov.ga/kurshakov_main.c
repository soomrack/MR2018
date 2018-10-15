#include <stdio.h>
#include <stdlib.h>
#include "matrixkga.h"
#define SIZE 2

int main () {
    Matrix A;
    A.rows = 2;
    A.cols = 3;
    A.data = malloc(2 * 3 * sizeof(double));
    A.data[0] = 1;
    A.data[1] = 2;
    A.data[2] = 0;
    A.data[3] = 0;
    A.data[4] = 6;
    A.data[5] = 5;
    matrix_print(A);
    Matrix B;
    B.rows = 3;
    B.cols = 2;
    B.data = malloc(3 * 2 * sizeof(double));
    B.data[0] = 0;
    B.data[1] = 5;
    B.data[2] = 3;
    B.data[3] = 4;
    B.data[4] = 1;
    B.data[5] = 0;
    matrix_print(B);
    matrix_print(matrix_mult(A, B));
}