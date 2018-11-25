#include <iostream>

class Matrix
{
private:
    int rows;
    int cols;
    double *data;

    void setSize(int newRows, int newCols)
    {
        rows = newRows;
        cols = newCols;
        setHeapSize();
    }
    void setHeapSize()
    {
        data = new double[rows * cols];
    }

public:
    void set(const int row, const int col, const double value)
    {
        data[row * cols + col] = value;
    }

    int getRows()
    {
        return rows;
    }

    int getCols()
    {
        return cols;
    }

    double getValue(const int row, const int col)
    {
        double temp = data[row * cols + col];
        return data[row * cols + col];
    }

    //constructor
    Matrix(int newRows, int newCols)
    {
        std::cout << "standart constructor" << std::endl;
        setSize(newRows, newCols);
    }

    //constructor copy
    Matrix(const Matrix &A)
    {
        std::cout << "constructor copy" << std::endl;
        rows = A.rows;
        cols = A.cols;
        setSize(rows, cols);
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                data[row * cols + col] = A.data[row * cols + col];
            }
        }
    }


    //destructor
    ~Matrix()
    {
        printf("Minus matrix\n");
        delete data;
    }

    void print();
};

extern Matrix matrix_one(const unsigned int size);
