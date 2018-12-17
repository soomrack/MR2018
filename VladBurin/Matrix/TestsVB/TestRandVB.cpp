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

#define TEST_EQUAL( matrix )   \
{                                                                           \
    cout << endl << "Matrix Rand "  STRINGIFY(matrix) "         ";                      \
    unsigned int counter= 0;                                                      \
    for (int i = 0; i < matrix.rows; i++) {                                \
        for (int j = 0; j < matrix.cols; j++) {                            \
            if (matrix.data[i*matrix.cols + j] <1   \
                && matrix.data[i*matrix.cols + j]>(-1))       \
                  {     \
                counter ++;                                                \
            }                                                                \
            else {                                                          \
                cout << endl << "Something wrong with "<<"Element["<<i<<"]"<<"["<<j<<"]"<< endl;                     \
                    \
                return 1;                                                \
                 }                                                                   \
        }                                                                       \
    }                                                                           \
    if (counter == matrix.rows * matrix.cols) {                                  \
         cout <<"Everything is fine! Thank you!\n"<<endl;                        \
    }                                                                          \
}


int main()
{

    Matrix Test1(1,1);
    Test1.random();
    TEST_EQUAL( Test1 );

    Matrix Test2(3,3);
    Test2.random();
    TEST_EQUAL( Test2 );

    Matrix Test3(2,6);
    Test3.random();
    TEST_EQUAL( Test3 );

    Matrix Test4(5,5);
    Test4.random();
    TEST_EQUAL( Test4 );

}