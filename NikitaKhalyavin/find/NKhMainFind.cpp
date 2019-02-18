//
// Created by work on 11.02.2019.
//

#include "findInArray.h"
#include "ArraySort.h"
#include <stdio.h>

int main() {
    int * a = CreateRandArray(50, -100, 100);
    ArrayPrint(a, 50);
    MergeSort(a, 50);
    ArrayPrint(a, 50);

    int out = findForSorted(a, 30, 50, 0, 49);
    printf("%d\n", out);

    change(a,25,30,50);

    ArrayPrint(a, 50);
    /*
    int out = findForNotSorted(a, 30, 50);
    printf("%d\n", out);
    BubbleSort(a, 50);
    ArrayPrint(a, 50);
    out = findForSorted(a, 30, 50, 0, 49);
    printf("%d\n", out);*/
}