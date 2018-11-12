#include"library.h"


void Matrixcpp::matrix_rand(const int Mrows, const int Mcols)
{
    srand((unsigned int)time(nullptr));
    rows=Mrows;
    cols=Mcols;
    data=(double *) malloc(rows * cols * sizeof(double));
    for(int t=0;t<rows;t++)
    {
        for(int i=0;i<cols;i++)
        {
            data[t+i*cols]=(double)(-100+rand()%200)/100;
        }
    }
}

void Matrixcpp::matrix_print()
{
    for(int t=0;t<rows;t++)
    {
        for(int i=0;i<rows;i++)
        {
            std::cout << data[t*cols+i] << "\t";

        }
        std::cout <<std::endl;
    }
}

    Matrixcpp Matrixcpp::matrix_trans()
{
    Matrixcpp B;
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