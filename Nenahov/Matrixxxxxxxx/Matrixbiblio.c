//
// Created by prog on 15.10.2018.
//

#include "Matrixbiblio.h"
#include <stdio.h>
#include<stdlib.h>


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
            printf("%10.2lf\t",A.data[t*A.rows+i]);
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