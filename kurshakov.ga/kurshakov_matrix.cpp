#include "kurshakov_matrix.h"
#include <iostream>
#include <ctime>

//Конструктор квадратной матрицы
Matrix::Matrix(unsigned int size) {
    cols = size;
    rows = size;
    data = new double[cols * rows];
}

//Конструктор прямоугольной матрицы
Matrix::Matrix(unsigned int rows_arg, unsigned int cols_arg) {
    cols = cols_arg;
    rows = rows_arg;
    data = new double[cols * rows];
}

//Деструктор высвобождает память
Matrix::~Matrix() {
    delete[] data;
}

//Возвращает значение элемента матрицы. Параметры: строка, столбец
double Matrix::getElement(unsigned int row, unsigned int col) const {
    return data[cols * row + col];
}

//Присваивает значение элементу матрицы. Параметры: строка, столбец, присваиваемое значение
void Matrix::setElement(unsigned int row, unsigned int col, double value) {
    data[cols * row + col] = value;
}

//Выводит матрицу на экран
void Matrix::matrix_print() {
    for (unsigned int row = 0; row < rows; row++) {
        for (unsigned int col = 0; col < cols; col++){
            std::cout << getElement(row, col) << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Единичная матрица
extern Matrix matrix_one(const unsigned int rows, const unsigned int cols) {
    if (rows != cols){
        std::cerr << "Identity matrix must be square!" << std::endl;
        exit(1);
    }
    Matrix A = Matrix(rows);
    for (unsigned row = 0; row < A.rows ; row++) {
        for (unsigned col = 0; col < A.cols; col++) {
            if (row == col)
                A.setElement(row, col, 1.0);
            else
                A.setElement(row, col, 0.0);
        }
    }
    return A;
}

// Нулевая матрица
extern Matrix matrix_zero(const unsigned int rows, const unsigned int cols) {
    Matrix A = Matrix(rows, cols);
    for (unsigned row = 0; row < A.rows ; row++) {
        for (unsigned col = 0; col < A.cols; col++) {
                A.setElement(row, col, 0.0);
        }
    }
    return A;
}

// Матрица составленная из случайных чисел из диапазона [-1, +1]
extern Matrix matrix_rand(const unsigned int rows, const unsigned int cols) {
    srand(time(0));
    Matrix A = Matrix(rows, cols);
    for (unsigned row = 0; row < A.rows ; row++) {
        for (unsigned col = 0; col < A.cols; col++) {
            A.setElement(row, col, (((double)(rand()%101)) - 50)/50);
        }
    }
    return A;
}

// Сумма матриц
extern Matrix matrix_sum(const Matrix A, const Matrix B) {
    if ((A.rows != B.rows) || (A.cols != B.cols)) {
        std::cerr << "Different matrix sizes." << std::endl;
        exit (1);
    }
    Matrix C = Matrix(A.rows, A.cols);
    for (unsigned int row = 0; row < A.rows; row++) {
        for (unsigned int col = 0; col < A.cols; col++) {
            C.setElement(row, col, (A.getElement(row, col) + B.getElement(row, col)));
        }
    }
    return C;
}

// Умножение матриц
extern Matrix matrix_mult(const Matrix A, const Matrix B) {
    if (A.cols != B.rows) {
        std::cout << "Unable to multiply!" << std::endl;
        exit (1);
    }
    Matrix C = Matrix(A.rows, B.cols);
    for (unsigned int row = 0; row < C.rows; row++) {
        for (unsigned int col = 0; col < C.cols; col++) {
            //вычисление row,col-того элемента матрицы-произведения
            double a[A.cols];
            double sum = 0;
            for (unsigned int numInARow = 0; numInARow < A.cols; numInARow++) {
                a[numInARow] = A.getElement(row, numInARow) * B.getElement(numInARow, col);
                sum += a[numInARow];
            }
            C.setElement(row, col, sum);
        }
    }
    return C;
}

// Умножение матрицы на скаляр
Matrix Matrix::matrix_mult_scalar(const double scalar) {
    Matrix C = Matrix(rows, cols);
    for (unsigned int row = 0; row < rows; row++) {
        for (unsigned int col = 0; col < cols; col++) {
            C.setElement(row, col, scalar * getElement(row, col));
        }
    }
    return C;
}

// Транспонирование матрицы
Matrix Matrix::matrix_trans() {
    Matrix C = Matrix(cols, rows);
    for (unsigned int row = 0; row < C.rows; row++) {
        for (unsigned int col = 0; col < C.cols; col++) {
            C.setElement(row, col, getElement(col, row));
        }
    }
    return C;
}

// Обращение матрицы
Matrix matrix_invert(const Matrix A);

// Матричная экспонента
Matrix matrix_exp(const Matrix A);

// Возведение матрицы в степень (натуральное число или 0)
Matrix matrix_power(const Matrix A, const unsigned int power);