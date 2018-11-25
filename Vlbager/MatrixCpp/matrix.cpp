
#include "matrix.h"
#include <iostream>


Matrix Matrix::one(const unsigned int size)
{
    Matrix result(size, size);
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (row == col)
            {
                result.set(row, col, 1.0);
            }
            else
            {
                result.set(row, col, 0.0);
            }
        }
    }
    return result;
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