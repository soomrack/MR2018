#ifndef ALEXVOLK_LIBRARY_H
#define ALEXVOLK_LIBRARY_H


class Matrix {
public:
    unsigned int rows;
    unsigned int cols;
    double *data;
public:
    // След матрицы
    double matrix_trace(const Matrix A);
    //Минор матрицы
    Matrix matrix_minor(int row, int col);
    //Матрица дополнений
    Matrix matrix_dop(const Matrix A);
    //Определитель матрицы
    double matrix_determinant(const Matrix A);
    //Сумма матриц
    Matrix matrix_sum(const Matrix A);
    //Собственные числа матрицы
    Matrix matrix_eigen_values();
    //Умножение матриц
    Matrix matrix_mult(const Matrix A, const Matrix B);
    //Умножение матрицы на скаляр
    Matrix matrix_mult__scalar(const double scalar, const Matrix A);
    //Транспонирование матрицы
    Matrix matrix_trans(const Matrix B);
    //Обращение матрицы
    Matrix matrix_invert(const Matrix A);
    //Возведение матрицы в степень (натуральное число или 0)
    Matrix matrix_power(const Matrix A, const unsigned int power);
    //Единичная матрица
    Matrix matrix_one(const unsigned int rows, const unsigned int cols);
    //Нулевая матрица
    Matrix matrix_zero(const unsigned int rows, const unsigned int cols);
    //Матрица, составленная из случайных чисел
    Matrix matrix_rand(const unsigned int rows, const unsigned int cols);
    //Вывести матрицу на экран
    void matrix_print(const Matrix A);

};
#endif