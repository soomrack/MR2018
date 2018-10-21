#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

extern double matrix_trace(const Matrix A)
{
    double trace = 0; // след матрицы
    for (int counter_rows = 0; counter_rows < A.rows; counter_rows++) {
        for (int counter_columns = 0; counter_columns < A.cols; counter_columns++) {
            if (counter_rows == counter_columns) {
                trace += A.data[counter_rows][counter_columns]; // считаем след матрицы
            }
        }
    }
    return trace;
}

extern Matrix matrix_mult(const Matrix A, const Matrix B)
{
    Matrix TMres;
    TMres.cols = B.cols;
    TMres.rows = A.rows;
    TMres.data = (double**)malloc(TMres.rows * sizeof(double));
    for (int i = 0; i < TMres.rows; i++) {
        *(TMres.data + i) = (double*)malloc(TMres.cols * sizeof(double));
    }

    for (int i=0; i<TMres.rows; i++)
        for (int j=0; j<TMres.cols; j++)
            TMres.data[i][j]=0;

    for (int i=0; i<TMres.rows; i++) // заполнение результирующего массива
        for (int j=0; j<TMres.cols; j++)
            for (int u=0; u<A.cols; u++)
                TMres.data[i][j ]= TMres.data[i][j]+(A.data[i][u]*B.data[u][j]);

     return TMres;
}
