#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern double matrix_trace(const Matrix A){
    if(A.cols != A.rows)exit(1);
    double trace = 0;

        for(int i = 0; i < A.rows; i++){     //construction sub-matrix
            trace += A.data[i + ( i * A.cols)];
        }
    return trace;
}


// Определитель матрицы
extern double matrix_determinant(const Matrix A){
    if(A.cols != A.rows)exit(1);
    if(A.cols == 1) return A.data[0];
    if(A.cols < 1) exit(1);

    Matrix Temp;
    Temp.cols = A.cols - 1;
    Temp.rows = A.rows - 1;
    Temp.data = malloc(Temp.cols * Temp.rows * sizeof(double));
    int row = 0;
    double det = 0;
    int sign;
    for(int col = 0; col < A.cols; col++){
        for(int i = 0; i < Temp.rows; i++){     //construction sub-matrix
            for(int j = 0; j < Temp.cols; j++){
                if((i <  row) && (j <  col))  Temp.data[j + ( i * Temp.cols)] = A.data[j + ( i * A.cols)];
                if((i <  row) && (j >= col))  Temp.data[j + ( i * Temp.cols)] = A.data[(j + 1) + ( i * A.cols)];
                if((i >= row) && (j <  col))  Temp.data[j + ( i * Temp.cols)] = A.data[j + ( (i + 1) * A.cols)];
                if((i >= row) && (j >= col))  Temp.data[j + ( i * Temp.cols)] = A.data[(j + 1) + ( (i + 1) * A.cols)];
            }
        }
        if(col % 2) sign = -1;
        else sign = 1;
        det += matrix_determinant(Temp)*A.data[col]*sign;
    }
    free(Temp.data);
    return det;
}

void polinomPrint(Polinom P){
    for(int i = 0; i < P.maxPower; i++){
        printf("%lf l^%d     ", P.data[i], i);
    }
}

Polinom PolinomMul(Polinom P1, Polinom P2){
    Polinom out;
    out.maxPower = P1.maxPower + P2.maxPower - 1;
    out.data = malloc(out.maxPower * sizeof(double));
    for(int i = 0; i < out.maxPower; i++)out.data[i] = 0;
    for(int p1 = 0; p1 < P1.maxPower; p1++){
        for(int p2 = 0; p2 < P2.maxPower; p2++){
            out.data[p1+p2] += P1.data[p1] * P2.data[p2];
        }
    }
    return out;
}

Polinom PolinomAdd(Polinom P1, Polinom P2){
    Polinom out;
    int minMaxPower;
    int flag;
    if(P1.maxPower > P2.maxPower) {
        out.maxPower = P1.maxPower;
        minMaxPower = P2.maxPower;
        flag = 1;
    }
    else {
        out.maxPower = P2.maxPower;
        minMaxPower = P1.maxPower;
        flag = 0;
    }
    out.data = malloc(sizeof(double) * out.maxPower);
    out.data = malloc(out.maxPower * sizeof(double));
    for(int i = 0; i < minMaxPower; i++){
        out.data[i] = P1.data[i] + P2.data[i];
    }
    for(int i = minMaxPower; i < out.maxPower; i++){
        if(flag) out.data[i] = P1.data[i];
        else out.data[i] = P2.data[i];
    }
    return out;
}

Polinom PolinomMulSc(Polinom P1, double Sc){
    Polinom out;
    out.maxPower = P1.maxPower;
    out.data = malloc(out.maxPower * sizeof(double));
    for(int p1 = 0; p1 < P1.maxPower; p1++){
        out.data[p1] = P1.data[p1] * Sc;
    }
    polinomPrint(out);
    printf("\n");
    return out;
}

Polinom determinant_PowerMatrix(PowerMatrix A){
    if(A.cols == 1) return A.data[0];
    PowerMatrix Temp;
    Polinom det;
    det.maxPower = A.cols;
    det.data = malloc(det.maxPower * sizeof(double));
    Polinom temp;
    Temp.cols = A.cols - 1;
    Temp.rows = A.rows - 1;
    Temp.data = malloc(sizeof(Polinom) * Temp.cols * Temp.rows);
    int row = 0;
    int sign;
    for(int i = 0; i < Temp.rows; i++){     //construction sub-matrix
        for(int j = 0; j < Temp.cols; j++){
            Temp.data[j + ( i * Temp.cols)].maxPower = A.data[j + ( i * Temp.cols)].maxPower;
            Temp.data[j + ( i * Temp.cols)].data = malloc(Temp.data[j + ( i * Temp.cols)].maxPower*sizeof(double));
        }
    }

    for(int col = 0; col < A.cols; col++){
        for(int i = 0; i < Temp.rows; i++){     //construction sub-matrix
            for(int j = 0; j < Temp.cols; j++){
                for(int k = 0; k < A.data[j + ( i * A.cols)].maxPower; k++) {
                    if ((i < row)  && (j < col))  Temp.data[j + (i * Temp.cols)].data[k] = A.data[j + (i * A.cols)].data[k];
                    if ((i < row)  && (j >= col)) Temp.data[j + (i * Temp.cols)].data[k] = A.data[(j + 1) + (i * A.cols)].data[k];
                    if ((i >= row) && (j < col))  Temp.data[j + (i * Temp.cols)].data[k] = A.data[j + ((i + 1) * A.cols)].data[k];
                    if ((i >= row) && (j >= col)) Temp.data[j + (i * Temp.cols)].data[k] = A.data[(j + 1) + ((i + 1) * A.cols)].data[k];
                }
            }
        }
        print_PowerMatrix(Temp);
        if(col % 2) sign = -1;
        else sign = 1;
        temp = PolinomAdd(det,PolinomMul(A.data[col],PolinomMulSc(determinant_PowerMatrix(Temp),sign)));
        free(det.data);
        det = temp;
    }
    return det;
}

