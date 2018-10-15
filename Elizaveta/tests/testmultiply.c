//
// Created by Елизавета on 17.09.2018.
//

#include <stdio.h>
#include <stdlib.h>
#include "../Elib.h"

#define M 2
#define N 3
#define Q 4

int main()
{
    int A[M][N], B[N][Q];

    int T[M][Q] = {{5, 8, 11, 14}, {8, 14, 20, 26}};
    int C[M][Q] = {{0, 0, 0, 0}, {0, 0, 0, 0}};

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = i+j;

        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < Q; j++)
        {
            B[i][j] = i+j;
        }
    }

    matrix_multiplication (*A, *B, *C, M, N, Q);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < Q; j++)
        {
            if (C[i][j] != T[i][j])
            {
                return 1;
            }
        }
    }



    return 0;
}