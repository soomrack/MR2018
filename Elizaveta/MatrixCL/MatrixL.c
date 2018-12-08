//
// Created by Елизавета on 15.10.2018.
//

#include <stdio.h>
#include <stdlib.h>
#include "Elib.h"

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

    double trace, det;

    trace = matrix_trace(A);
    printf("trace \n %lf \n", trace);

    Minor = matrix_minor(1, 1, B);
    matrix_print(Minor);

    Dop = matrix_dop(B);
    matrix_print(Dop);

    det = matrix_determinant(B);
    printf("determinant \n %lf \n", det);

    Sum = matrix_sum(A, B);
    matrix_print(Sum);

    Transp = matrix_trans(A);
    matrix_print(Transp);

    MultScal = matrix_mult__scalar(5, A);
    matrix_print(MultScal);

    Mult = matrix_mult(A, B);
    matrix_print(Mult);

    Invert = matrix_invert(B);
    matrix_print(Invert);

    matrix_print(matrix_one(4));
    matrix_print(matrix_zero(4, 3));
    matrix_print(matrix_rand(3, 4));

    power = matrix_power(B, 7);
    matrix_print(power);

    return 0;
}