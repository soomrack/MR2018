#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

#include "../MatrixOperation.h"

int main() {
    double test_1_1[2][2] = {{-3.85, 0.97},
                             {50.0, -156.75}};
    double test_1_2[2][2] = {{-23.67, 105.88},
                             {0, -30.99}};
    double result_1[2][2] = {{91.1295, -437.6938},
                             {-1183.5, 10151.6825}};

    Matrix A1(2);
    A1.data = *test_1_1;
    Matrix B1(2);
    B1.data = *test_1_2;
    Matrix res1(2);
    res1.data = *result_1;

    if ((A1 * B1) != res1 ) {
        return 1;
    }

    double test_2_1[3][4] = {{-58.0, 33.87, 12.99, -0.38},
                             {0.0, -33.85, 420.98, -32.88},
                             {-13.88, 53.9, -23.57, 0.43}};
    double test_2_2[4][3] = {{-22.83, 0.88, 143.82},
                             {88.37, -5.06, 3.48},
                             {-33.90, 0.23, -20.36},
                             {0.0, 12.34, -88.756}};
    double result_2[3][3] = {{3876.8709, -224.1237, -8454.44152},
                             {-17262.5465, -137.6328, -5770.65352},
                             {5879.0464, -285.0633, -1366.92948}};
    Matrix A2(3,4);
    A2.data = *test_2_1;
    Matrix B2(4,3);
    B2.data = *test_2_2;
    Matrix res2(3,3);
    res2.data = *result_2;

    if ((A2 * B2) != res2 ) {
        return 1;
    }

    return 0;
}