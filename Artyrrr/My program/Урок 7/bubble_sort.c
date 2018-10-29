#include <stdio.h>
#include <stdlib.h>

#define N_MAX 10

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
    bubble_sort(A, N);
    print_array(A, N);

    init_array(A, N);
    print_array(A, N);
    bubble_sort(A, N);
    print_array(A, N);

    return 0;
}
