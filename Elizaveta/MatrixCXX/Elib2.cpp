//
// Created by Елизавета on 12.11.2018.
//


#include <math.h>
#include <cstdlib>
#include "Elib2.h"
#include <iostream>


// След матрицы
extern double Matrix::matrix_trace(const Matrix A)
{
    double s = 0;
    for (int i = 0; i < A.rows; i++)
    {
        s += A.data[i*A.cols+i];
    }
    return s;
}


// Миноры
extern Matrix Matrix::matrix_minor(int row, int col, const Matrix A)
{
    Matrix result = {A.rows-1, A.cols-1};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
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


// Определитель матрицы
extern double Matrix::matrix_determinant(const Matrix A)
{
    double D = 0;
    switch (A.rows)
    {
        case 1:
            return A.data[0];
        case 2:
            return (A.data[0] * A.data[3] - A.data[1] * A.data[2]);
        default:
        {
            Matrix dop = matrix_dop(A);
            for (int j = 0; j < A.cols; j++)
            {
                D += A.data[j] * dop.data[j];
            }
            return D;
        }
    }
}

// Алгебраические дополнения
extern Matrix Matrix::matrix_dop(const Matrix A)
{
    Matrix result = {A.rows, A.cols};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < A.cols; j++)
        {
            result.data[i*A.cols + j] = pow((-1), i + j) * matrix_determinant(matrix_minor(i, j, A));
        }
    }
    return result;
}


// Сумма матриц
extern Matrix Matrix::matrix_sum(const Matrix A, const Matrix B)
{
    if ((A.rows != B.rows) || (A.cols != B.cols))
    {
        std::cout << "Sum error - different size\n";
        return A;
    }
    else
    {
        Matrix result = {A.rows, A.cols};
        result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
        for (int i = 0; i < A.rows; i++)
        {
            for (int j = 0; j < A.cols; j++)
            {
                result.data[i*A.cols+j] = A.data[i*A.cols+j] + B.data[i*A.cols+j];
            }

        }

        return result;
    }
}


// Умножение матриц
extern Matrix Matrix::matrix_mult(const Matrix A, const Matrix B)
{
    if (A.cols != B.rows)
    {
        std::cout << "Multiplication error \n";
        return A;
    }
    else
    {
        Matrix result = {A.rows, B.cols};
        result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
        for (int i = 0; i < A.rows; i++)
        {
            for (int j = 0; j < B.cols; j++)
            {
                result.data[i * B.cols + j] = 0;
                for (int k = 0; k < A.cols; k++) {
                    result.data[i * B.cols + j] += A.data[i * A.cols + k] * B.data[k * B.cols + j];
                }
            }
        }

        return result;
    }
}


// Умножение матрицы на скаляр
extern Matrix Matrix::matrix_mult_scalar(const double scalar, const Matrix A)
{
    Matrix result = {A.rows, A.cols};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < A.cols; j++)
        {
            result.data[i * A.cols + j] = scalar * A.data[i * A.cols + j];
        }
    }

    return result;
}

// Транспонирование матрицы
extern Matrix Matrix::matrix_trans(const Matrix A)
{
    Matrix result = {A.cols, A.rows};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < A.cols; j++)
        {
            result.data[j * A.rows + i] = A.data[i * A.cols + j];
        }
    }

    return result;
}

// Обращение матрицы
extern Matrix Matrix::matrix_invert(const Matrix A)
{
    double det = matrix_determinant(A);
    if (det == 0)
    {
        std::cout << "No invert matrix \n";
        return A;
    }
    else
    {
        Matrix result;
        result = matrix_mult_scalar(1/det, matrix_trans(matrix_dop(A)));
        return result;
    }
}

extern Matrix matrix_one_full(const unsigned int rows, const unsigned int cols)
{
    Matrix result = {rows, cols};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
    for (int i = 0; i < result.rows; i++)
    {
        for (int j = 0; j < result.cols; j++)
        {
            result.data[i * result.cols + j] = 1;
        }
    }

    return result;
}

// Возведение матрицы в степень (натуральное число или 0)
extern Matrix Matrix::matrix_power(const Matrix A, const unsigned int power)
{
    if (power == 0)
    {
        return matrix_one_full(A.rows, A.cols);
    }
    if (power == 1)
    {
        return A;
    }
    if (A.rows != A.cols)
    {
        std::cout << "only square matrix \n";
        return A;
    }
    Matrix result = A;
    for (int i = 0; i < (power-1); i++)
    {
        result = matrix_mult(result, A);
    }

    return result;
}

// Единичная матрица
extern Matrix Matrix::matrix_one(const unsigned int size)
{
    Matrix result = {size, size};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
    for (int i = 0; i < result.rows; i++)
    {
        for (int j = 0; j < result.cols; j++)
        {
            if (i == j)
            {
                result.data[i * result.cols + j] = 1;
            }
            else
            {
                result.data[i * result.cols + j] = 0;
            }
        }

    }

    return result;
}

// Нулевая матрица
extern Matrix Matrix::matrix_zero(const unsigned int rows, const unsigned int cols)
{
    Matrix result = {rows, cols};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
    for (int i = 0; i < result.rows; i++)
    {
        for (int j = 0; j < result.cols; j++)
        {
            result.data[i * result.cols + j] = 0;
        }
    }

    return result;
}

// Матрица оставленная из случайных чисел из диапазона [-1, +1]
extern Matrix Matrix::matrix_rand(const unsigned int rows, const unsigned int cols)
{
    Matrix result = {rows, cols};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
    for (int i = 0; i < result.rows; i++)
    {
        for (int j = 0; j < result.cols; j++)
        {
            result.data[i * result.cols + j] = -1 + rand()%3;
        }
    }

    return result;
}

// Вывести матрицу на экран
extern void Matrix::matrix_print(const Matrix A)
{
    std::cout << "matrix \n";
    for (int i = 0; i < (A.cols * A.rows); i++)
    {
        printf ("%5.2lf     ", A.data[i]);
        if ((i+1)%A.cols == 0)
        {
            printf("\n");
        }
    }
}

double norm (const Matrix A)
{
    double max_sum = 0;
    for (int i = 0; i < A.rows; i++)
    {
        double sum = 0;
        for (int j = 0; j < A.cols; j++)
        {
            sum += A.data[i * A.cols + j];
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

double factorial (int n)
{
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

extern Matrix Matrix::matrix_exp(const Matrix A)
{
    Matrix result = matrix_one_full(A.rows, A.cols);
    Matrix element = matrix_one_full(A.rows, A.cols);
    double eps = 0.001;
    int k = 1;
    while (norm(element) > eps)
    {
        element = matrix_mult_scalar(1/factorial(k), matrix_power(A, k));
        result = matrix_sum(result, element);
        k = k + 1;
    }
    return result;
}