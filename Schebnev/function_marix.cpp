#include "matrixlib.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


MatriXXX::MatriXXX(unsigned int size) {// Constructor of a square matrix
    cols = size;
    rows = size;
    data = new double[cols * rows];
}

MatriXXX::MatriXXX(unsigned int rows_arg, unsigned int cols_arg) {// Constructor of a rectangular matrix
    cols = cols_arg;
    rows = rows_arg;
    data = new double[cols * rows];
}
Matrix::MatriXXX_Destructor() {
    delete[] data;
}
double Matrix::Get_Element(unsigned int row, unsigned int col) const {
    return data[cols * row + col];
}

void MatriXXX::Set_Element(unsigned int row, unsigned int col, double value) { //Assigns a value to the matrix element. Parameters: row, column, value assigned
    data[cols * row + col] = value;
}
void MatriXXX::MatriXXX_print() {
        for (unsigned int row = 0; row < rows; row++) {
            for (unsigned int col = 0; col < cols; col++) {
                std::cout << Get_Element(row, col) << '\t';
            }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


extern MatriXXX MatriXXX_zero(const unsigned int Mrows, const unsigned int Mcols)
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
extern MatriXXX MatriXXX_one(const unsigned int Matrows, const unsigned int Matcols){

    rows=Matrows;
    cols=Matcols;
    data=(double *)malloc(cols*rows*sizeof(double));
    for(unsigned int i=0;i<rows;i++) {
        for(unsigned int j=0;j<cols;j++) {
            if(i==j){
                data[j + i * cols] = 1;
            }
            else {
                data[j + i * cols] = 0;
            }
        }
    }
}
MatriXXX MatriXXX::matrix_rand(const unsigned int rows, const unsigned int cols)
{
        srand(time(NULL));
        MatriXXX A = MatriXXX(rows, cols);
        for (unsigned row = 0; row < A.rows ; row++) {
            for (unsigned col = 0; col < A.cols; col++) {
                A.setElement(row, col, (((double)(rand()%101)) - 50)/50);
            }
        }
        return A;
}

double ** matrix_minor(double ** a, int size, int Last_str){
    double ** minor = (double **)malloc((size - 1) * sizeof(double *));
    for (int i = 0; i < size - 1; i++)
        minor[i] = (double *)malloc((size - 1) * sizeof(double));
    for (int i = 1; i < size; i++){
        for (int j = 0, k = 0; j < size; j++, k++){
            if (j == Last_str){
                k--;
                continue;
            }
            minor[i - 1][k] = a[i][j];
        }
    }

    return minor;
}

double det(double ** a, int size){
    if (size == 1)
        return a[0][0];
    if (size == 2)
        return (a[1][1] * a[0][0]) - (a[0][1] * a[1][0]);
    double determinant = 0, sign = 1;
    for (int i = 0; i < size; i++){
        determinant += (sign * a[0][i] * det(matrix_minor(a, size, i),size - 1));
        sign *= -1;
    }
    return determinant;
}

double MatriXXX::matrix_determinant(const MatriXXX A){
    double ** a = (double **)malloc(A.cols * sizeof(double *));
    for (int i = 0; i < A.cols; i++)
        a[i] = (double *)malloc(A.rows * sizeof(double));
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            a[i][j] = A.data[j + i * A.cols];
        }
    }
    return det(a, A.cols);
}

double MatriXXX::matrix_trace() {
    double trace=0;
    for(unsigned int i=0;i<rows;i++){
        trace+=data[i+i*rows];
    }
    return trace;
}


MatriXXX MatriXXX::matrix_trans()
{
    MatriXXX matrix = MatriXXX(cols, rows);
    for (unsigned int row = 0; row < matrix.rows; row++) {
        for (unsigned int col = 0; col < matrix.cols; col++) {
            matrix.Set_Element(row, col, Get_Element(col, row));
        }
    }
    return matrix;
}

MatriXXX MatriXXX::matrix_mult_scalar(const double scalar)
{
    MatriXXX matrix = MatriXXX(rows, cols);
    for (unsigned int row = 0; row < rows; row++) {
        for (unsigned int col = 0; col < cols; col++) {
            matrix.Set_Element(row, col, scalar * Get_Element(row, col));
        }
    }
    return matrix;

}


MatriXXX MatriXXX::matrix_sum(const MatriXXX A, const MatriXXX B)
{
    if ((A.rows != B.rows) || (A.cols != B.cols)) {
        std::cerr << "Different matrix sizes." << std::endl;
        exit (1);
    }
    MatriXXX matrix = MatriXXX(A.rows, A.cols);
    for (unsigned int row = 0; row < A.rows; row++) {
        for (unsigned int col = 0; col < A.cols; col++) {
            matrix.Set_Element(row, col, (A.Get_Element(row, col) + B.Get_Element(row, col)));
        }
    }
    return matrix;
}

MatriXXX MatriXXX::matrix_mult( const MatriXXX A, const MatriXXX B)
{
    if (A.cols != B.rows) {
        std::cout << "Unable to multiply!" << std::endl;
        exit (1);
    }
    MatriXXX matrix = MatriXXX(A.rows, B.cols);
    for (unsigned int row = 0; row < matrix.rows; row++) {
        for (unsigned int col = 0; col < matrix.cols; col++) {
            double a[A.cols];
            double sum = 0;
            for (unsigned int numInARow = 0; numInARow < A.cols; numInARow++) {
                a[numInARow] = A.getElement(row, numInARow) * B.getElement(numInARow, col);
                sum += a[numInARow];
            }
            matrix.Set_Element(row, col, sum);
        }
    }
    return matrix;
}

