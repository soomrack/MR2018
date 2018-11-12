//
// Created by Елизавета on 12.11.2018.
//


#include <stdio.h>
#include <stdlib.h>
#include "Elib2.h"
#include <cstdlib>

#define M 2
#define N 3
#define Q 4


int main () {
    double arqA[N][N] = {{0, 1, 2},
                         {1, 2, 3},
                         {2, 3, 4}};

    double arqB[N][N] = {{1, 2, 3},
                         {2, 3, 4},
                         {3, 4, 8}};

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

    double trace, det;

    trace = A.matrix_trace(A);
    printf("trace \n %lf \n", trace);

    Minor = B.matrix_minor(1, 1, B);
    Minor.matrix_print(Minor);

    Dop = B.matrix_dop(B);
    Dop.matrix_print(Minor);

    det = B.matrix_determinant(B);
    printf("determinant \n %lf \n", det);

    Sum = A.matrix_sum(A, B);
    Sum.matrix_print(Sum);

    Transp = A.matrix_trans(A);
    Transp.matrix_print(Transp);

    MultScal = A.matrix_mult__scalar(5, A);
    MultScal.matrix_print(MultScal);

    Mult = B.matrix_mult(A, B);
    Mult.matrix_print(Mult);

    Invert = B.matrix_invert(B);
    Invert.matrix_print(Invert);

    One = One.matrix_one(4);
    One.matrix_print(One);

    Zero = Zero.matrix_zero(4, 3);
    Zero.matrix_print(Zero);

    Rand = Rand.matrix_rand(3, 4);
    Rand.matrix_print(Rand);

    power = B.matrix_power(B, 7);
    power.matrix_print(power);

    return 0;
}