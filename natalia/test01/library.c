#include "library.h"
#include <stdio.h>
int N = 2;


void multiplication (int*  A, int* B, int* C) {
    {
        int size = 2;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int r = 0; r < size; r++) {
                    if (r == 0) {
                        C[i * size + j] = A[i * size + r] * B[r * size + j];
                    }
                    else {
                        C[i * size + j] += A[i * size + r] * B[r * size + j];
                    }
                }
            }
        }
    }
}

