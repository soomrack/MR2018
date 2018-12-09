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
    cout << endl << "Matrix Invert "  STRINGIFY(matrix) "         ";                      \
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

    vector<double> Data11={-1.8,       5.6,
                           112.5,     909.86};
    Matrix Test11(2,2,Data11);

    vector<double> ResultData1={-0.401,	0.00247,
                                0.0496,	0.000794};
    Matrix Result1(2,2,ResultData1);

    Matrix Test1=matrix_invert(Test11);

    TEST_EQUAL( Test1, Result1 );
    ////
    vector<double> Data22 = {-8.2,	4.1,	5.57,
                             6.5,	-2.22,	-5.3,
                             7.6,	54.0, 	9.9};
    Matrix Test22(3, 3, Data22);

    vector<double> ResultData2 = {-0.483,	-0.476,	   0.0171,
                                  0.191,    0.226,	   0.0133,
                                  -0.673,	-0.867,    0.0155};
    Matrix Result2(3, 3, ResultData2);

    Matrix Test2=matrix_invert(Test22);
    ////
    TEST_EQUAL(Test2, Result2);


    vector<double> Data33 = {4.22,      -5.56,	    8.8,	    -5.13,
                             -8.2,       4.35,      -8.266,	    5.4,
                             4.5,       -6.447,     -6.2,	    1.22,
                             -9.65,     5.26,       5.56,	    3.65};

    Matrix Test33(4, 4, Data33);

    vector<double> ResultData3 = {-0.227,	-0.256,	    0.0565,	    0.0413,
                                  -0.165,	-0.112,	    -0.112,	    -0.0295,
                                  -0.0492,	-0.132,	    0.0441,	    0.111,
                                  -0.287,	-0.316,	    0.244,	    0.256};
    Matrix Result3(4, 4, ResultData3);

    Matrix Test3=matrix_invert(Test33);
    TEST_EQUAL(Test3, Result3);

}
