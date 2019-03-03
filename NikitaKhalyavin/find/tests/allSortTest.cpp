//
// Created by work on 18.02.2019.
//

#include <cstring>
#include <cstdio>
#include "../ArraySort.h"

int main() {

    for (int size = 0; size < 5000; size++ ) {

        int *array = CreateRandArray(size, -100, 100);

        int forMerge[size];
        memcpy(forMerge, array, size * sizeof(int));

        int forInsert[size];
        memcpy(forInsert, array, size * sizeof(int));

        int forBubble[size];
        memcpy(forBubble, array, size * sizeof(int));

        int forHeap[size];
        memcpy(forHeap, array, size * sizeof(int));

        int forTim[size];
        memcpy(forTim, array, size * sizeof(int));

        MergeSort(forMerge, size);
        BubbleSort(forBubble, size);
        InsertSort(forInsert, size);
        HeapSort(forHeap, size);
        TimSort(forTim, size);

        int returnCode = 0;

        for (int i = 0; i < size; i++) {
            if ((forMerge[i] != forBubble[i]) || (forMerge[i] != forInsert[i]) || (forBubble[i] != forInsert[i]))
                returnCode++;
            else {
                if ( forHeap[i] != forBubble[i] ) returnCode++;
                if ( forTim[i] != forBubble[i] ) returnCode++;
            }
        }

        if (returnCode > 0) {
            ArrayPrint(forMerge, size);
            ArrayPrint(forBubble, size);
            ArrayPrint(forInsert, size);
            ArrayPrint(forHeap, size);
            ArrayPrint(forTim, size);
            return returnCode;
        }

        printf("step Ok %d \n", size);
    }

    return 0;
}