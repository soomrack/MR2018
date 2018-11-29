//
// Created by science on 16.09.18.
//

#include "libraryvb.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TOWNS 4

//курсач

Table table_rand(const unsigned int size){
    Table A;
    A.size = size;
    A.data = malloc(A.size * A.size * sizeof(int));
    for(int i = 0; i < A.size; i++) {
        for(int j = 0; j < A.size; j++) {
            if (i == j) A.data[A.size * i + j] = WINT_MAX;
            else A.data[A.size * i + j] = rand() % 10 + 1;
        };
    };
    return A;
};

void table_print(const Table A){
    for (int i = 0; i < A.size; i++){
        for (int j = 0; j < A.size; j++) {
            if (A.data[A.size * i + j] == WINT_MAX) printf("-\t\t");
            else printf("%d \t\t", A.data[A.size * i + j]);
        };
        printf("\n");
    }
    printf("\n");
};


Table table_trans(const Table A){
    Table B;
    B.size = A.size;
    B.data = malloc(B.size * B.size * sizeof(int));
    for (int i = 0; i < B.size; i++){
        for (int j = 0; j < B.size; j++) {
            B.data[B.size * i + j] = A.data[A.size * j + i];
        };
    }
    return B;
};

Table table_zero(const unsigned int size){
    Table A;
    A.size = size;
    A.data = malloc(A.size * A.size * sizeof(double));
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            A.data[A.size * i + j] = 0;
        }
    };
    return A;
};


Table method(const Table input, const Table shift1, const Table shift2){
    static int road = 0;
    int str = -1, col = -1;
    //если осталась только матрица 2х2 обработка отдельно
    if (input.size == 2){
        for (int i = 0; i < input.size; i++) {
             for (int j = 0; j < input.size; j++) {
               if (input.data[input.size * i + j] != WINT_MAX) {
                   str = i;
                   col = j;
               }
             }
         }
        road += input.data[input.size * str + col];

        printf("%d -> %d \n", str + 1 + shift1.data[shift1.size * str + col], col + 1 + shift2.data[shift2.size * str + col]);

        input.data[input.size * str + col] = WINT_MAX;
        for (int i = 0; i < input.size; i++) {
            for (int j = 0; j < input.size; j++) {
                if (input.data[input.size * i + j] != WINT_MAX) {
                    str = i;
                    col = j;
                }
            }
        }
        road += input.data[input.size * str + col];
        printf("%d -> %d \n", str + 1 + shift1.data[shift1.size * str + col], col + 1 + shift2.data[shift2.size * str + col]);

        printf("Длина дороги - %d\n", road);
        return (input);
    }

    //нахождение минимума по строкам
    int a[input.size], b[input.size];

    for (int i = 0; i < input.size; i++) {
        a[i] = input.data[input.size * i];
        for (int j = 1; j < input.size; j++) {
            if (input.data[input.size * i + j] < a[i]) a[i] = input.data[input.size * i + j];
        }
    }

    //нахождение минимума по столбцам
    Table trans = table_trans(input);

    for (int i = 0; i < trans.size; i++) {
        b[i] = trans.data[trans.size * i] - a[0];
        for (int j = 1; j < trans.size; j++) {
            if ((trans.data[trans.size * i + j] - a[j]) < b[i]) b[i] = trans.data[trans.size * i + j] - a[j];
        }
    }

    Table output;
    output.size = input.size;
    output.data = malloc(output.size * output.size * sizeof(int));

    //редукция матрицы
    for (int i = 0; i < output.size; i++) {
        for (int j = 0; j < output.size; j++) {
            if (input.data[input.size * i + j] == WINT_MAX) output.data[output.size * i + j] = WINT_MAX;
            else output.data[output.size * i + j] = input.data[input.size * i + j] - a[i] - b[j];
        }
    }

    //нахождение клетки с минимальной оценкой
    int max = 0;
    for (int i = 0; i < output.size; i++) {
        for (int j = 0; j < output.size; j++) {
            if (output.data[output.size * i + j] == 0){
                int minstr = WINT_MAX, mincol = WINT_MAX;
                for (int k = 0; k < output.size; k++) {
                    if ((output.data[output.size * i + k] < minstr) && (k != j)) minstr = output.data[output.size * i + k];
                }
                for (int k = 0; k < output.size; k++) {
                    if ((output.data[output.size * k + j] < mincol) && (k != i)) mincol = output.data[output.size * k + j];
                }
                if ((minstr + mincol) > max) {
                    max = minstr + mincol;
                    str = i;
                    col = j;
                }
            }
        }
    }

    //увеличиваем длину пути и выводим часть пути
    road += input.data[input.size * str + col];
    printf("Длина = %d, строка = %d, столбец = %d\n", road, str + 1, col + 1);

    //создаем таблицу смещений для следующего захода рекурсии
    static Table nextshift[2];
    if (input.size == TOWNS){
        for (int i = 0; i < nextshift[0].size; i++) {
            for (int j = 0; j < nextshift[0].size; j++) {
                nextshift[0].data[nextshift[0].size * i + j] = 0;
                nextshift[1].data[nextshift[1].size * i + j] = 0;
            }
        }
    }

    nextshift[0].size = output.size;
    nextshift[0].data = malloc(nextshift[0].size * nextshift[0].size * sizeof(int));
    nextshift[1].size = output.size;
    nextshift[1].data = malloc(nextshift[1].size * nextshift[1].size * sizeof(int));
    for (int i = 0; i < nextshift[0].size; i++) {
        for (int j = 0; j < nextshift[0].size; j++) {
            if (j >= col){
                nextshift[1].data[nextshift[1].size * i + j]++;
                shift2.data[shift2.size * i + j]++;
            }
            if(i >= str) {
                nextshift[0].data[nextshift[0].size * i + j]++;
                shift1.data[shift1.size * i + j]++;
            }
        }
    }
    printf("%d -> %d \n", str + 1 + shift1.data[shift1.size * str + col], col + 1 + shift2.data[shift2.size * str + col]);

    //редукция матрицы
    output.size = output.size - 1;
    for (int i = 0; i < output.size; i++) {
        for (int j = 0; j < output.size; j++) {
            if((i < str) && (j < col)) {
                if ((i == col + shift2.data[shift2.size * i + j]) && (j == str + shift1.data[shift1.size * i + j])) output.data[output.size * i + j] = WINT_MAX;
                else output.data[output.size * i + j] = input.data[input.size * i + j];
            }
            if((i < str) && (j >= col)){
                if ((i == col + shift2.data[shift2.size * i + j]) && (j == str + shift1.data[shift1.size * i + j] - 1)) output.data[output.size * i + j] = WINT_MAX;
                else output.data[output.size * i + j] = input.data[input.size * i + j + 1];
            }
            if((i >= str) && (j < col)){
                if ((i == col + shift2.data[shift2.size * i + j] - 1) && (j == str + shift1.data[shift1.size * i + j])) output.data[output.size * i + j] = WINT_MAX;
                else output.data[output.size * i + j] = input.data[input.size * (i + 1) + j];
            }
            if((i >= str) && (j >= col)){
                if ((i == col + shift2.data[shift2.size * i + j] - 1) && (j == str + shift1.data[shift1.size * i + j] - 1)) output.data[output.size * i + j] = WINT_MAX;
                else output.data[output.size * i + j] = input.data[input.size * (i + 1) + j + 1];
            }
        }
    }
    table_print(output);


    //рекурсия
    return method(output, nextshift[0], nextshift[1]);
}



