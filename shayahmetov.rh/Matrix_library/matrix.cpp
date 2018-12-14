//
// Created by CryLab on 06.12.2018.
//

#include "matrix.h"

#include <string.h>

#include <iostream>

#include <stdexcept>

#include <cstdlib>

#include <stdbool.h>

#include <math.h>

using namespace Mx;

double determinant(const Matrix A);

Matrix::Matrix(unsigned char rows_in, unsigned char cols_in)
{
        cols=cols_in;
        rows=rows_in;
        void *temp = malloc(rows * cols * sizeof(double));
        memset(temp, 0, rows*cols*sizeof(double));
        data = (double *)temp;
};
Matrix::Matrix(Mx::Matrix &o)
{
        cols=o.cols;
        rows=o.rows;
        void *temp = malloc(rows * cols * sizeof(double));
        memset(temp, 0, rows*cols*sizeof(double));
        data = (double *)temp;
        for(int i=0; i<rows*cols; i++) {
                data[i] =o.data[i];
        }
};
Matrix::~Matrix()
{
        free(data);
};
void Matrix::set(double *input)
{
        for(int i=0; i<rows*cols; i++) {
                data[i] =input[i];
        }
};
void Matrix::print()
{
        for(int i=0; i<rows; i++) {
                for(int j=0; j<cols; j++)
                        std::cout << data[j+i*cols] << ' ';
                std::cout << std::endl;
        }
        std::cout << std::endl;
};
//Function looking for trace of matrix
double Matrix::trace()
{
        int min=0;
        double sum=data[0];
        if(cols>rows)
                min=rows;
        else
                min=cols;
        for(int i=1; i<min; i++)
                sum+=data[i*cols+i];
        return sum;
};
//Function return matrix which was constructed of random num from -1 to 1
void Matrix::rand()
{
        for(int i=0; i<rows*cols; i++) {
                data[i] =((double)(std::rand())/RAND_MAX);
        }
};
//Function return matrix, which consist of zero
void Matrix::zero()
{
        for(int i=0; i<rows*cols; i++) {
                data[i] =0;
        }
};
//The function return unitary array
void Matrix::one()
{
        for (int i = 0; i < cols*rows; i++)
                data[i]=0;
        if(rows!=cols)
        {
                std::cout<<"Error: Unitary array must be square\n";
                exit(1);
        }
        else
                for(int i=0; i<cols; i++)
                        data[i*cols+i]=1;
};
//Function return sum of two matrices
void Matrix::sum(const Matrix &B)
{
        if((rows!=B.rows)||(cols!=B.cols))
        {
                std::cout<<"Error: Try to sum incompatible operands\n";
                exit(1);
        }
        else
                for (int i = 0; i < cols*B.rows; i++)
                        data[i]+=B.data[i];
};
//The function return result multiply of two matrices
void Matrix::mult(const Matrix &B)
{
        double sum=0;
        double *data2;
        void *temp2 = malloc(rows * B.cols * sizeof(double));
        memset(temp2, 0, rows*cols*sizeof(double));
        data2 = (double *)temp2;
        if(cols!=B.rows)
        {
                std::cout<<"Error: Try to multiply incompatible operands\n";
                exit(1);
        }
        else
                for (int i = 0; i < rows; i++)
                        for(int j=0; j<B.cols; j++){
                                for(int k=0;k<cols; k++)
                                        sum += data[k+i*cols] * B.data[(B.cols * k)+j];
                                data2[i*B.cols+j]=sum;
                                sum=0;
                        }
        free(data);
        data=data2;
        cols=B.cols;
};
//The function return result multiply of matrix and scalar
void Matrix::mult_scalar(const double scalar)
{
        for(int i=0; i<cols*rows; i++)
                data[i]*=scalar;
};
void Matrix::power(const unsigned int power)
{
        if(power==0)
                this->one();
        else
        {
                Matrix A(rows, cols);
                A.set(data);
                for (int h = 1; h < power; h++)
                {
                        this->mult(A);
                }
        }
};
//The fuction return transposition matrix A
void Matrix::trans()
{
        double *data2;
        void *temp2 = malloc(rows * cols * sizeof(double));
        memset(temp2, 0, rows*cols*sizeof(double));
        data2 = (double *)temp2;
        for(int i=0; i<cols; i++)
                for(int j=0; j<rows; j++)
                        data2[j+i*rows]=data[i+j*cols];
        free(data);
        data=data2;
        unsigned char temp = rows;
        rows = cols;
        cols = temp;
};
//The function return factorial of num
long int factorial(long int n)
{
        if (n == 0 || n == 1) return 1;
        return n * factorial(n - 1);
};
//The function return inverse matrix of the original
void Matrix::invert()
{
        double result=0;
        {
                unsigned int size=rows;
                if(rows!=cols)
                {
                        std::cout<<"Error: determinant does not exist for non-square matrix\n";
                        exit(1);
                }
                else
                {
                        double deter=this->determinant();
                        this->trans();
                        this->mult_scalar(1/deter);
                }
        }
};
Matrix element(const Mx::Matrix A, unsigned int position)
{
        Mx::Matrix A1(10, 10);
        A1=A;
        double det=0;
        det=A1.determinant();
        det=1/det;
        A1.power(position);
        A1.mult_scalar(det);
        return A1;
};
Matrix mexp(const Mx::Matrix A)
{
        Mx::Matrix A1(10, 10);
        A1=A;
        for(unsigned int i=1; i<5; i++)
              A1.sum(element(A1, i));
        return A1;
};
Matrix Matrix::Minor(int row,int col)
{
        Matrix B(rows-1, cols-1);
        for(int i=0;i<B.rows;i++)
        {
                for(int j=0;j<B.cols;j++)
                {
                        int r=0;
                        int c=0;
                        if(j>=col) c=1;
                        if(i>=row) r=1;
                        B.data[j + i * B.cols] = data[j+c+(i+r)*cols];
                }
        }
        return B;
};
double Matrix::determinant()
{
        double det=0;
        if(cols==1)
        {
                det=data[0];
        }
        if(cols==2)
        {
                det=data[0]*data[3]-data[2]*data[1];
        }
        else{
                int k=1;
                //int rows=0;
                for(int i=0;i<rows;i++)
                {
                        det+=k*data[i]*Minor(0,i).determinant();
                        k*=(-1);
                }
        }
        return det;
};
Matrix operator+(Matrix &left, Matrix &right)
{
        Matrix result(1, 1);
        result=left;
        result.sum(right);
        return result;
};
Matrix operator-(Matrix &left, Matrix &right)
{
        Matrix result(1, 1);
        result=right;
        result.mult_scalar(-1);
        result.sum(left);
        return result;
};
Matrix operator*(Matrix &left, Matrix &right)
{
        Matrix result(1, 1);
        result=left;
        result.mult(right);
        return result;
};
Matrix operator*(Matrix &left, double &right)
{
        Matrix result(1, 1);
        result=left;
        result.mult_scalar(right);
        return result;
};
Matrix operator^ (Matrix &left, unsigned power)
{
        Matrix result(1, 1);
        result=left;
        result.power(power);
        return result;
};