//
// Created by science on 16.09.18.
//

typedef struct {
    unsigned int rows;
    unsigned int cols;
    double* data;
} Matrix;



#include "librain.h"

#include <stdio.h>

//Procedure print value matrix
extern void matrix_print(const Matrix A) {
        for (int i = 0; i < A.cols*A.rows; i++) {
            printf("%5.1lf ", A.data[i]);
            if((i+1)%A.cols==0)
                printf("\n");
        }
}

