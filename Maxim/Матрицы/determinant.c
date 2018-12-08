#include <stdio.h>
#include "matrix.h"
#include "stdlib.h"
#include "time.h"
#include <malloc.h>


int ** matric(int ** a, int size, int Last_str){
    int ** minor = (int **)malloc((size - 1) * sizeof(int *));
    for (int i = 0; i < size - 1; i++)
        minor[i] = (int *)malloc((size - 1) * sizeof(int));
    for (int i = 1; i < size; i++){
        for (int j = 0, k = 0; j < size; j++, k++){
            if (j == Last_str){
                k--;
                continue;
            }
            minor[i - 1][k] = a[i][j];
        }
    }

    return minor;
}

int det(int ** a, int size){
    if (size == 1)
        return a[0][0];
    if (size == 2)
        return (a[1][1] * a[0][0]) - (a[0][1] * a[1][0]);
    int determinant = 0, sign = 1;
    for (int i = 0; i < size; i++){
        determinant += (sign * a[0][i] * det(matric(a, size, i),size - 1));
        sign *= -1;
    }
    return determinant;
}

extern double matrix_determinant(const Matrix A){
    int ** a = (int **)malloc(A.cols * sizeof(int *));
    for (int i = 0; i < A.cols; i++)
        a[i] = (int *)malloc(A.rows * sizeof(int));
    for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.cols; j++) {
            a[i][j] = A.data[j + i * A.cols];
        }
        printf("\n");
    }
    printf("%d%s\n",det(a, A.cols),"=determinant");
}