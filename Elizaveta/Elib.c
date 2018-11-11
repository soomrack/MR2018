//
// Created by Елизавета on 17.09.2018.
//


#include <stdio.h>
#include <stdlib.h>
#include "Elib.h"
#include <Math.h>


void matrix_multiplication (int* A, int* B, int* C, int m, int n, int q)
{
    for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                C[i*q+j] = 0;
                for (int k = 0; k < n; k++)
                {
                    C[i*q+j] += A[i*n+k] * B[k*q+j];
                }
            }
        }
}

// След матрицы
extern double matrix_trace(const Matrix A)
{
    double s = 0;
    for (int i = 0; i < A.rows; i++)
    {
       s += A.data[i*A.cols+i];
    }
    return s;
}

// Миноры
extern Matrix matrix_minor(int row, int col, const Matrix A)
{
    Matrix result = {A.rows-1, A.cols-1};
    result.data = malloc(result.rows * result.cols * sizeof(double));
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

// Алгебраические дополнения
extern Matrix matrix_dop(const Matrix A)
{
    Matrix result = {A.rows, A.cols};
    result.data = malloc(result.rows * result.cols * sizeof(double));
    Matrix M;
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < A.cols; j++)
        {
            M = matrix_minor(i, j, A);
            result.data[i*A.cols + j] = pow((-1), i + j) * matrix_determinant(M);
            free(M.data);
        }
    }
    return result;
}

// Определитель матрицы
extern double matrix_determinant(const Matrix A)
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

// Собственные числа матрицы
extern Matrix matrix_eigen_values(const Matrix A);


// Матрица собственных векторов
extern Matrix matrix_eigen_vectors(const Matrix A);


// Сумма матриц
extern Matrix matrix_sum(const Matrix A, const Matrix B)
{
    if ((A.rows != B.rows) || (A.cols != B.cols))
    {
        printf("Sum error - different size\n");
    }
    else
    {
        Matrix result = {A.rows, A.cols};
        result.data = malloc(result.rows * result.cols * sizeof(double));
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
extern Matrix matrix_mult(const Matrix A, const Matrix B)
{
    if (A.cols != B.rows)
    {
        printf ("Multiplication error \n");
    }
    else
    {
        Matrix result = {A.rows, B.cols};
        result.data = malloc(result.rows * result.cols * sizeof(double));
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
extern Matrix matrix_mult__scalar(const double scalar, const Matrix A)
{
    Matrix result = {A.rows, A.cols};
    result.data = malloc(result.rows * result.cols * sizeof(double));
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
extern Matrix matrix_trans(const Matrix A)
{
    Matrix result = {A.cols, A.rows};
    result.data = malloc(result.rows * result.cols * sizeof(double));
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
extern Matrix matrix_invert(const Matrix A)
{
    double det = matrix_determinant(A);
    if (det == 0)
    {
        printf ("No invert matrix \n");
    }
    else
    {
        Matrix result;
        result = matrix_mult__scalar(1/det, matrix_trans(matrix_dop(A)));
        return result;
    }
}
// Матричная экспонента
extern Matrix matrix_exp(const Matrix A);

// Возведение матрицы в степень (натуральное число или 0)
extern Matrix matrix_power(const Matrix A, const unsigned int power)
{
    if (power < 2)
    {
        printf("wrong power \n");
    }
    else
    {
        if (A.rows != A.cols)
        {
            printf("only square matrix \n");
        }
        else
        {
            Matrix result = A;
            for (int i = 0; i < (power-1); i++)
            {
                result = matrix_mult(result, A);
            }

        return result;
        }
    }
}

// Единичная матрица
extern Matrix matrix_one(const unsigned int size)
{
    Matrix result = {size, size};
    result.data = malloc(result.rows * result.cols * sizeof(double));
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
extern Matrix matrix_zero(const unsigned int rows, const unsigned int cols)
{
    Matrix result = {rows, cols};
    result.data = malloc(result.rows * result.cols * sizeof(double));
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
extern Matrix matrix_rand(const unsigned int rows, const unsigned int cols)
{
    Matrix result = {rows, cols};
    result.data = malloc(result.rows * result.cols * sizeof(double));
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
extern void matrix_print(const Matrix A)
{
    printf("matrix \n");
    for (int i = 0; i < (A.cols * A.rows); i++)
    {
        printf ("%5.2lf     ", A.data[i]);
        if ((i+1)%A.cols == 0)
        {
            printf("\n");
        }
    }
}

// ТАУ

// Решение уравнения Ляпунова X * A + A^T * X = -C
extern Matrix matrix_lyapunov_equation(const Matrix A, const Matrix C);



