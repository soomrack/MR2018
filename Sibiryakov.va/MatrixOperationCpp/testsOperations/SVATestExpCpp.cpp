#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

#include "../MatrixOperation.h"



int main() {
    double test1[3][3] =  {{1.0, 0.0, 0.0},
                           {2.0, 2.0, 0.0},
                           {1.0, 4.0, 7.0}};

    double res1[3][3] = {{2.7183, 0.0, 0.0},
                         {9.3415, 7.3891, 0.0},
                         {466.56, 871.39, 1.096e+3}};

    Matrix A1(3);
    A1.data = *test1;
    Matrix result1(3);
    result1.data = *res1;

    if (A1.Exp() != result1) {
        return 1;
    }

    return 0;
}

