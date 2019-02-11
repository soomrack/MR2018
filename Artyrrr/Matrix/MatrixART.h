#ifndef INC_1_MatrixART_H
#define INC_1_MatrixART_H


class Mat {
public:
    unsigned int rows;
    unsigned int cols;
    double * data;

public:

    double trace(const Mat A);// След матрицы

    Mat sum(const Mat A, const Mat B);// Сумма матриц

    Mat mult(const Mat A, const Mat B);// Умножение матриц

    Mat mult_const(const double scalar, const Mat A); // Умножение матрицы на скаляр

    Mat transp(const Mat A); // Транспонирование матрицы

    Mat minor(int row, int col, const Mat A);// Миноры

    Mat dop(const Mat A);//Матрица дополнений

    double det(const Mat A); // Определитель матрицы

    Mat one(const unsigned int size);  // Единичная матрица

    Mat power(const Mat A, const unsigned int power); // Возведение матрицы в степень

    Mat exp(const Mat A);

    void print(const Mat A);// Вывести матрицу на экран
};


#endif //INC_1_MatrixART_H
