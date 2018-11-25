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

    TEST_EQUAL(matrix_one(1), A);


    double dB[2][2] = {{1.0, 0},
                       {0, 1.0}};
    Matrix B = {2, 2, *dB};

    TEST_EQUAL(matrix_one(2), B);


    double dC[3][3] = {{1.0, 0.0, 0.0},
                       {0.0, 1.0, 0.0},
                       {0.0, 0.0, 1.0}};
    Matrix C = {3, 3, *dC};

    TEST_EQUAL(matrix_one(3), C);

    double dD[4][4] = {{1.0, 0.0, 0.0, 0.0},
                       {0.0, 1.0, 0.0, 0.0},
                       {0.0, 0.0, 1.0, 0.0},
                       {0.0, 0.0, 0.0, 1.0}};
    Matrix D = {4, 4, *dD};

    TEST_EQUAL(matrix_one(4), D);

    double dE[5][5] = {{1.0, 0.0, 0.0, 0.0, 0.0},
                       {0.0, 1.0, 0.0, 0.0, 0.0},
                       {0.0, 0.0, 1.0, 0.0, 0.0},
                       {0.0, 0.0, 0.0, 1.0, 0.0},
                       {0.0, 0.0, 0.0, 0.0, 1.0}};
    Matrix E = {5, 5, *dE};

    TEST_EQUAL(matrix_one(5), E)

    return returnCode;
}