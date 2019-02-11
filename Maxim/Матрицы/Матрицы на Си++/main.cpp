#include <iostream>
#include "matrixcpplib.h"
#include <cstdlib>

int main() {
    MyMatrix A(4, 4);
    MyMatrix B(4, 4);
    MyMatrix C(4, 4);
    MyMatrix D(4,4);
    MyMatrix E(4,4);
    C = A.matrix_rand(A.rows, A.cols);
    std::cout << "matrix C\n";
    C.matrix_print();
    A = A.matrix_rand(A.rows, A.cols);
    std::cout << "matrix trace of C is\t" << C.matrix_trace() << std::endl;
    MyMatrix V(4, 4);
    std::cout << "one matrix\n";
    V.matrix_one(5, 5);
    V.matrix_print();
    std::cout<< "zero matrix\n";
    D.matrix_zero(3,3);
    D.matrix_print();
    std::cout<< "matrix trans of C\n";
    B = C.matrix_trans();
    B.matrix_print();
    MyMatrix G(4, 3);
    G = G.matrix_rand(4, 3);
    std::cout << "matrix G\n";
    G.matrix_print();
    C = C.matrix_rand(3, 5);//если подать матрицу неверного размера, то она станет размера поданных параметров
    std::cout << "matrix C\n";
    C.matrix_print();
    std::cout << "mult_matrix G and C\n";
    MyMatrix H = G.matrix_mult(C);
    H.matrix_print();
    std::cout << "mult_scalar A on 6\n";
    V = A.matrix_mult__scalar(6);
    V.matrix_print();
    std::cout<< "matrix A\n";
    A.matrix_print();
    std::cout<< "matrix V\n";
    V.matrix_print();
    std::cout<< "sum_matrix A and V\n";
    A =(A.matrix_sum(V));
    A.matrix_print();
    std::cout<< "matrix_power A^3\n";
    std::cout<<"initial matrix\n";
    A.matrix_print();
    A = A.matrix_power(3);
    A.matrix_print();
    std::cout<< "matrix_invert C\n";
    V = V.matrix_invert();
    V.matrix_print();
    std::cout<< "matrix E\n";
    E=E.matrix_rand(4,4);
    E.matrix_print();
    std::cout<< "matrix exp of E\n";
    E=E.matrix_exp();
    E.matrix_print();
    B = A.matrix_rand(A.rows, A.cols);
    std::cout << "matrix B\n";
    B.matrix_print();
    double e = B.matrix_determinant();
    std::cout  <<  "determinant of B = "  <<  e  <<  std::endl;
return 0;
}


