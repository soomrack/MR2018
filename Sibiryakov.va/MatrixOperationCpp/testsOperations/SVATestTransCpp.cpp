#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

#include "../MatrixOperation.h"

int main() {
  /*  double test_2[1][5] = {{5.0, -6.0, 3.0, -2.0, 1.27}};

    double result_2[5][1] = {{5.0},
                             {-6.0},
                             {3.0},
                             {-2.0},
                             {1.27}};

    Matrix A1(1,5);
    A1.data = *test_2;
    Matrix res1(5,1);
    res1.data = *result_2;

    if (res1 != A1.Trans()) {
        return 1;
    } */

    double test_1[2][3] = {{1.0, 2.0, 3.0},
                           {4.0, 5.0, 6.0}};

    double result_1[3][2] = {{1.0, 4.0},
                             {2.0, 5.0},
                             {3.0, 6.0}};
    Matrix A1(2,3);
    A1.data = *test_1;
    Matrix res1(3,2);
    res1.data = *result_1;

    if (res1 != A1.Trans()) {
        return 1;
    }
    else {
        cout << "test1 is passed successfully!" << endl;
    }



    double test_2[3][6] = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0},
                           {7.0, 8.0, 9.0, 10.0, 11.0, 12.0},
                           {13.0, 14.0, 15.0, 16.0, 17.0, 18.0}};

    double result_2[6][3] = {{1.0, 7.0, 13.0},
                             {2.0, 8.0, 14.0},
                             {3.0, 9.0, 15.0},
                             {4.0, 10.0, 16.0},
                             {5.0, 11.0, 17.0},
                             {6.0, 12.0, 18.0}};

    Matrix A2(3,6);
    A2.data = *test_2;
    Matrix res2(6,3);
    res2.data = *result_2;

    if (res2 != A2.Trans()) {
        return 1;
    }
    else {
        cout << "test2 is passed successfully!" << endl;
    }

    return 0;
}

