#include <string>
#ifndef UNTITLED3_MATRIXCPPLIB_H
#define UNTITLED3_MATRIXCPPLIB_H
#endif

class MyMatrix {
public:
    unsigned int rows;
    unsigned int cols;
    double* data;
public:
MyMatrix()
{
};
public:
MyMatrix matrix_rand(const unsigned int Matrows,const unsigned int Matcols);
    void matrix_print();
    MyMatrix matrix_trans();
    MyMatrix matrix_mult__scalar(const double scalar);
    double matrix_trace();
    MyMatrix matrix_sum(const MyMatrix A);
    void matrix_zero(const unsigned int Matrows, const unsigned int Matcols);
   MyMatrix matrix_mult( const MyMatrix A);
    double matrix_determinant(const MyMatrix A);
   // MyMatrix matrix_invert();
    void matrix_one(const unsigned int Matrows, const unsigned int Matcols);
    //MyMatrix matrix_power( const int power);
    //MyMatrix matrix_exp();
};
