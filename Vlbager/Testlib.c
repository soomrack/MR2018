
#include "Testlib.h"

#include <stdio.h>
#include <stdint.h>


void multiplymatrix(int result[2][2], int A[2][2], int B[2][2])
{
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int r = 0; r < 2; r++) {
                result[i][j] += A[i][r] * B[r][j];

            }
        }
    }
}
