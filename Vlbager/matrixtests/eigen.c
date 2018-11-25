#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <float.h>

#include "../matrix.h"

#define STRINGIFY( x ) #x

#define TEST_INVERT( M )                                                                                           \
{                                                                                                                  \
    printf("%-40s","Testing "  STRINGIFY(M) " ");                                                                  \
    bool ifEqual = true;                                                                                           \
    Matrix expected = matrix_one(M.rows);                                                                          \
    Matrix inverted = matrix_invert(M);                                                                            \
    Matrix m = matrix_mult(M, inverted);                                                                           \
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
    matrix_print(inverted);                                                                                        \
    free(m.data);                                                                                                  \
    free(expected.data);                                                                                           \
    free(inverted.data);                                                                                           \
    printf("\n");                                                                                                  \
}                                                                                                                  \

static bool doublecomparison (double a, double b)
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



    double dB[2][2] = {{1.0, 0},
                       {0, 1.0}};
    Matrix B = {2, 2, *dB};


    //TEST_INVERT(B);

    double dC[2][2] = {{1.0, -1.0},
                       {1.0, 1.0}};
    Matrix C = {2, 2, *dC};

    //TEST_INVERT(C);

    double dD[2][2] = {{5.0, -2.0},
                       {-2.0, 8.0}};
    Matrix D = {2, 2, *dD};



    //TEST_INVERT(D);

    double dE[2][2] = {{-55.965, 38.325},
                       {-1.875, 69.123}};
    Matrix E = {2, 2, *dE};

    //TEST_INVERT(E);

    double dF[3][3] = {{1.0, 3.0, 5.0},
                       {7.0, 8.0, 5.0},
                       {5.0, 3.0, 1.0}};
    Matrix F = {3, 3, *dF};

    matrix_print(matrix_eigen_vectors(D));

    //TEST_INVERT(F);

    double dG[4][4] = {{20.0, 13.1, 14.0, -6.38},
                       {15.2, 16.0, 17.4, 5.25},
                       {18.0, 19.3, 20.0, -9.99},
                       {25.45, 15.0, 57.1, 5.65}};
    Matrix G = {4, 4, *dG};

    //TEST_INVERT(G);

    double dH[5][5] = {{54.0, 66.0, 11.0, 0.0, 1.0},
                       {10.0, 20.0, 1.0, 2.0, 15.0},
                       {12.0, 5.0, 2.0, 0.55, 0.31},
                       {16.0, 78.5, 55.68, 7.0, 0.4},
                       {49.0, 55.2, 8.8, 4.1, 12.5}};
    Matrix H = {5, 5, *dH};



    //TEST_INVERT(H);

    return returnCode;
}