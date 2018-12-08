#include <stdio.h>
#include <math.h>
#include "../matrix.h"
#include <malloc.h>


#define MATRIX_EQUAL( matrix, expected_matrix )                                \
{                                                                           \
    printf("Testing matrix_mult__scalar... \n ");                                   \
    int no_error = 0;                                                      \
    for (int i = 0; i < matrix.rows; i++) {                                \
        for (int j = 0; j < matrix.cols; j++) {                            \
            if (    (fabs(0.99*matrix.data[i*matrix.rows + j]) <= fabs(expected_matrix[i][j]))  \
                && (fabs(1.01*matrix.data[i*matrix.rows + j]) >= fabs(expected_matrix[i][j]))    ) {     \
                no_error ++;                                                \
            }                                                                \
            else {                                                          \
                printf("value: %lf, expected: %lf; row: %d, col: %d\n",         \
                        matrix.data[i*matrix.rows + j], expected_matrix[i][j],     \
                        (i+1), (j+1));   \
                 return 1;       \
            }                                                                   \
        }                                                                       \
    }                                                                           \
    if (no_error == matrix.rows * matrix.cols) {                                  \
        printf("Test is completed successfully!\n");                                 \
    }                                                                               \
}                                                                                    \

int main() {
    double test_1[3][3] = {{1.0, 5.0, 9.0},
                           {13.0, 17.0, 21.0},
                           {25.0, 29.0, 33.0}};
    double scalar1 = 4.0;
    double result1[3][3] = {{4.0, 20.0, 36.0},
                            {52.0, 68.0, 84.0},
                            {100.0, 116.0, 132.0}};

    Matrix test_one = {3,3,*test_1};
    Matrix res_mult_scalar1 = matrix_mult__scalar(scalar1, test_one);

    MATRIX_EQUAL(res_mult_scalar1, result1);
    free(res_mult_scalar1.data);

    return 0;
}
