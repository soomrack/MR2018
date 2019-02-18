//
// Created by work on 11.02.2019.
//

#include "findInArray.h"
#include "ArraySort.h"
#include <stdio.h>

int main() {
    int * a = CreateRandArray(50, -100, 100);
    ArrayPrint(a, 50);
    InsertSort(a, 50);
    ArrayPrint(a, 50);
}