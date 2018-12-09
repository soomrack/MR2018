#include <stdio.h>
#include "narayana.h"

/* Обмен значениями двух элементов последовательности */
static void swapItems (T *sequence, unsigned index_1, unsigned index_2) {
    T item = sequence[index_1];
    sequence[index_1] = sequence[index_2];
    sequence[index_2] = item;
}

/* Поиск очередной перестановки */
unsigned nextPermutation (T *sequence, unsigned const count, int (*compare)(T const, T const)) {
    unsigned i = count, j;

    /* Этап № 1 */
    do {
        if (i < 2)
            return 0; /* Перебор закончен */
        --i;
    }
    while (!(*compare)(sequence[i - 1], sequence[i]));

    /* Этап № 2 */
    for (j = count; j > i && !(*compare)(sequence[i - 1], sequence[--j]); );
    swapItems(sequence, i - 1, j);

    /* Этап № 3 */
    for (j = count; i < --j; )
		swapItems(sequence, i++, j);
    return 1;
}

