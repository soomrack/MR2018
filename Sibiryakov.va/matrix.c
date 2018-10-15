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
