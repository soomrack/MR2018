#include "komarovMatrixLibC.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


extern void matrix_print(const Matrix A){
    for(int i = 0 ; i < A.rows ; i++) {
        for(int j = 0 ; j < A.cols ; j++) {
            printf("%lf\t", A.data[A.cols * i + j]);
        }
        printf("\n");
    }
}

static Matrix matrix_trace(const Matrix A){
    if(A.rows == A.cols) {
        double trace = 0;
        for (int i = 0, j = 0; i < A.rows && j < A.cols; i++, j++) {
            trace += A.data[i * A.rows + j];
        }
        printf("%lf\n", trace);
    }
    else{
        printf("Matrix is not square %s\n");
    }
}

static Matrix Minor(const Matrix A, int row, int col) {
    int h = 0;
    Matrix C;
    C.rows = A.rows - 1;
    C.cols = A.cols - 1;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            if (i != row && j != col) {
                C.data[h] = A.data[A.cols * i + j];
                h++;
            }
        }
    }
    return C;
}

extern double matrix_determinant(const Matrix A) {
    if (A.cols == A.rows) {
        if (A.rows == 1) {
            return A.data[0];
        }
        double result = 0;
        int sign = 1;
        for (int j = 0; j < A.cols; j++) {
            Matrix F;
            F = Minor(A, 0, j);
            result += sign * A.data[j] * matrix_determinant(F);
            sign = -sign;
            free(F.data);
        }
        return result;
    }
    else{
        printf("Matrix is not square %s\n");
    }
}

const Matrix matrix_sum(const Matrix A, const Matrix B){
    if(A.rows == B.rows && A.cols == B.cols){
        Matrix C;
        C.rows = A.rows;
        C.cols = A.cols;
        C.data = malloc(C.cols * C.rows * sizeof(double));
        for(int i = 0 ; i < C.rows ; i++) {
            for (int j = 0; j < C.cols; j++) {
                C.data[C.cols * i + j] = A.data[A.cols * i + j] + B.data[B.cols * i + j];
            }
        }
        return C;
    }
    else{
        printf("Matrices of different sizes %s\n");
    }
}

static Matrix matrix_mult(const Matrix A, const Matrix B) {
    if(A.cols==B.rows){
        Matrix C;
        C.rows = A.rows;
        C.cols = B.cols;
        C.data = malloc(C.cols * C.rows * sizeof(double));
        for(int i = 0 ; i < C.rows ; i++) {
            for(int j = 0 ; j < C.cols ; j++) {
                C.data[C.cols * i + j] = 0.0;
                for(int r = 0; r < C.rows; r++){
                    C.data[C.cols * i + j] =  C.data[C.cols * i + j] + A.data[A.cols * i + r] * B.data[B.cols * r + j];
                }
            }
        }
        return C;
    }
    else{
        printf("These matrices cannot be multiplied %s\n");
    }
}

static Matrix matrix_mult__scalar(const double scalar, const Matrix A){
    for(int i = 0 ; i < A.rows ; i++) {
        for(int j = 0 ; j < A.cols ; j++) {
            A.data[A.cols * i + j] = A.data[A.cols * i + j] * scalar;
        }
    }
    return A;
}

static Matrix matrix_trans(const Matrix A){
    Matrix C;
    C.cols = A.rows;
    C.rows = A.cols;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    for(int i = 0 ; i < A.rows ; i++) {
        for (int j = 0; j < A.cols; j++) {
            C.data[C.cols * j + i] = A.data[A.cols * i + j];
        }
    }
    return C;
}

static Matrix matrix_invert(const Matrix A){
    double Det=0;
    Matrix C;
    C.cols = A.rows;
    C.rows = A.cols;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    Matrix D;
    D.cols = A.rows;
    D.rows = A.cols;
    D.data = malloc(D.cols * D.rows * sizeof(double));
    Det = matrix_determinant(A);
    D = matrix_trans(A);
    int sign=1;
    for(int i = 0; i < A.rows; i++){
        for(int j = 0; j < A.cols; j++){
            C.data[C.cols * i + j] = sign * matrix_determinant( Minor(D, i, j));
            sign = -sign;
        }
    }
    C=matrix_mult__scalar( ( 1 / Det), C );
    return C;
}

/*static Matrix matrix_exp(const Matrix A){
    std::cout << "___________________________________________________" << std::endl;
    Matrix C;
    C.cols = A.rows;
    C.rows = A.cols;
    C.data = malloc double[C.cols * C.rows * sizeof(double)];
    C.data = A.data;
    std::cout << "Matrix C=" << std::endl;
    matrix_print(C);
    unsigned int k = 0;
    double o=0;
    do{
        Matrix F;
        std::cout << "__________________________________________________________________________________________________" << std::endl;
        std::cout << "k=" << k << std::endl;
        matrix_print(C);
        o=(1.0 / Factorial(k));
        //std::cout << "(1.0 / Factorial(k))" << o << std::endl;
        C = matrix_sum(C , matrix_mult__scalar( o , matrix_power(A , k) ) );
        k++;
    }while(k < 30);
    return C;
}*/

static Matrix matrix_power(const Matrix A, const unsigned int power){
    Matrix C;
    C.cols = A.rows;
    C.rows = A.cols;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    C.data = A.data;
    if(A.rows == A.cols){
        if(power == 0){
            for(int i = 0; i < C.rows; i++){
                for(int j = 0; j < C.cols; j++){
                    C.data[C.cols * i + j] = 1;
                }
            }
        }
        else{
            for(int i =0; i <= power; i++){
                C = matrix_mult(C, C);
            }
            return C;
        }
    }
    else{
        printf("Matrix is not square %s\n");
    }
}

static Matrix matrix_one(const unsigned int rows, const unsigned int cols){
    Matrix C;
    C.cols = cols;
    C.rows = rows;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    for(int i = 0; i < C.rows; i++){
        for(int j = 0; j < C.cols; j++){
            if(i == j){
                C.data[C.cols * i + j] = 1;
            }
            else{
                C.data[C.cols * i + j] = 0;
            }
        }
    }
    return C;
}

static Matrix matrix_zero(const unsigned int rows, const unsigned int cols){
    Matrix C;
    C.cols = cols;
    C.rows = rows;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    for(int i = 0; i < C.rows; i++){
        for(int j = 0; j < C.cols; j++){
            C.data[C.cols * i + j] = 0;
        }
    }
    return C;
}

static Matrix matrix_rand(const unsigned int rows, const unsigned int cols){
    Matrix C;
    C.cols = cols;
    C.rows = rows;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    for(int i = 0; i < C.rows; i++){
        for(int j = 0; j < C.cols; j++){
            C.data[C.cols * i + j] = Random_Number();
        }
    }
    return C;
}

extern int Factorial(unsigned int k){
    int result=1;
    for(int i = 1; i <= k; i++){
        result = result*i;
    }
    return result;
}

extern double Random_Number(){
    double x = rand()%3 - 1;
    double y = ((rand())/(double) RAND_MAX)+x;
    return y;
}

