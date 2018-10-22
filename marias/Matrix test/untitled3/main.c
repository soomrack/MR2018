//
// Created by prog on 15.10.2018.
//

#include "Matrixbiblio.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

extern Matrix matrix_rand(const unsigned int rows, const unsigned int cols)
{
    Matrix A;
    srand(time(NULL));
    A.rows=rows;
    A.cols=cols;
    A.data=malloc(A.cols*A.rows*sizeof(double));
    for(int t=0;t<A.rows;t++)
    {
        for(int i=0;i<A.cols;i++)
        {
            A.data[t+i*A.cols]=(double)(-100+rand()%200)/100;
        }
    }
    return A;
}

extern Matrix matrix_mult__scalar(const double scalar, const Matrix A)
{
    for(int t=0;t<A.rows;t++)
    {
        for(int i=0;i<A.cols;i++)
        {
            A.data[t+i*A.cols]=scalar*A.data[t+i*A.cols];
        }
    }
    return A;

}

double matrix_trace(const Matrix A)
{
    double trace=0;
    for(int i=0;i<A.rows;i++)
    {
        trace+=A.data[i+A.rows*i];
    }
    return trace;
}

void matrix_print(const Matrix A)
{

    for(int t=0;t<A.rows;t++)
    {
        for(int i=0;i<A.rows;i++)
        {
            printf("%10.2lf\t",A.data[i*A.rows+t]);
        }
        printf("\n");
    }
}

Matrix matrix_sum(const Matrix A, const Matrix B)
{
    Matrix C;
    C.rows=A.rows;
    C.cols=A.cols;
    C.data=malloc(C.cols*C.rows*sizeof(double));
    for(int t=0;t<A.rows;t++)
    {
        for(int i=0;i<A.rows;i++)
        {
            C.data[i+t*A.rows]=A.data[i+t*A.rows]+B.data[i+t*A.rows];
        }
    }
    return C;
}

extern Matrix matrix_zero(const unsigned int rows, const unsigned int cols)
{
    Matrix A;

    A.rows=rows;
    A.cols=cols;
    A.data=malloc(A.cols*A.rows*sizeof(double));
    for(int t=0;t<A.rows;t++)
    {
        for(int i=0;i<A.cols;i++)
        {
            A.data[t+i*A.rows]=0;
        }
    }
    return A;
}

extern Matrix matrix_mult(const Matrix A, const Matrix B)
{
    Matrix C=matrix_zero(A.rows,B.cols);
    for(int i=0;i<A.rows;i++)
    {
        for(int t=0;t<B.cols;t++)
        {
            for(int n=0;n<A.cols;n++)
            {
                C.data[i+t*A.rows]+=A.data[i+n*A.rows]*B.data[n+t*A.rows];
            }
        }
    }
    return C;
