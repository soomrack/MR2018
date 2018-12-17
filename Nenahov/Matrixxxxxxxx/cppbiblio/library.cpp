#include"library.h"




void Matrix::matrix_rand(const int Mrows, const int Mcols)
{
    srand((unsigned int)time(nullptr));
    rows=Mrows;
    cols=Mcols;
    data=(double *) malloc(rows * cols * sizeof(double));
    for(int t=0;t<rows;t++)
    {
        for(int i=0;i<cols;i++)
        {
            data[t+i*cols]=(-100+rand()%200)/100;
        }
    }
}

void Matrix::matrix_print()
{
    std::cout << std::endl;
    for(int t=0;t<rows;t++)
    {
        for(int i=0;i<rows;i++)
        {
            std::cout << data[t*cols+i] << "\t";

        }
        std::cout <<std::endl;
    }
    std::cout << std::endl;
}

    Matrix Matrix::matrix_trans()
{
    Matrix B;
    B.rows=cols;
    B.cols=rows;
    B.data=(double *)malloc(B.cols*B.rows*sizeof(double));
    for(int t=0;t<B.rows;t++)
    {
        for(int i=0;i<B.cols;i++)
        {
            B.data[t+i*B.cols]=data[i+t*cols];
        }
    }
    return B;
}

Matrix Matrix::matrix_mult__scalar(const double scalar)
{
    Matrix B;
    B.rows=rows;
    B.cols=cols;
    B.data=(double *)malloc(B.cols*B.rows*sizeof(double));
    for(int t=0;t<rows;t++)
    {
        for(int i=0;i<cols;i++)
        {
            B.data[t+i*cols]=scalar*data[t+i*cols];
        }
    }
    return B;

}

double Matrix::matrix_trace()
{
    double trace=0;
    for(int i=0;i<rows;i++)
    {
        trace+=data[i+rows*i];
    }
    return trace;
}

Matrix Matrix::matrix_sum(const Matrix B)
{
    Matrix C;
    C.rows=rows;
    C.cols=cols;
    C.data=(double *)malloc(C.cols*C.rows*sizeof(double));
    for(int t=0;t<rows;t++)
    {
        for(int i=0;i<rows;i++)
        {
            C.data[i+t*cols]=data[i+t*cols]+B.data[i+t*cols];
        }
    }
    return C;
}

void Matrix::matrix_zero(const int Mrows, const int Mcols)
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

Matrix Matrix::matrix_mult( const Matrix B)
{
    Matrix C;
    C.matrix_zero(rows,B.cols);
    C.data=(double*)malloc(C.cols*C.rows*sizeof(double));
    for(int i=0;i<rows;i++)
    {
        for(int t=0;t<B.cols;t++)
        {
            for(int n=0;n<cols;n++)
            {
                C.data[i+t*rows]+=data[i+n*rows]*B.data[n+t*rows];
            }
        }
    }
    return C;
}

Matrix Matrix::Minor(int row,int col)
{
    Matrix B;
    B.rows=rows-1;
    B.cols=cols-1;
    B.data=(double*)malloc(B.cols*B.rows*sizeof(double));
    for(int rows=0;rows<B.rows;rows++)
    for(int i=0;i<B.rows;i++)
    {
        for(int j=0;j<B.cols;j++)
        {
            int r=0;
            int c=0;
            if(j>=col) c=1;
            if(i>=row) r=1;
            B.data[j + i * B.cols] = data[j+c+(i+r)*cols];
        }
    }
    return B;
};
double Matrix::matrix_determinant()
{
    double det=0;
    if(cols==1)
    {
        det=data[0];
    }
    if(cols==2)
    {
        det=data[0]*data[3]-data[2]*data[1];
    }
    else{
        int k=1;

        for(int i=0;i<rows;i++)
        {
            det+=k*data[i]*Minor(0,i).matrix_determinant();
            k*=(-1);
        }
    }
    return det;
};

Matrix Matrix::matrix_invert()
{
    Matrix invA;
    invA.rows=cols;
    invA.cols=rows;
    invA.data=(double*)malloc(invA.cols*invA.rows*sizeof(double));
    Matrix AlgDop;
    AlgDop.rows=cols;
    AlgDop.cols=rows;
    AlgDop.data=(double*)malloc(AlgDop.cols*AlgDop.rows*sizeof(double));
    int k=1;
    for(int rows=0;rows<AlgDop.rows;rows++)
    {
        for(int cols=0;cols<AlgDop.cols;cols++)
        {
            AlgDop.data[cols+rows*AlgDop.cols]=k*Minor(cols,rows).matrix_determinant();
            k*=(-1);
        }
    }

    invA=AlgDop.matrix_mult__scalar(1/matrix_determinant());
    return invA;
}

void Matrix::matrix_one(const int Mrows, const int Mcols)
{
    srand((unsigned int)time(nullptr));
    rows=Mrows;
    cols=Mcols;
    data=(double*)malloc(cols*rows*sizeof(double));
    for(int t=0;t<rows;t++)
    {
        for(int i=0;i<cols;i++)
        {
            if(i==t)
                data[t+i*cols]=1;
            else  data[t+i*cols]=0;
        }
    }
}

Matrix Matrix::matrix_power( const int power)
{
    Matrix C;
    Matrix B;
    B.rows=rows;
    B.cols=cols;
    B.data=(double*)malloc(B.cols*B.rows*sizeof(double));
    C.matrix_one(B.rows,B.cols);
    if(power!=0)
    {
        for (unsigned int i = 0; i < power; i++) {
            C.matrix_mult(B);
        }
    }
    return C;
}

Matrix Matrix::matrix_exp()
{
    Matrix B;
    B.matrix_one(rows,cols);
    B.rows=rows;
    B.cols=cols;
    B.data=(double*)malloc(B.cols*B.rows*sizeof(double));
    double F=1;
    for(int i=1;i<10;i++)
    {
        for (int t=2;t<i+1;t++){
            F=F*t;
        }
        B.matrix_sum(matrix_power(i).matrix_mult__scalar(1/F));
    }
    return B;

}
