#include <stdio.h>
#include "eval1.h"
#include <string.h>
#include <stdlib.h>

int main(void)
{

    printf("Otvet %d \n",eval1(" (100 - (9/1)) ")); // returns 3

    return 0;
}