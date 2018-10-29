#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ** _array;
    int M, N;
} Array2d;

Array2d Array2d_memalloc(int M, int N);

void Array2d_print(Array2d a);
void Array2d_memfree(Array2d *a);

int main()
{
    Array2d a;
    printf("Array 2d sizes: ");
    int M, N;
    scanf("%d%d", &M, &N);
    a = Array2d_memalloc(M, N);

    for (int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            a._array[i][j] = i*M + j + 1;

    Array2d_print(a);
    Array2d_memfree(&a);
    return 0;
}

Array2d Array2d_memalloc(int M, int N)
{
    Array2d a;
    a._array = (int **)calloc(sizeof(int *), N);
    if (a._array == NULL) {
        a.M = a.N = 0;
        return a;
    {
            a.M = a.N = 0;
            return a;
    }
    for(int i = 0; i < N; i++) {
        a._array[i] = (int *)calloc(sizeof(int), M);
        if (a._array[i] == NULL) {
            a.N = i;
            Array2d_memfree(&a);
            a.M = a.N = 0;
            return a;
        }
    }
    return a;
}
    for(int i = 0; i < N; i++) {
        a._array[i] = (int *)calloc(sizeof(int), M);
    if (a._array[i] == NULL) {
        a.N = i;
        Array2d_memfree(&a);
        a.M = a.N = 0;
        return a;
        }
    }
    a.M = M;
    a.N = N;
    return a;
}

void Array2d_memfree(Array2d *a)
{
    for (int i = 0; i < a->N; i++)
        free(a->_array);
    free(a->_array);
    a->M = a->N = 0;
}

void Array2d_print(Array2d a)
{
    for (int i = 0; i < a.N; i++) {
        for(int j = 0; j < a.M; j++){
                printf("%4d", a._array[i][j]);
        }
        printf("\n");
    }
}
