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
Matrix::Matrix(unsigned int cols_arg, unsigned int rows_arg) {
    cols = cols_arg;
    rows = rows_arg;
    data = new double[cols * rows];
}

//Деструктор высвобождает память
Matrix::~Matrix() {
    delete[] data;
}

//Возвращает значение элемента матрицы. Параметры: строка, столбец
double Matrix::getElement(unsigned int row, unsigned int col) {
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
    Matrix A = Matrix(cols, rows);
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
    Matrix A = Matrix(cols, rows);
    for (unsigned row = 0; row < A.rows ; row++) {
        for (unsigned col = 0; col < A.cols; col++) {
            A.setElement(row, col, (((double)(rand()%101)) - 50)/50);
        }
    }
    return A;
}

// Сумма матриц
Matrix Matrix::matrix_sum(const Matrix B) {
    if ((rows != B.rows) || (cols != B.cols)) {
        std::cerr << "Different matrix sizes." << std::endl;
        exit (1);
    }
    Matrix C = Matrix(cols, rows);
    for (unsigned int row = 0; row < rows; row++) {
        for (unsigned int col = 0; col < cols; col++) {
            setElement(row, col, getElement(row, col) + B.getElement(row, col));
        }
    }
    return C;
}

// Умножение матриц
Matrix matrix_mult(const Matrix A, const Matrix B);

// Умножение матрицы на скаляр
Matrix matrix_mult__scalar(const double scalar, const Matrix A);

// Транспонирование матрицы
Matrix matrix_trans(const Matrix A);

// Обращение матрицы
Matrix matrix_invert(const Matrix A);

// Матричная экспонента
Matrix matrix_exp(const Matrix A);

// Возведение матрицы в степень (натуральное число или 0)
Matrix matrix_power(const Matrix A, const unsigned int power);