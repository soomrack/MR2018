
#include "matrix.h"
#include <iostream>
#include <ctime>


void Matrix::one()
{
    for (int row = 0; row < this->rows; row++)
    {
        for (int col = 0; col < this->cols; col++)
        {
            if (row == col)
            {
                this->data[row * this->cols + col] = 1.0;
            }
            else
            {
                this->data[row * this->cols + col] = 0.0;
            }
        }
    }
}

void Matrix::zero()
{
    for (int row = 0; row < this->rows; row++)
    {
        for (int col = 0; col < this->cols; col++)
        {
            this->data[row * this->cols + col] = 0.0;
        }
    }
}

static double get_rand_range(int min, int max)
{
    return ( (double) (rand() % (1000 * max - 1000 * min + 1) + 1000 * min) / 1000);
}

void Matrix::rand()
{
    static bool ifNotInit = true;
    if (ifNotInit)
    {
        srand( (unsigned int) time(0));
        ifNotInit = false;
    }

    for ( int row = 0; row < this->rows; row++)
    {
        for ( int col = 0; col < this->cols; col++)
        {
            this->data[row * this->cols + col] = get_rand_range(-1, 1);
        }
    }
}

void Matrix::print()
{
    for (int row = 0; row < rows; row++)
    {
        std::cout << "|";
        for(int col = 0; col < cols; col++)
        {
            std::cout << " " << data[row * cols + col] << " ";
        }
        std::cout << "|" << std::endl;
    }
}


Matrix Matrix::operator + (const Matrix &B)
{
    Matrix result(B.rows, B.cols);
    for (int row = 0; row < B.rows; row++)
    {
        for (int col = 0; col < A.cols; col++)
        {
            result.data[row * A.cols + col] = A.data[row * A.cols + col] + B.data[row * A.cols + col];
        }
    }
}
