#include <stdio.h>
#include "matrix.h"
#include <malloc.h>

double sum;

Matrix matrix_trace(const Matrix A)
{
    sum=0.0;
    for (int i = 0; i < A.rows; i++) {
        sum += A.data[i + A.cols * i];
    }
    printf("\n trace = %f",sum);
}


int main() {
    unsigned int size=2;
    double* B;
    Matrix C;
    C.rows = size;
    C.cols = size;

    B = malloc(C.rows * C.cols * sizeof(double));

    for (int row = 0; row < C.rows; row++) {
        for (int col = 0; col < C.cols; col++) {
            B[row * size + col] = 1.0;
            printf("%f \t", B[row * size + col]);
            if (col == C.cols - 1) {
                printf("\n");
            }
        }
    }
    C.data = B;
    //printf("\n111 %d %d \n", C.rows, C.cols);
    matrix_trace(C);
    //printf("\n111  %f \n",sum);
    return 0;
}