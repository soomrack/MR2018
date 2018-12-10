#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

#include "../MatrixOperation.h"


static int checkingResult (unsigned size, vector < vector <double> > testing_matrix) {
    enum resultTest {Passed, Failed};

    Matrix A(size);

    double array[size][size];

    for (unsigned row = 0; row < size; row++) {
        for (unsigned col = 0; col < size; col++) {
            array[row][col] = testing_matrix[row][col];
        }
    }

    A.data = *array;

    double result = 0;

    for (unsigned diagonal = 0; diagonal < size; diagonal ++) {
        result += testing_matrix[diagonal][diagonal];
    }

    double resultTrace = A.Trace();

    if (resultTrace != result) {
        cout << "expected:" << result
        << "result:" << resultTrace << endl;
        return Failed;
    }
    else {
        cout << "Test is passed succesfully!" << endl;
        return Passed;
    }
}

int main() {

    vector <vector <double> > test1 = {{3.8, -59.35},
                                      {90.37, -0.98}};

    if (checkingResult(2, test1) == 1) {
        return 1;
    }

    vector < vector <double> > test2 = {{0.65, -3.874, 879.333},
                                        {0, -3.13, -1000.25},
                                        {50.0, -42.66, 30.89}};

    Matrix test(3,3);


    if (checkingResult(3, test2) == 1) {
        return 1;
    }

    vector < vector <double> > test3 = {{-50.34, 100.89, 0, -30.99},
                                        {123.44, 98.21, -156.72, 500.0},
                                        {-35.77, 0.93, -0.002, 142.28},
                                        {12.23, 34.45, -60.78, 32.99}};

    if (checkingResult(4, test3) == 1) {
        return 1;
    }

    return 0;
}