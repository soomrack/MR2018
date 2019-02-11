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






int main () {

    ////
    vector<double> Data11={1.8,     5.6,
                           112.5,   909.86};
    Matrix Test11(2,2,Data11);

    vector<double> ResultData1={1,0,
                                0,1};
    Matrix Result1(2,2,ResultData1);


    if(!((Test11.power(0))==Result1))
    {
        return 1;
    };
    ////
    vector<double> Data22={1.8,     5.6,
                           112.5,   909.86};
    Matrix Test22(2,2,Data22);

    if(!((Test22.power(1))==Test22))
    {
        return 1;
    };
    ////
    vector<double> Data33={1,	6,
                           2,	5};
    Matrix Test33(2,2,Data33);

    vector<double> ResultData3={13,	36,
                                12,	37};
    Matrix Result3(2,2,ResultData3);

    if(!((Test33.power(2))==Result3))
    {
        return 1;
    };
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

    if(!((Test44.power(4))==Result4))
    {
        return 1;
    };

    
    return 0;
}
