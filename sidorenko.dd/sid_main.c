

#include "sid_matrix.h"
#include <stdio.h>

int main()
{
    double test;
    Matrix A;
    Matrix B;
    A.cols=3;
    A.rows=2;
    B.cols=2;
    B.rows=3;
    A=matrix_rand(A.cols,A.rows);
    B=matrix_rand(B.cols,B.rows);
    matrix_print(A);
    printf("\n");
    matrix_print(B);
    printf("\n");
    printf("Result \n");
    A=matrix_mult(A,B);
    matrix_print(A);



    return 0;
}
