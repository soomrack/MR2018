#include <string>

#ifndef UNTITLED42_MATRIXLIB_H
#define UNTITLED42_MATRIXLIB_H

#endif //UNTITLED42_MATRIXLIB_H
class MatriXXX {
public:
    unsigned int rows;
    unsigned int cols;
private:
    double* data;
public:
    explicit MatriXXX(unsigned int size); //Constructor of a square matrix

    MatriXXX(unsigned int cols_arg, unsigned int rows_arg); // Constructor of a rectangular matrix

    ~MatriXXX();// Destructor that memory free.

    double getElement(unsigned int row, unsigned int col) const;// Returns the value of the matrix element. Parameters: row, column

    MatriXXX matrix_rand(const unsigned int rows,const unsigned int cols);//Matrix composed of random numbers from the range [-1, +1]

    void matrix_print();//Displays a matrix on the screen.

    MatriXXX matrix_trans();//Matrix transpose

    MatriXXX matrix_mult__scalar(const double scalar);//Matrix multiplication by scalar

    double matrix_trace();//

    MatriXXX matrix_sum(const MatriXXX A, const MatriXXX B);//Matrix sum

    void matrix_zero(const unsigned int rows, const unsigned int cols);//Zero Matrix

    MatriXXX matrix_mult( const MatriXXX A, const MatriXXX B);
    double matrix_determinant(const MatriXXX A);

    MatriXXX matrix_invert();//Matrix inversion

    void matrix_one(const unsigned int rows, const unsigned int cols);//Unit matrix

    MatriXXX matrix_power( const int power);//Raising the matrix to a power (a natural number or 0)

    MatriXXX matrix_exp();//Matrix Exhibitor
    void setElement(unsigned int row, unsigned int col, double value);//Assigns a value to the matrix element. Parameters: row, column, value assigned

};