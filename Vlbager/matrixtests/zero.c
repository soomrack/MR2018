#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../matrix.h"

#define STRINGIFY( x ) #x

#define TEST_EQUAL( foo, expected )                                                                \
{                                                                                                  \
    printf("%-40s","Testing "  STRINGIFY(expected) " ");                                           \
    bool ifEqual = true;                                                                           \
    Matrix matrix = foo;                                                                           \
    for (int row = 0; row < matrix.rows; row++)                                                    \
    {                                                                                              \
        for (int col = 0; col < matrix.cols; col++)                                                \
        {                                                                                          \
            if (matrix.data[row * matrix.cols + col] != expected.data[row * expected.cols + col])  \
            {                                                                                      \
                ifEqual = false;                                                                   \
            }                                                                                      \
        }                                                                                          \
    }                                                                                              \
    if (ifEqual)                                                                                   \
    {                                                                                              \
        printf("Passed\n" );                                                                       \
    }                                                                                              \
    else                                                                                           \
    {                                                                                              \
        printf("Shaitan!\n");                                                                      \
        returnCode = 1;                                                                            \
    }                                                                                              \
    matrix_print(matrix);                                                                          \
    free(matrix.data);                                                                             \
    printf("\n");                                                                                  \
}                                                                                                  \

int main()
{
    int returnCode = 0;


    double dA[1][1] = {0.0};
    Matrix A = {1, 1, *dA};

    TEST_EQUAL(matrix_zero(1, 1), A);


    double dA2[2][1] = {{0.0},
                        {0.0}};
    Matrix A2 = {2, 1, *dA2};

    TEST_EQUAL(matrix_zero(2, 1), A2)


    double dB[2][2] = {{0.0, 0.0},
                       {0.0, 0.0}};
    Matrix B = {2, 2, *dB};

    TEST_EQUAL(matrix_zero(2, 2), B);


    double dC[2][3] = {{0.0, 0.0, 0.0},
                       {0.0, 0.0, 0.0}};
    Matrix C = {2, 3, *dC};

    TEST_EQUAL(matrix_zero(2, 3), C);

    double dD[4][2] = {{0.0, 0.0},
                       {0.0, 0.0},
                       {0.0, 0.0},
                       {0.0, 0.0}};
    Matrix D = {4, 2, *dD};

    Matrix test = matrix_zero(4, 2);

    TEST_EQUAL(matrix_zero(4, 2), D);

    double dE[5][5] = {{0.0},
                       {0.0},
                       {0.0},
                       {0.0},
                       {0.0}};
    Matrix E = {5, 1, *dE};

    TEST_EQUAL(matrix_zero(5, 1), E)

    return returnCode;
}