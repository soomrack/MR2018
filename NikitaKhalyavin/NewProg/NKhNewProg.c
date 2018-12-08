#include <stdio.h>
#include <malloc.h>
#include "matrix.h"

int main(){

    Matrix A = matrix_rand(3,3);
    matrix_print(A);
    PowerMatrix P = ToPowerMatrix(A);
    print_PowerMatrix(P);
    Polinom T = determinant_PowerMatrix(P);
    polinomPrint(T);
    polinomPrint(Pr(T));
    matrix_print(matrix_eigen_values(A));
    return 0;
}