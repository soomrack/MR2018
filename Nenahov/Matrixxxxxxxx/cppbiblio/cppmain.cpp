#include "library.h"
#include <iostream>


int main(){
    Matrixcpp A;
    A.matrix_rand(3,3);
    A.matrix_print();
    Matrixcpp B;
    B=A.matrix_trans();
    std::cout << std::endl;
    B.matrix_print();

return 0;
}