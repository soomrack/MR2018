//
// Created by work on 18.02.2019.
//

#include <cstring>
#include <cstdio>
#include "../ArraySort.h"

int main() {

    for (int size = 50; size < 10000; size++ ) {

        int *array = CreateRandArray(size, -100, 100);

        int forMerge[size];
        memcpy(forMerge, array, size * sizeof(int));

        int forInsert[size];
        memcpy(forInsert, array, size * sizeof(int));

        int forBubble[size];
        memcpy(forBubble, array, size * sizeof(int));

        MergeSort(forMerge, size);
        BubbleSort(forBubble, size);
        InsertSort(forInsert, size);

        int returnCode = 0;

        for (int i = 0; i < size; i++) {
            if ((forMerge[i] != forBubble[i]) || (forMerge[i] != forInsert[i]) ||
                (forBubble[i] != forInsert[i]))
                returnCode++;
        }

        if (returnCode > 0) {
            ArrayPrint(forMerge, size);
            ArrayPrint(forBubble, size);
            ArrayPrint(forInsert, size);
            return returnCode;
        }

        printf("step Ok %d \n", size);
    }

    return 0;
}