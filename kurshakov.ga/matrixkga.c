#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    unsigned int rows;
    unsigned int cols;
    double* data;
} Matrix;

// След матрицы
extern double matrix_trace(const Matrix A) {
    if (A.cols != A.rows) {
        printf("Матрица не квадратная.\n");
        exit (1);
    }
    double trace = 0;
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            if (i == j) {
                trace += A.data[j + i * A.cols];
            }
        }
    }
    return trace;
}

// Определитель матрицы
extern double matrix_determinant(const Matrix A);

// Собственные числа матрицы
extern Matrix matrix_eigen_values(const Matrix A);

// Матрица собственных векторов
extern Matrix matrix_eigen_vectors(const Matrix A);


// Сумма матриц
extern Matrix matrix_sum(const Matrix A, const Matrix B) {
    if ((A.rows != B.rows) || (A.cols != B.cols)) {
        printf("Матрицы разных размерностей.\n");
        exit (1);
    }
    Matrix C;
    C.rows = A.rows;
    C.cols = A.cols;
    C.data = malloc(A.rows * A.cols * sizeof(double));
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            C.data[j + i * C.cols] = A.data[j + i * C.cols] + B.data[j + i * C.cols];
        }
    }
    return C;
}

// Умножение матриц
extern Matrix matrix_mult(const Matrix A, const Matrix B) {
    if (A.cols != B.rows) {
        printf("Матрицы нельзя перемножить.\n");
        exit (1);
    }
    Matrix C;
    C.rows = A.rows;
    C.cols = B.cols;
    C.data = malloc(C.rows * C.cols * sizeof(double));
    for (int row = 0; row < C.rows; row++) {
        for (int col = 0; col < C.cols; col++) {
            double a[A.cols];
            double sum = 0;
            for (int numInARow = 0; numInARow < A.cols; numInARow++) {
                a[numInARow] = A.data[numInARow + row * C.cols] * B.data[col + numInARow * C.cols];
                sum += a[numInARow];
            }
            C.data[col + row * C.cols] = sum;
        }
    }
    return C;
}

// Умножение матрицы на скаляр
extern Matrix matrix_mult__scalar(const double scalar, const Matrix A){
    Matrix C;
    C.rows = A.rows;
    C.cols = A.cols;
    C.data = malloc(A.rows * A.cols * sizeof(double));
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            C.data[j + i * C.cols] = scalar * A.data[j + i * C.cols];
        }
    }
    return C;
}

// Транспонирование матрицы
extern Matrix matrix_trans(const Matrix A);

// Обращение матрицы
extern Matrix matrix_invert(const Matrix A);

// Матричная экспонента
extern Matrix matrix_exp(const Matrix A);

// Возведение матрицы в степень (натуральное число или 0)
extern Matrix matrix_power(const Matrix A, const unsigned int power);


// Единичная матрица
extern Matrix matrix_one(const unsigned int rows, const unsigned int cols) {
    if (cols != rows) {
        printf("Матрица не квадратная.\n");
        exit (1);
    }
    Matrix A;
    A.rows = rows;
    A.cols = cols;
    A.data = malloc(rows * cols * sizeof(double));
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            if (i == j) {
                A.data[j + i * cols] = 1;
            }
            else {
                A.data[j + i * cols] = 0;
            }
        }
    }
    return A;
}

// Нулевая матрица
extern Matrix matrix_zero(const unsigned int rows, const unsigned int cols) {
    Matrix A;
    A.rows = rows;
    A.cols = cols;
    A.data = malloc(rows * cols * sizeof(double));
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            A.data[j + i * cols] = 0;
        }
    }
    return A;
}

// Матрица оставленная из случайных чисел из диапазона [-1, +1]
extern Matrix matrix_rand(const unsigned int rows, const unsigned int cols){
    srand(time(NULL));
    Matrix A;
    A.rows = rows;
    A.cols = cols;
    A.data = malloc(rows * cols * sizeof(double));
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            A.data[j + i * cols] =  (((double)(rand()%101)) - 50)/50;
        }
    }
    return A;
}


// Вывести матрицу на экран
extern void matrix_print(const Matrix A) {
    for (int i = 0; i < A.cols * A.rows; i++) {
        printf("%.3lf\t", A.data[i]);
        if (((i+1)%A.cols) == 0) {
            printf("\n");
        }
    }
    printf("\n");
}


// ТАУ

// Решение уравнения Ляпунова X * A + A^T * X = -C
extern Matrix matrix_lyapunov_equation(const Matrix A, const Matrix C);