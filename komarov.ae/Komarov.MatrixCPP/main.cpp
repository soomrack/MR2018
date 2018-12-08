#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "functions.h"
#include <cstdlib>



int main() {
    Matrix A; Matrix B; Matrix C;
    A.rows=3; B.rows=3;
    A.cols=3; B.cols=3;
    A.data=(double*)malloc(A.cols*A.rows*sizeof(double));
    B.data=new double[B.cols*B.rows*sizeof(double)];
    double A1[]={1.0,2.0,7.0,5.0,1.0,9.0,0.0,2.0,1.0};
    double B1[]={1.0,2.0,3.0,1.0,1.0,4.0,5.0,8.0,1.0,1.0,7.0,8.0,9.0,1.0,1.0};
    A.data=A1;
    B.data=B1;
    matrix_print(A);
    matrix_print(B);
    matrix_print(matrix_exp(A));
    return 0;
}