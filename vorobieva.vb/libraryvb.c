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
    double trace = 0;
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

/* double matrix_determinant(const Matrix A){
    double determonant = 1;
    if (A.cols != A.rows){
        printf("sasi");
    }
    else{
        if (A.cols == 1) {
            return A.data[0];
        }
       else{
            return
        }

    }
}; */

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
    srand(time(NULL));
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
