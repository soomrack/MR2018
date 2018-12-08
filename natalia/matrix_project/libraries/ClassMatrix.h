#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H

#include <string.h>
#include <vector>

class ClassMatrix{
public:
    unsigned int rows;
    unsigned int cols;
    double* data;

    ClassMatrix(unsigned int k_rows, unsigned int k_cols, double* dat){
        rows = k_rows;
        cols = k_cols;
        data = new double [cols * rows * sizeof(double)];
         for (int i = 0; i < rows; i++) {
             for(int j = 0; j < cols; j++) {
                 data[i*cols+j] = dat[i*cols+j];
             }
         }

    }
    // След матрицы
    double matrix_trace(const ClassMatrix A);
    // Определитель матрицы
    double matrix_determinant(const ClassMatrix A);
    // Сумма матриц

    // Умножение матрицы на скаляр
    void matrix_mult__scalar(const double scalar, ClassMatrix& A);

    ~ClassMatrix()
    {
        delete [] data;
    };


};

double minor(ClassMatrix A, int row, int col, int size);

double determinant(double* B, int max);

double add_matrix(double* G, int n, int m, int max);

ClassMatrix& matrix_sum(const ClassMatrix A, const ClassMatrix B, ClassMatrix& C);
#endif


