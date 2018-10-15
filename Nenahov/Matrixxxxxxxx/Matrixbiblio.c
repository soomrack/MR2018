//
// Created by prog on 15.10.2018.
//

#include "Matrixbiblio.h"
#include <stdio.h>

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