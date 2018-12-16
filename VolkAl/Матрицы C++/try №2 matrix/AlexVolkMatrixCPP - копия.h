#ifndef ALEXVOLK_LIBRARY_H
#define ALEXVOLK_LIBRARY_H


class Matrix {
private:
    unsigned int rows;
    unsigned int cols;
public:
    double *data;
    Matrix(const unsigned rowss, const unsigned colss) {
        rows = rowss;
        cols = colss;
        data = new double[rows * cols];
    }
    Matrix(const unsigned size) {
        rows = size;
        cols = size;
        data = new double[size * size];
    }
    Matrix(const Matrix &K) {
        rows = K.rows;
        cols = K.cols;
        data = new double[rows * cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i * cols + j] = K.data[i * K.cols + j];
            }
        }
    }
    ~Matrix() {
        delete [] data;
    }
    // След матрицы
    double matrix_trace();
    //Минор матрицы
    Matrix matrix_minor(int row, int col);
    //Матрица дополнений
    Matrix matrix_dop(const Matrix A);
    //Определитель матрицы
    double matrix_determinant(const Matrix A);
    //Сумма матриц
    Matrix operator + (const Matrix &C);
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
    Matrix matrix_power(const unsigned int power);
    //Единичная матрица
    Matrix matrix_one();
    //Нулевая матрица
    Matrix matrix_zero(const unsigned int row, const unsigned int col);
    //Матрица, составленная из случайных чисел
    Matrix matrix_rand(const unsigned int rows, const unsigned int cols);
    //Вывести матрицу на экран
    void matrix_print(const Matrix A);

};
#endif