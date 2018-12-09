//
// Created by vladburin on 09.11.18.
//


#include "MatrixOperations.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"
#include "time.h"


// След матрицы
extern double matrix_trace(const Matrix A)
{
    double Result=0;

    for(int i=0;i<A.rows;i++)
    {
       Result+=A.data[i*A.cols+i];
    }

return Result;
}

// Определитель матрицы
extern double matrix_determinant(const Matrix A)
{
    if(A.cols==1)
    {
        return A.data[0];
    }


    double Result=0;

    if (A.rows>2)
    {
        for(int k=0;k<A.cols;k++)
        {
            double *Mdata=(double*)malloc((A.cols-1)*(A.cols-1)*sizeof(double));
            int f=0;
            for(int i=A.cols;i<A.rows*A.cols;i++)
                {
                    if(!((i-k)%A.cols))
                    {
                        continue;
                    }
                    Mdata[f]=A.data[i];
                    f++;
                }
            Matrix M={A.rows-1,A.cols-1,Mdata};
            Result+=A.data[k]*pow(-1,k)*matrix_determinant(M);
            free(Mdata);
        }
    }

    else
    {

       Result=A.data[0]*A.data[3]-A.data[1]*A.data[2];
    }

return Result;
}

// Сумма матриц
extern Matrix matrix_sum(const Matrix A, const Matrix B)
{

    Matrix Result={A.rows,A.cols};

    double *Cdata=malloc(A.cols*A.cols*sizeof(double));

    for(int i=0;i<A.cols*A.rows;i++)
    {
        Cdata[i]=A.data[i]+B.data[i];
    };

    Result.data=Cdata;
    return Result;
}

// Умножение матрицы на скаляр
extern Matrix matrix_mult__scalar(const double scalar, const Matrix A) {

    Matrix Result = {A.rows, A.cols};

    double *Cdata = malloc(A.cols * A.cols * sizeof(double));

    for (int i = 0; i < A.cols * A.rows; i++)
    {
        Cdata[i] = scalar*A.data[i];
    }

    Result.data = Cdata;

    return Result;
}

// Умножение матриц
extern Matrix matrix_mult(const Matrix A, const Matrix B) {

    Matrix B1 = matrix_trans(B);
    Matrix Result = {A.rows, B.cols};
    double *Cdata = malloc(A.rows * B.cols * sizeof(double));


    int k=0;

    for(int r=0;r<Result.rows;r++)
    {
        for(int c=0;c<Result.cols;c++)
        {
            double Temp = 0;
            for (int j = r*A.cols, i = c*B1.cols; j < A.cols*(1+r), i < B1.cols*(1+c); j++, i++)
            {
                Temp += A.data[j]*B1.data[i];
            }
            Cdata[k] = Temp;
            k++;
        }
    }

    Result.data = Cdata;
    return Result;
}

// Транспонирование матрицы
extern Matrix matrix_trans(const Matrix A)
{
    Matrix Result = {A.cols, A.rows};
    double *Cdata = malloc(A.rows * A.cols * sizeof(double));

    int k=0;

    for(int j=0;j<A.cols;j++)
    {
        for(int i=0;i<A.rows;i++)
        {
            Cdata[k] = A.data[i*A.cols+j];
            k++;
        }
    }

    Result.data = Cdata;

    return Result;
}

// Нулевая матрица
extern Matrix matrix_zero(const unsigned int rows, const unsigned int cols)
{

Matrix Result = {rows, cols};

double *Cdata = malloc(rows * cols * sizeof(double));

for(int i=0;i<rows * cols;i++)
{
    Cdata[i]=0;
}
    Result.data = Cdata;
    return Result;
}

// Единичная матрица
extern Matrix matrix_one(const unsigned int rows, const unsigned int cols)
{
    Matrix Result = matrix_zero(rows,cols);
    for(int i=0;i<Result.rows;i++)
    {
       Result.data[i*Result.cols+i]=1;
    }
   return Result;
}

// Возведение матрицы в степень (натуральное число или 0)
extern Matrix matrix_power(const Matrix A, const unsigned int power)
{

if(power==0)
{
    return matrix_one(A.rows,A.cols);
}

    Matrix Result = {A.rows, A.cols};

if(power==1)
{
    Result=A;
    return Result;
}

else{

    Result=A;
    //double *Cdata = malloc(A.rows * A.cols * sizeof(double));
    for(int i=power; i>1;i--)
    {
     Result=matrix_mult(Result,A);

    }

return Result;

}

}

// Вывести матрицу на экран
extern void matrix_print(const Matrix A)
{
    for(int i=0;i<A.rows;i++)
    {
        for(int j=0;j<A.cols;j++) {

        printf("%f ", A.data[i*A.cols+j]);
        }
    printf("\n");
    }
}

// Матрица оставленная из случайных чисел из диапазона [-1, +1]
extern Matrix matrix_rand(const unsigned int rows, const unsigned int cols)
{
    Matrix Result = {rows,cols};
    double *Cdata = malloc(rows * cols * sizeof(double));

    for(int i=0;i<rows * cols;i++)
    {
        srand(time(NULL)-clock());
        Cdata[i]=(double)(rand()%1000000)/1000000;
        if(rand()%2)
        {
            Cdata[i]=-Cdata[i];
        }
    }
    Result.data = Cdata;
    return Result;
}

//Минор элемента матрицы
extern double matrix_addition(const Matrix A, const unsigned int i,const unsigned int j)
{
    Matrix ADD={A.rows-1,A.cols-1};
    double *ADDdata=(double*)malloc((A.rows-1)*(A.cols-1)*sizeof(double));
    int f=0;

    for(int u=0;u<A.rows*A.cols;u++)
    {
        if((i*A.cols)<=u && u<(i+1)*A.cols)
        {
            continue;
        }
        if(!((u-j)%A.cols))
        {
            continue;
        }
        ADDdata[f]=A.data[u];
        f++;
    }

    ADD.data=ADDdata;

    double Adding=pow(-1,(i+j))*matrix_determinant(ADD);

    free(ADDdata);

    return Adding;
}

// Обращение матрицы
extern Matrix matrix_invert(const Matrix A)
{
    double Determ=matrix_determinant(A);
    Matrix Add={A.rows,A.cols};
    double *Adddata = malloc(A.rows * A.cols * sizeof(double));
    int k=0;
    for(int i=0;i<A.rows;i++)
    {
        for(int j=0;j<A.cols;j++)
        {
            Adddata[k]= matrix_addition(A,i,j);
            k++;
        }
    }
    Add.data=Adddata;

    Add=matrix_mult__scalar((1/Determ),Add);
    Matrix Result=matrix_trans(Add);
    free(Adddata);
    return Result;


}


