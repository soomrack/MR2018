#include <string>
#ifndef UNTITLED3_MATRIXCPPLIB_H
#define UNTITLED3_MATRIXCPPLIB_H
#endif

class MyMatrix {
public:
    unsigned int rows;
    unsigned int cols;
    double* data;
    MyMatrix()
    {
    };
    ~MyMatrix(){
        free(data);
    };
    void copy(MyMatrix A){
        rows=A.rows;
        cols=A.cols;
        data=(double*)malloc(cols*rows*sizeof(double));
        *data=*A.data;
        for(int t=0;t<rows;t++)
            for(int i=0;i<cols;i++)
                data[t*cols+i]=A.data[t*cols+i];
    }
    MyMatrix matrix_rand(const unsigned int Matrows,const unsigned int Matcols);
    void matrix_print();
    MyMatrix matrix_trans();
    MyMatrix matrix_mult__scalar(const double scalar);
    double matrix_trace();
    MyMatrix matrix_sum(const MyMatrix A, const MyMatrix B);
    void matrix_zero(const unsigned int Matrows, const unsigned int Matcols);
    MyMatrix matrix_mult( const MyMatrix A,const MyMatrix B);
    double matrix_determinant(const MyMatrix A);
    MyMatrix matrix_invert(const MyMatrix A);
    void matrix_one(const unsigned int Matrows, const unsigned int Matcols);
    MyMatrix matrix_power(const MyMatrix A, const int power);
    MyMatrix matrix_exp(const MyMatrix A);
};
