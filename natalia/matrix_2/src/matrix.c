#include <stdio.h>
#include "matrix.h"
#include <malloc.h>
#include <math.h>

double sum;
int n;

int Mytest(const int number)
{
    return 3;
}

double* minor(const Matrix A, int row, int col, int size)
{
    int row_minor = 0;
    int cols_minor = 0;
    double* B = malloc(A.rows * A.cols * sizeof(double));
    for (int rows = 0; rows < size-1; rows++) {
        if (rows == row)
        {
            row_minor = 1;
        }
        for (int cols = 0; cols < size-1; cols++)
        {
            if (cols == col) {
                cols_minor = 1;

            }
            if ((row_minor != 1)&&(cols_minor != 1))
                B[rows * (size-1) + cols] = A.data[rows * (size) + cols];
            if ((row_minor == 1)&&(cols_minor != 1))
                B[rows * (size-1) + cols] = A.data[(rows + 1) * (size) + cols];
            if ((row_minor != 1)&&(cols_minor == 1))
                B[rows * (size-1) + cols] = A.data[rows * (size) + (cols + 1)];
            if ((row_minor == 1)&&(cols_minor == 1))
                B[rows * (size-1) + cols] = A.data[(rows+1) * (size) + (cols + 1)];
            printf("%f \t",B[rows * (size-1) + cols]);
        }
        printf("\n");
        cols_minor = 0;
    }
    return B;
}

Matrix matrix_trace(const Matrix A)
{
    sum=0.0;
    for (int i = 0; i < A.rows; i++) {
        sum += A.data[i + A.cols * i];
    }
    printf("\n trace = %f",sum);
}

double determinant( Matrix B, int max)
{


    double det = 0;
    int sign = 1;
    if (max == 1) {
        det = B.data[0*(B.cols-1)+0];
        return det;
    }
    if (max == 2)
    {
        double* C = minor(B, n, n, B.cols);
        det = C[0*(B.cols-2)+0] * C[1*(B.cols-2)+1] - C[1*(B.cols-2)+0] * C[0*(B.cols-2)+1];
        printf("\n minor C\n");
        for (int row = 0; row < B.cols-1; row++) {
            for (int col = 0; col < B.cols-1; col++) {
                printf("%f \t", C[row*(B.cols-1)+col]);

            }
        }
        printf("\n");
        printf("det \n [0,0] %f, [0,1] %f\n [1,0] %f [1,1] %f \n",C[0*(B.cols-2)+0], C[0*(B.cols-2)+1], C[1*(B.cols-2)+0],C[1*(B.cols-2)+1]);
        return det;
    }
    if (max > 2) {
        for (n = 0; n < max; n++) {
            //minor(B, i, 0, max);

            det += sign * B.data[n*(B.cols-1) + 0] * determinant(B, max-1);
            sign *= (-1);
            //max-=1;

        }

    }


    return det;
}

double matrix_determinant(const Matrix A)
{
    double determin = determinant(A, A.cols);
    printf("determinant \n");
    printf("%f", determin);
    return determin;
}



/*int main() {
    unsigned int size=3;
    double* B;
    Matrix C;
    C.rows = size;
    C.cols = size;

    B = malloc(C.rows * C.cols * sizeof(double));

    for (int row = 0; row < C.rows; row++) {
        for (int col = 0; col < C.cols; col++) {
            B[row * size + col] = 2.0;
            printf("%f \t", B[row * size + col]);
            if (col == C.cols - 1) {
                printf("\n");
            }
        }
    }
    C.data = B;
    //printf("\n111 %d %d \n", C.rows, C.cols);
    matrix_trace(C);
    printf("\n");
    C.data[0*size+0]=0.0;
    C.data[0*size+1]=-1.0;
    C.data[0*size+2]=0.0;
    C.data[1*size+0]=1.0;
    C.data[1*size+1]=3.0;
    C.data[1*size+2]=-2.0;
    C.data[2*size+0]=2.0;
    C.data[2*size+1]=5.0;
    C.data[2*size+2]=-1.0;
    printf("\n C. data\n [0,0] %f, [0,1] %f\n [1,0] %f [1,1] %f \n",C.data[0*size+0], C.data[0*size+1], C.data[1*size+0],C.data[1*size+1]);

    printf("\nMinor K \n");
    double* K = minor(C,0, 0, C.cols);

    /*for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%f \t", K[row, col]);
            if (col = size-1) {
                printf("\n");
            }
        }
    }*/
/*
    double D = matrix_determinant(C);
    //printf("\n111  %f \n",sum);
    return 0;
}*/