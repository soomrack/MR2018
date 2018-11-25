#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <float.h>
#include "../matrix.h"

#define STRINGIFY( x ) #x

#define TEST_EQUAL( foo, expected )                                                                                 \
{                                                                                                                   \
    printf("%-40s","Testing "  STRINGIFY(expected) " ");                                                            \
    bool ifEqual = true;                                                                                            \
    Matrix matrix = foo;                                                                                            \
    for (int row = 0; row < matrix.rows; row++)                                                                     \
    {                                                                                                               \
        for (int col = 0; col < matrix.cols; col++)                                                                 \
        {                                                                                                           \
            if (!doublecomparison(matrix.data[row * matrix.cols + col], expected.data[row * expected.cols + col]))  \
            {                                                                                                       \
                ifEqual = false;                                                                                    \
            }                                                                                                       \
        }                                                                                                           \
    }                                                                                                               \
    if (ifEqual)                                                                                                    \
    {                                                                                                               \
        printf("Passed\n" );                                                                                        \
    }                                                                                                               \
    else                                                                                                            \
    {                                                                                                               \
        printf("Shaitan!\n");                                                                                       \
        returnCode = 1;                                                                                             \
    }                                                                                                               \
    matrix_print(matrix);                                                                                           \
    free(matrix.data);                                                                                              \
    printf("\n");                                                                                                   \
}                                                                                                                   \

bool doublecomparison (double a, double b)
{
    double diff = fabs(a - b);
    const double eps = 0.001;
    if ( a == b )
    {   //случаи для нулей и бесконечностей
        return true;
    }
    else if ( a == 0 || b == 0 || diff < DBL_MIN )
    {   //близкие к нулю значения сравниваются с абсолютным eps
        return diff <= eps;
    }
    else
    {   //все остальное сравнивнивается относительно
        return diff / (fabs(a) + fabs(b)) <= eps;
    }
}

int main()
{
    int returnCode = 0;

    double dK[2][2] = {{10.0, 20.0},
                       {30.0, 40.0}};
    double dK1[2][2] = {{0.5125e+23, 0.7470e+23},
                        {1.1204e+23, 1.6329e+23}};
    Matrix K = {2, 2, *dK};
    Matrix K1 = {2, 2, *dK1};

    TEST_EQUAL(matrix_exp(K), K1);

    double dA[1][1] = {1.0};
    Matrix A = {1, 1, *dA};

    double dA1[1][1] = {2.7183};
    Matrix A1 = {1, 1, *dA1};

    TEST_EQUAL(matrix_exp(A), A1);


    double dB[2][2] = {{1.0, 0.0},
                       {0.0, 1.0}};
    Matrix B = {2, 2, *dB};

    double dB1[2][2] = {{2.7183, 0.0},
                       {0.0, 2.7183}};
    Matrix B1 = {2, 2, *dB1};

    TEST_EQUAL(matrix_exp(B), B1);


    double dC[2][2] = {{1.0, 2.0},
                        {3.0, 4.0}};
    double dC1[2][2] = {{51.969, 74.7366},
                        {112.1048, 164.0738}};
    Matrix C = {2, 2, *dC};
    Matrix C1 = {2, 2, *dC1};

    TEST_EQUAL(matrix_exp(C), C1);


    double dD[3][3] = {{1.0, 0.0, 0.0},
                       {2.0, 2.0, 0.0},
                       {1.0, 4.0, 7.0}};
    Matrix D = {3, 3, *dD};
    double dD1[3][3] = {{2.7183, 0.0, 0.0},
                        {9.3415, 7.3891, 0.0},
                        {466.56, 871.39, 1.096e+3}};
    Matrix D1 = {3, 3, *dD1};

    TEST_EQUAL(matrix_exp(D), D1);


    double dE[5][5] = {{54.0, 66.0, 11.0, 0.0, 1.0},
                       {10.0, 20.0, 1.0, 2.0, 15.0},
                       {12.0, 5.0, 2.0, 0.55, 0.31},
                       {16.0, 78.5, 55.68, 7.0, 0.4},
                       {49.0, 55.2, 8.8, 4.1, 12.5}};
    Matrix E = {5, 5, *dE};
    double dE1[5][5] = {{4.5584e+36, 6.1072e+36, 0.9742e+36, 0.2332e+36, 1.3304e+36},
                       {1.9372e+36, 2.5954e+36, 0.4140e+36, 0.0991e+36, 0.5654e+36},
                       {0.8162e+36, 1.0935e+36, 0.1744e+36, 0.0417e+36, 0.2382e+36},
                       {3.4885e+36, 4.6738e+36, 0.7456e+36, 0.1784e+36, 1.0181e+36},
                       {4.8467e+36, 6.4935e+36, 1.0358e+36, 0.2479e+36, 1.4145e+36}};
    Matrix E1 = {5, 5, *dE1};

    TEST_EQUAL(matrix_exp(E), E1);

    return returnCode;
}