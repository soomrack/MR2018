#include<time.h>
#include<windows.h>
#include <iomanip>
#include <ctime>
#include <iostream>
#include "matrixcpplib.h"
#include <cstdlib>
MyMatrix MyMatrix::matrix_rand(const unsigned int rows, const unsigned int cols)
{
    MyMatrix ext2;
    srand(static_cast<unsigned int>(time(nullptr)));
    ext2.rows=rows;
    ext2.cols=cols;
    ext2.data=(double*)malloc(ext2.cols*ext2.rows*sizeof(double));;
    for(unsigned int i=0;i<ext2.rows;i++)
    {
        for(unsigned int j=0;j<ext2.cols;j++)
        {
            ext2.data[i+j*ext2.cols]=(double)(-100+rand()%200)/100;
        }
    }
    return ext2;
}

double ** matric(double ** a, int size, int Last_str){
    double ** minor = (double **)malloc((size - 1) * sizeof(double *));
    for (int i = 0; i < size - 1; i++)
        minor[i] = (double *)malloc((size - 1) * sizeof(double));
    for (int i = 1; i < size; i++){
        for (int j = 0, k = 0; j < size; j++, k++){
            if (j == Last_str){
                k--;
                continue;
            }
            minor[i - 1][k] = a[i][j];
        }
    }

    return minor;
}

double det(double ** a, int size){
    if (size == 1)
        return a[0][0];
    if (size == 2)
        return (a[1][1] * a[0][0]) - (a[0][1] * a[1][0]);
    double determinant = 0, sign = 1;
    for (int i = 0; i < size; i++){
        determinant += (sign * a[0][i] * det(matric(a, size, i),size - 1));
        sign *= -1;
    }
    return determinant;
}

double MyMatrix::matrix_determinant(const MyMatrix A){
    double ** a = (double **)malloc(A.cols * sizeof(double *));
    for (int i = 0; i < A.cols; i++)
        a[i] = (double *)malloc(A.rows * sizeof(double));
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            a[i][j] = A.data[j + i * A.cols];
        }
    }
    return det(a, A.cols);
}

double MyMatrix::matrix_trace() {
    double trace=0;
    for(unsigned int i=0;i<rows;i++){
        trace+=data[i+i*rows];
    }
    return trace;
}


void MyMatrix::matrix_print() {
    for(unsigned int i=0;i<rows;i++){
        for(unsigned int j=0;j<cols;j++){
            printf("%10.2lf\t",data[j+i*cols]);
        }
        printf("%s","\n");
    }
    printf("%s","\n");
}


void MyMatrix::matrix_one(const unsigned int Mrows, const unsigned int Mcols){
    rows=Mrows;
    cols=Mcols;
    data=(double *)malloc(cols*rows*sizeof(double));
    for(unsigned int i=0;i<rows;i++) {
        for(unsigned int j=0;j<cols;j++) {
            if(i==j){
                data[j + i * cols] = 1;
            }
            else {
                data[j + i * cols] = 0;
            }
        }
    }
}


void MyMatrix::matrix_zero(const unsigned int Mrows, const unsigned int Mcols)
{
    rows=Mrows;
    cols=Mcols;
    data=(double *)malloc(cols*rows*sizeof(double));
    for(unsigned int t=0;t<rows;t++)
    {
        for(unsigned int i=0;i<cols;i++)
        {
            data[i+t*cols]=0;
        }
    }
}

MyMatrix MyMatrix::matrix_trans()
{
    MyMatrix ext1;
    ext1.rows=cols;
    ext1.cols=rows;
    ext1.data=(double*)malloc(ext1.cols*ext1.rows*sizeof(double));
    for(int rowtocol=0;rowtocol<ext1.rows;rowtocol++)
    {
        for(int coltorow=0;coltorow<ext1.cols;coltorow++)
        {
            ext1.data[coltorow+rowtocol*ext1.cols]=data[rowtocol+coltorow*cols];
        }
    }
    return ext1;
}

