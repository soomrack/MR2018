#include <iostream>
#include <stdio.h>
#include <math.h>

#include "../MatrixOperation.h"

int main() {
    double result1[5][5] = {{1,0,0,0,0},
                            {0,1,0,0,0},
                            {0,0,1,0,0},
                            {0,0,0,1,0},
                            {0,0,0,0,1}};

    Matrix res(5);
    res.data = *result1;

    Matrix A(5);

    if(A.One() != res) {
        return 1;
    }

    double result2[10][10] = {{1,0,0,0,0,0,0,0,0,0},
                              {0,1,0,0,0,0,0,0,0,0},
                              {0,0,1,0,0,0,0,0,0,0},
                              {0,0,0,1,0,0,0,0,0,0},
                              {0,0,0,0,1,0,0,0,0,0},
                              {0,0,0,0,0,1,0,0,0,0},
                              {0,0,0,0,0,0,1,0,0,0},
                              {0,0,0,0,0,0,0,1,0,0},
                              {0,0,0,0,0,0,0,0,1,0},
                              {0,0,0,0,0,0,0,0,0,1}};

    Matrix res2(10);
    res2.data = *result2;

    Matrix B(10);

    if(B.One() != res2) {
        return 1;
    }

    return 0;
}
