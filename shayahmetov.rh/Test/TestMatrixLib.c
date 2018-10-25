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
        B.data[i]=(1+i)*factor;
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
    printf("_________________Test start____________________");
    for(long int i=1; i<LIMIT; i++)
    {
        double mark;
        Matrix A=matrix_test_consistend(i);
        if(((matrix_trace(A)+1)<A.data[i*i-1])||(matrix_trace(A)>A.data[i*i-1]*A.data[i*i-1]))
        {
            printf("Test Error: matrix_trace: consistend test: out of range");
            return 1;
        }
        free(A.data);
    }
        return 0;
}
