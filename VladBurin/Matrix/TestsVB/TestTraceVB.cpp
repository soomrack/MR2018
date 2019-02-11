//
// Created by vladburin on 30.11.18.
//

//
// Created by vladburin on 30.11.18.
//
#include <stdio.h>
#include <math.h>
#include "../matrix.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

#define STRINGIFY( x ) #x

#define TEST_EQUAL( matrix, expected )   \
{                                                                           \
   cout << endl << "Matrix Trace "  STRINGIFY(matrix) "         ";                      \
    double value = matrix.trace();                               \
    if(     (fabs(1.005 * value) >= fabs(expected))                          \
         && (fabs(0.995 * value) <= fabs(expected))                          \
         && ((expected * value) >= 0))                                       \
    {                                                                        \
        cout <<"Everything is fine! Thank you!\n"<<endl;                                                 \
    }                                                                        \
    else                                                                     \
    {                                                                        \
        cout<<"FAIL!" << endl << "Expected: "<< expected << ", got: "<< value << endl;                  \
        return 1;                                                \
                                                        \
    }                                                                             \
   cout << endl;                                                            \
}


int main() {
    vector<double> Test1data = {6.8};
    Matrix Test1(1, 1, Test1data);
    TEST_EQUAL(Test1, 6.8);


    vector<double> Test2data = {1.8,5.6,112.5,909.86};
    Matrix Test2 (2, 2, Test2data);
    TEST_EQUAL(Test2, 911.66);


    vector<double> Test3data = {8.2,	45.1,	56.57,
                                67.5,	24.22,	5.3,
                                77.6,	54.4,	9.9};
    Matrix Test3 (3, 3, Test3data);
    TEST_EQUAL(Test3,42.32);


    vector<double> Test4data= {4.22,	-5.56,	8.8,	-5.13,
                               8.2,	4.35	,-8.266,	5.4,
                               4.5	,-6.447	,-6.2,	1.22,
                               -9.65,	5.26	,5.56,	3.65};
    Matrix Test4 (4, 4, Test4data);
    TEST_EQUAL(Test4, 6.02);


    vector<double> Test5data= {
            3,	0	,0,	0,	3,
            0,	5,	0,	2,	0,
            0,	0,	7,	0,	5,
            0,	3,	0,	7,	0,
            4, 0,	0,	0,	9};
    Matrix Test5 (5, 5, Test5data);
    TEST_EQUAL(Test5, 31.0);


    return 0;
}
