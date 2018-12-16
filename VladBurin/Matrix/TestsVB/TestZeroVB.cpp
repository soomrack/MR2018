//
// Created by vladburin on 03.12.18.
//


using namespace std;
#include <stdio.h>
#include <math.h>
#include "../matrix.h"
#include <stdlib.h>
#include <iostream>






int main () {


    vector<double> ResultData1={0};
    Matrix Result1(1,1,ResultData1);


    Matrix Test1(1);

    Test1.zero();

    if(!((Test1)==Result1))
    {
        return 1;
    };
    ////

    vector<double> ResultData2 = {0,    0,
                                  0,    0};
    Matrix Result2(2, 2, ResultData2);

    Matrix Test2(2);

    Test2.zero();

    if(!((Test2)==Result2))
    {
        return 1;
    };
    ////

    vector<double> ResultData3 = {0,    0,   0,
                                  0,    0,   0,
                                  0,    0,   0};
    Matrix Result3(3, 3, ResultData3);

    Matrix Test3(3);
    Test3.zero();

    if(!((Test3)==Result3))
    {
        return 1;
    };
    ////

    vector<double> ResultData4 = {0,    0,   0,     0,  0,  0,
                                  0,    0,   0,     0,  0,  0,
                                  0,    0,   0,     0,  0,  0,
                                  0,    0,   0,     0,  0,  0};

    Matrix Result4(4, 6, ResultData4);

    Matrix Test4(4,6);
    Test3.zero();

    if(!((Test3)==Result3))
    {
        return 1;
    };
    ////

    return 0;
}
