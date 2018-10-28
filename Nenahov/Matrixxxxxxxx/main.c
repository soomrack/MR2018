#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Matrixbiblio.h"
#include<math.h>




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
    //matrix_sum(A,B);

    matrix_print(A);

    printf("trace=%4.2lf\n",matrix_trace(A));
   // printf("a 32=%lf\n",A.data[0+1*A.rows]);
//    matrix_print(B);
    printf("\n");
    Matrix C=matrix_sum(A,B);
    //matrix_print(C);
    Matrix D=matrix_zero(2,2);
    Matrix E=matrix_mult(A,B);
    Matrix G=matrix_mult__scalar(2,A);
    Matrix H=matrix_trans(A);
    Matrix I=matrix_invert(A);
    double det=matrix_determinant(A);
    printf("det=%lf\n",det);

    //matrix_print(matrix_invert(A));

   // matrix_print(matrix_mult__scalar(1/matrix_determinant(A),matrix_trans(A)));
    Matrix F=matrix_rand(4,4);
    //matrix_print(matrix_mult__scalar(1/matrix_determinant(A),matrix_trans(A)));
    //matrix_print(I);
   // matrix_print(matrix_one(4,4));
   matrix_print(matrix_exp(A));
    return 0;
}

while(1)
{
matrix_m_vector(A, Xn, Xn1);
float num=0,den=0;
vector_m_vector(Xn1, Xn, &num);
vector_m_vector(Xn, Xn, &den);
float Lprev=L;
L=num/den;
if ((fabs(L-Lprev))<0.00001) break;
memcpy(Xn, Xn1, sizeof(Xn)*_n);
it++;
}