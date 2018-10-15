#include <stdio.h>
#include "matrixkga.h"
#define SIZE 3

int main () {
    Matrix A = matrix_rand(SIZE,SIZE);
    Matrix B = matrix_rand(SIZE,SIZE);
    matrix_print(A);
    matrix_print(B);
}