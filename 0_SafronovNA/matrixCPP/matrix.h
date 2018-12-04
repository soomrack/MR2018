#ifndef C_LIBRARY_H
#define C_LIBRARY_H


typedef struct {
        unsigned int rows;
        unsigned int cols;
        double* data;
} Matrix;


class MatrixCalc{
public:
    //MATRIX GENERATORS
// Единичная матрица
    static Matrix matrix_one(const unsigned int size);

// Нулевая матрица
    static Matrix matrix_zero(const unsigned int rows, const unsigned int cols);

// Матрица оставленная из случайных чисел из диапазона [-1, +1]
    static Matrix matrix_rand(const unsigned int rows, const unsigned int cols);

    // Скопировать матрицу
    static Matrix matrix_copy(const Matrix A);

    //UTILS
    //освободить память, занятую матрицей
    static void matrix_free(const Matrix A);

    //IO
    // Вывести матрицу на экран
    static void matrix_print(const Matrix A);

    //MATRIX TO DOUBLE
// След матрицы
    static double matrix_trace(const Matrix A);

// Определитель матрицы
    static double matrix_determinant(const Matrix A);

    //MATRIX TO MATRIX
// Сумма матриц
    static Matrix matrix_sum(const Matrix A, const Matrix B);

// Умножение матриц (assumed dot product)
    static Matrix matrix_mult(const Matrix A, const Matrix B);

// Умножение матрицы на скаляр
    static Matrix matrix_mult_scalar(const double scalar, const Matrix A);

// Транспонирование матрицы
    static Matrix matrix_trans(const Matrix A);

// Обращение матрицы
    static Matrix matrix_invert(const Matrix A);

// Матричная экспонента
    static Matrix matrix_exp(const Matrix A);

// Возведение матрицы в степень (натуральное число или 0)
    static Matrix matrix_power(const Matrix A, const unsigned int power);





};

#endif //C_LIBRARY_H
