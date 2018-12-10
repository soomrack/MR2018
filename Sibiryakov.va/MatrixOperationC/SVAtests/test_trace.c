#include "../matrix.h"
#include <stdio.h>
#include <malloc.h>
#include <math.h>

#define STRINGIFY( x ) #x

#define TEST_EQUAL( matrix, expected )                                        \
{                                                                           \
    printf("%-40s","Testing "  STRINGIFY(matrix) " ");                       \
    double value = matrix_trace(matrix);                               \
    if(     (fabs(1.005 * value) >= fabs(expected))                          \
         && (fabs(0.995 * value) <= fabs(expected))                          \
         && ((expected * value) >= 0))                                       \
    {                                                                        \
        printf("Test is completed successfully!\n" );                      \
    }                                                                        \
    else                                                                     \
    {                                                                        \
        printf("Error! "                                                   \
               " Expected: %lf, got %lf\n", expected, value);                  \
        return 1;                                                      \
    }                                                                             \
    printf("\n");                                                            \
}                                                                           \



int main() {
    double test_1[2][2] = {{3.8, -59.35},
                         {90.37, -0.98}};
    Matrix test_one = {2,2,*test_1};
    double result_test1 = test_1[0][0] + test_1[1][1];
    TEST_EQUAL(test_one, result_test1);

    double test_2[3][3] = {{0.65, -3.874, 879.333},
                           {0, -3.13, -1000.25},
                           {50.0, -42.66, 30.89}};

    Matrix test_two = {3,3,*test_2};
    double result_test2 = test_2[0][0] + test_2[1][1] + test_2[2][2];
    TEST_EQUAL(test_two, result_test2);

    double test_3[4][4] = {{-50.34, 100.89, 0, -30.99},
                           {123.44, 98.21, -156.72, 500.0},
                           {-35.77, 0.93, -0.002, 142.28},
                           {12.23, 34.45, -60.78, 32.99}};
    Matrix test_three = {4,4,*test_3};
    double result_test3 = test_3[0][0] + test_3[1][1] + test_3[2][2] + test_3[3][3];
    TEST_EQUAL(test_three, result_test3);

    return 0;
}

