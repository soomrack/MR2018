#include <iostream>
#include "ClassMatrix.h"
#include <malloc.h>
#include <math.h>

int main() {
    std::cout << "Hello, World!" << std::endl;
    unsigned int size=3;
    ClassMatrix C;
    C.rows = size;
    C.cols = size;
    double *B = new double[C.rows * C.cols * sizeof(double)];

    for (int row = 0; row < C.rows; row++) {
        for (int col = 0; col < C.cols; col++) {
            B[row * size + col] = 2.0;
            std::cout <<"\t" << B[row * size + col];
            if (col == C.cols - 1) {
                std::cout <<"\n";
            }
        }
    }
    C.data = B;
    C.matrix_trace(C);
    delete B;
    return 0;
}