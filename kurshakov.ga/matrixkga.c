#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    unsigned int rows;
    unsigned int cols;
    double* data;
} Matrix;

static int factorial (int n)
{
    return (n < 2) ? 1 : n * factorial (n - 1);
}

// След матрицы
extern double matrix_trace(const Matrix A) {
    if (A.cols != A.rows) {
        printf("Матрица не квадратная.\n");
        exit (1);
    }
    double trace = 0;
    for (int row = 0; row < A.rows; row++) {
        for (int col = 0; col < A.cols; col++) {
            if (row == col) {
                trace += A.data[col + row * A.cols];
            }
        }
    }
    return trace;
}

// Определитель матрицы
extern double matrix_determinant(const Matrix A) {
    if (A.cols != A.rows) {
        printf("Матрица не квадратная.\n");
        exit (1);
    }
    if(A.cols == 1) return A.data[0];

    Matrix Aux;
    Aux.cols = A.cols - 1;
    Aux.rows = A.rows - 1;
    Aux.data = malloc(Aux.cols * Aux.rows * sizeof(double));
    int row = 0;
    double det = 0;
    int sign;
    for(int col = 0; col < A.cols; col++){
        for(int i = 0; i < Aux.rows; i++){     //construction sub-matrix
            for(int j = 0; j < Aux.cols; j++){
                if((i <  row) && (j <  col))  Aux.data[j + ( i * Aux.cols)] = A.data[j + ( i * A.cols)];
                if((i <  row) && (j >= col))  Aux.data[j + ( i * Aux.cols)] = A.data[(j + 1) + ( i * A.cols)];
                if((i >= row) && (j <  col))  Aux.data[j + ( i * Aux.cols)] = A.data[j + ( (i + 1) * A.cols)];
                if((i >= row) && (j >= col))  Aux.data[j + ( i * Aux.cols)] = A.data[(j + 1) + ( (i + 1) * A.cols)];
            }
        }
        if(col % 2)
            sign = -1;
        else
            sign = 1;
        det += matrix_determinant(Aux)*A.data[col]*sign;
    }
    return det;
}

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
            //вычисление row,col-того элемента матрицы-произведения
            double a[A.cols];
            double sum = 0;
            for (int numInARow = 0; numInARow < A.cols; numInARow++) {
                a[numInARow] = A.data[numInARow + row * A.cols] * B.data[col + numInARow * B.cols];
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
extern Matrix matrix_trans(const Matrix A){
    Matrix C;
    C.rows = A.cols;
    C.cols = A.rows;
    C.data = malloc(C.rows * C.cols * sizeof(double));
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            C.data[i + j * C.cols] = A.data[j + i * A.cols];
        }
    }
    return C;
}

// Обращение матрицы
extern Matrix matrix_invert(const Matrix A) {
    if (A.cols != A.rows) {
        printf("Матрица не квадратная.\n");
        exit (1);
    }
    if (matrix_determinant(A) == 0) {
        printf("Определитель равен нулю, обратной матрицы не существует.\n");
        exit (1);
    }
    Matrix Addition;
    Addition.rows = A.rows;
    Addition.cols = A.cols;
    Addition.data = malloc(Addition.rows * Addition.cols * sizeof(double));
    for (int row = 0; row < Addition.rows; row++) {
        for (int col = 0; col < Addition.cols; col++) {
            Matrix temp;
            temp.rows = A.rows - 1;
            temp.cols = A.cols - 1;
            temp.data = malloc(temp.rows * temp.cols * sizeof(double));
            for (int row2 = 0; row2 < temp.rows; row2++) {
                for (int col2 = 0; col2 < temp.cols; col2++) {
                    if ((row2 == row) || (col2 == col)) {

                    }
                }
            }
//            Addition.data[col + row * Addition.cols] = A.data[col + i * C.cols] + B.data[col + i * C.cols];
        }
    }
}

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

// Возведение матрицы в степень (натуральное число или 0)
extern Matrix matrix_power(const Matrix A, const unsigned int power) {
    if (A.cols != A.rows) {
        printf("Матрица не квадратная.\n");
        exit (1);
    }
    Matrix C;
    if (power == 0) {
        C = matrix_one(A.rows, A.cols);
    }
    else {
        C = A;
        for (int pow = 1; pow < power; pow++) {
            C = matrix_mult(C, A);
        }
    }
    return C;
}

// Матричная экспонента
extern Matrix matrix_exp(const Matrix A) {
    if (A.cols != A.rows) {
        printf("Матрица не квадратная.\n");
        exit (1);
    }
    Matrix exp = matrix_one(A.rows, A.cols);
    for (unsigned int cock = 1; cock < 10; cock++) {
        exp = matrix_sum(exp, matrix_mult__scalar(1.0 / factorial(cock), matrix_power(A, cock)));
    }
    return exp;
}


// Матрица составленная из случайных чисел из диапазона [-1, +1]
extern Matrix matrix_rand(const unsigned int rows, const unsigned int cols){
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