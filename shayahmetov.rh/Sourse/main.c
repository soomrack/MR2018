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
        A.data[i]=(double)i*M_PI/6;
    matrix_print(A);
        return 0;
}
