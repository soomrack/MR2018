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


    vector<double> Data11={-1.8,       5.6,
                           112.5,     909.86};
    Matrix Test11(2,2,Data11);

    vector<double> ResultData1={-0.401,	0.00247,
                                0.0496,	0.000794};
    Matrix Result1(2,2,ResultData1);

    if(!((Test11.invert())==Result1))
    {
        return 1;
    };
    ////
    vector<double> Data22 = {-8.2,	4.1,	5.57,
                             6.5,	-2.22,	-5.3,
                             7.6,	54.0, 	9.9};
    Matrix Test22(3, 3, Data22);

    vector<double> ResultData2 = {-0.483,	-0.476,	   0.0171,
                                  0.191,    0.226,	   0.0133,
                                  -0.673,	-0.867,    0.0155};
    Matrix Result2(3, 3, ResultData2);

    if(!((Test22.invert())==Result2))
    {
        return 1;
    };


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

    if(!((Test22.invert())==Result2))
    {
        return 1;
    };
return 0;
}
