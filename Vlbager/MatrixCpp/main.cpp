#include <iostream>
#include "matrix.h"

int main() {
    Matrix test = matrix_one(3);
    test.print();
/*
    Matrix test2 = test;
    test2.print();

    Matrix test3(3,3);
    test3 = test2;
    test3.print();
*/
    return 0;
}