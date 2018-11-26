typedef int T;

/* Обмен значениями двух элементов последовательности */
static void swapItems (T *sequence, unsigned index_1, unsigned index_2);

/* Поиск очередной перестановки */
unsigned nextPermutation (T *sequence, unsigned const count, int (*compare)(T const, T const));
