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


// Определитель матрицы
extern double matrix_determinant(const Matrix A)
{
    double D, Ad, m;
    double M[4];
    int j;

    switch (A.rows)
        {
            case 1:
                return A.data[0];
            case 2:
                return (A.data[0] * A.data[3] - A.data[1] * A.data[2]);
            case 3:
            {
                for (int i = 0; i < A.rows; i++)
                {
                    j = 0;
                    for (int  k = 0; k < (A.rows * A.cols); k++)
                    {
                        if ((k < (i * A.cols)) && (k > (i * A.cols + 2)))
                        {
                            M[j] = A.data[k];
                            j += 1;
                        }

                    }
                    m = M[0] * M[3] - M[1] * M[2];
                    Ad = pow((-1), i + 1) * m;
                    D += A.data[i * A.cols] * Ad;
                }
                return D;
            }
        }
}


