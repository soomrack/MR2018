#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <float.h>
#include "../matrix.h"

#define STRINGIFY( x ) #x

#define TEST_EQUAL( foo, expected )                                                                                \
{                                                                                                                  \
    printf("%-40s","Testing "  STRINGIFY(expected) " ");                                                           \
    bool ifEqual = true;                                                                                           \
    Matrix m = foo;                                                                                                \
    for (int row = 0; row < m.rows; row++)                                                                         \
    {                                                                                                              \
        for (int col = 0; col < m.cols; col++)                                                                     \
        {                                                                                                          \
        if (!doublecomparison(m.data[row * m.cols + col], expected.data[row * expected.cols + col]))               \
            {                                                                                                      \
                ifEqual = false;                                                                                   \
            }                                                                                                      \
        }                                                                                                          \
    }                                                                                                              \
    if (ifEqual)                                                                                                   \
    {                                                                                                              \
        printf("Passed\n" );                                                                                       \
    }                                                                                                              \
    else                                                                                                           \
    {                                                                                                              \
        printf("Shaitan!\n");                                                                                      \
        returnCode = 1;                                                                                            \
    }                                                                                                              \
    matrix_print(m);                                                                                               \
    free(m.data);                                                                                                  \
    printf("\n");                                                                                                  \
}                                                                                                                  \

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



    double dA1[1][1] = {1.0};
    Matrix A1 = {1, 1, *dA1};

    double dA2[1][1] = {-1.0};
    Matrix A2 = {1, 1, *dA2};

    double dAr[1][1] = {0.0};
    Matrix Ar = {1, 1, *dAr};

    TEST_EQUAL(matrix_sum(A1, A2), Ar);



    double dB1[2][2] = {{25.8, -100.0},
                        {343, 0.99}};
    Matrix B1 = {2, 2, *dB1};

    double dB2[2][2] = {{0.2, 200.0},
                        {-43, 0.01}};
    Matrix B2 = {2, 2, *dB2};

    double dBr[2][2] = {{26, 100},
                        {300, 1.0}};
    Matrix Br = {2, 2, *dBr};

    TEST_EQUAL(matrix_sum(B1, B2), Br);



    double dC1[2][1] = {{999.99},
                        {0.01}};
    Matrix C1 = {2, 1, *dC1};

    double dC2[2][1] = {{0.01},
                        {-999.99}};
    Matrix C2 = {2, 1, *dC2};

    double dCr[2][1] = {{1000.0},
                        {-999.98}};
    Matrix Cr = {2, 1, *dCr};

    TEST_EQUAL(matrix_sum(C1, C2), Cr);



    double dD1[1][2] = {{1.0, 0.0}};
    Matrix D1 = {1, 2, *dD1};

    double dD2[1][2] = {{0.0, -1.0}};
    Matrix D2 = {1, 2, *dD2};

    double dDr[1][2] = {{1.0, -1.0}};
    Matrix Dr = {1, 2, *dDr};

    TEST_EQUAL(matrix_sum(D1, D2), Dr);



    double dE1[5][3] = {{1.0, 2.0, 3.0},
                        {4.0, 5.0, 6.0},
                        {7.0, 8.0, 9.0},
                        {10.0, 11.0, 12.0},
                        {13.0, 14.0, 15.0}};
    Matrix E1 = {5, 3, *dE1};

    double dE2[5][3] = {{2.0, 4.0, 6.0},
                        {8.0, 10.0, 12.0},
                        {14.0, 16.0, 18.0},
                        {20.0, 22.0, 24.0},
                        {26.0, 28.0, 30.0}};
    Matrix E2 = {5, 3, *dE2};

    double dEr[5][3] = {{3.0, 6.0, 9.0},
                        {12.0, 15.0, 18.0},
                        {21.0, 24.0, 27.0},
                        {30.0, 33.0, 36.0},
                        {39.0, 42.0, 45.0}};
    Matrix Er = {5, 3, *dEr};

    TEST_EQUAL(matrix_sum(E1, E2), Er)

    return returnCode;
}