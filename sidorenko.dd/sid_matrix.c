

#include "sid_matrix.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

extern Matrix matrix_zero(const unsigned int rows, const unsigned int cols)
{
    Matrix A;
    A.cols=cols;
    A.rows=rows;
    A.data=malloc(A.cols*A.rows*sizeof(double));
    for(int row=0; row<rows; row++)
    {
        for (int col=0; col<cols; col++)
        {
            A.data[row*cols+col]=0.0;
        }
    }

    return A;


}
extern void matrix_print(const Matrix A)
{

    for(int row=0; row<A.rows; row++)
    {
        for (int col=0; col<A.cols; col++)
        {
            printf("%f  ",A.data[row*A.cols+col]);
        }
        printf("\n");
    }
}
extern Matrix matrix_one(const unsigned int rows, const unsigned int cols)
{
    Matrix A;
    A.cols=cols;
    A.rows=rows;
    A.data=malloc(A.cols*A.rows*sizeof(double));
    for(int row=0; row<rows; row++)
    {
        for (int col=0; col<cols; col++)
        {
           if (row==col)
           {
               A.data[row*rows+col]=1.0;
           }
           else
           {
               A.data[row*rows+col]=0.0;
           }
        }
    }

    return A;
}
extern Matrix matrix_rand(const unsigned int rows, const unsigned int cols)
{
    Matrix A;
    A.cols=cols;
    A.rows=rows;
    A.data=malloc(A.cols*A.rows*sizeof(double));
    srand(time(NULL));
    for(int row=0; row<rows; row++)
    {
        for (int col=0; col<cols; col++)
        {
            A.data[row*cols+col]=-1.0+2.0*rand()/(double) RAND_MAX;
        }
    }

    return A;
}
extern Matrix matrix_mult__scalar(const double scalar, const Matrix A)
{
    Matrix B;
    B.cols=A.cols;
    B.rows=A.rows;
    B.data=malloc(B.cols*B.rows*sizeof(double));
    for(int row=0; row<B.rows; row++)
    {
        for (int col=0; col<B.cols; col++)
        {
            B.data[row*B.rows+col]= A.data[row*A.rows+col]*scalar;
        }
    }

    return B;
}
extern Matrix matrix_sum(const Matrix A, const Matrix B)
{
    Matrix C;
    C.cols=A.cols;
    C.rows=A.rows;
    C.data=malloc(A.cols*A.rows*sizeof(double));
    for(int row=0; row<B.rows; row++)
    {
        for (int col=0; col<B.cols; col++)
        {
            C.data[row*C.rows+col]= A.data[row*A.rows+col]+B.data[row*B.rows+col];
        }
    }

    return C;
}

extern double matrix_trace(const Matrix A)
{
    if (A.cols!=A.rows)
    {
        printf("ERROR");
        exit(1);
    }
    double sum=0;
    for(int count=0; count<A.cols; count++)
    {
        sum+=A.data[count*A.rows+count];
    }
    return sum;
}

extern Matrix matrix_trans(const Matrix A)
{
    if (A.cols!=A.rows)
    {
        printf("ERROR");
        exit(1);
    }
    Matrix B;
    B.cols=A.cols;
    B.rows=A.rows;
    B.data=malloc(A.cols*A.rows*sizeof(double));
    for(int row=0; row<B.rows; row++)
    {
        for (int col=0; col<B.cols; col++)
        {
            B.data[col*B.rows+row]= A.data[row*A.rows+col];
        }
    }
    return B;
}
extern Matrix matrix_mult(const Matrix A, const Matrix B)
{
    if (A.cols!=B.rows)
    {
        printf("ERROR");
        exit(1);
    }
    Matrix C;
    C.cols=B.cols;
    C.rows=A.rows;
    C.data=malloc(C.cols*C.rows*sizeof(double));
    for (int row=0; row<C.rows; row++)
    {
        for(int col=0; col<C.cols; col++)
        {
            C.data[row*C.rows+col]=0;
            for(int count=0; count<A.cols; count++)
            {
                C.data[row*C.cols+col]+=A.data[row*C.cols+count]*B.data[count*C.cols+col];
            }
        }
    }
    return C;
}
