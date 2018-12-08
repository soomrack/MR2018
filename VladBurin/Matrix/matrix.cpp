//
// Created by vladburin on 30.11.18.
//

using namespace std;

#include "matrix.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <vector>
#include "iostream"




// След матрицы
extern double matrix_trace(const Matrix A)
{
    double Result=0;
    for(int i=0;i<A.rows;i++)
    {
        Result+=(double)A.data[i*A.cols+i];
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
            vector<double> Mdata;
            Mdata.resize((A.cols-1)*(A.cols-1));

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
            Mdata.clear();
            Result+=A.data[k]*pow(-1,k)*matrix_determinant(M);

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


    vector<double> Cdata;
    Cdata.resize((A.cols)*(A.rows));

    for(int i=0;i<A.cols*A.rows;i++)
    {
        Cdata[i]=A.data[i]+B.data[i];
    }

    Matrix Result(A.rows,A.cols,Cdata);

    Cdata.clear();
    return Result;
}

// Умножение матрицы на скаляр
extern Matrix matrix_mult__scalar(const double scalar, const Matrix A) {


    vector<double> Cdata;
    Cdata.resize((A.cols)*(A.rows));

    for (int i = 0; i < A.cols * A.rows; i++)
    {
        Cdata[i] = scalar*A.data[i];
    }

    Matrix Result(A.rows,A.cols,Cdata);
    Cdata.clear();
    return Result;
}

// Транспонирование матрицы
extern Matrix matrix_trans(const Matrix A)
{

    vector<double> Cdata;
    Cdata.resize((A.cols)*(A.rows));

    int k=0;

    for(int j=0;j<A.cols;j++)
    {
        for(int i=0;i<A.rows;i++)
        {
            Cdata[k] = A.data[i*A.cols+j];
            k++;
        }
    }

    Matrix Result(A.cols,A.rows,Cdata);
    Cdata.clear();
    return Result;
}


// Умножение матриц
extern Matrix matrix_mult(const Matrix A, const Matrix B) {

    Matrix B1 = matrix_trans(B);

    vector<double> Cdata;
    Cdata.resize((A.rows)*(B.cols));

    int k=0;

    for(int r=0;r<A.rows;r++)
    {
        for(int c=0;c<B.cols;c++)
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

    Matrix Result(A.rows,B.cols,Cdata);
    Cdata.clear();
    return Result;
}


// Нулевая матрица
extern Matrix matrix_zero(const unsigned int rows, const unsigned int cols)
{

    vector<double> Cdata;
    Cdata.resize((rows)*(cols));


    for(int i=0;i<rows * cols;i++)
    {
        Cdata[i]=0;
    }

    Matrix Result(rows,cols,Cdata);
    Cdata.clear();
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


    if(power==1)
    {
        return A;
    }

    else{

        Matrix Result=A;

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

            cout<<A.data[i*A.cols+j]<< "  ";
        }
        cout<<endl;
    }
}

// Матрица оставленная из случайных чисел из диапазона [-1, +1]
extern Matrix matrix_rand(const unsigned int rows, const unsigned int cols)
{

    vector<double> Cdata;
    Cdata.resize((rows)*(cols));
    srand(time(NULL)/cols*clock()+rows);
    for(int i=0;i<rows * cols;i++)
    {

        Cdata[i]=(double)(rand()%1000000)/1000000;

        if(rand()%2)
        {
            Cdata[i]=-Cdata[i];
        }
    }
    Matrix Result(rows, cols,Cdata);
    Cdata.clear();
    return Result;
}

//Минор элемента матрицы
extern double matrix_addition(const Matrix A, const int i,const int j)
{

    vector<double> ADDdata;
    ADDdata.resize((A.rows-1)*(A.cols-1));
    int f=0;

    for(int u=0;u<A.rows*A.cols;u++)
    {
        if((i*A.cols)<=u && u<(i+1)*A.cols)
        {

            continue;
        }

        if( !((u-j)%A.cols) && (u-j)>0 )
        {
            continue;
        }
        if( (u-j)==0 )
        {
            continue;
        }
        ADDdata[f]=A.data[u];
        f++;
    }
    Matrix ADD(A.rows-1,A.cols-1,ADDdata);
    ADDdata.clear();
    double Adding=pow(-1,(i+j))*matrix_determinant(ADD);

    return Adding;
}

// Обращение матрицы
extern Matrix matrix_invert(const Matrix A)
{
    double Determ=matrix_determinant(A);
    vector<double> Adddata;
    Adddata.resize((A.rows)*(A.cols));
    int k=0;
    for(unsigned int i=0;i<A.rows;i++)
    {
        for(unsigned int j=0;j<A.cols;j++)
        {
            Adddata[k]= matrix_addition(A,i,j);
            k++;
        }
    }

    Matrix Add(A.rows,A.cols,Adddata);

    Add=matrix_mult__scalar((1/Determ),Add);

    Matrix Result=matrix_trans(Add);

    return Result;


}


