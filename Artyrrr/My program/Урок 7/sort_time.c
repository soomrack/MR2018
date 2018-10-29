#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N_MAX 100000

void merge(int A[], size_t N, size_t middle);
void choise_sort(int A[], size_t N);
void merge_sort(int A[], size_t N);

void print_array(int A[], size_t N);

void init_array(int A[], size_t N);

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
        A[i] = rand()%10000;
}

void test_sort_function()
{

}

int main()
{
    stress_test(100000);

    return 0;
}

void stress_test(int N)
{
    time_t t1, t2;

    int A[N];

    init_array(A, N);
    t1 = time(NULL);
    merge_sort(A, N);
    t2 = time(NULL);
    printf("merge sort \tsec = %d\n", t2-t1);

    init_array(A, N);
    t1 = time(NULL);
    choise_sort(A, N);
    t2 = time(NULL);
    printf("choise sort \tsec = %d\n", t2-t1);

    init_array(A, N);
    t1 = time(NULL);
    bubble_sort(A, N);
    t2 = time(NULL);
    printf("bubble sort \tsec = %d\n", t2-t1);
    return 0;
}
