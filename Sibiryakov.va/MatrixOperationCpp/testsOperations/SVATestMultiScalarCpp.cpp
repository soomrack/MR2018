#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

#include "../MatrixOperation.h"

int main() {
    double test_1[3][3] = {{1.0, 5.0, 9.0},
                           {13.0, 17.0, 21.0},
                           {25.0, 29.0, 33.0}};
    double scalar1 = 4.0;
    double result1[3][3] = {{4.0, 20.0, 36.0},
                            {52.0, 68.0, 84.0},
                            {100.0, 116.0, 132.0}};
    Matrix A1(3);
    A1.data = *test_1;
    Matrix res1(3);
    res1.data = *result1;

    if ((A1 * scalar1) != res1) {
        return 1;
    }

    double test_2[5][2] = {{-0.56, 154.66},
                           {666.666, -907.43},
                           {0.002, 1897321.567},
                           {-20.34, -2000000.00},
                           {18.999, -5.32}};
    double scalar2 = 2.46;
    double result2[5][2] = {{-1.3776, 380.4636},
                            {1639.9984, -2232.2778},
                            {0.00492, 4667411.055},
                            {-50.0364, -4920000.00},
                            {46.7375, -13.0872}};

    Matrix A2(5,2);
    A2.data = *test_2;
    Matrix res2(5,2);
    res2.data = *result2;

    if ((A2 * scalar2) != res2) {
        return 1;
    }

    return 0;
}