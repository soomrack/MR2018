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
    B.data=malloc(B.cols*B.rows*sizeof(double));
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
    B.rows=A.rows;
    B.cols=A.cols;
    B.data=malloc(B.cols*B.rows*sizeof(double));
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

extern void matrix_print(const Matrix A)
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
    for(unsigned int t=0;t<A.rows;t++)
    {
        for(unsigned int i=0;i<A.cols;i++)
        {
            A.data[i+t*A.cols]=0;
        }
    }
    return A;
}

extern Matrix matrix_mult(const Matrix A, const Matrix B)
{
    Matrix C=matrix_zero(A.rows,B.cols);
    C.data=malloc(C.cols*C.rows*sizeof(double));
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

extern Matrix Minor(Matrix A,int row,int col)
{
    Matrix B;
    B.rows=A.rows-1;
    B.cols=A.cols-1;
    B.data=malloc(B.cols*B.rows*sizeof(double));
    for(int rows=0;rows<B.rows;rows++)
    {
        for(int cols=0;cols<B.cols;cols++)
        {
            int r=0;
            int c=0;
            if(cols>=col) c=1;
            if(rows>=row) r=1;
            B.data[cols + rows * B.cols] = A.data[cols+c+(rows+r)*A.cols];

        }
    }
    return B;
}
extern double matrix_determinant(const Matrix A)
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
        int rows=0;
        for(int cols=0;cols<A.rows;cols++)
        {
            det+=k*A.data[cols]*matrix_determinant(Minor(A,rows,cols));
            k*=(-1);
        }
    }
    return det;
}

extern Matrix matrix_invert(const Matrix A)
{
    Matrix invA;
    invA.rows=A.cols;
    invA.cols=A.rows;
    invA.data=malloc(invA.cols*invA.rows*sizeof(double));
    Matrix AlgDop;
    AlgDop.rows=A.cols;
    AlgDop.cols=A.rows;
    AlgDop.data=malloc(AlgDop.cols*AlgDop.rows*sizeof(double));
    int k=1;
    for(int rows=0;rows<AlgDop.rows;rows++)
    {
        for(int cols=0;cols<AlgDop.cols;cols++)
        {
            AlgDop.data[cols+rows*AlgDop.cols]=k*matrix_determinant(Minor(A,cols,rows));
            k*=(-1);
        }
    }
   /* double d=matrix_determinant(A);
    printf("det=%lf\n",d);
    double id=1/d;
    MatrixCL=matrix_trans(A);
    invA=matrix_mult__scalar(id,C);*/
    invA=matrix_mult__scalar(1/matrix_determinant(A),AlgDop);
    return invA;
}

extern Matrix matrix_one(const unsigned int rows, const unsigned int cols)
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
            if(i==t)
            A.data[t+i*A.cols]=1;
            else  A.data[t+i*A.cols]=0;
        }
    }
    return A;
}

extern Matrix matrix_power(const Matrix A, const unsigned int power)
{
    Matrix B;
    B.rows=A.rows;
    B.cols=A.cols;
    B.data=malloc(B.cols*B.rows*sizeof(double));
    if(power==0) B=matrix_one(B.rows,B.cols);
    else {
        B=matrix_one(B.rows,B.cols);
        for (unsigned int i = 0; i < power; i++) {
            B = matrix_mult(B,A);
        }
    }
    return B;
}

extern Matrix matrix_exp(const Matrix A)
{
    Matrix B=matrix_one(A.rows,A.cols);
    B.rows=A.rows;
    B.cols=A.cols;
    B.data=malloc(B.cols*B.rows*sizeof(double));
    double F=1;
    for(int i=1;i<10;i++)
    {
        for (int t=2;t<i+1;t++){
            F=F*t;
        }
        B=matrix_sum(B,matrix_mult__scalar(1/F,matrix_power(A,i)));
    }
    return B;

}

