#include <stdio.h>
#include "matrix.h"
#include "stdlib.h"
#include "time.h"
int main(){
    Matrix A;
    A.rows = 3;
    A.cols = 3;
    A.data = malloc(A.cols * A.rows * sizeof(double));
   matrix_trace(A);
   //matrix_eigen_values(A);
   printf("%s","determinant=");
    matrix_determinant(A);
    return 0;
}