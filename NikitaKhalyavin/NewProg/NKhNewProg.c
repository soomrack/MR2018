#include <stdio.h>
#include "../../matrix.h"

int main(){
    Matrix M = matrix_rand(3,3);
    matrix_print(M);
    Matrix O = matrix_one(3,3);
    matrix_print(matrix_exp(O));
    return 0;
}