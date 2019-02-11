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

    Matrix C = {Q, Q, *arqC};
    Matrix A = {N, N, *arqA};
    Matrix B = {N, N, *arqB};
    Matrix Sum;
    Matrix Mult;
    Matrix MultScal;
    Matrix Transp;
    Matrix Minor;
    Matrix Dop;
    Matrix Invert;
    Matrix power;
    Matrix Zero;
    Matrix One;
    Matrix Rand;
    Matrix Exp;

    double trace, det;

    trace = A.matrix_trace(A);
    std::cout << "trace \n" << trace << "\n";

    std::cout << "minor \n";
    Minor = B.matrix_minor(1, 1, B);
    Minor.matrix_print(Minor);

    Dop = B.matrix_dop(B);
    Dop.matrix_print(Dop);


    det = B.matrix_determinant(C);
    std::cout << "determinant \n" << det << "\n";

    std::cout << "sum \n";
    Sum = A.matrix_sum(A, B);
    Sum.matrix_print(Sum);

    std::cout << "transpose \n";
    Transp = A.matrix_trans(A);
    Transp.matrix_print(Transp);

    std::cout << "multiplication - scalar \n";
    MultScal = A.matrix_mult_scalar(5, A);
    MultScal.matrix_print(MultScal);

    std::cout << "multiplication - matrix \n";
    Mult = B.matrix_mult(A, B);
    Mult.matrix_print(Mult);

    std::cout << "invert matrix \n";
    Invert = B.matrix_invert(B);
    Invert.matrix_print(Invert);

    std::cout << "unit matrix \n";
    One = One.matrix_one(4);
    One.matrix_print(One);

    std::cout << "zero matrix \n";
    Zero = Zero.matrix_zero(4, 3);
    Zero.matrix_print(Zero);

    std::cout << "random 1 -1 matrix \n";
    Rand = Rand.matrix_rand(3, 4);
    Rand.matrix_print(Rand);

    std::cout << "matrix power \n";
    power = B.matrix_power(B, 7);
    power.matrix_print(power);

    std::cout << "matrix exponent \n";
    Exp = B.matrix_exp(B);
    Exp.matrix_print(Exp);
    
    return 0;
}