//курсач

void matrix_print(const Matrix A){
    for (int i = 0; i < A.cols; i++){
        for (int j = 0; j < A.rows; j++) {
            printf("%1.3lf \t\t", A.data[A.cols * i + j]);
        };
        printf("\n");
    }
};

double matrix_trace(const Matrix A){
    double trace = 0.0;
    if (A.cols != A.rows) {
        printf("Матрица не квадратная");
    }
    else {
        for (int i = 0; i < A.cols; i++){
            for (int j = 0; j < A.rows; j++) {
                if (i == j) {
                    trace += A.data[A.cols * i + j];
                }
            }
        };
        printf("\n");
    }
    return trace;
};

double matrix_determinant(const Matrix A){
    double det = 0;
    if (A.cols != A.rows){
        printf("Матрица не квадртаная");
        exit(1);
    }
    else{
        if (A.cols == 1) {
            return A.data[0];
        }
        else{
            Matrix B;
            B.cols = A.cols - 1;
            B.rows = A.rows - 1;
            B.data = malloc(B.cols * B.rows * sizeof(double));
            int row = 0;
            int sign;
            for(int col = 0; col < A.cols; col++){
                for(int i = 0; i < B.rows; i++){
                    for(int j = 0; j < B.cols; j++){
                        if((i < row) && (j < col))  B.data[B.cols * i + j] = A.data[A.cols * i + j];
                        if((i < row) && (j >= col))  B.data[B.cols * i + j] = A.data[A.cols * i + j + 1];
                        if((i >= row) && (j < col))  B.data[B.cols * i + j] = A.data[A.cols * (i + 1) + j];
                        if((i >= row) && (j >= col))  B.data[B.cols * i + j] = A.data[A.cols * (i + 1) + j + 1];
                    }
                }
                if(col % 2) sign = -1;
                else sign = 1;
                det += matrix_determinant(B)*A.data[col]*sign;
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

Matrix matrix_trans(const Matrix A){
    Matrix B;
    B.cols = A.rows;
    B.rows = A.cols;
    B.data = malloc(B.cols * B.rows * sizeof(double));
    for (int i = 0; i < B.cols; i++){
        for (int j = 0; j < B.rows; j++) {
            B.data[B.cols * i + j] = A.data[A.rows * j + i];
        };
    }
    return B;
};

Matrix matrix_invert(const Matrix A){
    if(A.cols != A.rows){
        printf("Матрица не квадратная");
        exit(1);
    };
    if(A.cols < 1) exit(1);
    Matrix B;
    Matrix C;
    C.cols = A.cols;
    C.rows = A.rows;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    B.cols = A.cols - 1;
    B.rows = A.rows - 1;
    B.data = malloc(B.cols * B.rows * sizeof(double));
    double det = 0;
    int sign;
    for(int col = 0; col < A.cols; col++){
        for(int row = 0; row < A.rows; row++) {
            for (int i = 0; i < B.rows; i++) {
                for (int j = 0; j < B.cols; j++) {
                    if ((i <  row) && (j <  col)) B.data[i * B.cols + j] = A.data[j + (i * A.cols)];
                    if ((i <  row) && (j >= col)) B.data[i * B.cols + j] = A.data[(j + 1) + (i * A.cols)];
                    if ((i >= row) && (j <  col)) B.data[i * B.cols + j] = A.data[j + ((i + 1) * A.cols)];
                    if ((i >= row) && (j >= col)) B.data[i * B.cols + j] = A.data[(j + 1) + ((i + 1) * A.cols)];
                }
            }
            if(( col + row ) % 2) sign = -1;
            else sign = 1;
            C.data[col + row * C.cols] = matrix_determinant(B) * sign;
        }
    }
    Matrix Out = matrix_mult__scalar( ( 1 / matrix_determinant(A) ), matrix_trans(C));
    free(C.data);
    free(B.data);
    return Out;
};


Matrix matrix_eigen_values(const Matrix A){

};

Matrix matrix_eigen_vectors(const Matrix A){

};

Matrix matrix_mult(const Matrix A, const Matrix B){
    Matrix C;
    C.rows = A.rows;
    C.cols = B.cols;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    if(A.cols != B.rows) {
        printf("Матрица не квадратная");
        exit(1);
    }
    else for(int i = 0; i < C.rows; i++){
            for(int j = 0; j < C.cols; j++){
                C.data[i * C.cols + j] = 0;
                for(int k = 0; k < A.cols; k++) {
                    C.data[i * C.cols + j] += A.data[i * A.cols + k] * B.data[k * B.rows + j];
                }
            }
        }
    return C;
};

Matrix matrix_power(const Matrix A, const unsigned int power){
    Matrix B = A;
    if (B.cols != B.rows) {
        printf("Матрица не квадратная");
        exit(1);
    }
    else{
        for (int i = 1; i < power; i++){
            B = matrix_mult(B, A);
        }
        return B;
    }
};

Matrix matrix_one(const unsigned int rows, const unsigned int cols){
    Matrix A;
    A.cols = cols;
    A.rows = rows;
    A.data = malloc(A.cols * A.rows * sizeof(double));
    for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++) {
            if(i==j){
                A.data[A.cols * i + j] = 1;
            }
            else{
                A.data[A.cols * i + j] = 0;
            };
        }
    };
    return A;
};

Matrix matrix_zero(const unsigned int rows, const unsigned int cols){
    Matrix A;
    A.cols = cols;
    A.rows = rows;
    A.data = malloc(A.cols * A.rows * sizeof(double));
    for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++) {
            A.data[A.cols * i + j] = 0;
        }
    };
    return A;
};

