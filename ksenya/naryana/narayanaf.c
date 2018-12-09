#include <stdio.h>
#include <malloc.h>
#include "narayana.h"

/* Возвращает 1, если value_0 меньше value_1, иначе — 0 */
int less (T const value_0, T const value_1) {
    return value_0 < value_1;
}

/* Возвращает 1, если value_0 больше value_1, иначе — 0 */
int greater (T const value_0, T const value_1) {
    return value_0 > value_1;
}

/* Инициализация последовательности */
void initSequence (T *sequence, unsigned count) {
    /* Заполнение последовательности значениями 1, 2, 3… */
    unsigned i;
    for (i = count; i; --i)
        sequence[i - 1] = i;
}

/* Вывод содержимого последовательности */
void outputSequence (T const *sequence, unsigned count) {
    putchar('[');
    if (count) { /* Если последовательность не пуста */
        unsigned i;
        printf("%d", sequence[0]);
        for (i = 1; i < count; ++i)
            printf(", %d", sequence[i]);
    }
    putchar(']');
    putchar('\n');
}

int main() {
    unsigned count = 4;
    T *sequence = (T*)malloc(count * sizeof(T));
    initSequence(sequence, count); /* Формирование исходной последовательности */
    printf("Non-creasing sequence and its permutations:\n");
    do {
        outputSequence(sequence, count);
    }
    while (nextPermutation(sequence, count, &less)); /* x < y — критерий сравнения для неубывающей последовательности */

    printf("Non-growing sequence and its permutations:\n");
    do {
        outputSequence(sequence, count);
    }
    while (nextPermutation(sequence, count, &greater)); /* x > y — критерий сравнения для невозрастающей последовательности */
    free(sequence);
    return 0;
}



