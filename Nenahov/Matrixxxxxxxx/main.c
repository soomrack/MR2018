#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Matrixbiblio.h"
/*
typedef struct {
    unsigned int rows;
    unsigned int cols;
    double* data;
} Matrix;*/


int main() {

    Matrix A;
    srand(time(NULL));
    A.rows=3;
    A.cols=3;
    A.data=malloc(A.cols*A.rows*sizeof(double));

   /*  A.data = (double**) malloc (sizeof (double*) * A.rows);
    for (int i = 0; i < A.rows; i++) {
        A.data [i] = (int*) malloc (sizeof (int)*A.cols);
    }*/

    for(int t=0;t<A.rows;t++)
    {
        for(int i=0;i<A.rows;i++)
        {
          A.data[i+t*A.rows]=rand();
        }
    }
    matrix_print(A);
    printf("trace=%4.2lf",matrix_trace(A));

    return 0;
}