#include <stdio.h>
#include "matrix.h"
#include "stdlib.h"
#include "time.h"
int main(){
    Matrix A;
    A.rows = 10;
    A.cols = 10;
    A.data = malloc(A.cols * A.rows * sizeof(double));
    A=matrix_one(A.rows,A.cols);
   matrix_print(A);
  //matrix_trace(A);
   //matrix_eigen_values(A);
   //printf("%s","determinant=");
    matrix_determinant(A);
   // A=matrix_rand(A.cols,A.rows);
  //  matrix_print(A);
    // // Mat rix B=matrix_trans(A);
 // matrix_print(B);
  //Matrix H=matrix_zero(A.rows,A.cols);
 // matrix_print(H);
   // Matrix G=matrix_one(A.rows,A.cols);
 //    matrix_print(G);

    return 0;
}