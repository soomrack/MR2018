#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "AlexVolkMatrixCPP.h"
using namespace std;

double Matrix::matrix_trace()
{
    Matrix A (rows,cols);
    int rows = A.rows;
    double *data = A.data;
    double trace=0;
    for( int i=0;i<rows;i++){
        trace+=data[i + i * rows];
    }
    return trace;
}

Matrix Matrix::matrix_rand(const unsigned int rows, const unsigned int cols)
{
    Matrix newMatrix = {rows, cols};
    for (int i = 0; i < newMatrix.rows; i++)
    {
        for (int j = 0; j < newMatrix.cols; j++)
        {
            newMatrix.data[i * newMatrix.cols + j] = rand()%100;
        }
    }

    return newMatrix;
}

Matrix Matrix::matrix_one(){
    Matrix A (rows, cols);
    for(int i = 0; i < A.rows; i++){
        for(int j = 0; j < A.cols; j++){
            if(i == j){
                A.data[A.cols * i + j] = 1;
            }
            else{
                A.data[A.cols * i + j] = 0;
            }
        }
    }
    return A;
}

Matrix Matrix::matrix_minor(int row, int col)
{
    Matrix A (rows, cols);
    for(row=0;rows<A.rows;rows++)
    {
        for(col=0;cols<A.cols;cols++)
        {
            int r=0;
            int c=0;
            if(cols>=col) c=1;
            if(rows>=row) r=1;
            A.data[cols + rows * A.cols] = data[cols+c+(rows+r)*cols];
        }
    }
    return A;
}

void Matrix::matrix_print(const Matrix A){
    for(int i = 0 ; i < A.rows ; i++) {
        for(int j = 0 ; j < A.cols ; j++) {
            std::cout << A.data[A.cols * i + j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::matrix_invert()
{
    double Determinant=0;
    Matrix Result = (this->cols, this->rows);
    Matrix Result1 = (this->cols, this->rows);

    Determinant = this->matrix_determinant(Result1);
    Result1 = this->matrix_trans(Result1);
    int sign=1;
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            Result.data[Result.cols * i + j] = sign * (Result1.matrix_minor(i,j)).matrix_determinant(Result1);
            sign = -sign;
        }
    }

    Result=matrix_mult__scalar( ( 1 / Determinant), Result );
    return Result;
}


Matrix Matrix::matrix_zero()
{
    Matrix Result(rows,cols);
    for(int i = 0; i < Result.rows; i++){
        for(int j = 0; j < Result.cols; j++){
            Result.data[Result.cols * i + j] = 0;
        }
    }
    Result.matrix_print(Result);
    return Result;
}

Matrix Matrix::matrix_mult(const Matrix A, const Matrix B)
{
    if(A.cols==B.rows){
        Matrix MULT (rows, cols);
        MULT.rows = A.rows;
        MULT.cols = B.cols;
        for(int i = 0 ; i < MULT.rows ; i++) {
            for(int j = 0 ; j < MULT.cols ; j++) {
                MULT.data[MULT.cols * i + j] = 0.0;
                for(int t = 0; t < MULT.rows; t++){
                    MULT.data[MULT.cols * i + j] =  MULT.data[MULT.cols * i + j] + A.data[A.cols * i + t] * B.data[B.cols * t + j];
                }
            }
        }
        return MULT;
    }
    else
        {
        std::cout << "Multiplication can`t be done" << std::endl;

    }
}


double Matrix::matrix_determinant( const Matrix A)
{
    //Matrix A (rows, cols);
    double D = 0;
    switch (A.rows)
    {
        case 1:
            return A.data[0];
        case 2:
            return (A.data[0] * A.data[3] - A.data[1] * A.data[2]);
        default:
        {
            Matrix dop = matrix_dop(A);
            for (int j = 0; j < A.cols; j++)
            {
                D += A.data[j] * dop.data[j];
            }
            return D;
        }
    }
}



Matrix Matrix::operator + (const Matrix &C) {
    if (this->rows == C.rows && this->cols == C.cols) {
        Matrix Result = (this->rows, this->cols);
        for (int i = 0; i < Result.rows; i++) {
            for (int j = 0; j < Result.cols; j++) {
                Result.data[Result.cols * i + j] = this->data[this->cols * i + j] + C.data[C.cols * i + j];
            }
        }
        return Result;
    }
}


Matrix Matrix::matrix_dop(const Matrix A)
{
    Matrix dop = {A.rows, A.cols};
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < A.cols; j++)
        {
            dop.data[i*A.cols + j] = pow((-1), i + j) * matrix_determinant(matrix_minor(i, j));
        }
    }
    return dop;
}

