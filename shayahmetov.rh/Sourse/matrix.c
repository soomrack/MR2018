//
// Created by science on 16.09.18.
//

typedef struct {
    unsigned int rows;
    unsigned int cols;
    double* data;
} Matrix;



#include "librain.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
//Procedure print value matrix
extern void matrix_print(const Matrix A) {
        for (int i = 0; i < A.cols*A.rows; i++) {
            printf("%5.5lf ", A.data[i]);
            if((i+1)%A.cols==0)
                printf("\n");
        }
}
//Function looking for trace of matrix
extern double matrix_trace(const Matrix A){
        int min=0;
        double sum=A.data[0];
        if(A.cols>A.rows)
                min=A.rows;
        else
                min=A.cols;
        for(int i=1; i<min; i++)
        sum+=A.data[i*A.cols+i];
        return sum;
}
//Function return matrix which was constructed of random num from -1 to 1
extern Matrix matrix_rand(const unsigned int rows, const unsigned int cols)
{
        Matrix A;
        A.cols=cols;
        A.rows=rows;
        A.data = malloc(cols * rows * sizeof(double));
        for (int i = 0; i < cols*rows; i++)
                A.data[i] = ((2*(double)rand())/(double)RAND_MAX)-1.0;
                return A;
}
//Function return matrix, which consist of zero
extern Matrix matrix_zero(const unsigned int rows, const unsigned int cols)
{
        Matrix A;
        A.cols=cols;
        A.rows=rows;
        A.data = malloc(cols * rows * sizeof(double));
        for (int i = 0; i < cols*rows; i++)
                A.data[i]=(double)0.0;
        return A;
}
//Function return sum of two matrices
extern Matrix matrix_sum(const Matrix A, const Matrix B)
{
        Matrix C=matrix_zero(A.rows, A.cols);
        if((A.rows!=B.rows)||(A.cols!=B.cols))
                printf("Error: Try to sum incompatible operands\n");
        else
                for (int i = 0; i < A.cols*B.rows; i++)
                        C.data[i]=A.data[i]+B.data[i];
        return C;
}
//The function return unitary array
extern Matrix matrix_one(const unsigned int rows, const unsigned int cols)
{
        Matrix A=matrix_zero(rows, cols);
        for (int i = 0; i < cols*rows; i++)
                A.data[i]=0;
        if(rows!=cols)
                printf("Error: Unitary array must be square\n");
        else
                for(int i=0; i<cols; i++)
                        A.data[i*cols+i]=1;
        return A;
}
//The function return result multiply of two matrices
extern Matrix matrix_mult(const Matrix A, const Matrix B)
{
        double sum=0;
        Matrix C=matrix_zero(A.rows, B.cols);
        if(A.cols!=B.rows)
                printf("Error: Try to multiply incompatible operands\n");
        else
                for (int i = 0; i < A.rows; i++)
                        for(int j=0; j<B.cols; j++){
                                for(int k=0;k<A.cols; k++)
                                        sum += A.data[k+i*A.cols] * B.data[(B.cols * k)+j];
                 C.data[i*B.cols+j]=sum;
                 sum=0;
                }
                                        return C;
}
//The function return result multiply of matrix and scalar
extern Matrix matrix_mult__scalar(const double scalar, const Matrix A)
{
        Matrix C=A;
        for(int i=0; i<A.cols*A.rows; i++)
                C.data[i]=A.data[i]*scalar;
        return C;
}
extern Matrix matrix_power(const Matrix A, const unsigned int power)
{
        Matrix C=A;
        if(power==0)
                C=matrix_one(A.rows, A.cols);
        else
                for(int i=1; i<power; i++)
                        C=matrix_mult(C,A);
        return C;
}
//The fuction return transposition matrix A
extern Matrix matrix_trans(const Matrix A)
{
        Matrix C=matrix_zero(A.cols, A.rows);
        for(int i=0; i<A.cols; i++)
                for(int j=0; j<A.rows; j++)
                        C.data[j+i*A.rows]=A.data[i+j*A.cols];
        return C;
}
//The function return factorial of num
long int factorial(long int n)
{
        if (n == 0 || n == 1) return 1;
        return n * factorial(n - 1);
}
//The function return one of possible implementation
int possible_implementation(int size, int nom)
{
       int temp[size];
       _Bool decline=0;
       int global_count=0;
       int start=0;
       for(int k=1; k<size; k++)
               start+=k*pow(10,size-k-1);
       for(int i=start; i<pow(10, size); i++)
       {
               int num = i;
               int count=0;
               while (num != 0)
               {
                       if((num%10==0)&&i<pow(10,size-1))
                               decline=1;
                       if(num%10>size-1)
                               decline=1;
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
               decline=0;
       }

}
//The function return determinant of matrix
extern double matrix_determinant(const Matrix A)
{
        unsigned int size=A.rows;
        double result=0;
        Matrix C=matrix_zero(size, size);
        if(A.rows!=A.cols)
                printf("Error: determinant does not exist for non-square matrix");
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
                                mul_result*=A.data[(j*size)+sequence%10];
                                sequence=sequence/10;
                        }
                        result+=mul_result;
                }
        }
        return result;
}
//The function return inverse matrix of the original
extern Matrix matrix_invert(const Matrix A)
{
        Matrix C=matrix_zero(A.rows, A.cols);
        if(matrix_determinant(A)==0)
                printf("Error: inverse of matrix imposible for those matrix whose determinant is zero");
        else
        {
                return matrix_mult__scalar((1/matrix_determinant(A)), matrix_trans(A));
        }
}
//The function return result of matrix exponent
extern Matrix matrix_exp(const Matrix A)
{
        Matrix C=matrix_one(A.rows, A.cols);
        for(int i=1; i<20; i++)
                C=matrix_sum(C, matrix_mult__scalar((1.0/factorial(i)), matrix_power(A, i)));
        return C;
}

