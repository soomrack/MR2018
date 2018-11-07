#include "library.h"
#include <stdio.h>
int N = 2;


int multiply (int  A[N][N],B[N][N]) {
    int i;
    int j;
    int k;
    int C[i][j];
    for(i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = 0;
            for (k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    for(i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d", C[i][j]);
        }
    }
    return C[i][j];
}

