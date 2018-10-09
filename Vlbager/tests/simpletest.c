#include "../Testlib.h"
#include <stdio.h>

int main() {
    int A[2][2]          = {{1, 2},
                            {3, 4}};
    int B[2][2]          = {{5, 6},
                            {7, 8}};
    int result[2][2]     = {{19, 22},
                            {43, 50}};
    int resulttest[2][2] = {{0, 0},
                            {0, 0}};

    multiplymatrix(*resulttest, *A, *B, 2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (resulttest[i][j] != result[i][j]) {
                return 1;
            }
        }
    }
    return 0;
}