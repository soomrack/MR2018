//
// Created by science on 16.09.18.
//

#include "libraryvb.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
        printf("sasi");
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
        printf("sasi");
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
        printf("sasi");
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
