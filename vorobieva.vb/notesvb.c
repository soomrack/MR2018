#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "libraryvb.h"
#include <time.h>
#define TOWNS 4

int main() {
    srand(time(NULL));
    Table input = table_rand(TOWNS);
    table_print(input);
    Table output = method(input);
    int min = WINT_MAX;
    for (int i = 0; i < output.size; i++) {
        for (int j = 0; j < output.size; j++) {
            if (output.data[output.size * i + j] < min) min = output.data[output.size * i + j];
        }
    }
    road += min;

    return 0;
}
