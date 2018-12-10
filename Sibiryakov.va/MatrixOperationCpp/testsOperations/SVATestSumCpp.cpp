#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

#include "../MatrixOperation.h"

int main() {


    double test_21[2][2] = {{-2.8, 33.6},
                            {-58.67, 33.9}};
    double test_22[2][2] = {{0.33, -15.6},
                            {900.87, -9.87}};
    double res_2[2][2] = {{-2.47, 18.0},
                          {842.2, 24.03}};
    double res_22[2][2] = {{-2.47, 18.0},
                          {842.2, 24.03}};

   /* double 123test_21[2][2] = {{-2.8, 33.6},
                            {-58.67, 33.9}};
    double 123test_22[2][2] = {{0.33, -15.6},
                            {900.87, -9.87}};
    double 123res_2[2][2] = {{-2.47, 18.0},
                          {842.2, 24.03}}; */

    Matrix A2(2);
    A2.data = *test_21;

    Matrix B2(2);
    B2.data = *test_22;

    Matrix res2(2);
    res2.data = *res_2;

    Matrix res22(2);
    res22.data = *res_22;

    if (res22 != (A2+B2)) {
        return 1;
    }

    double test_11[1][1] = {1.8};
    double test_12[1][1] = {-2.5};
    double res_1[1][1] = {-0.7};

    Matrix A1(1);
    A1.data = *test_11;
    Matrix B1(1);
    B1.data = *test_12;

    Matrix res1(1);
    res1.data = *res_1;

    if ((A1+B1) != res1) {
        return 1;
    }

    double test_31[3][3] = {{9.55, -98.7, 103.10},
                            {0.0, 55.67, -5.0},
                            {-33.87, -90.11, 13.0}};
    double test_32[3][3] = {{300.0, -95.90, 0.43},
                            {0.99, -50.48, 100.23},
                            {90.85, -13.4, 0.0}};
    double res_3[3][3] = {{309.55, -194.6, 103.53},
                          {0.99, 5.19, 95.23},
                          {56.98, -103.51, 13.0}};

    Matrix A3(3);
    A3.data = *test_31;
    Matrix B3(3);
    B3.data = *test_32;
    Matrix res3(3);
    res3.data = *res_3;

    if ((A3+B3) != res3) {
        return 1;
    }

    double test_41[4][4] = {{10.0, -20.2, 30.4, -40.6},
                            {5.0, -10.2, 15.4, -20.6},
                            {2.5, -5.02, 7.54, -10.06},
                            {1.25, -2.52, 5.04, -7.56}};
    double test_42[4][4] = {{1.1, 3.3, -7.7, 11.11},
                            {19.19, 23.23, -29.29, 31.31},
                            {34.34, 37.37, -39.39, 41.41},
                            {43.43, 47.47, -51.51, 53.53}};
    double res_4[4][4] = {{11.1, -16.9, 22.7, -29.49},
                          {24.19, 13.03, -13.89, 10.71},
                          {36.84, 32.35, -31.85, 31.35},
                          {44.68, 44.95, -46.47, 45.97}};

    Matrix A4(4);
    A4.data = *test_41;
    Matrix B4(4);
    B4.data = *test_42;
    Matrix res4(4);
    res4.data = *res_4;

    if ((A4+B4) != res4) {
        return 1;
    }

    return 0;
}