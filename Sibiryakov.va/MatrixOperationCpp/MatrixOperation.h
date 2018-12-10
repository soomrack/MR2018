#include <stdio.h>
#include <iostream>
#include <math.h>
#include <ctime>

#ifndef MR2018_MATRIXOPERATION_H
#define MR2018_MATRIXOPERATION_H

#endif //MR2018_MATRIXOPERATION_H

using namespace std;

class Matrix {
private:
    unsigned int rows;
    unsigned int cols;

public:
    double * data;

    Matrix(const unsigned rowsConstr, const unsigned colsConstr) { //конструктор для прямоугольной матрицы
        //  cout << "constructor of normal matrix" << endl;
        rows = rowsConstr;
        cols = colsConstr;
        data = new double[rows * cols];
    }

    Matrix(const unsigned size) { //конструктор для квадратной матрицы
        //  cout << "constructor of square matrix" << endl;
        rows = size;
        cols = size;
        data = new double[size * size];
    }

    ~Matrix() { //деструктор
        delete [] data;
        cout << "destructor" << endl;
    }

    Matrix(Matrix &M) { //конструктор копий
        rows = M.rows;
        cols = M.cols;
        data = new double[rows * cols];

        for (unsigned row = 0; row < rows; row++) {
            for (unsigned col = 0; col < cols; col++) {
                data[row * cols + col] = M(row,col);
            }
        }

    }


    Matrix operator + (const Matrix &A); //Сложение матриц

    Matrix operator * (const Matrix &A); //Умножение матриц

    Matrix operator * (double scalar); //Умножение матрицы на скаляр

    Matrix operator / (double x); //Деление матрицы на число

    void operator = (const Matrix& A); //Возможность приравнивать матрицы

    friend bool operator == (const Matrix &A, const Matrix &B) { //проверка двух матриц на равенство их элементов
        unsigned elements = A.rows * A.cols;
        //  cout << "elements: " << elements << endl;
        unsigned counter = 0;
        for (unsigned row = 0; row < A.rows; row++) {
            for (unsigned col = 0; col < A.cols; col++) {
                printf("%lf\t%lf\n", A.data[row * A.cols + col], B.data[row * B.cols + col]);
                if (     (fabs(1.05 * A.data[row * A.cols + col]) >= fabs(B.data[row * B.cols + col]))
                         && (fabs(0.95 * A.data[row * A.cols + col]) <= fabs(B.data[row * B.cols + col]))
                         && ((B.data[row * B.cols + col] * A.data[row * A.cols + col]) >= 0)) {
                    // if (fabs(A.data[row * A.cols + col]) == fabs(B.data[row * A.cols + col]))
                    // cout << row * A.cols + col << endl;
                    counter++;
                }
            }
        }
        //  cout << "counter: " << counter << endl;
        return (elements == counter);
    }

    friend bool operator != (const Matrix &A, const Matrix &B) { //проверка двух матриц на неравенство их элементов
        return !(A == B);
    }

    double fact(double n);

    double & operator () (unsigned targetRow, unsigned targetCol) { // вернуть целевой элемент
        return data[targetRow * cols + targetCol];
    }

    unsigned get_Rows() {
        return rows;
    }

    unsigned get_Cols() {
        return cols;
    }

    double Trace(); //след матрицы

    double Determinant(); //нахождение определителя матрицы

    void Random(); //Матрица оставленная из случайных чисел из диапазона [-1, +1]

    Matrix Trans(); //транспонирование матрицы

    void Print(); //вывод матрицы

    Matrix Invert(); //обращение матрицы

    Matrix One(); //создание единичной матрицы

    Matrix Zero(); //создание нулевой матрицы

    Matrix Power (unsigned power); //возведение матрицы в степень

    double norma(); //вычисление нормы матрицы

    //Матричная экспонента (при элементах матрицы меньше 10, погрешность приемлимая и процесс сходится,
    //при элементах, больших 10, процесс расходится, размеры элементов выходят за границы)
    Matrix Exp();

};