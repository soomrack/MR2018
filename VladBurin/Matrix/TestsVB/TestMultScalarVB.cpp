//
// Created by vladburin on 01.12.18.
//

using namespace std;
#include <stdio.h>
#include <math.h>
#include "../matrix.h"
#include <stdlib.h>
#include <iostream>




int main () {

    ////
    vector<double> Data11={-2};
    Matrix Test11(1,1,Data11);

    vector<double> ResultData1={-6};
    Matrix Result1(1,1,ResultData1);

    if(!((Test11*3)==Result1))
    {
        return 1;
    };
    ////
    vector<double> Data22={4,	    -22.33,	    3.5,	    -7.6,
                           45.6,	-8.7,	    35.5,	    12,
                           -21, 	5,	        9.042,	    -9.1};
    Matrix Test22(3,4,Data22);

    vector<double> ResultData2={24,	    -133.98,	21,	        -45.6,
                                273.6,	-52.2,	    213,	    72,
                                -126,	30,     	54.252,	    -54.6};
    Matrix Result2(3,4,ResultData2);

    if(!((Test22*6)==Result2))
    {
        return 1;
    };
    ////
    vector<double> Data33={5,	        74.3,	    21.2,
                           -21.6,       2,	        25.32,
                           1,	        5.23,	    65,
                           -12.2,       6,	        7,
                           99,	        -77,        -99.1,
                           53.3,        -51.8,	    88.9};
    Matrix Test33(6,3,Data33);

    vector<double> ResultData3={-386.5,	    -5743.39,	-1638.76,
                                1669.68,    -154.6,	    -1957.236,
                                -77.3,	    -404.279,	-5024.5,
                                943.06, 	-463.8,	    -541.1,
                                -7652.7,	5952.1,	    7660.43,
                                -4120.09,	4004.14,	-6871.97};
    Matrix Result3(6,3,ResultData3);

    if(!((Test33*(-77.3))==Result3))
    {
        return 1;
    };
return 0;

}