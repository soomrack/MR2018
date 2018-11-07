#include <iostream>
#include "ClassMatrix.h"

double ClassMatrix::matrix_trace(ClassMatrix A) {
    double sum=0.0;
    for (int i = 0; i < A.rows ; i++) {
        sum += A.data[i + A.cols * i];
    }
    std::cout << "\n Matrix trace = " << sum << std::endl;
    return sum;
}
<<<<<<< HEAD

extern double minor(ClassMatrix A, int row, int col, int size)
{
    int row_minor = 0;
    int cols_minor = 0;
    double B[A.rows*A.cols* sizeof(double)];
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
                B[rows * (size-1) + cols] = A.data[rows * (size) + cols];
            if ((row_minor == 1)&&(cols_minor != 1))
                B[rows * (size-1) + cols] = A.data[(rows + 1) * (size) + cols];
            if ((row_minor != 1)&&(cols_minor == 1))
                B[rows * (size-1) + cols] = A.data[rows * (size) + (cols + 1)];
            if ((row_minor == 1)&&(cols_minor == 1))
                B[rows * (size-1) + cols] = A.data[(rows+1) * (size) + (cols + 1)];
            std::cout <<B[rows * (size-1) + cols];
        }
        std::cout << std::endl;
        cols_minor = 0;
    }
    return B[A.rows*A.cols* sizeof(double)];

}
=======
>>>>>>> 33a26d8985261ae7bf72b981c6f43d46ceae23be
