//
// Created by vladburin on 01.12.18.
//
using namespace std;
#include <stdio.h>
#include <math.h>
#include "../matrix.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

#define STRINGIFY( x ) #x

#define TEST_EQUAL( matrix, expected )   \
{                                                                           \
    cout << endl << "Matrix Sum "  STRINGIFY(matrix) "         ";                      \
    unsigned int counter= 0;                                                      \
    for (int i = 0; i < matrix.rows; i++) {                                \
        for (int j = 0; j < matrix.cols; j++) {                            \
            if (    (fabs(0.99*matrix.data[i*matrix.cols + j]) <= fabs(expected.data[i*expected.cols+j]))  \
                && (fabs(1.01*matrix.data[i*matrix.cols + j]) >= fabs(expected.data[i*expected.cols+j]))    \
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
    vector<double> Data11={2};
    Matrix Test11(1,1,Data11);

    vector<double> Data12={-7};
    Matrix Test12(1,1,Data12);

    vector<double> ResultData1={-5};
    Matrix Result1(1,1,ResultData1);

    Matrix Test1=matrix_sum(Test11,Test12);

    TEST_EQUAL( Test1, Result1 );
    ////
    vector<double> Data21={4.3,	    33,
                           1.9,	    1,
                           2,	    87.4,
                           3,	    99.2};
    Matrix Test21(4,2,Data21);

    vector<double> Data22={545.4,	6.3,
                           5.7,	    98,
                           12,	    9.3,
                           7,	    1.1};
    Matrix Test22(4,2,Data22);

    vector<double> ResultData2={549.7,	39.3,
                                7.6,	99,
                                14,	    96.7,
                                10,	    100.3};
    Matrix Result2(4,2,ResultData2);

    Matrix Test2=matrix_sum(Test21,Test22);

    TEST_EQUAL( Test2, Result2);
    ////
    vector<double> Data31={2,1,2,
                          5,4,5,
                          6,9,2};
    Matrix Test31(3,3,Data31);

    vector<double> Data32={7.8, 11, 2.0,
                          3.5, 4,  5.8,
                          6.1, 7.9, 2};
    Matrix Test32(3,3,Data32);

    vector<double> ResultData3={9.8, 12, 4,
                          8.5, 8,  10.8,
                          12.1, 16.9, 4};
    Matrix Result3(3,3,ResultData3);

    Matrix Test3=matrix_sum(Test31,Test32);

    TEST_EQUAL( Test3, Result3 );
    ////
    vector<double> Data41={1.24,	-2,	    3,	    -4,
                           4,	    6,	    8,	    5.12,
                           4,	    356,	-8.99,	8,
                           5,	    -8.55,	7,	    -9,
                           234,     -23,	27,	    5.35};
    Matrix Test41(5,4,Data41);

    vector<double> Data42={4,	7,	    56,	    94,
                           1,	8,	    98, 	1,
                           -1,	34.33,	-42,	5,
                           38,	-6,	    57,	    0.234,
                           3,	345,	9,	    6};
    Matrix Test42(5,4,Data42);

    vector<double> ResultData4={5.24,	5,	        59, 	    90,
                                5,	    14,	        106,	    6.12,
                                3,	    390.33,	    -50.99,	    13,
                                43,	    -14.55,	    64,	        -8.766,
                                237,	322,	    36,	        11.35};
    Matrix Result4(5,4,ResultData4);

    Matrix Test4=matrix_sum(Test41,Test42);

    TEST_EQUAL( Test4, Result4 );


}