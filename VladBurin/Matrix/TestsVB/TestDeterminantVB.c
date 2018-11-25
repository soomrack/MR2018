
#include <stdio.h>
#include <math.h>
#include "../MatrixOperations.h"
#include <malloc.h>
#include <stdlib.h>

#define STRINGIFY( x ) #x

#define TEST_EQUAL( matrix, expected )   \
{                                                                           \
    printf("%-40s","Testing "  STRINGIFY(matrix) " ");                       \
    double value = matrix_determinant(matrix);                               \
    if(     (fabs(1.005 * value) >= fabs(expected))                          \
         && (fabs(0.995 * value) <= fabs(expected))                          \
         && ((expected * value) >= 0))                                       \
    {                                                                        \
        printf("Everything is fine! Thank you!\n" );                                                 \
    }                                                                        \
    else                                                                     \
    {                                                                        \
        printf("FAIL! "                                                   \
               " Expected: %lf, got: %lf\n", expected, value);                  \
        return 1;                                                      \
    }                                                                             \
    printf("\n");                                                            \
}


int main() {
    double Test1data[1][1] = {6.8};
    Matrix Test1 = {1, 1, *Test1data};
    TEST_EQUAL(Test1, 6.8);

    double Test2data[2][2] = {{1.8,5.6},
                              {112.5,909.86}};
    Matrix Test2 = {2, 2, *Test2data};
    TEST_EQUAL(Test2, 1007.748);

    double Test3data[3][3] = {{8.2,	45.1,	56.57},
                              { 67.5,	24.22,	5.3},
                                { 77.6,	54.4,	9.9}};
    Matrix Test3 = {3, 3, *Test3data};
    TEST_EQUAL(Test3,89415.918);

    double Test4data[4][4] = {{4.22,	-5.56,	8.8,	-5.13},
    {8.2,	4.35	,-8.266,	5.4},
{4.5	,-6.447	,-6.2,	1.22},
{ -9.65,	5.26	,5.56,	3.65}};

    Matrix Test4 = {4, 4, *Test4data};
    TEST_EQUAL(Test4, -5545.3962);

    double Test5data[5][5] = {{1,	0	,0,	0,	0},
    {0,	1,	0,	0,	0},
    {0,	0,	1,	0,	0},
    {0,	0,	0,	1,	0},
    {0, 0,	0,	0,	1}};
    Matrix Test5 = {5, 5, *Test5data};
    TEST_EQUAL(Test5, 1);


    return 0;
}