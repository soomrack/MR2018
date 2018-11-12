#include "library.h"
#include <iostream>


int main(){
    Matrixcpp A;
    A.matrix_rand(3,3);
    A.matrix_print();

    //std::cout << A.matrix_print(A) << std::endl;

return 0;
}