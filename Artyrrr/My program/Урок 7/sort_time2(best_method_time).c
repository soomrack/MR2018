#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N_MAX 50000

void merge(int A[], size_t N, size_t middle);
void choise_sort(int A[], size_t N);
void merge_sort(int A[], size_t N);

void print_array(int A[], size_t N);
void init_array(int A[], size_t N);

int compareInt (const void * a, const void * b);

int main()
{
    stress_test(50000);

    return 0;
}

void bubble_sort(int A[], size_t N)
{
    for(int prohod = 1; prohod < N; prohod++)
        for(int i = 0; i < N - prohod; i++)
            if (A[i] > A[i+1]) {
                int tmp = A[i];
                    A[i] = A[i+1];
                    A[i+1] = tmp;

    }
}

int compareInt (const void * a, const void * b)
{
    if ( *(int*)a <  *(int*)b ) return -1;
    if ( *(int*)a == *(int*)b ) return 0;
    if ( *(int*)a >  *(int*)b ) return 1;
}

void choise_sort(int A[], size_t N)
{
    for(int pos = 0; pos < N - 1; pos++)
    //A[pos] -- временный минимум
        for(int i = pos + 1; i < N; i++)
            if (A[i] < A[pos]) {
                int tmp = A[i];
                    A[i] = A[pos];
                    A[pos] = tmp;

    }
}

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
        A[i] = rand()%50000;
}

void test_sort_function()
{

}

void stress_test(int N)
{
    clock_t t;

    int A[N];

    init_array(A, N);
    t = clock();
    merge_sort(A, N);
    t = clock() - t;
    printf("merge sort \t%d clicks (%f seconds)\n", t, ((float)t)/CLOCKS_PER_SEC);

    init_array(A, N);
    t = clock();
    choise_sort(A, N);
    t = clock() - t;
    printf("choise sort \t%d clicks (%f seconds)\n", t, ((float)t)/CLOCKS_PER_SEC);

    init_array(A, N);
    t = clock();
    bubble_sort(A, N);
    t = clock() - t;
    printf("bubble sort \t%d clicks (%f seconds)\n", t, ((float)t)/CLOCKS_PER_SEC);

    init_array(A, N);
    t = clock();
    qsort(A, N, sizeof(int), compareInt);
    t = clock() - t;
    printf("q_sort \t%d clicks (%f seconds)\n", t, ((float)t)/CLOCKS_PER_SEC);

    return 0;
}
