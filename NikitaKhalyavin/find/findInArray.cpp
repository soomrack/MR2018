//
// Created by work on 11.02.2019.
//

#include "findInArray.h"

int findForSorted(int * array, int x, int size, int start, int stop){
    if(start == stop) return start;
    int center = (int) ( (start + stop) / 2 );
    if(center == x) return center;
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
