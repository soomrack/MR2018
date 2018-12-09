//
// Created by vladburin on 01.12.18.
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

    vector<double> Data11={-2};
    Matrix Test11(1,1,Data11);

    vector<double> ResultData1={-2};
    Matrix Result1(1,1,ResultData1);

    Matrix Test1=matrix_trans(Test11);

    TEST_EQUAL( Test1, Result1 );
    ////
    vector<double> Data22 = {1.8,       5.6,
                             112.5,     909.86};
    Matrix Test22(2, 2, Data22);

    vector<double> ResultData2 = {1.8,      112.5,
                                  5.6,    909.86};
    Matrix Result2(2, 2, ResultData2);

    Matrix Test2=matrix_trans(Test22);
    TEST_EQUAL(Test2, Result2);
    ////
    vector<double> Data33 = {4,	    -22.33,	    3.5,	    -7.6,
                             45.6,	-8.7,	    35.5,	    12,
                             -21, 	5,	        9.042,	    -9.1};
    Matrix Test33(3, 4, Data33);

    vector<double> ResultData3 = {4,        45.6,   -21,
                                  -22.33,   -8.7,   5,
                                  3.5,      35.5,   9.042,
                                  -7.6,     12,     -9.1};
    Matrix Result3(4, 3, ResultData3);

    Matrix Test3=matrix_trans(Test33);
    TEST_EQUAL(Test3, Result3);

}