Matrix matrix_rand(const unsigned int rows, const unsigned int cols){
    Matrix A;
    A.cols = rows;
    A.rows = cols;
    A.data = malloc(A.cols * A.rows * sizeof(double));
    for(int i = 0; i < A.cols; i++) {
        for(int j = 0; j < A.rows; j++) {
            A.data[A.cols * i + j] = (rand()/(double)RAND_MAX - 0.5)*2;
        };
    };
    return A;
};

Matrix matrix_sum(const Matrix A, const Matrix B){
    Matrix C;
    C.cols = A.cols;
    C.rows = A.rows;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    if ((A.cols != B.cols) || (A.rows != B.rows)) {
        printf("Матрицы разных размеров, нельзя сложить");
    }
    else {
        for(int i = 0; i < A.cols; i++) {
            for(int j = 0; j < A.rows; j++) {
                C.data[A.cols * i + j] = A.data[A.cols * i + j]+ B.data[A.cols * i + j];
            };
        };
    }
    return C;
};

Matrix matrix_exp(const Matrix A){
    Matrix exp;
    exp.cols = A.cols;
    exp.rows = A.rows;
    exp.data = malloc(exp.cols * exp.rows * sizeof(double));
    exp = matrix_zero(exp.rows, exp.cols);
    for(unsigned int k = 0; k < 100; k++){
        matrix_sum(exp, matrix_mult__scalar(1.0/factorial(k), matrix_power(A,k)));
    }
    return exp;
};

Matrix matrix_mult__scalar(const double scalar, const Matrix A){
    Matrix C;
    C.cols = A.cols;
    C.rows = A.rows;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    for(int i = 0; i < A.cols; i++) {
        for(int j = 0; j < A.rows; j++) {
            C.data[A.cols * i + j] = A.data[A.cols * i + j]*scalar;
        };
    };
    return C;
};

void main2() {

}
