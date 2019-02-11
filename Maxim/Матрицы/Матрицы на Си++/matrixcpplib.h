#include <string>
#ifndef UNTITLED3_MATRIXCPPLIB_H
#define UNTITLED3_MATRIXCPPLIB_H
#endif

class MyMatrix {
public:
    unsigned int rows;
    unsigned int cols;
    double* data;
    MyMatrix(){};
    MyMatrix(unsigned int Matrows,unsigned int Matcols)
    {
        //std::cout<<"Ordinary constructor\n";
        rows=Matrows;
        cols=Matcols;
        data=(double*)malloc(cols*rows*sizeof(double));
    };
    MyMatrix(const MyMatrix &A){
        //std::cout<<"Copy constructor\n";
        rows=A.rows;
        cols=A.cols;
        data=(double*)malloc(cols*rows*sizeof(double));
        for(int t=0;t<cols*rows;t++)
                data[t]=A.data[t];
    }
    MyMatrix & operator=(const MyMatrix &A){
        if(this != &A){
          //  std::cout << "peregruzjenniy operator ="<< std::endl;
            free(data);
            rows=A.rows;
            cols=A.cols;
            data=(double*)malloc(cols*rows*sizeof(double));
            for(int t=0;t<cols*rows;t++)
                data[t]=A.data[t];
        }
        else {
            std::cout << "Samoprisvaivanie" << std::endl;
        }
        return *this;
    }
    ~MyMatrix(){
        //std::cout<<"Destructor\n";
        free(data);
    };

    MyMatrix matrix_rand(const unsigned int Matrows,const unsigned int Matcols);
    void matrix_print();
    MyMatrix matrix_trans();
    MyMatrix matrix_mult__scalar(const double scalar);
    double matrix_trace();
    MyMatrix matrix_sum(const MyMatrix B);
    void matrix_zero(const unsigned int Matrows, const unsigned int Matcols);
    MyMatrix matrix_mult(const MyMatrix B);
    double matrix_determinant();
    MyMatrix matrix_invert();
    void matrix_one(const unsigned int Matrows, const unsigned int Matcols);
    MyMatrix matrix_power(const int power);
    MyMatrix matrix_exp();
};