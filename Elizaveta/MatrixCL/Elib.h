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
/*
 * Need free(matrix.data) after use!!!
 */


void matrix_multiplication (int* A, int* B, int* C, int m, int n, int q);


// След матрицы
extern double matrix_trace(const Matrix A);

extern Matrix matrix_minor(int row, int col, const Matrix A);

extern Matrix matrix_dop(const Matrix A);

// Определитель матрицы
extern double matrix_determinant(const Matrix A);

// Собственные числа матрицы
extern Matrix matrix_eigen_values(const Matrix A);

// Матрица собственных векторов
extern Matrix matrix_eigen_vectors(const Matrix A);


// Сумма матриц
extern Matrix matrix_sum(const Matrix A, const Matrix B);

// Умножение матриц
extern Matrix matrix_mult(const Matrix A, const Matrix B);

// Умножение матрицы на скаляр
extern Matrix matrix_mult__scalar(const double scalar, const Matrix A);

// Транспонирование матрицы
extern Matrix matrix_trans(const Matrix A);

// Обращение матрицы
extern Matrix matrix_invert(const Matrix A);

// Матричная экспонента
extern Matrix matrix_exp(const Matrix A);

// Возведение матрицы в степень (натуральное число или 0)
extern Matrix matrix_power(const Matrix A, const unsigned int power);


// Единичная матрица
extern Matrix matrix_one(const unsigned int size);

// Нулевая матрица
extern Matrix matrix_zero(const unsigned int rows, const unsigned int cols);

// Матрица оставленная из случайных чисел из диапазона [-1, +1]
extern Matrix matrix_rand(const unsigned int rows, const unsigned int cols);


// Вывести матрицу на экран
extern void matrix_print(const Matrix A);


// ТАУ

// Решение уравнения Ляпунова X * A + A^T * X = -C
extern Matrix matrix_lyapunov_equation(const Matrix A, const Matrix C);


#endif //MR2018_ELIZAVETA_ELIB_H

