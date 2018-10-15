//
// Created by Елизавета on 17.09.2018.
//


#include <stdio.h>
#include <stdlib.h>
#include "Elib.h"



void matrix_multiplication (int* A, int* B, int* C, int m, int n, int q)
{
for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            C[i*q+j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i*q+j] += A[i*n+k] * B[k*q+j];
            }
        }
    }
}







