//
// Created by Елизавета on 12.11.2018.
//

#ifndef MR2018_ELIZAVETA_ELIB2_H
#define MR2018_ELIZAVETA_ELIB2_H


class Matrix {
public:
    unsigned int rows;
    unsigned int cols;
    double * data;
public:
        double matrix_trace(const Matrix A); // След матрицы
        Matrix matrix_minor(int row, int col, const Matrix A); // Миноры
        Matrix matrix_dop(const Matrix A); //Матрица дополнений
        double matrix_determinant(const Matrix A); // Определитель матрицы
        Matrix matrix_sum(const Matrix A, const Matrix B); // Сумма матриц
        Matrix matrix_mult(const Matrix A, const Matrix B); // Умножение матриц
        Matrix matrix_mult__scalar(const double scalar, const Matrix A); // Умножение матрицы на скаляр
        Matrix matrix_trans(const Matrix A); // Транспонирование матрицы
        Matrix matrix_invert(const Matrix A); // Обращение матрицы
        Matrix matrix_power(const Matrix A, const unsigned int power); // Возведение матрицы в степень (натуральное число или 0)
        Matrix matrix_one(const unsigned int size); // Единичная матрица
        Matrix matrix_zero(const unsigned int rows, const unsigned int cols); // Нулевая матрица
        Matrix matrix_rand(const unsigned int rows, const unsigned int cols); // Матрица оставленная из случайных чисел из диапазона [-1, +1]
        void matrix_print(const Matrix A); // Вывести матрицу на экран

};

#endif //MR2018_ELIZAVETA_ELIB2_H
