//
// Created by work on 11.02.2019.
//

#include <cstdio>
#include "findInArray.h"

void change(int * array, int index, int newValue, int size) {

    int newPosition = findForSorted(array, newValue, size, 0, size - 1);

    printf("\n%d", newPosition);

    if(index < newPosition) {
        for(int i = index; i < newPosition; i++) {
            array[i] = array[i + 1];
        }
    }
    else {
        for(int i = newPosition; i < index; i++) {
            array[i + 1] = array[i];
        }
    }

    if(array[newPosition] > newValue) array[newPosition - 1] = newValue;
    else array[newPosition] = newValue;
}

int findForSorted(int * array, int x, int size, int start, int stop){
    if(start >= stop) return start;
    int center = (int) ( (start + stop) / 2 );
    if(array[center] == x) return center;
    if(array[center] > x){
        stop = center - 1;
    }
    else start = center + 1;
    return findForSorted(array, x, size, start, stop);
}

int findForNotSorted(int * array, int x, int size){
    int i;
    for (i = 0; i < size; i++){
        if(array[i] == x) break;
    }
    return i;
}
