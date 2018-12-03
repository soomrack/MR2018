//
// Created by vladburin on 01.12.18.
//
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
    cout << endl << "Matrix Power "  STRINGIFY(matrix) "         ";                      \
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

    ////
    vector<double> Data11={1.8,     5.6,
                           112.5,   909.86};
    Matrix Test11(2,2,Data11);

    vector<double> ResultData1={1,0,
                                0,1};
    Matrix Result1(2,2,ResultData1);

    Matrix Test1=matrix_power(Test11,0);

    TEST_EQUAL( Test1, Result1 );
    ////
    vector<double> Data22={1.8,     5.6,
                           112.5,   909.86};
    Matrix Test22(2,2,Data22);

    Matrix Test2=matrix_power(Test22,1);

    TEST_EQUAL( Test2, Test22 );
    ////
    vector<double> Data33={1,	6,
                           2,	5};
    Matrix Test33(2,2,Data33);

    vector<double> ResultData3={13,	36,
                                12,	37};
    Matrix Result3(2,2,ResultData3);

    Matrix Test3=matrix_power(Test33,2);

    TEST_EQUAL( Test3, Result3 );
    ////
    vector<double> Data44={4.22,	-5.56,	    8.8,	    -5.13,
                           8.2,	    4.35,       -8.266, 	5.4,
                           4.5,     -6.447,     -6.2,	    1.22,
                           -9.65,	5.26,       5.56,	    3.65};
    Matrix Test44(4,4,Data44);

    vector<double> ResultData4={6724.627708916,	    -18857.1238209972,	-6923.70050815968,	-8331.049833146,
                                -10784.842481586,	4207.807712763004,	23965.1839666976,	-7401.44766797304,
                                -14065.5839717468,	4718.6364965976,	26988.962016705405,	-9958.4097031776,
                                8104.682646254,	    11140.96908219136,	-26631.10890319432,	18234.3213725444};
    Matrix Result4(4,4,ResultData4);

    Matrix Test4=matrix_power(Test44,4);

    TEST_EQUAL( Test4, Result4 );

}
