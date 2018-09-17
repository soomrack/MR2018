#include "libraryvb.h"

#include <stdio.h>
#include <string.h>
#include <limits.h>


int main() {
        for (int i = 12; i<121; i+=12) {
                printf("%ld, %ld\n", -ipoteka(i)+6000000, vklad(i)-arenda(i)); //коммент
        }

        return 0;
}

