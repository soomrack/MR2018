#include <iostream>
#include <stdio.h>
#include <math.h>

#include "../MatrixOperation.h"


int main() {
    double test1[1][1] = {0.0};

    Matrix result1(1);
    result1.data = *test1;

    Matrix A(1);

    if (A.Zero() != result1) {
        return 1;
    }

    double test3[2][2] = {{0.0, 0.0},
                          {0.0, 0.0}};
    Matrix result3(2);
    result3.data = *test3;

    Matrix C(2);

    if ( C.Zero() != result3) {
        return 1;
    }

    double test4[2][3] = {{0.0, 0.0, 0.0},
                          {0.0, 0.0, 0.0}};
    Matrix result4(2,3);
    result4.data = *test4;

    Matrix D(2,3);

    if (D.Zero() != result4) {
        return 1;
    }


    double test5[4][2] = {{0.0, 0.0},
                          {0.0, 0.0},
                          {0.0, 0.0},
                          {0.0, 0.0}};
    Matrix result5(4,2);
    result5.data = *test5;

    Matrix E(4,2);

    if (E.Zero() != result5) {
        return 1;
    }


    return 0;
}
