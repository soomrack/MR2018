#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Matrixbiblio.h"
#include<math.h>
/*
typedef struct {
    unsigned int rows;
    unsigned int cols;
    double* data;
} Matrix;*/

/*double Minor(Matrix A,int n)
{
    if(A.rows>2)
    {
        A.rows--;
        for(int t=0;t<A.rows;t++)
        {
            for(int i=0;i<A.rows;i++)
            {
                if(i>=n)
                {
                    A.data[i+t*A.rows]=A.rows[i+t*A.rows+1];
                    
                }

            }
        }
    }
}
double matrix_determinant(const Matrix A)
{
    double det=0;
    Matrix M;
    M.rows=A.rows-1;
    M.cols=A.cols-1;
    M.data=malloc(M.cols*sizeof(double));
    for(int t=0;)
    for(int i=0;i<A.rows;i++)
    {
        M.data[i]=
        det+=pow(-1,1+i+1)*A.data[1+i*A.rows]*M.data[1+i*M.rows];
    }
}
*/


int main() {

    Matrix A;
    srand(time(NULL));
    A.rows=3;
    A.cols=3;
    A.data=malloc(A.cols*A.rows*sizeof(double));
    for(int t=0;t<A.rows;t++)
    {
        for(int i=0;i<A.cols;i++)
        {
          A.data[t+i*A.rows]=rand()%10;
        }
    }
    Matrix B;
    B.rows=3;
    B.cols=3;
    B.data=malloc(A.cols*A.rows*sizeof(double));
    for(int t=0;t<A.rows;t++)
    {
        for(int i=0;i<A.rows;i++)
        {
            B.data[t+i*A.rows]=rand()%10;
//            B.data[i+t*A.rows]=0;
        }
    }
    matrix_sum(A,B);

    matrix_print(A);

    printf("trace=%4.2lf\n",matrix_trace(A));
   // printf("a 32=%lf\n",A.data[0+1*A.rows]);
    matrix_print(B);
    printf("\n");
    //matrix_print(matrix_sum(A,B));
    //Matrix C=matrix_zero(2,2);
    matrix_print(matrix_mult(A,B));
    return 0;
}