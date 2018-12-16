#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include "AlexVolkMatrixCPP.h"

int main() {
    Matrix A (3, 3);
    Matrix B (3, 3);
    Matrix C (5, 5);
    Matrix D (4,4);
    double A1[]={5.0,8.0,7.0,10.0,1.0,9.0,0.0,2.0,1.0};
    A.data=A1;
    double D1[]={5.0,8.0,7.0,10.0,1.0,9.0,0.0,2.0,1.0};
    D.data=D1;
    //A.matrix_print(A);
   // C.matrix_print(C.matrix_one());
   // A.matrix_print(A.matrix_mult__scalar(2.0, A));
    //A.matrix_print(A.matrix_trans(A));
    B.matrix_print(B.matrix_rand(2,2));
    A.matrix_trace();
//    D.matrix_print(D.matrix_invert());
    return 0;
}
