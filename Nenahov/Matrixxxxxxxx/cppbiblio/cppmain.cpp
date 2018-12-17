#include "library.h"
#include <iostream>


int main(){

    Matrix A;
    A.matrix_one(3,3);
    A.matrix_print();
    A.copy(A.matrix_mult(A));
    double d=A.matrix_determinant();
    //A.matrix_print();
    Matrix B;
    B=A.matrix_trans();
   // B.matrix_print();
    Matrix C=A.matrix_mult__scalar(5);
    //C.matrix_print();
    //std::cout << A.matrix_trace() << std::endl;
    Matrix D;
    B.copy(A.matrix_invert());
    D.copy(B.matrix_mult(A));
    D.matrix_print();



return 0;
}