#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <float.h>

#include "../matrix.h"

#define STRINGIFY( x ) #x

#define TEST_EQUAL( foo, sizeone, letter )                                                                                \
{                                                                                                                  \
    printf("%-40s","Testing "  STRINGIFY(letter) " ");                                                           \
    bool ifEqual = true;                                                                                           \
    Matrix expected = matrix_one(sizeone); \
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
    free(expected.data); \
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
    Matrix temp;

    double dA[1][1] = {-1.0};
    Matrix A = {1, 1, *dA};

    temp = matrix_invert(A);
    matrix_print(temp);
    TEST_EQUAL(matrix_mult(A, matrix_invert(A)), A.rows, A);

    double dB[2][2] = {{1.0, 0},
                       {0, 1.0}};
    Matrix B = {2, 2, *dB};

    TEST_EQUAL(matrix_mult(B, matrix_invert(B)), B.rows, B);

    double dC[2][2] = {{0, 99.0},
                       {0, 1.0}};
    Matrix C = {2, 2, *dC};

    TEST_EQUAL(matrix_mult(C, matrix_invert(C)), C.rows, C);

    double dD[2][2] = {{5.0, 3.0},
                       {5.0, 5.0}};
    Matrix D = {2, 2, *dD};

    TEST_EQUAL(matrix_mult(D, matrix_invert(D)), D.rows, D);

    double dE[2][2] = {{-55.965, 38.325},
                       {-1.875, 69.123}};
    Matrix E = {2, 2, *dE};

    TEST_EQUAL(matrix_mult(E, matrix_invert(E)), E.rows, E);

    double dF[3][3] = {{20.0, 13.0, 14.0},
                       {15.0, 16.0, 17.0},
                       {18.0, 19.0, 20.0}};
    Matrix F = {3, 3, *dF};

    TEST_EQUAL(matrix_mult(E, matrix_invert(E)), E.rows, E);

    double dG[4][4] = {{20.0, 13.1, 14.0, -6.38},
                       {15.2, 16.0, 17.4, 5.25},
                       {18.0, 19.3, 20.0, -9.99},
                       {25.45, 15.0, 57.1, 5.65}};
    Matrix G = {4, 4, *dG};

    TEST_EQUAL(matrix_mult(G, matrix_invert(G)), G.rows, G);

    double dH[5][5] = {{54.0, 66.0, 11.0, 0.0, 1.0},
                       {10.0, 20.0, 1.0, 2.0, 15.0},
                       {12.0, 5.0, 2.0, 0.55, 0.31},
                       {16.0, 78.5, 55.68, 7.0, 0.4},
                       {49.0, 55.2, 8.8, 4.1, 12.5}};
    Matrix H = {5, 5, *dH};

    TEST_EQUAL(matrix_mult(H, matrix_invert(H)), H.rows, H);

    return returnCode;
}