/*Matrix PolynomEqvSolve(struct Polinom P){

}*/

// Собственные числа матрицы
extern Polinom matrix_eigen_values(const Matrix A){

    if(A.cols != A.rows)exit(1);
    PowerMatrix Temp;
    Temp = ToPowerMatrix(A);
    return determinant_PowerMatrix(Temp);

}

PowerMatrix ToPowerMatrix(Matrix A){
    if(A.cols != A.rows)exit(1);
    PowerMatrix Temp;
    Temp.cols = A.cols;
    Temp.rows = A.rows;
    Temp.data = malloc(sizeof(Polinom) * Temp.cols * Temp.rows);
    for(int row = 0; row < Temp.rows; row++){
        for(int col = 0; col < Temp.cols; col++){
            Temp.data[col + ( row * Temp.cols)].maxPower = 2;
            Temp.data[col + ( row * Temp.cols)].data = malloc(2*sizeof(double));
            Temp.data[col + ( row * Temp.cols)].data[0] = A.data[col + ( row * A.cols)];
            if(col == row)  Temp.data[col + ( row * Temp.cols)].data[1] = -1;
            else Temp.data[col + ( row * Temp.cols)].data[1] = 0;
        }
    }
    return Temp;
}

void print_PowerMatrix(PowerMatrix Temp){
    for(int row = 0; row < Temp.rows; row++){
        for(int col = 0; col < Temp.cols; col++){
            polinomPrint(Temp.data[col + ( row * Temp.cols)]);
            printf("\t|||\t");
        }
        printf("\n");
    }
    printf("\n\n\n");
}

// Матрица собственных векторов
extern Matrix matrix_eigen_vectors(const Matrix A);


// Сумма матриц
extern Matrix matrix_sum(const Matrix A, const Matrix B){
    if((A.cols != B.cols) || (A.rows != B.rows))exit(1);
    Matrix C;
    C.rows = A.rows;
    C.cols = A.cols;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    for(int i = 0; i < A.rows; i++){     //construction sub-matrix
        for(int j = 0; j < A.cols; j++){
            C.data[j + ( i * C.cols)] = A.data[j + ( i * A.cols)] + B.data[j + ( i * B.cols)];
        }
    }
    return C;
}

// Умножение матриц
extern Matrix matrix_mult(const Matrix A, const Matrix B){
    Matrix C;
    C.rows = A.rows;
    C.cols = B.cols;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    if(A.cols != B.rows) exit(1);
    for(int i = 0; i < C.rows; i++){
        for(int j = 0; j < C.cols; j++){
            C.data[i * C.cols + j] = 0;
            for(int k = 0; k < A.cols; k++) C.data[i * C.cols + j] += A.data[i * A.cols + k] * B.data[k * B.rows + j];
        }
    }
    return C;
}

// Умножение матрицы на скаляр
extern Matrix matrix_mult__scalar(const double scalar, const Matrix A){
    Matrix C;
    C.rows = A.rows;
    C.cols = A.cols;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    for(int i = 0; i < C.rows; i++){     //construction sub-matrix
        for(int j = 0; j < C.cols; j++){
            C.data[j + ( i * C.cols)] = A.data[j + ( i * A.cols)] * scalar;
        }
    }
    return C;
}

// Транспонирование матрицы
extern Matrix matrix_trans(const Matrix A){
    Matrix C;
    C.rows = A.cols;
    C.cols = A.rows;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    for(int i = 0; i < C.rows; i++){     //construction sub-matrix
        for(int j = 0; j < C.cols; j++){
            C.data[j + ( i * C.cols)] = A.data[i + ( j * A.rows)];
        }
    }
    return C;
}

