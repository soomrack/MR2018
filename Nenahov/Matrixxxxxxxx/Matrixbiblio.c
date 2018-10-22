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

extern Matrix matrix_trans(const Matrix A)
{
    Matrix B;
    B.rows=A.cols;
    B.cols=A.rows;
    for(int t=0;t<B.rows;t++)
    {
        for(int i=0;i<B.cols;i++)
        {
            B.data[t+i*B.cols]=A.data[i+t*A.cols];
        }
    }
    return B;
}

extern Matrix matrix_mult__scalar(const double scalar, const Matrix A)
{
    Matrix B;
    for(int t=0;t<A.rows;t++)
    {
        for(int i=0;i<A.cols;i++)
        {
            B.data[t+i*A.cols]=scalar*A.data[t+i*A.cols];
        }
    }
    return B;

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
            printf("%10.2lf\t",A.data[t*A.cols+i]);
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
            C.data[i+t*A.cols]=A.data[i+t*A.cols]+B.data[i+t*A.cols];
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
}

Matrix Minor(Matrix A,int n)
{
    Matrix B;
    B.rows=A.rows-1;
    B.cols=A.cols-1;
    for(int rows=0;rows<B.rows;rows++)
    {
        for(int cols=0;cols<B.cols;cols++)
        {
            if(cols<n)
            {
                B.data[cols+rows*B.cols]=A.data[cols+(rows+1)*A.cols];
            }
            else
            {
                B.data[cols + rows * B.cols] = A.data[cols+1+(rows+1)*A.cols];
            }

        }
    }
    return B;
}
double matrix_determinant(const Matrix A)
{
    double det=0;
    if(A.cols==1)
    {
        det=A.data[0];
    }
    if(A.cols==2)
    {
        det=A.data[0]*A.data[3]-A.data[2]*A.data[1];
    }
    else{
        int k=1;
        for(int rows=0;rows<A.rows;rows++)
        {
            det+=k*A.data[rows]*matrix_determinant(Minor(A,rows));
            k*=(-1);
        }
    }
    return det;
}

extern Matrix matrix_invert(const Matrix A)
{
    Matrix B;
    B=matrix_mult__scalar(1/matrix_determinant(A),matrix_trans(A));
    return B;
}

