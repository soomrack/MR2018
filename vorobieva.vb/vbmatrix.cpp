//
// Created by Veronika on 10/12/2018.
//

#include "vbmatrix.h"
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

//Деструктор
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

//след матрицы
double matrix_trace(const Matrix A){
    double trace = 0.0;
    if (A.cols != A.rows) {
        std::cout << "Identity matrix must be square!" << std::endl;
        exit (1);
    }
    else {
        for (unsigned int i = 0; i < A.cols; i++){
            for (unsigned int j = 0; j < A.rows; j++) {
                if (i == j) {
                    trace += A.getElement(i, j);
                }
            }
        };
        std::cout << '\n';
    }
    return trace;
};

//определитель
double matrix_determinant(const Matrix A){
    double det = 0;
    if (A.cols != A.rows){
        std::cout << "Identity matrix must be square!" << std::endl;
        exit(1);
    }
    else{
        if (A.cols == 1) {
            return A.getElement(0, 0);
        }
        else{
            Matrix B = Matrix(A.cols, A.rows);
            int row = 0;
            int sign;
            for(unsigned int col = 0; col < A.cols; col++){
                for(unsigned int i = 0; i < B.rows; i++){
                    for(unsigned int j = 0; j < B.cols; j++){
                        if((i < row) && (j < col))  B.setElement(i, j, A.getElement(i, j));
                        if((i < row) && (j >= col))  B.setElement(i, j, A.getElement(i, j + 1));
                        if((i >= row) && (j < col))  B.setElement(i, j, A.getElement(i + 1, j));
                        if((i >= row) && (j >= col))  B.setElement(i, j, A.getElement(i + 1, j + 1));
                    }
                }
                if(col % 2) sign = -1;
                else sign = 1;
                det += matrix_determinant(B)*A.getElement(col, 0)*sign;
            }
            return det;
        }
    }
};

int factorial(int a){
    int f = 1;
    for (int i = 0; i < a; i++){
        f *= a;
        a = a-1;
    }
    return f;
};

// Обращение матрицы
Matrix matrix_invert(const Matrix A){
    if(A.cols != A.rows){
        std::cout << "Матрица не квадратная";
        exit(1);
    };
    if(A.cols < 1) exit(1);
    Matrix B = Matrix (A.cols - 1, A.rows -1);
    Matrix C = Matrix (A.cols, A.rows);
    double det = 0;
    int sign;
    for(int col = 0; col < A.cols; col++) {
        for (unsigned int row = 0; row < A.rows; row++) {
            for (unsigned int i = 0; i < B.rows; i++) {
                for (unsigned int j = 0; j < B.cols; j++) {
                    if ((i < row) && (j < col)) B.setElement(i * B.cols, j, A.getElement(j, i * A.cols));
                    if ((i < row) && (j >= col)) B.setElement(i * B.cols, j, A.getElement(j + 1, i * A.cols));
                    if ((i >= row) && (j < col)) B.setElement(i * B.cols, j, A.getElement(j, (i + 1) * A.cols));
                    if ((i >= row) && (j >= col)) B.setElement(i * B.cols, j, A.getElement(j + 1, (i + 1) * A.cols));
                }
            }
            if ((col + row) % 2) sign = -1;
            else sign = 1;
            C.setElement(col, row * C.cols, matrix_determinant(B) * sign);
        }
    }
    Matrix D = Matrix (C.rows, C.cols);
    D = C.matrix_trans();
    Matrix Out = D.matrix_mult_scalar( 1/matrix_determinant(A));
    return Out;
};

// Матричная экспонента
Matrix matrix_exp(const Matrix A){
    Matrix exp = Matrix(A.cols, A.rows);
    exp = matrix_zero(exp.rows, exp.cols);
    for(unsigned int k = 0; k < 100; k++){
        Matrix B = Matrix (A.cols, A.rows);
        B = matrix_power(A, k);
        Matrix C = Matrix (A.cols, A.rows);
        C = B.matrix_mult_scalar(1.0/factorial(k));
        matrix_sum(exp, C);
    }
    return exp;
};

// Возведение матрицы в степень (натуральное число или 0)
Matrix matrix_power(const Matrix A, const unsigned int power){
    Matrix B = A;
    if (B.cols != B.rows) {
        std::cout << "Матрица не квадратная";
        exit(1);
    }
    else{
        for (int i = 1; i < power; i++){
            B = matrix_mult(B, A);
        }
        return B;
    }
};
