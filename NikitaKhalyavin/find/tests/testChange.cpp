//
// Created by work on 18.02.2019.
//

#include "../ArraySort.h"
#include "../findInArray.h"
#include <cstring>
#include <cstdio>

int main() {

    for(int size = 50; size < 10000; size++) {
        int *a = CreateRandArray(size, -100, 100);

        MergeSort(a, size);

        int b[size];
        memcpy(b, a, size * sizeof(int));

        change(a, 25, 30, size);

        printf("\t%d", b[25]);

        b[25] = 30;
        MergeSort(b, size);

        int returnCode = 0;

        for (int i = 0; i < size; i++) {
            if (a[i] != b[i]) returnCode++;
        }

        if (returnCode > 0) {
            ArrayPrint(a, size);
            ArrayPrint(b, size);
            return returnCode;
        }
    }

    return 0;
}