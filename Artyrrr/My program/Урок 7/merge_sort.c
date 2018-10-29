#include <stdio.h>
#include <stdlib.h>

#define N_MAX 10

void merge(int A[], size_t N, size_t middle)
{
    int *B = &A[middle];
    size_t A_size = middle;
    size_t B_size = N - middle;

    int C[A_size + B_size];
    int i = 0, j = 0, k = 0;
    while (i < A_size && j < B_size) {
        if (A[i] < B[j]) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }
    while (i < A_size) C[k++] = A[i++];
    while (j < B_size) C[k++] = B[j++];
    for(int i = 0; i < N; i++) A[i] = C[i];
}

void merge_sort(int A[], size_t N)
{
    if (N <= 1)
        return;
    else {
    int middle = N/2;
    merge_sort(A, middle);
    merge_sort(A + middle, N - middle);
    merge(A, N, middle);
    }
}

void print_array(int A[], size_t N)
{
    for(int i = 0; i < N; i++)
        printf("%4d", A[i]);
    printf("\n");
}

void init_array(int A[], size_t N)
{
        for(int i = 0; i < N; i++)
        A[i] = rand()%100;
}

void test_sort_function()
{

}

int main()
{
    int A[N_MAX];
    int N = N_MAX;

    init_array(A, N);
    print_array(A, N);
    merge_sort(A, N);
    print_array(A, N);

    return 0;
}
