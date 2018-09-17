#include "library.h"

#include <stdio.h>

void main2() {
    printf("It's from LIBRARY:Hello, World! It's me\n");
    int n, triangularNumber;
    printf("n Sum from 1 to n\n");
    triangularNumber=0;
    for (n=1; n<=10; ++n) {
        triangularNumber +=n;
        printf ("%i         %i\n", n, triangularNumber);
    }


}