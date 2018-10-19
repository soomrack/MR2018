//
// Created by Елизавета on 17.09.2018.
//

#ifndef MR2018_ELIZAVETA_ELIB_H
#define MR2018_ELIZAVETA_ELIB_H


int m, n, q;

typedef struct {
    unsigned int rows;
    unsigned int cols;
    double* data;
} Matrix;



void matrix_multiplication (int* A, int* B, int* C, int m, int n, int q);


// След матрицы
extern double matrix_trace(const Matrix A);

// Определитель матрицы
extern double matrix_determinant(const Matrix A);


#endif //MR2018_ELIZAVETA_ELIB_H