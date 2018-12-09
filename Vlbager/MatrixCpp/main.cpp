#include <iostream>
#include "matrix.hpp"

int main() {

    Matrix test(3);
    test.rand();
    test.print();

    Matrix eigenValues = test.eigenValues();
    eigenValues.print();

    Matrix eigenVectors = test.eigenVectors();
    eigenVectors.print();

    return 0;
}