#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "libraryvb.h"
#include <time.h>


int main()
{
    srand(time(NULL));
    Matrix A = matrix_rand(3,3);
    Matrix B = matrix_rand(3,3);
    matrix_print(A);
    printf("Determinant - %1.3f", matrix_determinant(A));
    printf("Trace - %1.3f\n\n", matrix_trace(A));
    matrix_print(matrix_exp(A));
    printf("\n");
    matrix_print(matrix_trans(A));
    printf("\n");
    matrix_print(B);
    printf("\n");
    matrix_print(matrix_one(3,3));
    printf("\n");
    matrix_print(matrix_zero(3,3));
    printf("\n");
    Matrix C = matrix_sum(A, B);
    matrix_print(C);
    printf("\n");
    C = matrix_mult__scalar(3,A);
    matrix_print(C);
    printf("\n");
    C = matrix_mult(A,B);
    matrix_print(C);
    printf("\n");
    matrix_print(matrix_power(A,2));
    printf("\n");
    return 0;
}
