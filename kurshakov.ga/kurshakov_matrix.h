//
// Created by admin on 07.12.2018.
//

#ifndef MR2018_KURSHAKOV_MATRIX_H
#define MR2018_KURSHAKOV_MATRIX_H

#endif //MR2018_KURSHAKOV_MATRIX_H

class Matrix {
private:
    double *data;
public:
    unsigned int cols;
    unsigned int rows;

    //Конструкторы:
    explicit Matrix(unsigned int size); //для квадратной матрицы
    Matrix(unsigned int cols_arg, unsigned int rows_arg); //для прямоугольной матрицы

    //Деструктор. Высвобождает память.
    ~Matrix();

    //Возвращает значение элемента матрицы. Параметры: строка, столбец
    double getElement(unsigned int row, unsigned int col);

    //Присваивает значение элементу матрицы. Параметры: строка, столбец, присваиваемое значение
    void setElement(unsigned int row, unsigned int col, double value);

    //Выводит матрицу на экран
    void matrix_print();

    // Сумма матриц
    Matrix matrix_sum(const Matrix B);

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
};

// Единичная матрица
extern Matrix matrix_one(const unsigned int rows, const unsigned int cols);

// Нулевая матрица
extern Matrix matrix_zero(const unsigned int rows, const unsigned int cols);

// Матрица оставленная из случайных чисел из диапазона [-1, +1]
extern Matrix matrix_rand(const unsigned int rows, const unsigned int cols);