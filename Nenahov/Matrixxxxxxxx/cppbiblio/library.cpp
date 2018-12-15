#include"library.h"




template <class T>
void Matrix<T>::matrix_rand(const int Mrows, const int Mcols)
{
    srand((unsigned int)time(nullptr));
    rows=Mrows;
    cols=Mcols;
    data=(T *) malloc(rows * cols * sizeof(T));
    for(int t=0;t<rows;t++)
    {
        for(int i=0;i<cols;i++)
        {
            data[t+i*cols]=(T)(-100+rand()%200)/100;
        }
    }
}

/*void Matrix<T>::matrix_print()
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

/*    Matrix Matrix::matrix_trans()
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

T Matrix::matrix_trace()
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
    {
        for(int cols=0;cols<B.cols;cols++)
        {
            int r=0;
            int c=0;
            if(cols>=col) c=1;
            if(rows>=row) r=1;
            B.data[cols + rows * B.cols] = data[cols+c+(rows+r)*cols];
        }
    }
    return B;
}
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
        int rows=0;
        for(int cols=0;cols<rows;cols++)
        {
            det+=k*data[cols]*Minor(rows,cols).matrix_determinant();
            k*=(-1);
        }
    }
    return det;
}

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

extern Matrix Matrix::matrix_eigen_values()
{
    Matrix B;
    B.rows=rows;
    B.cols=1;
    double w0[100],w[100],summ=0,w0norm[100],e,d,d0;
    int i,j,k;
    for (i=0;i<rows;i++)
        w0[i]=0;
    w0[0]=1;
    do
    {
        for (i=0;i<rows;i++)
            summ=summ+w0[i]*w0[i];
        d0=sqrt(summ);
        for (i=0;i<rows;i++)
            B.data[i]=w0[i]/d0;
        for (i=0;i<rows;i++)
        {
            w[i]=0;
            for (j=0;j<rows;j++)
                w[i]=w[i]+data[i+j*cols]*B.data[j];
        }
        summ=0;
        for (i=0;i<rows;i++)
            summ=summ+w[i]*w[i];
        d=sqrt(summ);
        e=fabs(d-d0);
        for (i=0;i<rows;i++)
            w0[i]=w[i];
        summ=0;
    }
    while(e>0.001);
   return B;

}*/