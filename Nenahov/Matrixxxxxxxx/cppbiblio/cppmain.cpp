#include "library.h"
#include <iostream>


int main(){

    Matrix A;
    A.matrix_rand(3,3);
    A.matrix_print();
    Matrix B;
    B=A.matrix_trans();
    B.matrix_print();
    Matrix C=A.matrix_mult__scalar(5);
    //C.matrix_print();
    //std::cout << A.matrix_trace() << std::endl;
    Matrix D;
    D=A.matrix_sum(B);
    D.matrix_print();



return 0;
}