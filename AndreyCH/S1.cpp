//
// Created by Laker on 22.12.2018.
//

#include "S1.h"
#include <math.h>
#include <cstdlib>
#include <iostream>

 double Mat::trace(const Mat A) // След
{
    double summ = 0;
    for (int i = 0; i < A.rows; i++)
    {
        summ += A.data[i*A.cols+i];
    }
    return summ;
}


Mat Mat::sum(const Mat A, const Mat B) // Сумма матриц
{
    if ((A.rows != B.rows) || (A.cols != B.cols))
    {
        std::cout << "Матрицы разного размера! \n";
        return A;
    }
    else
    {
        Mat result = {A.rows, A.cols};
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


Mat Mat::mult(const Mat A, const Mat B)// Умножение матриц
{
    if (A.cols != B.rows)
    {
        std::cout << "Multiplication error \n";
        return A;
    }
    else
    {
        Mat result = {A.rows, B.cols};
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


Mat Mat::mult_const(const double constt, const Mat A) // Умножение матрицы на константу
{
    Mat result = {A.rows, A.cols};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < A.cols; j++)
        {
            result.data[i * A.cols + j] = constt * A.data[i * A.cols + j];
        }
    }

    return result;
}


extern Mat Mat::transp(const Mat A) {
    Mat result = {A.cols, A.rows};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            result.data[j * A.rows + i] = A.data[i * A.cols + j];
        }
    }

    return result;
}

Mat Mat::minor(int row, int col, const Mat A)// Минор
{
    Mat result = {A.rows-1, A.cols-1};
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


Mat Mat::dop(const Mat A)// Алгебраические дополнения
{
    Mat result = {A.rows, A.cols};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < A.cols; j++)
        {
            result.data[i*A.cols + j] = pow((-1), i + j) * det(minor(i, j, A));
        }
    }
    return result;
}

double Mat::det(const Mat A) // Определитель матрицы
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
            Mat Dop = dop(A);
            for (int j = 0; j < A.cols; j++)
            {
                D += A.data[j] * Dop.data[j];
            }
            return D;
        }
    }
}

// Единичная матрица
Mat Mat::one(const unsigned int size)
{
    Mat result = {size, size};
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

double norm (const Mat A)
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

Mat all_one(const unsigned int rows, const unsigned int cols) {
    Mat result = {rows, cols};
    result.data = (double *) malloc(result.rows * result.cols * sizeof(double));
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            result.data[i * result.cols + j] = 1;
        }
    }

    return result;
}

Mat Mat::power(const Mat A, const unsigned int power)// Возведение матрицы в степень
{
    if (power == 0)
    {
        return all_one(A.rows, A.cols);
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
    Mat result = A;
    for (int i = 0; i < (power-1); i++)
    {
        result = mult(result, A);
    }

    return result;
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

extern Mat Mat::exp(const Mat A)
{
    Mat result = all_one(A.rows, A.cols);
    Mat element = all_one(A.rows, A.cols);
    double eps = 0.001;
    int k = 1;
    while (norm(element) > eps)
    {
        element = mult_const(1/factorial(k), power(A, k));
        result = sum(result, element);
        k = k + 1;
    }
    return result;
}

extern void Mat::print(const Mat A) // Вывести матрицу на экран
{
    //std::cout << "matrix \n";
    for (int i = 0; i < (A.cols * A.rows); i++)
    {
        printf ("%5.2lf     ", A.data[i]);
        if ((i+1)%A.cols == 0)
        {
            printf("\n");
        }
    }
}