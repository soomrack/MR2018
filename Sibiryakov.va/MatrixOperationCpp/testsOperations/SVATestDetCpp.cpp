#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

#include "../MatrixOperation.h"


#define TEST_EQUAL( value, expected )                                        \
{                                                                           \
    if(     (fabs(1.003 * value) >= fabs(expected))                          \
         && (fabs(0.997 * value) <= fabs(expected))                          \
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
} \

int main() {

    double test_1[1][1] = {5.2};

    Matrix A(1,1);
    A.data = *test_1;

    TEST_EQUAL(A.Determinant(), 5.2);

    double test_2[2][2] = {{1.8, 2.5},
                           {-3.4, -9.7}};

    Matrix B(2,2);
    B.data = *test_2;

    TEST_EQUAL(B.Determinant(), -8.96);

    double test_3[3][3] = {{-9.876, -3.647, 29.87},
                           {83.0, -92.97, -103.97},
                           {-150.30, 0.965, 1.99}};

    Matrix C(3,3);
    C.data = *test_3;

    TEST_EQUAL(C.Determinant(), -470744.626334);

    double test_4[4][4] = {{-5.356, 98.756, 144.98, 903.87},
                           {387.76, -0.975, -1.87, 76.5},
                           {30.56, 25.12, 20.09, 21.10},
                           {-30.57, 28.76, 98.88, -23.90}};

    Matrix D(4,4);
    D.data = *test_4;

    TEST_EQUAL(D.Determinant(), -648038614.68028);

    return 0;
}

