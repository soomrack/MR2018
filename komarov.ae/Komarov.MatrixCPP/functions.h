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
    Matrix(const Matrix &M) {
        rows = M.rows;
        cols = M.cols;
        data = new double[rows * cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i * cols + j] = M.data[i * M.cols + j];
            }
        }
    }
    ~Matrix() {
        delete [] data;
        cout << "destructor" << endl;
    }

    double matrix_trace();   // След матрицы
    double matrix_determinant(); // Определитель матрицы
    Matrix operator + (const Matrix &B);// Сумма матриц
    Matrix operator * (Matrix &B);// Умножение матриц
    Matrix operator * (double scalar);// Умножение матрицы на скаляр
    Matrix matrix_trans();// Транспонирование матрицы
    Matrix matrix_invert();// Обращение матрицы
    Matrix matrix_exp();// Матричная экспонента
    Matrix matrix_power(unsigned int power);// Возведение матрицы в степень (натуральное число или 0)
    Matrix matrix_one(unsigned int rows, unsigned int cols);// Единичная матрица
    Matrix matrix_zero(unsigned int rows, unsigned int cols);// Нулевая матрица
    Matrix matrix_rand(unsigned int rows, unsigned int cols);// Матрица составленная из случайных чисел из диапазона [-1, +1]
    void matrix_print();// Вывести матрицу на экран
    Matrix Minor(unsigned int row, unsigned int col);//Минор матрицы
    int Factorial(unsigned int k);//Факториал
    double Random_Number();//Рандом от -1 до 1
};

#endif //C_LIBRARY_H
