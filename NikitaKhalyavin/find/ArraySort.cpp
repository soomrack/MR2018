//
// Created by work on 11.02.2019.
//

#include "ArraySort.h"
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <cstring>

#define swap(a,b) { a ^= b; b ^= a; a ^= b;}

void BubbleSort(int * array, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1 - i; j++) {
            if( array[j] > array[j + 1] ) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void HeapSort(int * array, int size) {

}

void InsertSort(int * array, int size) {

    int place;

    for(int item = 1; item < size; item++ ) {
        place = item - 1;
        while(place >= 0) {
            if(array[place] > array[place+1]) {
                swap(array[place], array[place+1]);
            }
            else break;
            place--;
        }
    }

}

void MergeSort(int * array, int size) {
    if(size < 2) return;
    MergeSort(array, size / 2);
    MergeSort(array + (size / 2), size - (size / 2));
    int temp[size];

    int i = 0;
    int counterLeft = 0;
    int counterRight = size / 2;

    for(i = 0; i < size; i++) {
        if(array[counterLeft] < array[counterRight]) {
            temp[i] = array[counterLeft];
            counterLeft++;
            if(counterLeft == (size / 2)) break;
        }
        else {
            temp[i] = array[counterRight];
            counterRight++;
            if(counterRight == size) break;
        }
    }

    for(counterLeft; counterLeft < size / 2; counterLeft++) {
        i++;
        temp[i] = array[counterLeft];
    }
    for(counterRight; counterRight < size; counterRight++) {
        i++;
        temp[i] = array[counterRight];
    }

    memcpy(array, temp, sizeof(int) * size);
    return;
}

int * CreateRandArray(int size, int min, int max) {
    int * a = (int *) malloc(size * sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < size; i ++) {
        a[i] = (int)(rand()) * (max - min) / RAND_MAX + min;
    }
    return a;
}

void  ArrayPrint(int * array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}