Matrix Matrix::matrix_mult__scalar(const double scalar, const Matrix A) {
    for(int i = 0 ; i < A.rows ; i++) {
        for(int j = 0 ; j < A.cols ; j++) {
            A.data[A.cols * i + j] = A.data[A.cols * i + j] * scalar;
        }
    }
    return A;
}

Matrix Matrix::matrix_trans(const Matrix B)
{
    Matrix A = {B.cols, B.rows};
    for(int i = 0; i < B.rows; ++i)
    {
        for(int j = i; j < B.cols; ++j)
        {
            A.data[i * B.cols + j] = B.data[j * B.rows +i];
        }
    }
    return A;
}

Matrix Matrix::matrix_eigen_values()
{
    Matrix A (rows, cols);
    A.rows = rows;
    A.cols = 1;
    double w0[100],w[100],summ=0,w0norm[100],e,d,d0;
    int i,j,k;
    for (i=0;i<rows;i++)
        w0[i]=0;
    w0[0]=1;
    do
    {
        for (i=0;i<rows;i++)
            summ=summ+w0[i]*w0[i];
        d0=sqrt(summ);
        for (i=0;i<rows;i++)
            A.data[i]=w0[i]/d0;
        for (i=0;i<rows;i++)
        {
            w[i]=0;
            for (j=0;j<rows;j++)
                w[i]=w[i]+data[i+j*cols]*A.data[j];
        }
        summ=0;
        for (i=0;i<rows;i++)
            summ=summ+w[i]*w[i];
        d=sqrt(summ);
        e=fabs(d-d0);
        for (i=0;i<rows;i++)
            w0[i]=w[i];
        summ=0;
    }
    while(e>0.001);
    return A;
}

double Matrix::matrix_enorm()
{
    double result = 0;
    for (int row = 0; row < this->rows; row++)
    {
        for (int col = 0; col < this->cols; col++)
        {
            result += (this->data[row * this->cols + col] * this->data[row * this->cols + col]);
        }
    }
    return sqrt(result);
}


Matrix Matrix::matrix_power(const unsigned int power)
{
    Matrix A (rows, cols);
    Matrix C (rows, cols);
    C.cols = A.rows;
    C.rows = A.cols;
    C.data = A.data;
    if(A.rows == A.cols){
        if(power == 0){
            for(int i = 0; i < C.rows; i++){
                for(int j = 0; j < C.cols; j++){
                    C.data[C.cols * i + j] = 1;
                }
            }
        }
        else{
            for(int i =0; i <= power; i++){
                C = matrix_mult(C, C);
            }
            return C;
        }
    }
    else{
        std::cout << "Matrix must be square" << std::endl;
    }
}

Matrix Matrix::operator * (double scalar)
{
    Matrix result(this->rows, this->cols);

    for (int row = 0; row < result.rows; row++)
    {
        for (int col = 0; col < result.cols; col++)
        {
            result.data[row * result.cols + col] = scalar * this->data[row * this->cols + col];
        }
    }
    return result;
}

Matrix Matrix::operator * (Matrix &B)
{
    Matrix result(this->rows, B.cols);
    Matrix transB = B.matrix_trans(transB);
    for (int row = 0; row < result.rows; row++)
    {
        for (int col = 0; col < result.cols; col++)
        {
            result.data[row * result.cols + col] = 0;
            for (int i = 0; i < this->cols; i++)
            {
                result.data[row * result.cols + col] += this->data[row * this->cols + i] * transB.data[col * transB.cols  + i];
            }
        }
    }
    return result;
}

Matrix Matrix::matrix_exp()
{
    //чтобы не копить слишком большую ошибку, создам матрицу А2 в 2^p раз меньше А
    double norm = this->matrix_enorm();
    long long int p;
    if (norm < 4)
    {
        p = 1;
    }
    else
    {
        p = (long long int) norm;
    }
    Matrix A2 = (*this) * (1/pow(2.0, p));

    Matrix exp(this->rows);
    exp.matrix_one();
    Matrix temp = exp;
    int k = 0;
    do
    {
        k++;
        temp = temp * (1.0/k);
        temp = temp * A2;
        exp = exp + temp;
    }
    while ( (k < 10000) );

    for (int i = 0; i < p; i++)
    {
        exp = exp * exp;
    }

    return exp;
}