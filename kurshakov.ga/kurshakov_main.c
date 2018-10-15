//
// Created by admin on 17.09.2018.
//
#define CREDIT 500000000
#define RATE 0.17
#define TIME 120

#include <stdio.h>
#include "matrixkga.h"

int main () {
    printf("%ld\n", payment(CREDIT, RATE, TIME));
}