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
        if (  !doublecomparison(m.data[row * m.cols + col], expected.data[row * expected.cols + col]) )            \
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

    double dAr[1][1] = {-1.0};
    Matrix Ar = {1, 1, *dAr};

    TEST_EQUAL(matrix_mult(A1, A2), Ar);



    double dB1[2][2] = {{25.8, -100.0},
                        {343, 0.99}};
    Matrix B1 = {2, 2, *dB1};

    double dB2[2][2] = {{0.2, 200.0},
                        {-43, 0.01}};
    Matrix B2 = {2, 2, *dB2};

    double dBr[2][2] = {{4305.16, 5159.0},
                        {26.03, 68600.01}};
    Matrix Br = {2, 2, *dBr};

    TEST_EQUAL(matrix_mult(B1, B2), Br);



    double dC1[1][2] = {{999.99, 0.01}};
    Matrix C1 = {1, 2, *dC1};

    double dC2[2][1] = {{0.01},
                        {-999.99}};
    Matrix C2 = {2, 1, *dC2};

    double dCr[1][1] = {{0.0}};
    Matrix Cr = {1, 1, *dCr};

    TEST_EQUAL(matrix_mult(C1, C2), Cr);



    double dD1[2][1] = {{4.0},
                        {-1.0}};
    Matrix D1 = {2, 1, *dD1};

    double dD2[1][2] = {{1.0, 3.0}};
    Matrix D2 = {1, 2, *dD2};

    double dDr[2][2] = {{4.0, 12.0},
                        {-1.0, -3.0}};
    Matrix Dr = {2, 2, *dDr};

    TEST_EQUAL(matrix_mult(D1, D2), Dr);



    double dE1[5][3] = {{1.0, 2.0, 3.0},
                        {4.0, 5.0, 6.0},
                        {7.0, 8.0, 9.0},
                        {10.0, 11.0, 12.0},
                        {13.0, 14.0, 15.0}};
    Matrix E1 = {5, 3, *dE1};

    double dE2[3][3] = {{2.0, 4.0, 6.0},
                        {8.0, 10.0, 12.0},
                        {14.0, 16.0, 18.0}};
    Matrix E2 = {3, 3, *dE2};

    double dEr[5][3] = {{60.0, 72.0, 84.0},
                        {132.0, 162.0, 192.0},
                        {204.0, 252.0, 300.0},
                        {276.0, 342.0, 408.0},
                        {348.0, 432.0, 516.0}};
    Matrix Er = {5, 3, *dEr};

    TEST_EQUAL(matrix_mult(E1, E2), Er)



    double dF1[2][7] = {{1.0, 2.0, 3.0, 1.0, 2.0, 3.0, 5.0},
                        {4.0, 5.0, 6.0, 5.4, 6.6, 8.2, 3.3}};
    Matrix F1 = {2, 7, *dF1};

    double dF2[7][3] = {{2.0, 4.0, 6.0},
                        {8.0, 10.0, 12.0},
                        {3.0, 11.0, 16.0},
                        {8.0, 12.0, 18.0},
                        {0.0, 13.0, 20.0},
                        {0.0, 14.0, 0.0},
                        {14.0, 16.0, 18.0}};
    Matrix F2 = {7, 3, *dF2};

    double dFr[2][3] = {{105.0, 217.0, 226.0},
                        {155.4, 450.2, 468.6}};
    Matrix Fr = {2, 3, *dFr};

    TEST_EQUAL(matrix_mult(F1, F2), Fr)

    return returnCode;
}