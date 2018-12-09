#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include "AlexVolkMatrixCPP.h"

int main() {
    Matrix A;
    Matrix B;
    Matrix C;
    Matrix D;
    A.rows=3;
    A.cols=3;
    A.data=(double*)malloc(A.cols*A.rows*sizeof(double));
    D.rows=3;
    D.cols=3;
    D.data=(double*)malloc(D.cols*D.rows*sizeof(double));
    double A1[]={5.0,8.0,7.0,10.0,1.0,9.0,0.0,2.0,1.0};
    A.data=A1;
    double D1[]={5.0,8.0,7.0,10.0,1.0,9.0,0.0,2.0,1.0};
    D.data=D1;
    A.matrix_print(A);
    /*B.matrix_print(B.matrix_zero(2,2));
    C.matrix_print(C.matrix_one(5,5));
    A.matrix_print(A.matrix_mult__scalar(2.0, A));
    A.matrix_print(A.matrix_trans(A));
    B.matrix_print(B.matrix_rand(4,4));
    A.matrix_trace(A);*/
    D.matrix_print(D.matrix_invert());
    D.matrix_print(D.matrix_sum(D));
    return 0;
}
