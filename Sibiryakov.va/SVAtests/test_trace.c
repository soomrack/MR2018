#include "../matrix.h"
#include <stdio.h>
#include <malloc.h>



int main() {
    double result_trace;
    Matrix TT;
    TT.cols = 3;
    TT.rows = 3;
    TT.data = (double**)malloc(TT.rows * sizeof(double));
    for (int i = 0; i < TT.rows; i++) {
        *(TT.data + i) = (double*)malloc(TT.cols * sizeof(double));
    }

    for (int i = 0; i < 3; i++ ) {
        for (int j = 0; j < 3; j++ )
            TT.data[i][j] = (1.2i) * (-2.5j); // каждому элементу присваиваем значение произведения текущих индексов элемента массива
    }

    result_trace = (TT.data[0][0] + TT.data[1][1] + TT.data[2][2]);

    if (matrix_trace(TT) != result_trace) {
        return 1;
    }
    return 0;
}

