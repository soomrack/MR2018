#include <stdio.h>
#include "matrix.h"
#include "stdlib.h"
#include "time.h"

extern Matrix matrix_trans(const Matrix A)
{
    Matrix ext1;
    ext1.rows=A.cols;
    ext1.cols=A.rows;
    ext1.data=malloc(ext1.cols*ext1.rows*sizeof(double));
    for(int rowtocol=0;rowtocol<ext1.rows;rowtocol++)
    {
        for(int coltorow=0;coltorow<ext1.cols;coltorow++)
        {
            ext1.data[coltorow+rowtocol*ext1.cols]=A.data[rowtocol+coltorow*A.cols];
        }
    }
    return ext1;
}


















/*
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

*/