#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H

#include <string.h>
#include <vector>

class ClassMatrix{
public:
    unsigned int rows;
    unsigned int cols;
    double* data;

    ClassMatrix(unsigned int k_rows, unsigned int k_cols, double* dat){ //конструктор
        rows = k_rows;
        cols = k_cols;
        data = new double [cols * rows * sizeof(double)];
         for (int i = 0; i < rows; i++) {
             for(int j = 0; j < cols; j++) {
                 data[i*cols+j] = dat[i*cols+j];
             }
         }
    }

    ClassMatrix(const ClassMatrix &Matrix){ //конструктор копий
        rows = Matrix.rows;
        cols = Matrix.cols;
        data = new double [cols * rows * sizeof(double)];
        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                data[i*cols+j] = Matrix.data[i*cols+j];
            }
        }
    }

    ClassMatrix(unsigned int k_rows, unsigned int k_cols) {
        rows = k_rows;
        cols = k_cols;
        data = new double[cols * rows];
    }

    // Вывести матрицу на экран
    void matrix_print(const ClassMatrix A);
    // Единичная матрица
    ClassMatrix matrix_one(unsigned int rows, unsigned int cols);

    // Нулевая матрица
    ClassMatrix matrix_zero(const unsigned int rows, const unsigned int cols);

    // След матрицы
    double matrix_trace(const ClassMatrix A);
    // Определитель матрицы
    double matrix_determinant(const ClassMatrix A);

    // Умножение матрицы на скаляр
    void matrix_mult__scalar(const double scalar, ClassMatrix &A);

    // Транспонирование матрицы
    ClassMatrix matrix_trans();

    ClassMatrix operator + (const ClassMatrix &A);// Сумма матриц

    ClassMatrix operator * (const ClassMatrix &A);// Умножение матриц

    // Матрица оставленная из случайных чисел из диапазона [-1, +1]
    ClassMatrix matrix_rand(const unsigned int rows, const unsigned int cols);


    ~ClassMatrix()  //деструктор
    {
        delete [] data;
    };

};

double* minor(double* A, int row, int col, int size);

double determinant(double* B, int max);

double add_matrix(double* G, int n, int m, int max);

// Сумма матриц
ClassMatrix& matrix_sum(const ClassMatrix A, const ClassMatrix B, ClassMatrix& C);

#endif


