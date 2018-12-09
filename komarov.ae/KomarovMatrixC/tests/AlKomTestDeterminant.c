#include <stdio.h>
#include "../komarovMatrixLibC.h"

int returnCode = 0;

void TEST_EQUAL(double expected, double value)
{
    printf("Testing:  Expected:%10.0f\t  Value:%10.0f\t\t", expected, value);
    double v = value;
    if( v != expected )
    {
        printf("TEST FAILED!\n");
        returnCode = 1;
    }
    else
    {
        printf("PASSED \n");
    }
}


int main()
{
    returnCode = 0;

    printf("Starting tests on determinant...\n\n");

    double dA[2][2] = {1.0,0.0,0.0,1.0};            //единичная матрица 2х2
    Matrix A = {2, 2, *dA};
    TEST_EQUAL( matrix_determinant(A),  1  );

    double dB[2][2] = {1.0,1.0,0.0,0.0};
    Matrix B = {2, 2, *dB};
    TEST_EQUAL( matrix_determinant(B),  0  );

    double dC[2][2] = {6.0,-3.0,2.0,48.0};
    Matrix C = {2, 2, *dC};
    TEST_EQUAL( matrix_determinant(C),  294  );

    double dD[3][3] = {1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0}; //единичная матрица 3х3
    Matrix D = {3, 3, *dD};
    TEST_EQUAL( matrix_determinant(D),  1  );

    double dE[3][3] = {75.0,98.0,45.0,-12.0,1.0,0.0,8.0,0.0,1.0};
    Matrix E = {3, 3, *dE};
    TEST_EQUAL( matrix_determinant(E),  891  );

    double dF[4][4] = {1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0}; //единичная матрица 4х4
    Matrix F = {4, 4, *dF};
    TEST_EQUAL( matrix_determinant(F),  1  );

    double dG[4][4] = {1.0,74.0,0.0,855.0,0.0,1.0,0.0,-100.0,59.0,0.0,1.0,0.0,11.0,0.0,-12.0,1.0};
    Matrix G = {4, 4, *dG};
    TEST_EQUAL( matrix_determinant(G),  -5935344  );

    double dH[2][2] = {1.0,1.0,0.0,0.0};
    Matrix H = {2, 2, *dH};
    TEST_EQUAL( matrix_determinant(H),  0  );
    if( returnCode == 0 )
    {
        printf("\n");
        printf("ALL TESTS PASSED!\n");
    }
    return returnCode;
}