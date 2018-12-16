//
// Created by vladburin on 16.12.18.
//
#include <math.h>
#include "../matrix.h"
#include <iostream>


int main()
{
    vector <double> Data1 =  {1.0, 0.0, 0.0,
                              2.0, 2.0, 0.0,
                              1.0, 4.0, 7.0};

    Matrix Test1(3,Data1);

    vector <double> ResultData1 = {2.7183, 0.0, 0.0,
                                   9.3415, 7.3891, 0.0,
                                   466.56, 871.39, 1.096e+3};

    Matrix Result1(3,ResultData1);


    if(!((Test1.exp())==Result1))
    {
        return 1;
    };

    //////

    vector <double> Data2 =  {1.0, 0.0,
                              0.0, 1.0};

    Matrix Test2(2,Data2);

    vector <double> ResultData2 = {2.7183, 0.0,
                                   0.0, 2.7183};

    Matrix Result2(2,ResultData2);


    if(!((Test2.exp())==Result2))
    {
        return 1;
    };

    //////

    vector <double> Data3 =  {1};

    Matrix Test3(1,Data3);

    vector <double> ResultData3 = {2.7183};

    Matrix Result3(1,ResultData3);


    if(!((Test3.exp())==Result3))
    {
        return 1;
    };
    /////

    vector <double> Data4 =  {1.0, 2.0,
                              3.0, 4.0};

    Matrix Test4(2,Data4);

    vector <double> ResultData4 = {51.969, 74.7366,
                                   112.1048, 164.0738};

    Matrix Result4(2,ResultData4);

    if(!((Test4.exp())==Result4))
    {
        return 1;
    };


    return 0;
}