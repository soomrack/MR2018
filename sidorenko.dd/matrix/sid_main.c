

#include "sid_matrix.h"
#include <stdio.h>

int main()
{
    double test;
    Matrix A;
    A.cols=3;
    A.rows=3;
    A=matrix_rand(A.cols,A.rows);
    matrix_print(A);
    printf("\n");
    test=matrix_trace(A);
    printf("%f",test);


    return 0;
}