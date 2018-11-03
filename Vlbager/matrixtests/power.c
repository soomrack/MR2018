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
    const double eps = 0.000001;
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


    double dA[1][1] = {1.0};
    Matrix A = {1, 1, *dA};

    TEST_EQUAL(matrix_power(A, 2), A);


    double dB[2][2] = {{1.0, 0.0},
                       {0.0, 1.0}};
    Matrix B = {2, 2, *dB};

    TEST_EQUAL(matrix_power(B, 5), B);

    double dB1[2][2] = {{1.0, 2.0},
                        {3.0, 4.0}};
    double dB2[2][2] = {{7.0, 10.0},
                        {15.0, 22.0}};
    Matrix B1 = {2, 2, *dB1};
    Matrix B2 = {2, 2, *dB2};

    TEST_EQUAL(matrix_power(B1, 2), B2);

    TEST_EQUAL(matrix_power(B1, 1), B1);

    Matrix zerotest = matrix_one(2);
    TEST_EQUAL(matrix_power(B1, 0), zerotest);
    free(zerotest.data);


    double dC1[3][3] = {{1.0, 0.0, 0.0},
                        {4.0, 2.0, 0.0},
                        {5.0, 6.0, 3.0}};
    Matrix C1 = {3, 3, *dC1};
    double dC[3][3] = {{1.0, 0.0, 0.0},
                        {28.0, 8.0, 0.0},
                        {209.0, 114.0, 27.0}};
    Matrix C = {3, 3, *dC};

    TEST_EQUAL(matrix_power(C1, 3), C);


    double dD1[5][5] = {{54.0, 66.0, 11.0, 0.0, 1.0},
                       {10.0, 20.0, 1.0, 2.0, 15.0},
                       {12.0, 5.0, 2.0, 0.55, 0.31},
                       {16.0, 78.5, 55.68, 7.0, 0.4},
                       {49.0, 55.2, 8.8, 4.1, 12.5}};
    Matrix D1 = {5, 5, *dD1};
    double dD[5][5] = {{315319.59, 420965.81, 64944.92, 15709.021, 92189.883},
                       {133319.01, 179763.997, 30359.152, 7163.1, 38664.4066},
                       {56752.13, 75688.86, 11227.16, 2510.05, 16387.27},
                       {239624.22, 320901.74, 55920.49, 14033.43, 70151.11},
                       {334317.68, 448018.57, 71091.94, 16930.81, 98232.28}};
    Matrix D = {5, 5, *dD};

    TEST_EQUAL(matrix_power(D1, 3), D);

    return returnCode;
}