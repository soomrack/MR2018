#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>

#include "../matrix.h"

#define STRINGIFY( x ) #x

#define TEST_EQUAL( matrix, expected )                                       \
{                                                                            \
    printf("%-40s","Testing "  STRINGIFY(matrix) " ");                       \
    double value = matrix_determinant(matrix);                               \
    if( doublecomparison(value, expected) )                                  \
    {                                                                        \
        printf("Passed\n" );                                                 \
    }                                                                        \
    else                                                                     \
    {                                                                        \
        printf("Shaitan! "                                                   \
               " Expected: %E, got %E\n", expected, value);                  \
        returnCode = 1;                                                      \
    }                                                                        \
    matrix_print(matrix);                                                    \
    printf("\n");                                                            \
}                                                                            \

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

    double dA[1][1] = {-1.0};
    Matrix A = {1, 1, *dA};

    TEST_EQUAL(A, -1.0);

    double dB[2][2] = {{1.0, 0},
                       {0, 1.0}};
    Matrix B = {2, 2, *dB};

    TEST_EQUAL(B, 1.0);

    double dC[2][2] = {{0, 99.0},
                       {0, 1.0}};
    Matrix C = {2, 2, *dC};

    TEST_EQUAL(C, 0.0);

    double dD[2][2] = {{5.0, 3.0},
                       {5.0, 5.0}};
    Matrix D = {2, 2, *dD};

    TEST_EQUAL(D, 10.0);

    double dE[2][2] = {{-55.965, 38.325},
                       {-1.875, 69.123}};
    Matrix E = {2, 2, *dE};

    TEST_EQUAL(E, -3796.61);

    double dF[3][3] = {{20.0, 13.0, 14.0},
                       {15.0, 16.0, 17.0},
                       {18.0, 19.0, 20.0}};
    Matrix F = {3, 3, *dF};

    TEST_EQUAL(F, -24.0);

    double dG[4][4] = {{20.0, 13.1, 14.0, -6.38},
                       {15.2, 16.0, 17.4, 5.25},
                       {18.0, 19.3, 20.0, -9.99},
                       {25.45, 15.0, 57.1, 5.65}};
    Matrix G = {4, 4, *dG};

    TEST_EQUAL(G, 81552.67);

    double dH[5][5] = {{54.0, 66.0, 11.0, 0.0, 1.0},
                       {10.0, 20.0, 1.0, 2.0, 15.0},
                       {12.0, 5.0, 2.0, 0.55, 0.31},
                       {16.0, 78.5, 55.68, 7.0, 0.4},
                       {49.0, 55.2, 8.8, 4.1, 12.5}};
    Matrix H = {5, 5, *dH};

    TEST_EQUAL(H, 740217.96)

    return returnCode;
}