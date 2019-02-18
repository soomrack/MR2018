//
// Created by Елизавета on 12.11.2018.
//

#ifndef MR2018_ELIZAVETA_ELIB2_H
#define MR2018_ELIZAVETA_ELIB2_H


class Matrix {
public:
    unsigned int rows;
    unsigned int cols;
    double * data;

public:

    //Конструктор
    Matrix(unsigned int r, unsigned int c)
    {
        rows = r;
        cols = c;
        data = new double[rows * cols];
    }

    //Деструктор
    ~Matrix()
    {
        delete [] data;
    }

    //Конструктор копий
    Matrix(Matrix &Copy)
    {
        rows = Copy.rows;
        cols = Copy.cols;
        data = new double[rows * cols];

        for (unsigned row = 0; row < rows; row++)
        {
            for (unsigned col = 0; col < cols; col++)
            {
                data[row * cols + col] = Copy.data[row*cols+col];
            }
        }
    }


    // След матрицы
    double matrix_trace(const Matrix A);
    // Миноры
    Matrix matrix_minor(int row, int col);
    //Матрица дополнений
    Matrix matrix_dop();
    // Определитель матрицы
    double matrix_determinant();
    // Сумма матриц
    Matrix matrix_sum(const Matrix &A);
    // Умножение матриц
    Matrix matrix_mult(const Matrix A);
    // Умножение матрицы на скаляр
    Matrix matrix_mult_scalar(const double scalar);
    // Транспонирование матрицы
    Matrix matrix_trans();
    // Обращение матрицы
    Matrix matrix_invert();
    // Возведение матрицы в степень (натуральное число или 0)
    Matrix matrix_power(const unsigned int power);
    // Единичная матрица
    Matrix matrix_one(const unsigned int size);
    // Нулевая матрица
    Matrix matrix_zero(const unsigned int rows, const unsigned int cols);
    // Матрица оставленная из случайных чисел из диапазона [-1, +1]
    Matrix matrix_rand(const unsigned int rows, const unsigned int cols);
    // Вывести матрицу на экран
    void matrix_print();
    // Матричная экспонента
    Matrix matrix_exp();

};

#endif //MR2018_ELIZAVETA_ELIB2_H
