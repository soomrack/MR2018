#include <stdio.h>
#include <math.h>
#include "../matrix.h"
#include <malloc.h>

#define STRINGIFY( x ) #x

#define TEST_EQUAL( matrix, expected )                                       \
{                                                                            \
    printf("%-40s","Testing "  STRINGIFY(matrix) " ");                       \
    double value = matrix_determinant(matrix);                               \
    if(     (fabs(1.001 * value) >= fabs(expected))                          \
         && (fabs(0.999 * value) <= fabs(expected))                          \
         && ((expected * value) >= 0))                                       \
    {                                                                        \
        printf("Passed\n" );                                                 \
    }                                                                        \
    else                                                                     \
    {                                                                        \
        printf("Shaitan! "                                                   \
               " Expected: %E, got %E\n", expected, value);                  \
        returnCode = 1;                                                      \
    }                                                                        \
    matrix_print(matrix);                                                    \
    printf("\n");                                                            \
}

#define MATRIX_EQUAL( matrix, expected_sum )                                \
{                                                                           \
    printf("Testing matrix_sum... \n ");                                   \
    int no_error = 0;                                                      \
    for (int i = 0; i < matrix.rows; i++) {                                \
        for (int j = 0; j < matrix.cols; j++) {                            \
            if (    (fabs(0.99*matrix.data[i*matrix.rows + j]) <= fabs(expected_sum[i][j]))  \
                && (fabs(1.01*matrix.data[i*matrix.rows + j]) >= fabs(expected_sum[i][j]))    ) {     \
                no_error ++;                                                \
            }                                                                \
            else {                                                          \
                printf("value: %lf, expected: %lf; row: %d, col: %d\n",         \
                        matrix.data[i*matrix.rows + j], expected_sum[i][j],     \
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
    double test_11[1][1] = {1.8};
    double test_12[1][1] = {-2.5};
    double res_1[1][1] = {-0.7};

    Matrix test_one1 = {1,1,*test_11};
    Matrix test_one2 = {1,1,*test_12};
    Matrix res_sum1 = matrix_sum(test_one1, test_one2);

    MATRIX_EQUAL(res_sum1, res_1);
    free(res_sum1.data);


    double test_21[2][2] = {{-2.8, 33.6},
                            {-58.67, 33.9}};
    double test_22[2][2] = {{0.33, -15.6},
                            {900.87, -9.87}};
    double res_2[2][2] = {{-2.47, 18.0},
                          {842.2, 24.03}};

    Matrix test_two1 = {2,2,*test_21};
    Matrix test_two2 = {2,2,*test_22};
    Matrix res_sum2 = matrix_sum(test_two1, test_two2);

    MATRIX_EQUAL(res_sum2, res_2);
    free(res_sum2.data);

    double test_31[3][3] = {{9.55, -98.7, 103.10},
                            {0.0, 55.67, -5.0},
                            {-33.87, -90.11, 13.0}};
    double test_32[3][3] = {{300.0, -95.90, 0.43},
                            {0.99, -50.48, 100.23},
                            {90.85, -13.4, 0.0}};
    double res_3[3][3] = {{309.55, -194.6, 103.53},
                          {0.99, 5.19, 95.23},
                          {56.98, -103.53, 13.0}};

    Matrix test_three1 = {3,3,*test_31};
    Matrix test_three2 = {3,3,*test_32};
    Matrix res_sum3 = matrix_sum(test_three1, test_three2);

    MATRIX_EQUAL(res_sum3, res_3);
    free(res_sum3.data);

    double test_41[4][4] = {{10.0, -20.2, 30.4, -40.6},
                            {5.0, -10.2, 15.4, -20.6},
                            {2.5, -5.02, 7.54, -10.06},
                            {1.25, -2.52, 5.04, -7.56}};
    double test_42[4][4] = {{1.1, 3.3, -7.7, 11.11},
                            {19.19, 23.23, -29.29, 31.31},
                            {34.34, 37.37, -39.39, 41.41},
                            {43.43, 47.47, -51.51, 53.53}};
    double res_4[4][4] = {{11.1, -16.9, 22.7, -29.49},
                          {24.19, 13.03, -13.89, 10.71},
                          {36.84, 32.35, -31.85, 31.35},
                          {44.68, 44.95, -46.47, 45.97}};

    Matrix test_four1 = {4,4,*test_41};
    Matrix test_four2 = {4,4,*test_42};
    Matrix res_sum4 = matrix_sum(test_four1, test_four2);

    MATRIX_EQUAL(res_sum4, res_4);
    free(res_sum4.data);

    return 0;
}