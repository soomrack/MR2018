//
// Created by Никита on 12.11.2018.
//

#ifndef INC_1_MATRIX_H
#define INC_1_MATRIX_H

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctime>

class Matrix{
private:
    unsigned int cols;
    unsigned int rows;
public:
    double *data;
    Matrix(){
        rows=1;
        cols=1;
        data = new double [rows*cols];
        data[0]=0.0;
    }
    Matrix(unsigned int size);
    Matrix(unsigned int rows_,unsigned int cols_);
    ~Matrix(){
        rows=0;
        cols=0;
        delete[] data;
    };
    Matrix(const Matrix &A);
    void Print();
    Matrix One(unsigned int size);
    Matrix Zero(unsigned int rows_,unsigned int cols_);
    Matrix Sum(const Matrix A, const Matrix B);
    Matrix Mult(const Matrix A, const Matrix B);
    Matrix Trans();
    double Trace();
    void Random();
    Matrix matrix_exp(const Matrix A);
    Matrix Mult_scalar(const Matrix A, const double scalar);
    Matrix Power(Matrix A, unsigned int power);
    Matrix Minor(unsigned int row, unsigned int col, const Matrix A);
    double Determinant(const Matrix A);
    unsigned get_Rows() {
        return rows;
    }
    unsigned get_Cols() {
        return cols;
    }

};

static double norm (Matrix A);

static double factorial (unsigned int n);

#endif //INC_1_MATRIX_H