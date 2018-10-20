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

