#include <stdio.h>

/*Будет введено не более 1000 чисел, последнее число - ноль.
Вставить элемент в центр массива
*/

const max_array_size = 1000;

int main()
{
    int A[max_array_size];
    int A_size = 0; //количество реально хранимых элементов

    //считываем элементы с клавиатуры
    int x;
    scanf("%d", &x);
    while (x != 0) {
        A[A_size] = x;
        A_size++;
        scanf("%d", &x);
    }

    //обращение массива самого в себе
    for(int i = 0; i < A_size/2; i++) {
        int tmp = A[i];
        A[i] = A[A_size-1-i];
        A[A_size-1-i] = tmp;
    }

    //вывод массива на экран
    for(int i = 0; i < A_size/2; i++) {
        printf("%d", A[i]);
    }
    printf("\n");

    //циклический сдвиг влево
    x = A[0];
    for(int i = 0; i < A_size; i++) {
            A[i] = A[i+1];
    A[A_size-1] = x;

    //вывод массива на экран
    for(int i = 0; i < A_size; i++) {
        printf("%d", A[i]);
    }
    printf("\n");

    //удаление элемента из массива
    printf("Enter element index to remove:");
    scanf("%d", &x);
    if (x >= 0 && x < A_size) {
        A[i] = A[i+1];
    }
    A_size--; //элементов стало меньше
}
//вывод массива на экран
    for(int i = 0; i < A_size; i++) {
        printf("%d", A[i]);
    }
    printf("\n");

    //вставка элемента в середину массива
    printf("Enter index of element to insert:");
    scanf("%d", &x);
    if (x >= 0 && x <= A_size)
        for(int i = A_size; i > x; i--)
        A[i] = A[i-1];
    A[x] = 777;
    A_size++;

//вывод массива на экран
for(int i = 0; i < A_size; i++) {
    printf("%d ", A[i]);
    }
printf("\n");
    return 0;
}
