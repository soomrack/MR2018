#include <stdio.h>

/* считывает N, которые сохраняет в массив*/
void init_array(int A[], int N);

//меняет массив, увеличивая все элементы на 1
void modify_array(int A[], int N);

//выводит все значения в массиве A
void print_array(int A[], int N);

int main()
{
    int N;
    printf("Numer: ");
    scanf("%d", &N);
    int A[N];

    init_array(A, N);
    modify_array(A, N);
    print_array(A, N);

    return 0;
}

//меняет массив, увеличивая все элементы на 1
void init_array(int A[], int N)
{
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
}

//меняет массив, увеличивая все элементы на 1
void modify_array(int *p, int N)
{
    for(int i = 0; i < N; i++) {
       *p = (*p) * (*p); //возведение в квадрат
       p++;
    }
}

//выводит все значения в массиве A
void print_array(int A[], int N)
{
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}
