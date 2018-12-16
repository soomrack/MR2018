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
    double trace = 0;
    if (cols == rows) {
        for (int rowss = 0; rowss < rows; rowss++) {
            for (int colss = 0; colss < rows; colss++) {
                trace = data[rowss * rows + colss] + trace;
            }
            std::cout << trace << std::endl;
        }
    }
    return trace;
}

Matrix Matrix::matrix_rand(const unsigned int rows, const unsigned int cols)
{
    Matrix newMatrix = {rows, cols};
    //newMatrix.data = (double *) malloc(newMatrix.rows * newMatrix.cols * sizeof(double));
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
    A.cols = cols;
    A.rows = rows;
    //A.data = new double[A.cols * A.rows * sizeof(double)];
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
    A.rows=rows-1;
    A.cols=cols-1;
    //A.data=(double*)malloc(A.cols*A.rows*sizeof(double));
    for(int rows=0;rows<A.rows;rows++)
    {
        for(int cols=0;cols<A.cols;cols++)
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

/*Matrix Matrix::matrix_invert(const Matrix A)
{
    double Determinant=0;
    Matrix C;
    C.cols = A.rows;
    C.rows = A.cols;
    C.data = new double[C.cols * C.rows * sizeof(double)];
    Matrix D;
    D.cols = A.rows;
    D.rows = A.cols;
    D.data = new double[D.cols * D.rows * sizeof(double)];
    Determinant = matrix_determinant(A);
    D = matrix_trans(A);
    int sign=1;
    for(int i = 0; i < A.rows; i++){
        for(int j = 0; j < A.cols; j++){
            C.data[C.cols * i + j] = sign * matrix_determinant( matrix_minor(D, i, j));
            sign = -sign;
        }
    }
    C=matrix_mult__scalar( ( 1 / Determinant), C );
    return C;
}
*/

/*Matrix Matrix::matrix_zero(const unsigned int row, const unsigned int col)
{
    double * array; //= new double[rows*cols]{0};
    Matrix B = {row,col,array};

    return B;
}*/

Matrix Matrix::matrix_mult(const Matrix A, const Matrix B)
{
    if(A.cols==B.rows){
        Matrix MULT (rows, cols);
        MULT.rows = A.rows;
        MULT.cols = B.cols;
        //MULT.data = new double[MULT.cols * MULT.rows * sizeof(double)];
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
    /*else
        {
        std::cout << "Multiplication can`t be done" << std::endl;

    }*/
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
    //dop.data = (double *) malloc(dop.rows * dop.cols * sizeof(double));
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
   // A.data = (double *)malloc(A.rows * A.cols * sizeof(double));
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

Matrix Matrix::matrix_power(const unsigned int power)
{
    Matrix A (rows, cols);
    Matrix C (rows, cols);
    C.cols = A.rows;
    C.rows = A.cols;
   // C.data = new double[C.cols * C.rows * sizeof(double)];
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