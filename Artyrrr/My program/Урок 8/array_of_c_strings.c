#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void array2d_print(int **A, int M, int N);
void array2d_memfree(int **A, int M, int N);
int ** array2d_memalloc(int M, int N);

int main()
{
    int **A = NULL;
    size_t M = 0, N = 0;
    printf("Array 2d sizes: ");
    scanf("%d%d", &M, &N);
    A = array2d_memalloc(M, N);
    for (int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        A[i][j] = i*M + j + 1;
    array2d_print(A, M, N);
    array2d_memfree(A, M, N);
    return 0;
}

int ** array2d_memalloc(int M, int N)
{
    int **A = (int **)calloc(sizeof(int *), N);
    if (A == NULL) return NULL;
    for(int i = 0; i < N; i++) {
        A[i] = (int *)calloc(sizeof(int), M);
        if (A[i] == NULL) {
            array2d_memfree(A, M, i);
            return NULL;
        }
    }
        return A;
}

void array2d_memfree(int **A, int M, int N)
{
    for (int i = 0; i < N; i++)
        free(A[i]);
    free(A);
}

void array2d_print(int **A, int M, int N)
{
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++){
                printf("%4d", A[i][j]);
        }
        printf("\n");
    }
}
