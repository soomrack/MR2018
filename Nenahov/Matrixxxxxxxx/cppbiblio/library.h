#ifndef CPPBIBLIO_LIBRARY_H
#define CPPBIBLIO_LIBRARY_H



#endif

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

template <class T>
class Matrix  {
public:
    T *data;
    int rows;
    int cols;
    Matrix<T>(){
    };

public:
    void matrix_rand(const int Mrows, const int Mcols);
   /* void matrix_print();
    Matrix matrix_trans();
    Matrix matrix_mult__scalar(const T scalar);
    T matrix_trace();
    Matrix matrix_sum(const Matrix B);
    void matrix_zero(const int Mrows, const int Mcols);
    Matrix matrix_mult( const Matrix B);
    Matrix Minor(int row,int col);
    T matrix_determinant();
    Matrix matrix_invert();
    void matrix_one(const int Mrows, const int Mcols);
    Matrix matrix_power( const int power);
    Matrix matrix_exp();
    Matrix matrix_eigen_values();*/
};



/*class Matrix {
    public:
            double *data;
            int rows;
            int cols;
            Matrix(){
            };

    public:
    void matrix_rand(const int Mrows, const int Mcols);
    void matrix_print();
    Matrix matrix_trans();
    Matrix matrix_mult__scalar(const double scalar);
    double matrix_trace();
    Matrix matrix_sum(const Matrix B);
    void matrix_zero(const int Mrows, const int Mcols);
    Matrix matrix_mult( const Matrix B);
    Matrix Minor(int row,int col);
    double matrix_determinant();
    Matrix matrix_invert();
    void matrix_one(const int Mrows, const int Mcols);
    Matrix matrix_power( const int power);
    Matrix matrix_exp();
    Matrix matrix_eigen_values();

};
*/