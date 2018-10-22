#include <stdio.h>
#include <malloc.h>
#include "matrix.h"

int main(){

    Matrix A = matrix_rand(3,3);
    matrix_print(A);
    PowerMatrix P = ToPowerMatrix(A);
    print_PowerMatrix(P);
    polinomPrint(determinant_PowerMatrix(P));
    return 0;
}