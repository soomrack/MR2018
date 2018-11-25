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






    return 0;
}
