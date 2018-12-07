#include <stdio.h>
#include "../komarovMatrixLibC.h"

int returnCode = 0;

void TEST_EQUAL(const Matrix A, const Matrix B, int number)
{
    int flag = 0;
    for(int i = 0 ; i < A.rows ; i++) {
        for(int j = 0 ; j < A.cols ; j++) {
            if(A.data[A.cols * i + j] != B.data[B.cols * i + j]){
                flag = 1;
            }
        }
    }
    printf("Testing:  test number %4d\t\t", number);
    if( flag != 0 )
    {
        printf("TEST FAILED!\n");
        returnCode = 1;
    }
    else
    {
        printf("PASSED \n");
    }
}

int main(){
    returnCode = 0;
    int counter = 1;
    printf("Starting tests on matrix_sum...\n\n");

    double dA[2][2] = {1.0,4.0,0.0,-29.0};
    Matrix A = {2, 2, *dA};
    double dB[2][2] = {-78.0,47.0,0.0,1.0};
    Matrix B = {2, 2, *dB};
    double Answer1[2][2] = {-77.0,51.0,0.0,-28.0};
    Matrix AnswerAB = {2, 2, *Answer1};
    TEST_EQUAL( matrix_sum( A, B), AnswerAB, counter );
    counter++;

    double dC[2][3] = {78.0,144.0,789.0,-229.0,45.0,1.0};
    Matrix C = {2, 3, *dC};
    double dD[2][3] = {-78.0,47.0,0.0,1.0,784.0,-1.0};
    Matrix D = {2, 3, *dD};
    double Answer2[2][3] = {0.0,191.0,789.0,-228.0,829.0,0.0};
    Matrix AnswerCD = {2, 3, *Answer2};
    TEST_EQUAL( matrix_sum( C, D), AnswerCD, counter );
    counter++;

    double dE[5][3] = {78.0,144.0,789.0,-229.0,45.0,1.0,0.0,-78.0,12.0,64.0,100.0,87.0,14.0,-96.0,97.0};
    Matrix E = {5, 3, *dE};
    double dF[5][3] = {-78.0,-144.0,-789.0,229.0,-45.0,-1.0,0.0,78.0,-12.0,-64.0,-100.0,-87.0,-14.0,96.0,-97.0};
    Matrix F = {5, 3, *dF};
    double Answer3[5][3] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
    Matrix AnswerEF = {5, 3, *Answer3};
    TEST_EQUAL( matrix_sum( E, F), AnswerEF, counter );
    counter++;

    double dG[1][1] = {-7.0};
    Matrix G = {1, 1, *dG};
    double dH[1][1] = {15.0};
    Matrix H = {1, 1, *dH};
    double Answer4[1][1] = {8.0};
    Matrix AnswerGH = {1, 1, *Answer4};
    TEST_EQUAL( matrix_sum( G, H), AnswerGH, counter );
    counter++;

    double dI[2][3] = {-7.0,-1.0,0.0,3.5,7.0,-3.0};
    Matrix I = {2, 3, *dI};
    double dJ[2][3] = {-5.0,6.0,1.0,2.0,1.5,-3.5};
    Matrix J = {2, 3, *dJ};
    double Answer5[2][3] = {-12.0,5.0,1.0,5.5,8.5,-6.5};
    Matrix AnswerIJ = {2, 3, *Answer5};
    TEST_EQUAL( matrix_sum( I, J), AnswerIJ, counter );
    counter++;

    if( returnCode == 0 )
    {
        printf("\n");
        printf("ALL TESTS PASSED!\n");
    }
    return returnCode;
}