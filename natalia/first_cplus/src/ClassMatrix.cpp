#include <iostream>
#include "ClassMatrix.h"

double ClassMatrix::matrix_trace(ClassMatrix A) {
    double sum=0.0;
    for (int i = 0; i < A.rows ; i++) {
        sum += A.data[i + A.cols * i];
    }
    std::cout << "\n Matrix trace = " << sum << std::endl;
    return sum;
}
