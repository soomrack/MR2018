#include <stdio.h>
#include <math.h>
#include "../matrix.h"
#include <malloc.h>

#define STRINGIFY( x ) #x

#define TEST_EQUAL( matrix, expected )                                        \
{                                                                           \
    printf("%-40s","Testing "  STRINGIFY(matrix) " ");                       \
    double value = matrix_determinant(matrix);                               \
    if(     (fabs(1.005 * value) >= fabs(expected))                          \
         && (fabs(0.995 * value) <= fabs(expected))                          \
         && ((expected * value) >= 0))                                       \
    {                                                                        \
        printf("Test is completed successfully!\n" );                                                 \
    }                                                                        \
    else                                                                     \
    {                                                                        \
        printf("Error! "                                                   \
               " Expected: %lf, got %lf\n", expected, value);                  \
        return 1;                                                      \
    }                                                                             \
    printf("\n");                                                            \
}


int main() {
    double test_1[1][1] = {5.2};
    Matrix test_one = {1, 1, *test_1};
    TEST_EQUAL(test_one, 5.2);


    double test_2[2][2] = {{1.8, 2.5},
                            {-3.4, -9.7}};
    Matrix test_two = {2, 2, *test_2};
    TEST_EQUAL(test_two, -8.96);

    double test_3[3][3] = {{-9.876, -3.647, 29.87},
                           {83.0, -92.97, -103.97},
                           {-150.30, 0.965, 1.99}};
    Matrix test_three = {3, 3, *test_3};
    TEST_EQUAL(test_three, -470544.6263);

    double test_4[4][4] = {{-5.356, 98.756, 144.98, 903.87},
                           {387.76, -0.975, -1.87, 76.5},
                           {30.56, 25.12, 20.09, 21.10},
                           {-30.57, 28.76, 98.88, -23.90}};
    Matrix test_four = {4,4,*test_4};
    TEST_EQUAL(test_four, -648038614.6802);

    return 0;
}