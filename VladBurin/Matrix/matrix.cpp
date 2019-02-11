//
// Created by vladburin on 30.11.18.
//

using namespace std;

#include "matrix.h"
#include "math.h"
#include "time.h"
#include <vector>
#include "iostream"


void Matrix::operator=(const Matrix &A) {
    cols = A.cols;
    rows = A.rows;
    data = A.data;
}

// След матрицы
extern double Matrix::trace() {
    double Result=0;
    for(int i=0;i<rows;i++)
    {
        Result+=(double)data[i*cols+i];
    }
    return Result;
}

// Определитель матрицы
extern double Matrix::determinant()
{
    if(cols==1)
    {
        return data[0];
    }

    double Result=0;

    if (rows>2)
    {
        for(int k=0;k<cols;k++)
        {
            vector<double> Mdata;
            Mdata.resize((cols-1)*(cols-1));

            int f=0;
            for(int i=cols;i<rows*cols;i++)
            {
                if(!((i-k)%cols))
                {
                    continue;
                }
                Mdata[f]=data[i];
                f++;
            }
            Matrix M={rows-1,cols-1,Mdata};
            Mdata.clear();
            Result+=data[k]*pow(-1,k)*M.determinant();

        }
    }
    else
    {

        Result=data[0]*data[3]-data[1]*data[2];
    }
    return Result;
}

// Сумма матриц
Matrix Matrix::operator + (const Matrix &A)
{
    vector<double> Cdata;
    Cdata.resize((A.cols)*(A.rows));

    for(int i=0;i<A.cols*A.rows;i++)
    {
        Cdata[i]=A.data[i]+data[i];
    }
    Matrix Result(A.rows,A.cols,Cdata);
    Cdata.clear();
    return Result;
}


// Умножение матрицы на скаляр
Matrix Matrix::operator * (const double scalar) {

    vector<double> Cdata;
    Cdata.resize((cols)*(rows));

    for (int i = 0; i < cols * rows; i++)
    {
        Cdata[i] = scalar*data[i];
    }

    Matrix Result(rows,cols,Cdata);
    Cdata.clear();
    return Result;
}

// Транспонирование матрицы
extern Matrix Matrix::trans()
{
    vector<double> Cdata;
    Cdata.resize((cols)*(rows));

    int k=0;

    for(int j=0;j<cols;j++)
    {
        for(int i=0;i<rows;i++)
        {
            Cdata[k] = data[i*cols+j];
            k++;
        }
    }
    Matrix Result(cols,rows,Cdata);
    Cdata.clear();
    return Result;
}


// Умножение матриц
Matrix Matrix::operator * (Matrix &A) {



    vector<double> Cdata;

    Matrix B1(2,Cdata);

    Cdata.resize((rows)*(A.cols));

    B1 = A.trans();

    int k=0;
    for(int r=0;r<rows;r++)
    {
        for(int c=0;c<A.cols;c++)
        {
            double Temp = 0;
            for (int j = r*cols, i = c*B1.cols; j < cols*(1+r), i < B1.cols*(1+c); j++, i++)
            {
                Temp += data[j]*B1.data[i];
            }
            Cdata[k] = Temp;
            k++;
        }
    }

    Matrix Result(rows,A.cols,Cdata);
    Cdata.clear();
    return Result;
}


// Нулевая матрица
void Matrix::zero()
{

    for(int i=0;i<rows*cols;i++)
    {
        data[i]=0;
    }

}

// Единичная матрица
void Matrix::one()
{

    for(int i=0;i<rows;i++)
    {
        data[i*cols+i]=1;
    }

}


// Возведение матрицы в степень (натуральное число или 0)
extern Matrix Matrix::power(const unsigned int power)
{

    if(power==0)
    {
        Matrix B(rows,cols);
        B.one();
        return B;
    }

    if(power==1)
    {
        Matrix B(*this);
        return B;
    }

    else{
        Matrix Result1(*this);
        Matrix Result(*this);
        for(int i=power; i>1;i--)
        {

            Result=Result*Result1;

        }

        return Result;

    }

}



// Вывести матрицу на экран
extern void Matrix::print()
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++) {

            cout<<data[i*cols+j]<<"\t\t";
        }
        cout<<endl;
    }
}

// Матрица оставленная из случайных чисел из диапазона [-1, +1]
extern void Matrix::random()
{
    srand(time(NULL)/cols*clock()+rows);
    for(int i=0;i<rows * cols;i++)
    {

        data[i]=(double)(rand()%1000000)/1000000;

        if(rand()%2)
        {
            data[i]=-data[i];
        }
    }

}


//Алгебр.дополнение элемента матрицы
double Matrix::addition(const int i,const int j)
{

    vector<double> ADDdata;
    ADDdata.resize((rows-1)*(cols-1));
    int f=0;

    for(int u=0;u<rows*cols;u++)
    {
        if((i*cols)<=u && u<(i+1)*cols)
        {

            continue;
        }

        if( !((u-j)%cols) && (u-j)>0 )
        {
            continue;
        }
        if( (u-j)==0 )
        {
            continue;
        }
        ADDdata[f]=data[u];
        f++;
    }
    Matrix ADD(rows-1,cols-1,ADDdata);

    ADDdata.clear();

    double Adding=pow(-1,(i+j))*ADD.determinant();

    return Adding;
}


// Обращение матрицы
extern Matrix Matrix::invert()
{
    double Determ=this->determinant();
    vector<double> Adddata;
    Adddata.resize((rows)*(cols));
    int k=0;
    for(unsigned int i=0;i<rows;i++)
    {
        for(unsigned int j=0;j<cols;j++)
        {
            Adddata[k]= this->addition(i,j);
            k++;
        }
    }

    Matrix Add(rows,cols,Adddata);
    Add=Add*(1/Determ);

    Add=Add.trans();

    return Add;


}

double FindMax(Matrix A, Matrix B);

extern Matrix Matrix::exp()
{

    double F = 0;

    Matrix Exp(rows);
    unsigned int l=0;
    Exp.zero();

    Matrix Exp1(rows);
    Exp1.zero();

    Matrix Temp(rows);



    do
    {
        F = (double) Fuct(l);
        Temp = this->power(l);
        Temp = Temp*(1/F);
        Exp1=Exp;
        Exp = Exp + Temp;
        l++;
    }while(FindMax(Exp,Exp1)>0.1);
    return Exp;
}

unsigned long int Fuct(unsigned long int n)
{
if (n<2)
{return 1;}
else{

    unsigned long int result=1;
    for (unsigned long int p=n;p>=2;p--)
    {
        result*=p;
    }
    return result;
}
}


double FindMax(Matrix A, Matrix B)
{
    B=B*(-1);
    Matrix Temp(A.rows);
    Temp=A+B;

    for(int i=0; i<A.rows*A.rows;i++)
    {
        Temp.data[i]=fabs(Temp.data[i]);
    }

    double Max=Temp.data[0];
    for(int i=1; i<A.rows*A.rows;i++)
    {
        if(Temp.data[i]>Max)
        {
            Max=Temp.data[i];
        }
    }
    return Max;

}