#include "matrix.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZEMATRIX 3

int main() {
    Matrix A;
    A.cols = SIZEMATRIX;
    A.rows = SIZEMATRIX;
    A.data = malloc(SIZEMATRIX * SIZEMATRIX * sizeof(double));
    for(int i=0; i<SIZEMATRIX*SIZEMATRIX; i++)
        A.data[i]=(i+1);
    matrix_print(A);
    printf("____________________________\n");
    Matrix B;
    B.cols = 7;
    B.rows = 2;
    B.data = malloc(7 * 2 * sizeof(double));
    for(int i=0; i<7*2; i++)
        B.data[i]=i+1;
    matrix_print(B);
    printf("____________________________%lf\n", matrix_determinant(A));
    matrix_print(matrix_exp(A));
    return 0;
}
