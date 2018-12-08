

#include "sid_matrix.h"
#include <stdio.h>

int main()
{
    double test;
    Matrix A;
    A.cols=2;
    A.rows=2;
    A=matrix_rand(A.cols,A.rows);
    matrix_print(A);
    printf("\n");
    A=matrix_power(A,2);
    printf("Result \n");
    matrix_printe(A);



    return 0;
}
