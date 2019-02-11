//
// Created by Никита on 12.11.2018.
//

#include "Matrix.h"

Matrix :: Matrix(unsigned int size){
    rows=size;
    cols=size;
    data = new double [rows*cols];
}

Matrix :: Matrix(unsigned int rows_,unsigned int cols_) {
    rows = rows_;
    cols = cols_;
    data = new double[rows * cols];
}

Matrix :: Matrix(const Matrix &A){
    rows=A.rows;
    cols=A.cols;
    data = new double[rows * cols];
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            data[row * cols + col] = A.data[row * cols + col];
        }
    }
}

void Matrix :: Print() {
    for(int row=0; row<rows; row++) {
        for (int col = 0; col < cols; col++)
            std::cout << data[row * cols + col] << "\t";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

Matrix Matrix :: One(unsigned int size){
    Matrix A(size);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (row==col){
                A.data[row * size + row] = 1.0;
            }else {
                A.data[row * size + col] = 0.0;
            }
        }
    }
    return A;
}

Matrix Matrix :: Zero(unsigned int rows_,unsigned int cols_){
    Matrix A(rows_,cols_);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            A.data[row * cols_ + col] = 0.0;
        }
    }
    return A;
}

Matrix Matrix :: Sum(const Matrix A, const Matrix B) {
    if ((A.cols != B.cols) || (A.rows != B.rows)) {
        std::cout<<"Different size";
        exit(1);
    }
    Matrix C(A.rows,A.cols);
    for (int row = 0; row < C.rows; row++) {
        for (int col = 0; col < C.cols; col++) {
            C.data[row * cols + col] = A.data[row * cols + col] + B.data[row * cols + col];
        }
    }
    return C;
}

Matrix Matrix :: Mult(const Matrix A, const Matrix B) {
    if (A.cols != B.rows) {
        std::cout<<"Unreal";
        exit(1);
    }
    Matrix C(A.rows,B.cols);
    for(int row=0; row<C.rows; row++)
    {
        for (int col=0; col<C.cols; col++)
        {
            C.data[row*C.cols+col]= 0;
            for (int i = 0; i < A.cols; i++) {
                C.data[row*C.cols+col]+= A.data[row*A.cols+i]*B.data[i*B.cols+col];
            }
        }
    }
    return C;
}

Matrix Matrix :: Trans() {
    Matrix result(cols, rows);
    for(int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            result.data[col*rows + row] = data[row*cols+col];
        }
    }
    return result;
}

double Matrix :: Trace() {
    if (rows != cols) {
        std::cout << "Matrix must be square!" << std::endl;
        exit(1);
    }
    double trace = 0;

    for (unsigned row = 0; row < rows; row++) {
        trace += data[row * cols + row];
    }
    return trace;
}

void Matrix :: Random() {
    srand(time(0));
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            data[row * cols + col] = -1 + 2.0 * (double)(rand()) / (double) RAND_MAX;
        }
    }
}

Matrix Matrix :: Mult_scalar(const Matrix A, const double scalar){
    Matrix result(A.rows,A.cols);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            result.data[row * cols + col] = scalar * A.data[row * cols + col];
        }
    }
    return result;
}

Matrix Matrix :: Power(const Matrix A, const unsigned int power) {
    if (A.rows != A.cols)
    {
        std::cout << "only square matrix \n";
        exit(1);
    }
    if (power == 0)
    {
        return One(A.rows);
    }
    if (power == 1)
    {
        return A;
    }
    Matrix result = A;
    result.Print();
    for (int i = 0; i < (power-1); i++)
    {
        result = Mult(result, A);
    }

    return result;
}

static double norm (Matrix A) {
    double max_sum = 0;
    for (int i = 0; i < A.get_Rows(); i++)
    {
        double sum = 0;
        for (int j = 0; j < A.get_Cols(); j++)
        {
            sum += A.data[i * A.get_Cols() + j];
        }
        if (i == 0)
        {
            max_sum = sum;
        }
        if (sum > max_sum)
        {
            max_sum = sum;
        }
    }
    return max_sum;
}

static double factorial (unsigned int n) {
    if (n == 0)
    {
        return 1;
    }
    double result = 1;
    for (int i = 1; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}

Matrix Matrix::matrix_exp(const Matrix A)
{
    Matrix result = One(A.rows);
    Matrix element = One(A.rows);
    double eps = 0.001;
    unsigned int k = 1;
    while (norm(element) > eps)
    {
        element = Mult_scalar(Power(A, k), 1/factorial(k));
        result = Sum(result, element);
        k = k + 1;
    }
    return result;
}

double Matrix::Determinant(const Matrix A) {
    double D = 0;
    if(A.rows == 1){
        return A.data[0];
    }
    if(A.rows == 2){
        return (A.data[0] * A.data[3] - A.data[1] * A.data[2]);
    }

    for (unsigned int i = 0; i < A.rows; i++)
    {
        D+= pow((-1), i + A.cols-1) * Determinant(Minor(i, 0, A)) * A.data[i * A.cols];
    }
    return D;
}

Matrix Matrix::Minor(unsigned int row, unsigned int col, const Matrix A) {
    Matrix result (A.rows-1, A.cols-1);
    int k = 0;
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < A.cols; j++)
        {
            if ((i == row) || (j == col))
            {
                continue;
            }
            result.data[k] = A.data[i * A.cols + j];
            k++;
        }
    }
    return result;
}