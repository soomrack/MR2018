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

    vector<double> Data11={-2};
    Matrix Test11(1,1,Data11);

    vector<double> ResultData1={-2};
    Matrix Result1(1,1,ResultData1);

    if(!((Test11.trans())==Result1))
    {
        return 1;
    };
    ////
    vector<double> Data22 = {1.8,       5.6,
                             112.5,     909.86};
    Matrix Test22(2, 2, Data22);

    vector<double> ResultData2 = {1.8,      112.5,
                                  5.6,    909.86};
    Matrix Result2(2, 2, ResultData2);

    if(!((Test22.trans())==Result2))
    {
        return 1;
    };
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

    if(!((Test33.trans())==Result3))
    {
        return 1;
    };
return 0;
}