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
    vector<double> Data11={2};
    Matrix Test11(1,1,Data11);

    vector<double> Data12={-7};
    Matrix Test12(1,1,Data12);

    vector<double> ResultData1={-14};
    Matrix Result1(1,1,ResultData1);


    if(!((Test11*Test12)==Result1))
    {
        return 1;
    };
    ////
    vector<double> Data21={4.3,	    33,
                           1.9,	    1,
                           2,	    87.4,
                           3,	    99.2};
    Matrix Test21(4,2,Data21);

    vector<double> Data22={545.4,	6.3,    5.7,
                           98,      12,	    9.3,
                           };
    Matrix Test22(2,3,Data22);

    vector<double> ResultData2={5579.22,	423.09, 	331.41,
                                1134.26,	23.97, 	    20.13,
                                9656,	    1061.4, 	824.22,
                                11357.8,	1209.3, 	939.66};
    Matrix Result2(4,3,ResultData2);

    if(!((Test21*Test22)==Result2))
    {
        return 1;
    };
    ////
    vector<double> Data31={2.4,
                           1,
                           -2};
    Matrix Test31(3,1,Data31);

    vector<double> Data32={7.8, -11, 2.6, 3.5, 4,  5.8,
                           };
    Matrix Test32(1,6,Data32);

    vector<double> ResultData3={18.72,	-26.4,	6.24,	8.4,    9.6,	13.92,
                                7.8,	-11,	2.6,	3.5,	4,	    5.8,
                                -15.6,	22,	    -5.2,	-7,	    -8,	    -11.6};
    Matrix Result3(3,6,ResultData3);

    if(!((Test31*Test32)==Result3))
    {
        return 1;
    };
    vector<double> Data41={1.24,	-2,	    3,	    -4,
                           4,	    6,	    8,	    5.12,
                           4,	    356,	-8.99,	8,
                           5,	    -8.55,	7,	    -9};
    Matrix Test41(4,4,Data41);

    vector<double> Data42={1,	0,	    0,	    0,
                           0,	1,	    0,  	0,
                           0,	0,	    1,	    0,
                           0,	0,	    0,	    1};
    Matrix Test42(4,4,Data42);

    vector<double> ResultData4={1.24,	-2,	    3,	    -4,
                                4,	    6,	    8,	    5.12,
                                4,	    356,	-8.99,	8,
                                5,	    -8.55,	7,	    -9};
    Matrix Result4(4,4,ResultData4);

    if(!((Test41*Test42)==Result4))
    {
        return 1;
    };

return 0;
}
