#ifndef C_LIBRARY_H
#define C_LIBRARY_H
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Matrix{
private:
    unsigned int cols;
    unsigned int rows;
public:
    double *data;
    Matrix(const unsigned rowss, const unsigned colss) {
        rows = rowss;
        cols = colss;
        data = new double[rows * cols];
    }
    Matrix(const unsigned size) {
        rows = size;
        cols = size;
        data = new double[size * size];
    }
    Matrix(const Matrix &K) {
        rows = K.rows;
        cols = K.cols;
        data = new double[rows * cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i * cols + j] = K.data[i * K.cols + j];
            }
        }
    }
    ~Matrix() {
        delete [] data;
    }

    // След матрицы
    double matrix_trace();

    // Определитель матрицы
    double matrix_determinant();

    // Транспонирование матрицы
    Matrix matrix_trans();

    // Обращение матрицы
    Matrix matrix_invert();

    // Матричная экспонента
    Matrix matrix_exp();

    // Возведение матрицы в степень (натуральное число или 0)
    Matrix matrix_power(unsigned int power);

    // Единичная матрица
    Matrix matrix_one(const unsigned int size);

    // Нулевая матрица
    Matrix matrix_zero(unsigned int rows, unsigned int cols);

    // Матрица составленная из случайных чисел из диапазона [-1, +1]
    Matrix matrix_rand(unsigned int rows, unsigned int cols);

    // Сумма матриц
    Matrix operator + (const Matrix &C);

    // Разность матриц
    Matrix operator - (const Matrix &C);

    // Умножение матриц
    Matrix operator * (Matrix &C);

    // Умножение матрицы на скаляр
    Matrix operator * (double scalar);

    // Вывести матрицу на экран
    void matrix_print();

    //Минор матрицы
    Matrix Minor(unsigned int row, unsigned int col);

    //Факториал
    int Factorial(unsigned int k);

    //Рандом от -1 до 1
    double Random_Number();
};

#endif //C_LIBRARY_H
