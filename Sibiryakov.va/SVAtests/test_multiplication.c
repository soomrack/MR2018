#include "../matrix.h"
#include <stdio.h>
#include <malloc.h>

double** InputMatrix(int n, int m)
{
    double** Matrix;

    Matrix = (double**)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
        *(Matrix + i) = (double*)malloc(m * sizeof(double));

    return Matrix;
}

int main() {
    Matrix TMres;
    //объявление первой матрицы
    Matrix TM1;
    TM1.cols = 3;
    TM1.rows = 4;
    TM1.data = InputMatrix(TM1.rows, TM1.cols);
    //её инициализация
    for (int i = 0; i < TM1.rows; i++ ) {
        for (int j = 0; j < TM1.cols; j++ ) {
            TM1.data[i][j] = (1.25*i) * (-2.0*j); // каждому элементу присваиваем значение произведения текущих индексов элемента массива
            printf("%10lf", TM1.data[i][j]);
        }
        printf("\n");
    }

    //объявление второй матрицы
    Matrix TM2;
    TM2.cols = 5;
    TM2.rows = 3;
    TM2.data = InputMatrix(TM2.rows, TM2.cols);
    //её инициализация
    for (int i = 0; i < TM2.rows; i++ ) {
        for (int j = 0; j < TM2.cols; j++ ) {
            TM2.data[i][j] = (2.5 * i) * (3.00 * j); // каждому элементу присваиваем значение произведения текущих индексов элемента массива
            printf("%10lf", TM2.data[i][j]);
        }
        printf("\n");
    }

  /*  double **result = (double**)malloc(TM1.rows * sizeof(int*));
    for (int i = 0; i < TM1.rows; ++i)
        result[i]=(double*)malloc(TM2.cols * sizeof(double*)); */


    double result[4][5] =   {{0,       0,       0,       0,       0},
                             {0,    -93.75,  -187.5,  -281.25,  -375.0},
                             {0,    -187.5,  -375.0,  -562.5,  -750.0},
                             {0,    -281.25, -562.5,  -843.75, -1125.0}};


    TMres = matrix_mult(TM1,TM2);

    for (int i = 0; i < TMres.rows; i++ ) {
        for (int j = 0; j < TMres.cols; j++ ) {
            if (TMres.data[i][j] != result[i][j]) {
                return 1;
            }
        }

    }

    return 0;
}