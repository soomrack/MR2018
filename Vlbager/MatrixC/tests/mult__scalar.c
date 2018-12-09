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

    TEST_EQUAL(matrix_mult__scalar(1.0, A), A);
    

    double dB1[2][2] = {{1.0, 0.0},
                        {2.0, 3.0}};
    double dB2[2][2] = {{2.0, 0.0},
                        {4.0, 6.0}};
    Matrix B1 = {2, 2, *dB1};
    Matrix B2 = {2, 2, *dB2};

    TEST_EQUAL(matrix_mult__scalar(2.0, B1), B2);
    

    double dB3[2][1] = {{1.0},
                        {2.0}};
    double dB4[2][1] = {{1.5},
                        {3.0}};
    Matrix B3 = {2, 1, *dB3};
    Matrix B4 = {2, 1, *dB4};

    TEST_EQUAL(matrix_mult__scalar(1.5, B3), B4);
    
    

    double dC1[2][3] = {{1.0, 0.0, 0.0},
                        {4.0, 2.0, 0.0}};
    Matrix C1 = {2, 3, *dC1};
    double dC2[2][3] = {{0.0, 0.0, 0.0},
                        {0.0, 0.0, 0.0}};
    Matrix C2 = {2, 3, *dC2};

    TEST_EQUAL(matrix_mult__scalar(0.0, C1), C2);


    double dD1[5][3] = {{1.0, 0.0, 0.0},
                        {2.0, 6.0, 0.0},
                        {3.0, 7.0, 10.0},
                        {4.0, 8.0, 11.0},
                        {5.0, 9.0, 12.0}};
    Matrix D1 = {5, 3, *dD1};
    double dD2[5][3] = {{0.5, 0.0, 0.0},
                        {1.0, 3.0, 0.0},
                        {1.5, 3.5, 5.0},
                        {2.0, 4.0, 5.5},
                        {2.5, 4.5, 6.0}};
    Matrix D2 = {5, 3, *dD2};

    TEST_EQUAL(matrix_mult__scalar(0.5, D1), D2);


    return returnCode;
}