#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

#include "../MatrixOperation.h"

int main() {
    double test_1[2][2] = {{7.0, -3.0},
                           {4.0, -9.0}};

    Matrix A1(2,2);
    A1.data = *test_1;
    cout << A1.data[3] << endl;

    double res_2[2][2] = {{0.176, -0.0588},
                          {0.0784, -0.137}};

    Matrix res1(2,2);
    res1.data = *res_2;

    if (A1.Invert() != res1) {
        return 1;
    }

    double test_2[3][3] = {{-3.57, 5.28, -95.867},
                           {265.66, 0.0, -0.55},
                           {31.333, -55.827, 800.67}};
    double res_two[3][3] = {{-0.000103, 0.00376, -0.00001},
                            {-0.712, 0.000487, -0.0853},
                            {-0.0496, -0.000113, -0.0047}};
    Matrix A2(3);
    A2.data = *test_2;
    Matrix res2(3);
    res2.data = *res_two;

    if (A2.Invert() != res2) {
        return 1;
    }

    return 0;
}