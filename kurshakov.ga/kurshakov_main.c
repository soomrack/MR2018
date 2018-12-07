#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrixkga.h"
#define SIZE 3

int main () {
    srand(time(NULL));
    Matrix A = matrix_rand(SIZE,SIZE);
    matrix_print(A);
    matrix_print(matrix_exp(A));
}