//
// Created by vladburin on 30.11.18.
//

#ifndef VLADBURIN_MATRIX_H
#define VLADBURIN_MATRIX_H
#include <vector>
#include "iostream"
#include <math.h>
using namespace std;


class Matrix
{
public:
    unsigned int rows;
    unsigned int cols;
    vector<double> data;

    Matrix(unsigned int Valrows, unsigned int Valcols, vector<double> &Valdata) //конструктор прямоугольной матрицы
    {
        rows=Valrows;
        cols=Valcols;
        data=Valdata;
        data.resize(rows*cols);
        Valdata.clear();
    }

    Matrix(unsigned int Valrows, unsigned int Valcols) //конструктор прямоугольной матрицы
    {
        rows=Valrows;
        cols=Valcols;
        data.resize(rows*cols);
    }
    Matrix(unsigned int Valrows) //конструктор прямоугольной матрицы
    {
        rows=Valrows;
        cols=Valrows;
        data.resize(rows*cols);
    }
    Matrix(unsigned int Valrows, vector<double> &Valdata) //конструктор квадратной матрицы
    {
        rows=Valrows;
        cols=Valrows;
        data=Valdata;
        data.resize(rows*cols);
        Valdata.clear();
    }

    ~Matrix() {         //деструктор
        data.clear();
    }

    Matrix(Matrix &C) { //конструктор копий
        rows = C.rows;
        cols = C.cols;
        data = C.data;
    }

    void operator = (const Matrix& A);

    Matrix operator + (const Matrix &A); // Сумма матриц

    Matrix operator * (const double scalar); // Умножение на скаляр

    Matrix operator * (Matrix &A);// Умножение матриц

    bool operator == (const Matrix &B) //оператор проверки матриц на равенство
    {
        unsigned int counter= 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (    (fabs(0.99*data[i*cols + j]) <= fabs(B.data[i*B.cols+j]))
                && (fabs(1.01*data[i*cols + j]) >= fabs(B.data[i*B.cols+j]))
                 && (B.data[i*B.cols+j] * data[i*cols + j] >= 0))
            {
                counter ++;
            }
        }
    }
    return  (counter == rows * cols);
    }

    // След матрицы
    double trace();

    // Определитель матрицы
    double determinant();

    // Транспонирование матрицы
    Matrix trans();

    // Нулевая матрица
    void zero();

    // Единичная матрица
    void one();

    // Вывести матрицу на экран
    void print();

    // Возведение матрицы в степень (натуральное число или 0)
    Matrix power(const unsigned int power);


    // Матрица оставленная из случайных чисел из диапазона [-1, +1]
    void random();

    //Алгебр.дополнение элемента матрицы
    double addition(const int i,const int j);

    // Обращение матрицы
    Matrix invert();

    // Матричная экспонента
    Matrix exp();
};



unsigned long int Fuct(unsigned long int n);


// ТАУ

// Решение уравнения Ляпунова X * A + A^T * X = -C
extern Matrix matrix_lyapunov_equation(const Matrix A, const Matrix C);

// Собственные числа матрицы
extern double matrix_eigen_values(const Matrix A);


// Матрица собственных векторов
extern Matrix matrix_eigen_vectors(const Matrix A);



#endif //VLADBURIN_MATRIX_H


