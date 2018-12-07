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
                std::cout<<"Error: Unitary array must be square\n";
        else
                for(int i=0; i<cols; i++)
                        data[i*cols+i]=1;
};
//Function return sum of two matrices
void Matrix::sum(const Matrix &B)
{
        if((rows!=B.rows)||(cols!=B.cols))
                std::cout<<"Error: Try to sum incompatible operands\n";
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
                std::cout<<"Error: Try to multiply incompatible operands\n";
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
        {
                for (int i = 0; i < cols*rows; i++)
                        data[i]=0;
                if(rows!=cols)
                        std::cout<<"Error: Unitary array must be square\n";
                else
                        for(int i=0; i<cols; i++)
                                data[i*cols+i]=1;
        }
        else
                for(int h=1; h<power; h++)
                {
                        double sum=0;
                        double *data2;
                        void *temp2 = malloc(rows * cols * sizeof(double));
                        memset(temp2, 0, rows*cols*sizeof(double));
                        data2 = (double *)temp2;
                        if(cols!=rows)
                                std::cout<<"Error: Try to multiply incompatible operands\n";
                        else
                                for (int i = 0; i < rows; i++)
                                        for(int j=0; j<cols; j++){
                                                for(int k=0;k<cols; k++)
                                                        sum += data[k+i*cols] * data[(cols * k)+j];
                                                data2[i*cols+j]=sum;
                                                sum=0;
                                        }
                        free(data);
                        data=data2;
                        cols=cols;
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
//The function return one of possible implementation
int possible_implementation(int size, int nom)
{
        int temp[size];
        _Bool decline=false;
        int global_count=0;
        int start=0;
        for(int k=1; k<size; k++)
                start+=k*(int)pow(10,size-k-1);
        for(int i=start; i<pow(10, size); i++)
        {
                int num = i;
                int count=0;
                while (num != 0)
                {
                        if((num%10==0)&&i<pow(10,size-1))
                                decline=true;
                        if(num%10>size-1)
                                decline=true;
                        if(count==0)
                        {
                                temp[count]=num%10;
                                count++;
                        }
                        else
                        {
                                for(int j=0; j<count; j++)
                                        if(temp[j]==num%10)
                                                decline=1;
                                temp[count]=num%10;
                                count++;
                        }
                        num=num/10;
                }
                if(!decline)
                        global_count++;
                if(global_count==nom)
                        return i;
                decline=false;
        }
};
//The function return determinant of matrix
double Matrix::determinant()
{
        unsigned int size=rows;
        double result=0;
        if(rows!=cols)
                std::cout<<"Error: determinant does not exist for non-square matrix\n";
        else
        {
                for(int i=1; i<factorial(size)+1; i++)
                {
                        double mul_result=1;
                        if(i%4<2)
                                mul_result=-1;
                        int sequence = possible_implementation(size, i);
                        for (int j = 0; j < size; j++)
                        {
                                mul_result*=data[(j*size)+sequence%10];
                                sequence=sequence/10;
                        }
                        result+=mul_result;
                }
        }
        return result;
}
//The function return inverse matrix of the original
void Matrix::invert()
{
        double result=0;
        {
                unsigned int size=rows;
                if(rows!=cols)
                        std::cout<<"Error: determinant does not exist for non-square matrix\n";
                else
                {
                        for(int i=1; i<factorial(size)+1; i++)
                        {
                                double mul_result=1;
                                if(i%4<2)
                                        mul_result=-1;
                                int sequence = possible_implementation(size, i);
                                for (int j = 0; j < size; j++)
                                {
                                        mul_result*=data[(j*size)+sequence%10];
                                        sequence=sequence/10;
                                }
                                result+=mul_result;
                        }
                }
        }
        if(result==0)
                std::cout<<"Error: inverse of matrix imposable for those matrix whose determinant is zero\n";
        else
        {
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
                }
                for(int i=0; i<cols*rows; i++)
                        data[i]*=(1/result);
        }
};
