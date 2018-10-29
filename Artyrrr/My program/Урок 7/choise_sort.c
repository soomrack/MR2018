#include <stdio.h>
#include <stdlib.h>

#define N_MAX 10

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
    choise_sort(A, N);
    print_array(A, N);

    return 0;
}
