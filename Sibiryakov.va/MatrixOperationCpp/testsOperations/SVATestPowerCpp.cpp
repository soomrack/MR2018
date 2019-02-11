#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

#include "../MatrixOperation.h"

int main() {
    double test1[2][2] = {{-2.8, 33.6},
                          {-58.67, 33.9}};
    Matrix A(2);
    A.data = *test1;
    double res_power0[2][2] = {{1, 0},
                               {0, 1}};
    Matrix res_0(2);
    res_0.data = *res_power0;
    if (A.Power(0) != res_0) {
        return 1;
    }
    double res_power1[2][2] = {{-2.8, 33.6},
                               {-58.67, 33.9}};
    res_0.data = *res_power1;
    if (A.Power(1) != res_0) {
        return 1;
    }
    double res_power3[2][2] = {{-55810.0816, -30548.5152},
                               {53341.70794, -89177.061}};
    res_0.data = *res_power3;
    if (A.Power(3) != res_0) {
        return 1;
    }
    double res_power5[2][2] = {{165321483.6682976, -33205307.4257856},
                               {57980815.07948932, 129052591.3312044}};
    Matrix res_3(2);
    res_0.data = *res_power5;
    if (A.Power(5) != res_0) {
        return 1;
    }

    double test2[4][4] = {{1.1, 3.3, -7.7, 11.11},
                          {19.19, 23.23, -29.29, 31.31},
                          {34.34, 37.37, -39.39, 41.41},
                          {43.43, 47.47, -51.51, 53.53}};
    Matrix B(4);
    B.data = *test2;
    double res2_power0[4][4] = {{1, 0, 0, 0},
                                {0, 1, 0, 0},
                                {0, 0, 1, 0},
                                {0, 0, 0, 1}};
    Matrix res_1(4);
    res_1.data = *res2_power0;
    if (B.Power(0) != res_1) {
        return 1;
    }
    double res2_power1[4][4] = {{1.1, 3.3, -7.7, 11.11},
                                {19.19, 23.23, -29.29, 31.31},
                                {34.34, 37.37, -39.39, 41.41},
                                {43.43, 47.47, -51.51, 53.53}};
    res_1.data = *res2_power1;
    if (B.Power(1) != res_1) {
        return 1;
    }
    double res2_power4[4][4] = {{486174.15464651, 585664.46912402, -751810.9727755, 817476.8194758},
                                {1629042.06416012, 1967038.21586162, -2533080.10615706, 2758155.56222613},
                                {2457417.4611823, 2968687.78373885, -3825371.78840301, 4166444.38378695},
                                {3102700.83407638, 3748267.12892796, -4829996.07518668, 5260672.82166443}};
    res_1.data = *res2_power4;
    if (B.Power(4) != res_1) {
        return 1;
    }

    return 0;
}
