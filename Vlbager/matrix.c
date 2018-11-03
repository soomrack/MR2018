#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

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
    printf("\n");
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

double get_rand_range(int min, int max)
{
    return ( (double) (rand() % (1000 * max - 1000 * min + 1) + 1000 * min) / 1000);
}

extern Matrix matrix_rand(const unsigned int rows, const unsigned int cols)
{
    Matrix result = {rows, cols};
    result.data = malloc(rows * cols * sizeof(double));

    static bool ifNotInit = true;
    if (ifNotInit)
    {
        srand( (unsigned int) time(NULL));
        ifNotInit = false;
    }

    for ( int row = 0; row < result.rows; row++)
    {
        for ( int col = 0; col < result.cols; col++)
        {
            result.data[row * result.cols + col] = get_rand_range(-1, 1);
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

void matrix_swap_rows(Matrix A, int rowtoswap1, int rowtoswap2)
{
    double temp;
    for (int col = 0; col < A.cols; col++)
    {
        temp = A.data[rowtoswap1 * A.cols + col];
        A.data[rowtoswap1 * A.cols + col] = A.data[rowtoswap2 * A.cols + col];
        A.data[rowtoswap2 * A.cols + col] = temp;
    }
}

void matrix_datacopy(Matrix A, const Matrix B)
{
    for (int row = 0; row < A.rows; row++)
    {
        for (int col = 0; col < A.cols; col++)
        {
            A.data[row * A.cols + col] = B.data[row * B.cols + col];
        }
    }
}

extern Matrix matrix_invert(const Matrix A)
{
    Matrix A2 = {A.rows, A.cols};
    A2.data = malloc(A2.rows * A2.cols * sizeof(double));
    matrix_datacopy(A2, A);

    Matrix result = matrix_one(A.rows);

    //прямой ход
    for (int diagonal = 0; diagonal < A2.cols; diagonal++)
    {
        //ищу ненулевой элемент и меняю строки местами, если нужно
        if (A2.data[diagonal * A2.rows + diagonal] == 0)
        {
            for (int nozerorow = diagonal + 1; nozerorow < A2.rows; nozerorow++)
            {
                if (A2.data[nozerorow * A2.rows + diagonal] == 0)
                {
                    continue;
                }
                matrix_swap_rows(A2, diagonal, nozerorow);
                matrix_swap_rows(result, diagonal, nozerorow);
                break;
            }
        }


        //делим всю строку на A[row][row]
        double temp = A2.data[diagonal * A2.cols + diagonal];
        for (int col = 0; col < A2.cols; col++)
        {
            A2.data[diagonal * A2.cols + col] /= temp;
            result.data[diagonal * result.cols + col] /= temp;
        }

        //отнимаю от всех нижних строк diagonal строку, помноженную на [row][diagonal] элемент
        for (int row = diagonal + 1; row < A2.rows; row++)
        {
            temp = A2.data[row * A2.cols + diagonal];
            for (int col = 0; col < A2.cols; col++)
            {
                A2.data[row * A2.cols + col] -= A2.data[diagonal * A2.cols + col] * temp;
                result.data[row * result.cols + col] -= result.data[diagonal * A2.cols + col] * temp;
            }
        }

    }
    //обратный ход
    for ( int diagonal = 1; diagonal < A2.rows; diagonal++)
    {
        for ( int row = 0; row < diagonal; row++)
        {
            double temp = A2.data[row * A2.cols + diagonal];
            for ( int col = 0; col < A2.cols; col++)
            {
                A2.data[row * A2.cols + col] -= A2.data[diagonal * A2.cols + col] * temp;
                result.data[row * result.cols + col] -= result.data[diagonal * result.cols + col] * temp;
            }
        }
    }

    free(A2.data);
    return result;
}

extern Matrix matrix_power(const Matrix A, const unsigned int power)
{
    Matrix result = {A.rows, A.cols};
    result.data = malloc(result.rows * result.cols * sizeof(double));

    if (power == 0)
    {
        Matrix one = matrix_one(result.rows);
        matrix_datacopy(result, one);
        free(one.data);
        return result;
    }

    matrix_datacopy(result, A);

    if (power == 1)
    {
        return result;
    }


    for (int i = 1; i < power; i++)
    {
        double * dataptr = result.data;
        result = matrix_mult(result, A);
        free(dataptr);
    }

    return result;
}

extern Matrix matrix_exp(const Matrix A)
{
    Matrix result = {A.rows, A.cols};
    result.data = malloc(result.rows * result.cols * sizeof(double));

    //blabla
}







