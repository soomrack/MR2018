
#include "Testlib.h"

#include <stdio.h>
#include <stdlib.h>


void multiplymatrix(int* result, int* A, int* B, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int r = 0; r < size; r++) {
                if (r == 0) {
                    result[i * size + j] = A[i * size + r] * B[r * size + j];
                }
                else {
                    result[i * size + j] += A[i * size + r] * B[r * size + j];
                }
            }
        }
    }
}

void transposematrix(int* B, int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (i == j) {
                continue;
            }
            else {
                temp = B[i * size + j];
                B[i * size + j] = B[j * size + i];
                B[j * size + i] = temp;
            }
        }
    }
}

void multiplymatrixfast(int* result, int* A, int* B, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int r = 0; r < size; r++) {
                if (r == 0) {
                    result[i * size + j] = A[i * size + r] * B[j * size + r];
                }
                else {
                    result[i * size + j] += A[i * size + r] * B[j * size + r];
                }
            }
        }
    }
}
    /*
     * Функция rand() псевдорандомная, поэтому тут warning
     */
int get_rand_range(int min, int max){
    return (rand() % (max - min + 1) + min);
}

void fillmatrix(int* matrix, int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i * size + j] = get_rand_range(0, 10);
        }
    }
}
