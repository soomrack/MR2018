//
// Created by vladburin on 30.11.18.
//

#include "Matrix/matrix.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{

    vector<double> Data1={1,	6,
                          2,	5};

    Matrix A(2,2,Data1);


    vector<double> Data2={3,	2,	    68,	    8,
                          1,	43,	    6,	    9,
                          2,	6,	    5,	    21};
        
    Matrix B(3,4,Data2);

    Matrix C= matrix_invert(A);
    matrix_print(C);



    return 0;
}