// Обращение матрицы
extern Matrix matrix_invert(const Matrix A){
    if(A.cols != A.rows)exit(1);
    if(A.cols < 1) exit(1);

    Matrix Temp;
    Matrix Algd;
    Algd.cols = A.cols;
    Algd.rows = A.rows;
    Algd.data = malloc(Algd.cols * Algd.rows * sizeof(double));
    Temp.cols = A.cols - 1;
    Temp.rows = A.rows - 1;
    Temp.data = malloc(Temp.cols * Temp.rows * sizeof(double));
    double det = 0;
    int sign;
    for(int col = 0; col < A.cols; col++){
        for(int row = 0; row < A.rows; row++) {
            for (int i = 0; i < Temp.rows; i++) {     //construction sub-matrix
                for (int j = 0; j < Temp.cols; j++) {
                    if ((i <  row) && (j <  col)) Temp.data[j + (i * Temp.cols)] = A.data[j + (i * A.cols)];
                    if ((i <  row) && (j >= col)) Temp.data[j + (i * Temp.cols)] = A.data[(j + 1) + (i * A.cols)];
                    if ((i >= row) && (j <  col)) Temp.data[j + (i * Temp.cols)] = A.data[j + ((i + 1) * A.cols)];
                    if ((i >= row) && (j >= col)) Temp.data[j + (i * Temp.cols)] = A.data[(j + 1) + ((i + 1) * A.cols)];
                }
            }
            if(( col + row ) % 2) sign = -1;
            else sign = 1;
            Algd.data[col + row*Algd.cols] = matrix_determinant(Temp)*sign;
        }
    }
    Matrix Out = matrix_mult__scalar( ( 1 / matrix_determinant(A) ), matrix_trans(Algd));
    free(Algd.data);
    free(Temp.data);
    return Out;
}


unsigned long long int fact(unsigned int n){
    unsigned long long int out = 1;
    for(int i = 2; i < n; i++)out*=i;
    return  out;
}
// Матричная экспонента
extern Matrix matrix_exp(const Matrix A){
    Matrix C = matrix_zero(A.rows, A.cols);
    Matrix B;
    for(unsigned int k = 1; k < 1000; k++) {
        int flag = 1;
        B = matrix_power(A, k);
        unsigned long long int f = fact(k);
        for (int i = 0; i < C.rows; i++) {
            for (int j = 0; j < C.cols; j++) {
                C.data[j + (i * C.cols)] += B.data[j + (i * B.cols)] / f;
                flag &=  !( ( B.data[j + (i * B.cols)] / f / C.data[j + (i * C.cols)] ) > 0.0001);
            }
        }
        if(flag) break;
    }
    free(B.data);
    return C;
}

// Возведение матрицы в степень (натуральное число или 0)
extern Matrix matrix_power(const Matrix A, const unsigned int power){
    Matrix C;
    Matrix B;
    C.rows = A.rows;
    C.cols = A.cols;
    C.data = malloc(C.cols * C.rows * sizeof(double));
    for(int i = 0; i < C.rows; i++){
        for(int j = 0; j < C.cols; j++){
            if(i == j) C.data[j + ( i * C.cols)] = 1;
            else       C.data[j + ( i * C.cols)] = 0;
        }
    }
    B.rows = A.rows;
    B.cols = A.cols;
    B.data = malloc(B.cols * B.rows * sizeof(double));
    for(int p = 0; p < power; p++) {
        for(int i = 0; i < B.rows; i++){
            for(int j = 0; j < B.cols; j++){
                B.data[i * B.cols + j] = C.data[i * C.cols + j];
            }
        }
        for (int i = 0; i < C.rows; i++) {
            for (int j = 0; j < C.cols; j++) {
                C.data[i * C.cols + j] = 0;
                for (int k = 0; k < A.cols; k++)
                    C.data[i * C.cols + j] += B.data[i * B.cols + k] * A.data[k * A.rows + j];
            }
        }
        for (int i = 0; i < B.rows; i++) {
            for (int j = 0; j < B.cols; j++) {
                B.data[i * B.cols + j] =  C.data[i * C.cols + j];
            }
        }
    }
    free(B.data);
    return C;
}


// Единичная матрица
extern Matrix matrix_one(const unsigned int rows, const unsigned int cols){
    Matrix M;
    M.cols = cols;
    M.rows = rows;
    M.data = malloc(cols * rows * sizeof(double));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(i == j) M.data[j + ( i * cols)] = 1;
            else       M.data[j + ( i * cols)] = 0;
        }
    }
    return M;
}

// Нулевая матрица
extern Matrix matrix_zero(const unsigned int rows, const unsigned int cols){
    Matrix M;
    M.cols = cols;
    M.rows = rows;
    M.data = malloc(cols * rows * sizeof(double));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            M.data[j + ( i * cols)] = 0;
        }

    }
    return M;
}

// Матрица оставленная из случайных чисел из диапазона [-1, +1]
extern Matrix matrix_rand(const unsigned int rows, const unsigned int cols){
    srand(time(NULL));
    Matrix M;
    M.cols = cols;
    M.rows = rows;
    M.data = malloc(cols * rows * sizeof(double));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            M.data[j + ( i * cols)] = -1 + (double)(rand())/RAND_MAX * 2;
        }

    }
    return M;
}


// Вывести матрицу на экран
extern void matrix_print(const Matrix A){
    for(int i = 0; i < A.rows; i++){
        for(int j = 0; j < A.cols; j++){
            printf("%5.2lf\t", A.data[j + (i * A.cols)]);
        }
        printf("\n");
    }
    printf("\n");
}


// ТАУ

// Решение уравнения Ляпунова X * A + A^T * X = -C
extern Matrix matrix_lyapunov_equation(const Matrix A, const Matrix C);