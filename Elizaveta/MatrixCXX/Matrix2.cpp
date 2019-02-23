//
// Created by Елизавета on 12.11.2018.
//


#include <iostream>
#include "Elib2.h"
#include <cstdlib>

#define M 2
#define N 3
#define Q 4

int main ()
{
    double arqA[N][N] = {{0, 1, 2},
                         {1, 2, 3},
                         {2, 3, 4}};

    double arqB[N][N] = {{1, 2, 3},
                         {2, 3, 4},
                         {3, 4, 8}};

    double arqC[Q][Q] = {{1, 2, 3, 5},
                         {2, 3, 4, 6},
                         {3, 4, 8, 7},
                         {8, 9, 10, 15}};

    Matrix C (Q, Q);
    C.data = *arqC;
    Matrix A (N, N);
    A.data = *arqA;
    Matrix B (N, N);
    B.data = *arqB;
    Matrix Sum (0,0);
    Matrix Mult(0,0);
    Matrix MultScal(0,0);
    Matrix Transp(0,0);
    Matrix Minor(0,0);
    Matrix Dop(0,0);
    Matrix Invert(0,0);
    Matrix power(0,0);
    Matrix Zero(0,0);
    Matrix One(0,0);
    Matrix Rand(0,0);
    Matrix Exp(0,0);

    double trace, det;

    trace = A.matrix_trace(A);
    std::cout << "trace \n" << trace << "\n";

    std::cout << "minor \n";
    Minor = B.matrix_minor(1, 1);
    Minor.matrix_print();

    Dop = B.matrix_dop();
    Dop.matrix_print();


    det = B.matrix_determinant();
    std::cout << "determinant \n" << det << "\n";

    std::cout << "sum \n";
    Sum = A.matrix_sum(B);
    Sum.matrix_print();

    std::cout << "transpose \n";
    Transp = A.matrix_trans();
    Transp.matrix_print();

    std::cout << "multiplication - scalar \n";
    MultScal = A.matrix_mult_scalar(5);
    MultScal.matrix_print();

    std::cout << "multiplication - matrix \n";
    Mult = B.matrix_mult(A);
    Mult.matrix_print();

    std::cout << "invert matrix \n";
    Invert = B.matrix_invert();
    Invert.matrix_print();

    std::cout << "unit matrix \n";
    One = One.matrix_one(4);
    One.matrix_print();

    std::cout << "zero matrix \n";
    Zero = Zero.matrix_zero(4, 3);
    Zero.matrix_print();

    std::cout << "random 1 -1 matrix \n";
    Rand = Rand.matrix_rand(3, 4);
    Rand.matrix_print();

    std::cout << "matrix power \n";
    power = B.matrix_power(7);
    power.matrix_print();

    std::cout << "matrix exponent \n";
    Exp = B.matrix_exp();
    Exp.matrix_print();
    
    return 0;
}