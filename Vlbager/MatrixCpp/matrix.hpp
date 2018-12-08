#include <iostream>
#include <vector>

typedef std::vector<double> dVector;

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

    void swapRows(unsigned int row1, unsigned int row2);

    Matrix forMinor(unsigned int mrow, unsigned int mcol);

    double Enorm();

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
    Matrix(const int newRows, const int newCols)
    {
        std::cout << "standart constructor" << std::endl;
        setSize(newRows, newCols);
    }

    //конструктор для квадратной матрицы
    Matrix(int size)
    {
        std::cout << "quadro constructor" << std::endl;
        setSize(size, size);
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

    void operator = (const Matrix &A)
    {
        std::cout << "operator =" << std::endl;
        for (int row = 0; row < A.rows; row++)
        {
            for (int col = 0; col < A.cols; col++)
            {
                this->data[row * this->cols + col] = A.data[row * A.cols + col];
            }
        }
    }

    //destructor
    ~Matrix()
    {
        printf("destructor\n");
        delete data;
    }


    void print();

    void one();

    void zero();

    void rand();

    Matrix operator + (const Matrix &B);

    Matrix operator - (const Matrix &B);

    Matrix trans();

    Matrix operator * (Matrix &B);

    Matrix operator * (double scalar);

    Matrix invert();

    double determinant();

    Matrix exp();

    Matrix power(unsigned int power);

    dVector getVector(int col)
    {
        dVector result;
        for (int row = 0; row < this->rows; row++)
        {
            result.push_back(this->data[row * this->rows + col]);
        }
        return result;
    }

    void QR(Matrix &Q, Matrix &R);

    bool checkTriangular();

    Matrix eigenValues();

    Matrix eigenVectors();

};
