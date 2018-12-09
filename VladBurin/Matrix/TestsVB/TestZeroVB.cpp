//
// Created by vladburin on 03.12.18.
//


using namespace std;
#include <stdio.h>
#include <math.h>
#include "../matrix.h"
#include <stdlib.h>
#include <iostream>


#define STRINGIFY( x ) #x

#define TEST_EQUAL( matrix, expected )   \
{                                                                           \
    cout << endl << "Matrix Trans "  STRINGIFY(matrix) "         ";                      \
    unsigned int counter= 0;                                                      \
    for (int i = 0; i < matrix.rows; i++) {                                \
        for (int j = 0; j < matrix.cols; j++) {                            \
            if (    (fabs(0.99*matrix.data[i*matrix.cols + j]) <= fabs(expected.data[i*expected.cols+j]))  \
                && (fabs(1.01*matrix.data[i*matrix.cols + j]) >= fabs(expected.data[i*expected.cols+j]))        \
                 && (expected.data[i*expected.cols+j] * matrix.data[i*matrix.cols + j] >= 0)) {     \
                counter ++;                                                \
            }                                                                \
            else {                                                          \
                cout << endl << "Something wrong with "<<"Element["<<i<<"]"<<"["<<j<<"]"<< endl<<                     \
                "Expected: "<<expected.data[i*expected.cols+j]<<endl<<"But got: "<<matrix.data[i*matrix.cols + j] <<endl;                        \
                 }                                                                   \
        }                                                                       \
    }                                                                           \
    if (counter == matrix.rows * matrix.cols) {                                  \
         cout <<"Everything is fine! Thank you!\n"<<endl;                        \
    }                                                                          \
}



int main () {


    vector<double> ResultData1={0};
    Matrix Result1(1,1,ResultData1);

    Matrix Test1=matrix_zero(1,1);

    TEST_EQUAL( Test1, Result1 );
    ////

    vector<double> ResultData2 = {0,    0,
                                  0,    0};
    Matrix Result2(2, 2, ResultData2);

    Matrix Test2=matrix_zero(2,2);
    TEST_EQUAL(Test2, Result2);
    ////

    vector<double> ResultData3 = {0,    0,   0,
                                  0,    0,   0,
                                  0,    0,   0};
    Matrix Result3(3, 3, ResultData3);

    Matrix Test3=matrix_zero(3,3);
    TEST_EQUAL(Test3, Result3);
    ////

    vector<double> ResultData4 = {0,    0,   0,     0,
                                  0,    0,   0,     0,
                                  0,    0,   0,     0,
                                  0,    0,   0,     0};

    Matrix Result4(4, 4, ResultData4);

    Matrix Test4=matrix_zero(4,4);
    TEST_EQUAL(Test4, Result4);
    ////

    return 0;
}
