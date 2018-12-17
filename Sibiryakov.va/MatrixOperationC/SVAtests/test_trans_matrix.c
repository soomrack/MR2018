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
}                                                                                    \

int main () {
   /* double test_1[2][3] = {{1.0, 2.0, 3.0},
                             {4.0, 5.0, 6.0}};

    double result_1[3][2] = {{1.0, 4.0},
                             {2.0, 5.0},
                             {3.0, 6.0}};

    Matrix test_one = {2,3,*test_1};
    Matrix res_trans1 = matrix_trans(test_one);

    MATRIX_EQUAL(res_trans1, result_1);
    free(res_trans1.data);

    double test_2[1][5] = {{5.0, -6.0, 3.0, -2.0, 1.27}};

    double result_2[5][1] = {{5.0},
                             {-6.0},
                             {3.0},
                             {-2.0},
                             {1.27}};

    Matrix test_two = {1,5,*test_2};
    Matrix res_trans2 = matrix_trans(test_two);

    MATRIX_EQUAL(res_trans2, result_2);
    free(res_trans2.data);

    double test_3[3][6] = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0},
                           {7.0, 8.0, 9.0, 10.0, 11.0, 12.0},
                           {13.0, 14.0, 15.0, 16.0, 17.0, 18.0}};

    double result_3[6][3] = {{1.0, 7.0, 13.0},
                             {2.0, 8.0, 14.0},
                             {3.0, 9.0, 15.0},
                             {4.0, 10.0, 16.0},
                             {5.0, 11.0, 17.0},
                             {6.0, 12.0, 18.0}};

    Matrix test_three = {1,5,*test_3};
    Matrix res_trans3 = matrix_trans(test_three);

    MATRIX_EQUAL(res_trans3, result_3);
    free(res_trans3.data);
  */
    return 0;
}