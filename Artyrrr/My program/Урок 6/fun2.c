#include <stdio.h>

typedef struct {
    int values[100];
    unsigned int N;
} array_t;

/* считывает N,
а затем N строк (но не больше 100), которые сохраняет в массив*/
array_t create_array()
{
    array_t A;
    printf("Numer: ");
    scanf("%d", &A.N);
    //заполняем массив и возвращаем его
    //инкапсулированный в структуру в качестве результата
    for(int i = 0; i < A.N; i++)
        scanf("%d", &A.values[i]);
    return A;
}

//меняет массив, увеличивая все элементы на 1
void modify_array(array_t *);

//выводит все значения в массиве A
void print_array(const array_t *A);

int main()
{
    array_t A = create_array();
    modify_array(&A);
    print_array(&A);

    return 0;
}

//меняет массив, возводя все элементы в квадрат
void modify_array(array_t *A)
{
    for(int i = 0; i < A->N; i++)
        A->values[i] *= A->values[i]; //возведение в квадрат
}

//выводит все значения в массиве A
void print_array(const array_t *A)
{
    for(int i = 0; i < A->N; i++)
        printf("%d ", A->values[i]);
    printf("\n");
}
