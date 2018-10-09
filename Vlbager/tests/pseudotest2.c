#include "../Testlib.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 500

/*
 * Если предположить, что PseudoTest1 пройден и все функции в нем
 * работают правильно, то этот тест доказывает, что в случае с
 * транспонированной матрицей все работает точно также
 */

int main() {

    int A[SIZE][SIZE];
    int B[SIZE][SIZE];

    srand( (unsigned int) time(NULL)); //randomize

    fillmatrix(*A, SIZE);
    fillmatrix(*B, SIZE);

    int result[SIZE][SIZE];
    int resulttest[SIZE][SIZE];

    multiplymatrix(*result, *A, *B, SIZE);

    transposematrix(*B, SIZE);
    multiplymatrixfast(*resulttest, *A, *B, SIZE);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (resulttest[i][j] != result[i][j]) {
                return 1;
            }
        }
    }
    return 0;
}
