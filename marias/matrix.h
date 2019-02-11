#ifndef MATRIX_H
#define MATRIX_H


typedef struct {
        unsigned int rows;
        unsigned int cols;
        double* data;
} Matrix;


// След матрицы
double matrix_trace(const Matrix A);

// Определитель матрицы
double matrix_determinant(const Matrix A);
//уменьшение матрицы
Matrix matrix_minor(Matrix A, int row, int column);


// Сумма матриц
Matrix matrix_sum(const Matrix A, const Matrix B);

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


// Единичная матрица
Matrix matrix_one(const unsigned int rows, const unsigned int cols);

// Нулевая матрица
Matrix matrix_zero(const unsigned int rows, const unsigned int cols);

// Матрица оставленная из случайных чисел из диапазона [-1, +1]
Matrix matrix_rand(const unsigned int rows, const unsigned int cols);


// Вывести матрицу на экран
void matrix_print(const Matrix A);


double fRand(double fMin, double fMax);



#endif //MATRIX_H
