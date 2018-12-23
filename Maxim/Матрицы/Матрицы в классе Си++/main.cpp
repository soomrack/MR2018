#include <iostream>
#include "matrixcpplib.h"
#include <cstdlib>

int main() {
    MyMatrix A;
    MyMatrix B;
    MyMatrix C;
    A.rows = 3;
    A.cols = 3;
    A.data = (double*)malloc(A.cols * A.rows * sizeof(int));
    C.rows = 3;
    C.cols = 3;
    C.data = (double*)malloc(A.cols * A.rows * sizeof(int));
    C.copy(A.matrix_rand(A.cols,A.rows));
    C.matrix_print();
    std::cout << C.matrix_trace() << std::endl;
    B.copy(C.matrix_trans());
    B.matrix_print();
    double e=A.matrix_determinant(B);
    printf("%f",e);
    MyMatrix D;
    std::cout<< "zero matrix\n";
    D.matrix_zero(3,3);
    D.matrix_print();
    MyMatrix V;
    std::cout<< "one matrix\n";
    V.matrix_one(3,3);
    V.matrix_print();
    MyMatrix S;
    std::cout<< "mult_scalar\n";
    S.copy(C.matrix_mult__scalar(6));
    S.matrix_print();
    MyMatrix L;

    std::cout<< "matrix C\n";
    C.matrix_print();
    std::cout<< "matrix S\n";
    S.matrix_print();
    std::cout<< "sum_matrix C and S\n";
    L.copy(C.matrix_sum(S,C));
    L.matrix_print();
    MyMatrix G;
    G.copy(A.matrix_rand(3,3));
    std::cout<< "matrix G\n";
    G.matrix_print();
    std::cout<< "matrix C\n";
    C.copy(C.matrix_rand(3,3));
    C.matrix_print();
    std::cout<< "mult_matrix G and C\n";
    G.copy(C.matrix_mult(S,V));
    G.matrix_print();
    MyMatrix K;
    K.copy(A.matrix_rand(3,3));
    std::cout<< "matrix K\n";
    K.matrix_print();
    std::cout<< "matrix_power K^3\n";
    K.copy(A.matrix_power(K,3));
    K.matrix_print();
    std::cout<< "matrix C\n";
    C.copy(A.matrix_rand(3,3));
    C.matrix_print();
    std::cout<< "matrix_invert C\n";
    C=(A.matrix_invert(C));
}