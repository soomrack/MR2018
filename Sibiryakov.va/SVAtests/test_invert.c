#include <stdio.h>
#include <math.h>
#include "../matrix.h"
#include <malloc.h>


#define MATRIX_EQUAL( matrix, expected_matrix )                                \
{                                                                           \
    printf("Testing matrix_invert... \n ");                                   \
    int no_error = 0;                                                      \
    for (int i = 0; i < matrix.rows; i++) {                                \
        for (int j = 0; j < matrix.cols; j++) {                            \
            if (    (fabs(0.95*matrix.data[i*matrix.rows + j]) <= fabs(expected_matrix[i][j]))  \
                && (fabs(1.05*matrix.data[i*matrix.rows + j]) >= fabs(expected_matrix[i][j]))    ) {     \
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
}

int main() {
    double test_1[2][2] = {{7.0, -3.0},
                           {4.0, -9.0}};

    Matrix test_one = {2,2,*test_1};

    double res_one[2][2] = {{0.176, -0.0588},
                            {0.0784, -0.137}};

    double test_2[3][3] = {{-3.57, 5.28, -95.867},
                           {265.66, 0, -0.55},
                           {31.333, -55.827, 800.67}};

    Matrix test_two = {3,3,*test_2};

    double res_two[3][3] = {{-0.000103, 0.00376, -0.00001},
                            {-0.712, 0.000487, -0.0853},
                            {-0.0496, -0.000113, -0.0047}};

    Matrix res_test1 = matrix_invert(test_one);
    Matrix res_test2 = matrix_invert(test_two);

    MATRIX_EQUAL(res_test1, res_one);
    MATRIX_EQUAL(res_test2, res_two);
    free(res_test1.data);
    free(res_test2.data);

    return 0;
}