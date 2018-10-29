#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "matrix.h"



extern double matrix_trace(const Matrix  A)
{

    double result = 0;

    for (int row = 0; row < A.rows; row++)
    {
        result += A.data[row * A.cols + row];
    }
    return result;
}

extern Matrix matrix_forminor(const Matrix A, int mrow, int mcol)
{
    int counter = 0;

    Matrix result = {A.rows - 1, A.cols - 1};
    result.data = malloc(result.cols * result.rows * sizeof(double));

    for (int row = 0; row < A.rows; row++)
    {
        if (row == mrow)
        {
            continue;
        }
        for (int col = 0; col < A.cols; col++)
        {
            if (col == mcol)
            {
                continue;
            }
            result.data[counter] = A.data[row * (A.cols) + col];
            counter++;
        }
    }

    return result;
}

extern double matrix_determinant(const Matrix A)
{

    if (A.rows == 1)
    {
        return A.data[0];
    }

    double result = 0;
    int sign = 1;

    for (int col = 0; col < A.cols; col++)
    {
        Matrix temp;
        temp = matrix_forminor(A, 0, col);

        result += sign * A.data[col] * matrix_determinant(temp);

        sign = -sign;

        free(temp.data);
    }
    return result;
}

extern void matrix_print(const Matrix A)
{
    for (int row = 0; row < A.rows; row++)
    {
        printf("|");
        for(int col = 0; col < A.cols; col++)
        {
            printf(" %5.2lf ", A.data[row * A.cols + col]);
        }
        printf("|\n");
    }
}

extern Matrix matrix_one(const unsigned int size)
{
    Matrix result = {size, size};
    result.data = malloc(size * size * sizeof(double));
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (row == col)
            {
                result.data[row * size + col] = 1.0;
            }
            else
            {
                result.data[row * size + col] = 0.0;
            }
        }
    }
    return result;
}

extern Matrix matrix_zero(const unsigned int rows, const unsigned int cols)
{
    Matrix result = {rows, cols};
    result.data = malloc(rows * cols * sizeof(double));
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            result.data[row * cols + col] = 0.0;
        }
    }
    return result;
}

extern Matrix matrix_sum(const Matrix A, const Matrix B)
{
    Matrix result = {A.rows, A.cols};
    result.data = malloc(result.rows * result.cols * sizeof(double));
    for (int row = 0; row < A.rows; row++)
    {
        for (int col = 0; col < A.cols; col++)
        {
            result.data[row * A.cols + col] = A.data[row * A.cols + col] + B.data[row * A.cols + col];
        }
    }
    return result;
}

extern Matrix matrix_trans(const Matrix A)
{
    Matrix result = {A.cols, A.rows};
    result.data = malloc(result.rows * result.cols * sizeof(double));
    for (int row = 0; row < result.rows; row++)
    {
        for (int col = 0; col < result.cols; col++)
        {
            result.data[row * result.cols + col] = A.data[col * A.cols + row];
        }
    }
    return result;
}

extern Matrix matrix_mult(const Matrix A, const Matrix B)
{
    Matrix result = {A.rows, B.cols};
    result.data = malloc(result.rows * result.cols * sizeof(double));

    Matrix transB = matrix_trans(B);
    for (int row = 0; row < result.rows; row++)
    {
        for (int col = 0; col < result.cols; col++)
        {
            result.data[row * result.cols + col] = 0;
            for (int i = 0; i < A.cols; i++)
            {
                result.data[row * result.cols + col] += A.data[row * A.cols + i] * transB.data[col * transB.cols  + i];
            }
        }
    }
    free(transB.data);
    return result;
}

extern Matrix matrix_mult__scalar(const double scalar, const Matrix A)
{
    Matrix result = {A.rows, A.cols};
    result.data = malloc(result.rows * result.cols * sizeof(double));

    for (int row = 0; row < result.rows; row++)
    {
        for (int col = 0; col < result.cols; col++)
        {
            result.data[row * result.cols + col] = scalar * A.data[row * A.cols + col];
        }
    }

    return result;
}

extern Matrix matrix_invert(const Matrix A)
{
    Matrix result = {A.rows, A.cols};
    result.data = malloc(result.rows * result.cols * sizeof(double));

    if (A.rows == 1)
    {
        result.data[0] = 1 / A.data[0];
        return result;
    }

    int sign = 1;
    for (int row = 0; row < result.rows; row++)
    {
        for (int col = 0; col < result.cols; col++)
        {

            Matrix temp;
            temp = matrix_forminor(A, row, col);

            result.data[row * result.cols + col] = sign * matrix_determinant(temp);
            sign = -sign;

            free(temp.data);
        }
    }
    matrix_mult__scalar(matrix_determinant(A), result);
    return result;
}








