//#include "source/matrix.h"
#include "../Sourse/matrix.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define LIMIT 100


Matrix matrix_test_consistend(unsigned int size)
{
    Matrix A;
    A.cols = size;
    A.rows = size;
    A.data = malloc(size * size * sizeof(double));
    for(int i=0; i<size*size; i++)
        A.data[i]=1+i;
    return A;
}
Matrix matrix_test_progressive(unsigned int size, double factor)
{
    Matrix B;
    B.cols = size;
    B.rows = size;
    B.data = malloc(size * size * sizeof(double));
    for(int i=0; i<size*size; i++)
        B.data[i]=(double)(1+i)*factor;
    return B;
}
Matrix matrix_test_random(unsigned int size)
{
    Matrix C;
    C.cols = size;
    C.rows = size;
    C.data = malloc(size * size * sizeof(double));
    for(int i=0; i<size*size; i++)
        C.data[i]=rand();
    return C;
}
Matrix matrix_test_nonsquare(unsigned int rows, unsigned int cols)
{
    Matrix D;
    D.cols = rows;
    D.rows = cols;
    D.data = malloc(rows * cols * sizeof(double));
    for(int i=0; i<rows*cols; i++)
        D.data[i]=rand();
    return D;
}
int main() {
    //Define matrix for handmade calculating
    double data[16]={3, -3, -5, 8, -3, 2, 4, -6, 2, -5, -7, 5, -4, 3, 5, -6};
    const Matrix HM = {.rows=4, .cols=4, .data=data};
    printf("_________________Test start____________________\n");
    //Auto testing
    //___________________________________________________________________________________________
    for(unsigned long int i=1; i<LIMIT; i++)
    {
        Matrix A=matrix_test_consistend(i);
        if(((matrix_trace(A)+1)<A.data[i*i-1])||(matrix_trace(A)>A.data[i*i-1]*A.data[i*i-1]))
        {
            printf("Test Error: matrix_trace: consistend test: out of range\n");
            return 1;
        }
        free(A.data);
    }
    //___________________________________________________________________________________________
    for(unsigned long int i=1; i<LIMIT; i++)
    {
        Matrix A=matrix_test_progressive(i, (double)(i/10));
        if(((matrix_trace(A)+1)<A.data[i*i-1])||(matrix_trace(A)>A.data[i*i-1]*A.data[i*i-1]))
        {
            printf("Test Error: matrix_trace: progressive test: out of range\n");
            return 1;
        }
        free(A.data);
    }
    //Handmade testing
    if(matrix_trace(HM)!=-8)
    {
        printf("Test Error: matrix_trace: handmade test: expected -8, but it does not got\n");
        return 1;
    }
    printf("Testing of function is finished. Function matrix_trace is correct.\n");
    //Auto testing
    //_______________________________________________________________________________________
    for(unsigned long int i=1; i<LIMIT; i++)
    {
        Matrix A=matrix_test_consistend(i);
        Matrix B=matrix_test_progressive(i, (i/10));
        if(matrix_sum(A,B).data[i*i-1]!=A.data[i*i-1]+B.data[i*i-1])
        {
            printf("Test Error: matrix_sum: consistent-progressive test: error of sum\n");
            return 1;
        }
        free(A.data);
        free(B.data);
    }
    //_______________________________________________________________________________________
    for(unsigned long int i=1; i<LIMIT; i++)
    {
        Matrix A=matrix_test_consistend(i);
        Matrix B=matrix_test_progressive(i, (i/10));
        if(matrix_sum(A,B).data[i-1]!=matrix_sum(B,A).data[i-1])
        {
            printf("Test Error: matrix_sum: consistend-prograssive test: error replace");
            return 1;
        }
        free(A.data);
        free(B.data);
    }
    printf("Testing of function is finished. Function matrix_sum is correct.\n");
    //Auto testing
    //_______________________________________________________________________________________
    for(unsigned long int i=1; i<LIMIT; i++)
    {
        Matrix A=matrix_one(i);
        Matrix B=matrix_test_progressive(i, (i/10));
        if(matrix_mult(A, B).data[i*i-1]=B.data[i*i-1])
        {
            printf("Test Error: matrix_mult: prograssive-one_matrix test: error multiplicate");
            return 1;
        }
        free(A.data);
        free(B.data);
    }
    return 0;
}