MyMatrix MyMatrix::matrix_mult__scalar(const double scalar)
{
    MyMatrix ext5;
    ext5.rows=rows;
    ext5.cols=cols;
    ext5.data=(double *)malloc(ext5.cols*ext5.rows*sizeof(double));
    for(int t=0;t<rows;t++)
    {
        for(int i=0;i<cols;i++)
        {
            ext5.data[t+i*cols]=scalar*data[t+i*cols];
        }
    }
    return ext5;
}


MyMatrix MyMatrix::matrix_sum(const MyMatrix A, const MyMatrix B)
{
    MyMatrix ext6;
    ext6.rows=rows;
    ext6.cols=cols;
    ext6.data=(double *)malloc(ext6.cols*ext6.rows*sizeof(double));
    for(int t=0;t<rows;t++)
    {
        for(int i=0;i<rows;i++)
        {
            ext6.data[i+t*cols]=B.data[i+t*cols]+A.data[i+t*cols];
        }
    }
    return ext6;
}

MyMatrix MyMatrix::matrix_mult( const MyMatrix A,const MyMatrix B)
{
    MyMatrix ext7;
    ext7.rows=rows;
    ext7.cols=cols;
    ext7.data=(double*)malloc(ext7.cols*ext7.rows*sizeof(double));
    for(int i=0;i<rows;i++)
    {
        for(int t=0;t<B.cols;t++)
        {
            for(int n=0;n<A.cols;n++)
            {
                ext7.data[i+t*rows]+=B.data[i+n*rows]*A.data[n+t*rows];
            }
        }
    }
    return ext7;
}

MyMatrix MyMatrix::matrix_power(MyMatrix A, const int power){

    A.rows=rows;
    A.cols=cols;
    A.data= (double*)malloc(cols*rows*sizeof(double));
    if(power!=0)

    {
        for (unsigned int i = 0; i < power; i++) {
            A.matrix_mult(A,A);
        }
    }
    return A;
}

MyMatrix MyMatrix::matrix_exp(MyMatrix A)
{
    A.rows=rows;
    A.cols=cols;
    A.data=(double*)malloc(cols*rows*sizeof(double));
    double F=1;
    for(int i=1;i<10;i++)
    {
        for (int j=2;j<=i;j++){
            F=F*j;
        }
        MyMatrix pow = matrix_power(A,i);
        MyMatrix powdiv = pow.matrix_mult__scalar(1/F);
        A= powdiv.matrix_sum(A,powdiv);
    }
    return A;
}

void inversionMatrix(double **A, int N)
{
    double temp;
    double **B = new double *[N];

    for (int i = 0; i < N; i++){
        B[i] = new double [N];}
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            B[i][j] = 0.0;

            if (i == j)
                B[i][j] = 1.0;
        }

    for (int k = 0; k < N; k++)
    {
        temp = A[k][k];

        for (int j = 0; j < N; j++)
        {
            A[k][j] /= temp;
            B[k][j] /= temp;
        }

        for (int i = k + 1; i < N; i++)
        {
            temp = A[i][k];

            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                B[i][j] -= B[k][j] * temp;
            }
        }
    }

    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = A[i][k];

            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                B[i][j] -= B[k][j] * temp;
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = B[i][j];

}

MyMatrix MyMatrix::matrix_invert(const MyMatrix A)
{
    MyMatrix ext6;
    ext6.rows=rows;
    ext6.cols=cols;
    ext6.data=(double*)malloc(ext6.cols*ext6.rows*sizeof(double));;
    int N=rows;
    double **matrix =  new double *[N];
    for (int i = 0; i < N; i++)
        matrix[i] = new double[N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            matrix[i][j] = A.data[j+N*i];
    std::cout << " initial matrix "<<"\n\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            std::cout <<std::setw(8) << std::setprecision(3) << setiosflags (std::ios::fixed | std::ios::showpoint)<< matrix[i][j];
        std::cout << "\n";
    }
    inversionMatrix(matrix, N);
    std::cout << "\n\n";
    std::cout << " inverted matrix "<<"\n\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            std::cout <<std::setw(8) << std::setprecision(3) << setiosflags (std::ios::fixed | std::ios::showpoint)<< matrix[i][j];
        std::cout << "\n";
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ext6.data[j+N*i] = matrix[i][j];
    return ext6;
}
