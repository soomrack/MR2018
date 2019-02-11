#include "functions.h"


void Matrix::matrix_print(){
        for(int i = 0 ; i < rows ; i++) {
                for(int j = 0 ; j < cols ; j++) {
                        std::cout << data[cols * i + j] << " ";
                }
                std::cout << std::endl;
        }
}

double Matrix::matrix_trace(){
    if(rows == cols) {
        double trace = 0;
        for (int i = 0, j = 0; i < rows && j < cols; i++, j++) {
            trace += data[i * rows + j];
        }
        std::cout << trace << std::endl;
        return trace;
    }
    else{
        std::cout << "Matrix is not square" << std::endl;
    }
}

Matrix Matrix::Minor(unsigned int row, unsigned int col) {
    int h = 0;
    Matrix C(this->rows -1, this->cols- 1);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            if (i != row && j != col) {
                C.data[h] = this->data[this->cols * i + j];
                h++;
            }
        }
    }
    return C;
}

double Matrix::matrix_determinant() {
    if (this->cols == this->rows) {
        if (this->rows == 1) {
            return this->data[0];
        }
        double result = 0;
        int sign = 1;
        for (int j = 0; j < this->cols; j++) {
            Matrix C = this->Minor(0,j);
            result += sign * this->data[j] * C.matrix_determinant();
            sign = -sign;
        }
        return result;
    }
    else{
        std::cout << "Matrix is not square" << std::endl;
    }
}

Matrix Matrix::operator + (const Matrix &B){
        if(this->rows == B.rows && this->cols == B.cols){
                Matrix C=(this->rows,this->cols);
                for(int i = 0 ; i < C.rows ; i++) {
                        for (int j = 0; j < C.cols; j++) {
                                C.data[C.cols * i + j] = this->data[this->cols * i + j] + B.data[B.cols * i + j];
                        }
                }
                return C;
        }
        else{
                std::cout << "Matrices of different sizes" << std::endl;
        }
}

Matrix Matrix::operator * (Matrix &B){
        if(this->cols==B.rows){
                Matrix C=(this->rows,B.cols);

                for(int i = 0 ; i < C.rows ; i++) {
                        for(int j = 0 ; j < C.cols ; j++) {
                                C.data[C.cols * i + j] = 0.0;
                                for(int r = 0; r < C.rows; r++){
                                        C.data[C.cols * i + j] =  C.data[C.cols * i + j] + this->data[this->cols * i + r] * B.data[B.cols * r + j];
                                }
                        }
                }
                return C;
        }
        else{
                std::cout << "These matrices cannot be multiplied" << std::endl;
        }
}

Matrix Matrix::operator * (double scalar){
        Matrix C = *this;
        for(int i = 0 ; i < this->rows ; i++) {
                for(int j = 0 ; j < this->cols ; j++) {
                    C.data[C.cols * i + j] = 0.0;
                    C.data[this->cols * i + j] = this->data[this->cols * i + j] * scalar;
                }
        }
        return C;
}

Matrix Matrix::matrix_trans(){
        Matrix C=(this->rows,this->cols);
        for(int i = 0 ; i < rows ; i++) {
                for (int j = 0; j < cols; j++) {
                        C.data[cols * j + i] = this->data[this->cols * i + j];
                }
        }
        C.matrix_print();
        return C;
}

Matrix Matrix::matrix_invert(){
    double Det=0;
    Matrix C = (this->cols, this->rows);
    Matrix D = (this->cols, this->rows);

    Det = this->matrix_determinant();
    D = this->matrix_trans();
    int sign=1;
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            C.data[C.cols * i + j] = sign * (D.Minor(i,j)).matrix_determinant();
            sign = -sign;
        }
    }
    C.operator*(1 / Det);
    return C;
}
/*
extern Matrix matrix_exp(const Matrix A){
    std::cout << "___________________________________________________" << std::endl;
    Matrix C;
    C.cols = A.rows;
    C.rows = A.cols;
    C.data = new double[C.cols * C.rows * sizeof(double)];
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
}
*/
Matrix Matrix::matrix_power(unsigned int power){
    Matrix C(this->rows,this->cols);
    if(this->rows == this->cols){
        if(power == 0){
            for(int i = 0; i < C.rows; i++){
                for(int j = 0; j < C.cols; j++){
                        C.data[C.cols * i + j] = 1;
                    }
                }
            }
        else{
            for(int i =0; i <= power; i++){
                C.operator*(C);
            }
            return C;
        }
    }
    else{
        std::cout << "Matrix is not square" << std::endl;
    }
}

Matrix Matrix::matrix_one(unsigned int rows, unsigned int cols){
    Matrix C=(rows,cols);

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
    C.matrix_print();
    return C;
}

Matrix Matrix::matrix_zero(unsigned int rows, unsigned int cols){
    Matrix C=(rows,cols);
    //C.cols = cols;
    //C.rows = rows;
    //C.data = new double[C.cols * C.rows * sizeof(double)];
    for(int i = 0; i < C.rows; i++){
        for(int j = 0; j < C.cols; j++){
            C.data[C.cols * i + j] = 0;
        }
    }
    C.matrix_print();
    return C;
}

Matrix Matrix::matrix_rand(unsigned int rows, unsigned int cols){
    Matrix C=(rows,cols);
    for(int i = 0; i < C.rows; i++){
        for(int j = 0; j < C.cols; j++){
            C.data[C.cols * i + j] = Random_Number();
        }
    }
    C.matrix_print();
    return C;
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