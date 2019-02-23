//
// Created by Елизавета on 12.11.2018.
//


#include <math.h>
#include <cstdlib>
#include "Elib2.h"
#include <iostream>


// След матрицы
double Matrix::matrix_trace(const Matrix A)
{
    double s = 0;
    for (int i = 0; i < A.rows; i++)
    {
        s += A.data[i*A.cols+i];
    }
    return s;
}


// Миноры
Matrix Matrix::matrix_minor(int row, int col)
{
    Matrix result = {rows-1, cols-1};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if ((i == row) || (j == col))
            {
                continue;
            }
            result.data[k] = data[i * cols + j];
            k++;
        }
    }
    return result;
}


// Определитель матрицы
double Matrix::matrix_determinant()
{
    double D = 0;
    switch (rows)
    {
        case 1:
            return data[0];
        case 2:
            return (data[0] * data[3] - data[1] * data[2]);
        default:
        {
            Matrix dop = matrix_dop();
            for (int j = 0; j < cols; j++)
            {
                D += data[j] * dop.data[j];
            }
            return D;
        }
    }
}

// Алгебраические дополнения
Matrix Matrix::matrix_dop()
{
    Matrix result = {rows, cols};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
    for (int i = 0; i < rows; i++)
    {
        Matrix minor = {rows-1, cols-1};
        for (int j = 0; j < cols; j++)
        {
            minor = matrix_minor(i, j);
            result.data[i*cols + j] = pow((-1), i + j) * minor.matrix_determinant();
        }
    }
    return result;
}


// Сумма матриц
Matrix Matrix::matrix_sum(const Matrix &A)
{
    if ((A.rows != rows) || (A.cols != cols))
    {
        std::cout << "Sum error - different size\n";
        exit(1);
    }
    else
    {
        Matrix result = {A.rows, A.cols};
        result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
        for (int i = 0; i < A.rows; i++)
        {
            for (int j = 0; j < A.cols; j++)
            {
                result.data[i*A.cols+j] = A.data[i*A.cols+j] + data[i*A.cols+j];
            }

        }

        return result;
    }
}


// Умножение матриц
Matrix Matrix::matrix_mult(const Matrix A)
{
    if (A.cols != rows)
    {
        std::cout << "Multiplication error \n";
        exit(1);
    }
    else
    {
        Matrix result = {A.rows, cols};
        result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
        for (int i = 0; i < A.rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i * cols + j] = 0;
                for (int k = 0; k < A.cols; k++) {
                    result.data[i * cols + j] += A.data[i * A.cols + k] * data[k * cols + j];
                }
            }
        }

        return result;
    }
}


// Умножение матрицы на скаляр
extern Matrix Matrix::matrix_mult_scalar(const double scalar)
{
    Matrix result = {rows, cols};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.data[i * cols + j] = scalar * data[i * cols + j];
        }
    }

    return result;
}

// Транспонирование матрицы
Matrix Matrix::matrix_trans()
{
    Matrix result = {cols, rows};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.data[j * rows + i] = data[i * cols + j];
        }
    }

    return result;
}

// Обращение матрицы
Matrix Matrix::matrix_invert()
{
    double det = matrix_determinant();
    if (det == 0)
    {
        std::cout << "No invert matrix \n";
        exit(1);
    }
    else
    {
        Matrix result(rows, cols);
        result = matrix_dop();
        result =result.matrix_trans();
        result = matrix_mult_scalar(1/det);
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
Matrix Matrix::matrix_power(const unsigned int power)
{
    Matrix B(rows, cols);
    B = *this;

    if (power == 0)
    {
        return matrix_one_full(rows, cols);
    }
    if (power == 1)
    {
        return B;
    }
    if (rows != cols)
    {
        std::cout << "only square matrix \n";
        return B;
    }
    for (int i = 0; i < (power-1); i++)
    {
        B = matrix_mult(B);
    }

    return B;
}

// Единичная матрица
Matrix Matrix::matrix_one(const unsigned int size)
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
void Matrix::matrix_print()
{
    std::cout << "matrix \n";
    for (int i = 0; i < (cols * rows); i++)
    {
        printf ("%9.2lf     ", data[i]);
        if ((i+1)%cols == 0)
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

extern Matrix Matrix::matrix_exp()
{
    Matrix B(rows, cols);
    B = *this;
    Matrix result = matrix_one_full(rows, cols);
    Matrix element = matrix_one_full(rows, cols);
    double eps = 0.001;
    int k = 1;
    while (norm(element) > eps)
    {
        element = B.matrix_power(k);
        element = element.matrix_mult_scalar(1/factorial(k));
        result = result.matrix_sum(element);
        k = k + 1;
    }
    return result;
}