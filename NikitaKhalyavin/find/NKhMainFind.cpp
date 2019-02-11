//
// Created by work on 11.02.2019.
//

#include "findInArray.h"
#include "ArraySort.h"
#include <stdio.h>

int main() {
    int a[50];
    for(int i = 0; i < 50; i++){
        a[i] = 40 - i;
    }
    int out = findForNotSorted(a, 30, 50);
    printf("%d\t", out);
    BubbleSort(a, 50);
    out = findForSorted(a, 30, 50, 0, 49);
    printf("%d\n", out);
}