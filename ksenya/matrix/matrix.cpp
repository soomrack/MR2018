#include "matrix.h"

double Matrix::matrix_trace() {
    double trace = 0;
    if (cols == rows) {
        for (int rowss = 0; rowss < rows; rowss++) {
            for (int colss = 0; colss < rows; colss++) {
                trace = data[rowss * rows + colss] + trace;
            }
            std::cout << trace << std::endl;
        }
    }
}

Matrix Matrix::Minor(unsigned int row, unsigned int col) {
    Matrix Result(this->rows-1, this->cols-1);
    int p = 0;
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            if ((i == row) || (j == col))
                continue;
            Result.data[p] = this->data[i * this->cols + j];
            p++;
        }
    }
    return Result;
}

double Matrix::matrix_determinant() {
    double result = 0;
    int sign = 1;
    if (this->cols == this->rows) {
        if (this->rows == 1) {
            result = this->data[0];
            return result;
        }
        for (int i = 0; i < this->cols; i++) {
            Matrix Result = this->Minor(0, i);
            result = sign * this->data[i] * Result.matrix_determinant() + result;
            sign *= -1;
        }
        return result;
    }
}

Matrix Matrix::matrix_trans(){
    Matrix Result(this->rows,this->cols);
    for(int i = 0 ; i < rows ; i++) {
        for (int j = 0; j < cols; j++) {
            Result.data[j * rows + i] = this->data[i * this->cols + j];
        }
    }
    return Result;
}

Matrix Matrix::matrix_invert(){
    double Det=0;
    Matrix Result = (this->cols, this->rows);
    Matrix Result1 = (this->cols, this->rows);

    Det = this->matrix_determinant();
    Result1 = this->matrix_trans();
    int sign=1;
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            Result.data[Result.cols * i + j] = sign * (Result1.Minor(i,j)).matrix_determinant();
            sign = -sign;
        }
    }
    Result.operator*(1 / Det);
    return Result;
}

Matrix Matrix::matrix_power(unsigned int power){

    Matrix Result(this->rows, this->cols);
    if(this->rows == this->cols){
        if(power == 0){
            for(int i = 0; i < Result.rows; i++){
                for(int j = 0; j < Result.cols; j++){
                    Result.data[Result.cols * i + j] = 1;
                }
            }
        }
        else{
            for(int k =0; k <= power; k++){
                Result.operator*(Result);
            }
            return Result;
        }
    }
}

Matrix Matrix::matrix_one(const unsigned int size){
    Matrix Result(size, size);
    for (int i = 0; i < Result.rows; i++) {
        for (int j = 0; j < Result.cols; j++) {
            if (i == j) {
                Result.data[i * Result.cols + j] = 1;
            }
            else {
                Result.data[i * Result.cols + j] = 0;
            }
        }
    }
    Result.matrix_print();
    return Result;
}

Matrix Matrix::matrix_zero(unsigned int rows, unsigned int cols){
    Matrix Result(rows,cols);
    for(int i = 0; i < Result.rows; i++){
        for(int j = 0; j < Result.cols; j++){
            Result.data[Result.cols * i + j] = 0;
        }
    }
    Result.matrix_print();
    return Result;
}

Matrix Matrix::matrix_rand(unsigned int rows, unsigned int cols){
    Matrix Result=(rows,cols);
    for(int i = 0; i < Result.rows; i++){
        for(int j = 0; j < Result.cols; j++){
            Result.data[Result.cols * i + j] = Random_Number();
        }
    }
    Result.matrix_print();
    return Result;
}

int Matrix::Factorial(unsigned int k){
    int result=1;
    for(int i = 1; i <= k; i++){
        result = result*i;
    }
    return result;
}

double Matrix::Random_Number(){
    double x = rand()%3 - 1;
    double y = ((rand())/(double) RAND_MAX)+x;
    return y;
}

Matrix Matrix::operator + (const Matrix &C) {
    if (this->rows == C.rows && this->cols == C.cols) {
        Matrix Result = (this->rows, this->cols);
        for (int i = 0; i < Result.rows; i++) {
            for (int j = 0; j < Result.cols; j++) {
                Result.data[Result.cols * i + j] = this->data[this->cols * i + j] + C.data[C.cols * i + j];
            }
        }
        return Result;
    }
}

Matrix Matrix::operator - (const Matrix &C) {
    if (this->rows == C.rows && this->cols == C.cols) {
        Matrix Result = (this->rows, this->cols);
        for (int i = 0; i < Result.rows; i++) {
            for (int j = 0; j < Result.cols; j++) {
                Result.data[Result.cols * i + j] = this->data[this->cols * i + j] - C.data[C.cols * i + j];
            }
        }
        return Result;
    }
}

Matrix Matrix::operator * (Matrix &C){
    if(this->cols==C.rows){
        Matrix Result=(this->rows,C.cols);

        for(int i = 0 ; i < Result.rows ; i++) {
            for(int j = 0 ; j < Result.cols ; j++) {
                Result.data[Result.cols * i + j] = 0.0;
                for(int r = 0; r < Result.rows; r++){
                    Result.data[Result.cols * i + j] =  Result.data[Result.cols * i + j] + this->data[this->cols * i + r] * C.data[C.cols * r + j];
                }
            }
        }
        return Result;
    }
}

Matrix Matrix::operator * (double scalar){
    Matrix Result = *this;
    for(int i = 0 ; i < this->rows ; i++) {
        for(int j = 0 ; j < this->cols ; j++) {
            Result.data[Result.cols * i + j] = 0.0;
            Result.data[this->cols * i + j] = this->data[this->cols * i + j] * scalar;
        }
    }
    return Result;
}

void Matrix::matrix_print(){
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < cols ; j++) {
            std::cout << data[cols * i + j] << " ";
        }
        std::cout << std::endl;
    }
}
