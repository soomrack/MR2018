#include "matrixlib.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


int main () {
        srand(time(NULL));
        MatriXXX matrix1 = matrix1.matrix_rand(3,3);
        matrix1.matrix_print();
        MatriXXX matrix2 = matrix2.matrix_trans();
        matrix2.matrix_print();
    }
