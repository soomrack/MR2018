#include <iostream>
#include "matrixcpplib.h"
#include <cstdlib>
int main() {
    MyMatrix A;
    MyMatrix B;
    A.rows = 3;
    A.cols = 3;
    A.data = (double*)malloc(A.cols * A.rows * sizeof(int));
    A.matrix_print();
    MyMatrix C;
C=A.matrix_rand(A.cols,A.rows);
C.matrix_print();
    std::cout << C.matrix_trace() << std::endl;
   B=C.matrix_trans();
    B.matrix_print();
double e=A.matrix_determinant(B);
printf("%f",e);
MyMatrix D;
    D.matrix_zero(3,3);
    D.matrix_print();
    MyMatrix V;
    V.matrix_one(3,3);
    V.matrix_print();
    MyMatrix S;
    S=C.matrix_mult__scalar(6);
    S.matrix_print();
    MyMatrix L;
    L=C.matrix_sum(S);
    L.matrix_print();
    MyMatrix G;
    G=C.matrix_mult(S);
    G.matrix_print();
}