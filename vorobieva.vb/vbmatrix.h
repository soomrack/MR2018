//
// Created by Veronika on 10/12/2018.
//

#ifndef MR2018_VBMATRIX_H
#define MR2018_VBMATRIX_H

#include <iostream>
#include <ctime>


class Matrix {
private:
    double *data;
public:
    unsigned int cols;
    unsigned int rows;

    //Конструкторы:
    explicit Matrix(unsigned int size); //для квадратной матрицы
    Matrix(unsigned int cols_arg, unsigned int rows_arg); //для прямоугольной матрицы

    //Деструктор
    ~Matrix();

    //Возвращает значение элемента матрицы
    double getElement(unsigned int row, unsigned int col) const;

    //Присваивает значение элементу матрицы
    void setElement(unsigned int row, unsigned int col, double value);

    //Выводит матрицу на экран
    void matrix_print();

    // Умножение матрицы на скаляр
    Matrix matrix_mult_scalar(double scalar);

    // Транспонирование матрицы
    Matrix matrix_trans();

    // Обращение матрицы
    Matrix matrix_invert(Matrix A);

    // Матричная экспонента
    Matrix matrix_exp(Matrix A);

    // Возведение матрицы в степень (натуральное число или 0)
    Matrix matrix_power(Matrix A, unsigned int power);

    //след матрицы
    double matrix_trace (Matrix A);
};

// Единичная матрица
extern Matrix matrix_one(unsigned int rows, unsigned int cols);

// Нулевая матрица
extern Matrix matrix_zero(unsigned int rows, unsigned int cols);

// Матрица оставленная из случайных чисел из диапазона [-1, +1]
extern Matrix matrix_rand(unsigned int rows, unsigned int cols);

// Сумма матриц
extern Matrix matrix_sum(Matrix A, Matrix B);

// Умножение матриц
extern Matrix matrix_mult(Matrix A, Matrix B);

#endif //MR2018_VBMATRIX_H
