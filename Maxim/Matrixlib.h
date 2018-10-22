#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define width1 3
#define height1 4
#define width2 4
#define height2 5
void Matrix(){//int ar[size][size],int ar2[size][size]
    int **A = (int**)malloc(width1 * sizeof(int*));
    int **B = (int**)malloc(width2 * sizeof(int*));
    int **C = (int**)malloc(width1 * sizeof(int*));
    for (int i = 0; i <  height2; i++) {
        A[i] = (int *) malloc(height1 * sizeof(int));
    }
    for (int i = 0; i < height1; i++)
        {
        B[i] = (int*)malloc( height2 * sizeof(int));
        C[i] = (int*)malloc( height2 * sizeof(int));
    }
    srand(time(NULL));
    for (int i = 0; i < height1; i++)
        for (int j = 0; j < width1; j++)
        {
            A[i][j] = rand() % 10;
        }
    srand(time(NULL));
    for (int i = 0; i < height2; i++)
        for (int j = 0; j < width2; j++)
        {
            B[i][j] = rand() % 10;
        }
    srand(time(NULL));
    for(int i = 0; i <  height2; i++)
        for(int j = 0; j < width1; j++)
        {
            C[i][j] = 0;
            for(int k = 0; k < width2; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    printf("matrix A\n");
    for (int i = 0; i <  height1; i++)
    {
        for (int j = 0; j < width1; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    printf("\nmatrix B\n");
    for (int i = 0; i <  height2; i++)
    {
        for (int j = 0; j < width2; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }
    printf("\nthe result of multiplying\n");
    for (int i = 0; i <  height2; i++)
    {
        for (int j = 0; j < width1; j++)
            printf("%3d ", C[i][j]);
        printf("\n");
    }
    for (int i = 0; i < height2; i++)
    {
        free(B[i]);
        free(C[i]);
    }
    for (int i = 0; i < height1; i++)
    {
        free(A[i]);
    }
    free(A);
    free(B);
    free(C);
}