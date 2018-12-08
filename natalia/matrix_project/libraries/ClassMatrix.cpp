#include <iostream>
#include <cmath>
#include "ClassMatrix.h"

double ClassMatrix::matrix_trace(const ClassMatrix A) {
    double sum=0.0;
    for (int i = 0; i < A.rows ; i++) {
        sum += A.data[i + A.cols * i];
    }
    std::cout << "\n Matrix trace = " << sum << std::endl;
    return sum;
}

extern double* minor(double* A, int row, int col, int size)
{
    int row_minor = 0;
    int cols_minor = 0;
    double B[(size-1)*(size-1)];
    std::cout << std::endl;
    for (int rows = 0; rows < size-1; rows++) {
        if (rows == row)
        {
            row_minor = 1;
        }
        for (int cols = 0; cols < size-1; cols++)
        {
            if (cols == col) {
                cols_minor = 1;
            }
            if ((row_minor != 1)&&(cols_minor != 1))
                B[rows * (size-1) + cols] = A[rows * (size) + cols];
            if ((row_minor == 1)&&(cols_minor != 1))
                B[rows * (size-1) + cols] = A[(rows + 1) * (size) + cols];
            if ((row_minor != 1)&&(cols_minor == 1))
                B[rows * (size-1) + cols] = A[rows * (size) + (cols + 1)];
            if ((row_minor == 1)&&(cols_minor == 1))
                B[rows * (size-1) + cols] = A[(rows+1) * (size) + (cols + 1)];
            std::cout << B[rows * (size-1) + cols];
        }
        std::cout << std::endl;
        cols_minor = 0;
    }
    double* point_B = &*B;
    return point_B;

}

extern double determinant(double* C, int max)
{
    double det = 0;
    int sign = 1;
    int n;
    int m = 0;
    if (max == 1) {
        det = C[0];
        return det;
    }
    if (max == 2)
    {
        det = C[0] * C[1*max+1] - C[1] * C[2];
        return det;
    }
    if (max > 2) {

        for (n = 0; n < max; n++) {
                double add = add_matrix(C, n, m, max);
                det += C[n * max] * add;
        }
    }
    return det;
}

extern double add_matrix(double* G, int n, int m, int max){
    double* min = minor(G, n, m, max);
    double det_minor = determinant(min, max-1);
    double res = pow(-1.0, n + m) * det_minor;
    return res;

}



double ClassMatrix::matrix_determinant(const ClassMatrix A) {
    double determin = determinant(A.data, A.cols);
    printf("determinant \n");
    printf("%f", determin);
    return determin;
}

void ClassMatrix::matrix_mult__scalar(const double scalar, ClassMatrix &A) {
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++){
            A.data[i*(A.cols)+j] *= scalar ;
            std::cout << A.data[i*(A.cols)+j];
        }
        std::cout << std::endl;
    }
}

extern ClassMatrix& matrix_sum(const ClassMatrix A, const ClassMatrix B, ClassMatrix& C) {

    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++){
            C.data[i*(A.cols)+j] = A.data[i*(A.cols)+j]+B.data[i*(A.cols)+j];
            //std::cout << A.data[i*(A.cols)+j];
        }
        //std::cout << std::endl;
    }
    return C;
}

