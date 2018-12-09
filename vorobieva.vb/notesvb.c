#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "libraryvb.h"
#include <time.h>
#define TOWNS 4

int main() {
    clock_t begin = clock();
    srand(time(NULL));
    Table input = table_rand(TOWNS);
    table_print(input);
    Table shift = table_zero(TOWNS - 1);
    method(input, shift, shift);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n", time_spent);
    return 0;
}
