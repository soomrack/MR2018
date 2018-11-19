//
// Created by work on 29.10.2018.
//

#include <malloc.h>
#include <time.h>
#include <stdio.h>
#include <cstring>
#include <cmath>

#ifndef MR2018_MATRLIB_H
#define MR2018_MATRLIB_H

#endif //MR2018_MATRLIB_H


static unsigned long long int fact(unsigned int n);


class Matrix{
private:
    int m_cols;
    int m_rows;
    static int countIncrement(int delta) {
        static int count = 0;
        count += delta;
        return count;
    }

    static int memUsedIncrement(int delta) {
        static int memUsed = 0;
        memUsed += delta;
        return memUsed;
    }
public:
    double * data;

    int getCols(){
        return m_cols;
    }

    int getRows(){
        return m_rows;
    }

    Matrix(){
        data = (double *)0;
        countIncrement(1);
        memUsedIncrement(sizeof(Matrix));
    }

    Matrix(Matrix& Arg){
        m_cols = Arg.m_cols;
        m_rows = Arg.m_rows;
        data = new double[m_cols * m_rows];
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_cols; j++){
                data[j + ( i * m_cols)] = Arg.data[j + ( i * m_cols)];
            }
        }
        memUsedIncrement(m_cols * m_rows * sizeof(double));
    }

    void beSymmetric(){
        for(int i = 0; i < m_rows; i++){
            for(int j = i; j < m_cols; j++){
                data[j + ( i * m_cols)] = data[i + ( j * m_rows)];
            }
        }
    }

    void countPrint(){
        printf("%d\n", countIncrement(0));
    }
    void memUsedPrint(){
        printf("%d\n", memUsedIncrement(0));
    }

    Matrix(int cols, int rows):    m_cols(cols), m_rows(rows){
        data = new double[m_cols * m_rows];
        srand(time(NULL));
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_cols; j++){
                data[j + ( i * m_cols)] = -1 + (double)(rand())/RAND_MAX * 2;
            }
        }
        countIncrement(1);
        memUsedIncrement(sizeof(Matrix) + m_cols * m_rows * sizeof(double));
    }

    Matrix(int cols, int rows, int type): m_cols(cols), m_rows(rows){
        data = new double[m_cols * m_rows];
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_cols; j++){
                if(i == j) data[j + ( i * m_cols)] = type;
                else       data[j + ( i * m_cols)] = 0;
            }
        }
        countIncrement(1);
        memUsedIncrement(sizeof(Matrix) + m_cols * m_rows * sizeof(double));
    }

    ~Matrix(){
        if(data != (double *)0)
            delete [] data;

    }

    void Print() {
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                printf("%5.6lf\t", data[j + (i * m_cols)]);
            }
            printf("\n");
        }
        printf("\n");
    }

    double Trace(){
        double trace = 0;

        for(int i = 0; i < m_rows; i++){
            trace += data[i + ( i * m_cols)];
        }
        return trace;
    }

    Matrix Trans(){
        Matrix out(m_rows, m_cols);
        for(int i = 0; i < m_rows; i++){     //construction sub-matrix
            for(int j = 0; j < m_cols; j++){
                out.data[j + ( i * m_cols)] = data[i + ( j * m_rows)];
            }
        }
        return out;
    }

    Matrix operator + (const Matrix& Arg){
        Matrix out(m_cols, m_rows);
        for(int i = 0; i < m_cols; i++){     //construction sub-matrix
            for(int j = 0; j < m_rows; j++){
                out.data[j + ( i * m_rows)] = data[j + ( i * m_rows)] + Arg.data[j + ( i * m_rows)];
            }
        }
        return out;
    }

    Matrix operator * (const Matrix& Arg){
        Matrix out(Arg.m_cols, m_rows);
        for(int i = 0; i < out.m_rows; i++){
            for(int j = 0; j < out.m_cols; j++){
                out.data[i * out.m_cols + j] = 0;
                for(int k = 0; k < m_cols; k++) {
                    out.data[i * out.m_cols + j] += data[i * m_cols + k] * Arg.data[k * Arg.m_cols + j];
                }
            }
        }
        return out;
    }

    Matrix operator * (double Arg){
        Matrix out (m_cols, m_rows);
        for(int i = 0; i < m_rows; i++){     //construction sub-matrix
            for(int j = 0; j < m_cols; j++){
                out.data[j + ( i * m_cols)] = data[j + ( i * m_cols)] * Arg;
            }
        }
        return out;
    }

    void operator = (const Matrix& Arg){
        if(data != (double *)0)
            delete [] data;
        memUsedIncrement(-m_cols * m_rows * sizeof(double));
        m_cols = Arg.m_cols;
        m_rows = Arg.m_rows;
        data = new double[m_cols * m_rows];
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_cols; j++){
                data[j + ( i * m_cols)] = Arg.data[j + ( i * m_cols)];
            }
        }
        memUsedIncrement(m_cols * m_rows * sizeof(double));
    }

    Matrix Power (int power){
        Matrix C(m_cols, m_rows, 1);
        Matrix B(m_cols, m_rows);
        for(int p = 0; p < power; p++) {
            B = C;
            C = (B * *this);
        }
        return C;
    }

    Matrix Exp(){
        Matrix C(m_cols, m_rows, 0);
        Matrix B;
        for(unsigned int k = 1; k < 1000; k++) {
            int flag = 1;
            B = this->Power(k);
            unsigned long long int f = fact(k);
            for (int i = 0; i < C.m_rows; i++) {
                for (int j = 0; j < C.m_cols; j++) {
                    C.data[j + (i * C.m_cols)] += B.data[j + (i * B.m_cols)] / f;
                    flag &=  !( ( B.data[j + (i * B.m_cols)] / f / C.data[j + (i * C.m_cols)] ) > 0.0001);
                }
            }
            if(flag) break;
        }
        return C;
    }

    double Determinant(){
        if(m_cols == 1) return data[0];
        Matrix Temp(m_cols - 1, m_rows - 1, 0);
        double det = 0;
        int sign;
        for(int col = 0; col < m_cols; col++){
            for(int i = 0; i < Temp.m_rows; i++){     //construction sub-matrix
                for(int j = 0; j < Temp.m_cols; j++){
                    if(j <  col)  Temp.data[j + ( i * Temp.m_cols)] = data[j + ( (i + 1) * m_cols)];
                    if(j >= col)  Temp.data[j + ( i * Temp.m_cols)] = data[(j + 1) + ( (i + 1) * m_cols)];
                }
            }
            if(col % 2) sign = -1;
            else sign = 1;
            det += Temp.Determinant()*data[col]*sign;
        }
        return det;
    }

    Matrix Invert(){
        Matrix Temp(m_cols - 1, m_rows - 1);
        Matrix Algd(m_cols, m_rows);
        double det = 0;
        int sign;
        for(int col = 0; col < m_cols; col++){
            for(int row = 0; row < m_rows; row++) {
                for (int i = 0; i < Temp.m_rows; i++) {     //construction sub-matrix
                    for (int j = 0; j < Temp.m_cols; j++) {
                        if ((i <  row) && (j <  col)) Temp.data[j + (i * Temp.m_cols)] = data[j + (i * m_cols)];
                        if ((i <  row) && (j >= col)) Temp.data[j + (i * Temp.m_cols)] = data[(j + 1) + (i * m_cols)];
                        if ((i >= row) && (j <  col)) Temp.data[j + (i * Temp.m_cols)] = data[j + ((i + 1) * m_cols)];
                        if ((i >= row) && (j >= col)) Temp.data[j + (i * Temp.m_cols)] = data[(j + 1) + ((i + 1) * m_cols)];
                    }
                }
                if(( col + row ) % 2) sign = -1;
                else sign = 1;
                Algd.data[col + row*Algd.m_cols] = Temp.Determinant()*sign;
            }
        }
        for(int col = 0; col < m_cols; col++){
            det += Algd.data[col]*data[col];
        }
        Matrix Out;
        Out = Algd.Trans() * ( 1 / det );
        return Out;
    }
};




class Polinom{
private:
    int maxPower;
public:

    double * data;

    Polinom(){
        data = (double *)0;
        maxPower = 0;
    }

    Polinom(Polinom& Arg){
        maxPower = Arg.maxPower;
        data = new double[maxPower];
        for(int i = 0; i < maxPower; i++){
            data[i] = Arg.data[i];
        }
    }

    Polinom(int power):     maxPower(power){
        data = new double[maxPower];
    }

    Polinom(int power, double min, double max):   maxPower(power){
        data = new double[maxPower];
        srand(time(NULL));
        for(int i = 0; i < maxPower; i++){
            data[i] = min + (rand() * (max - min) / RAND_MAX);
        }
    }
    ~Polinom(){
        if(data != (double *)0)
            delete [] data;
    }

    Polinom operator + (const Polinom& Arg2){
        int MaxPower;
        int minMaxPower;
        bool flag;
        if(maxPower > Arg2.maxPower) {
            MaxPower = maxPower;
            minMaxPower = Arg2.maxPower;
            flag = 1;
        }
        else {
            MaxPower = Arg2.maxPower;
            minMaxPower = maxPower;
            flag = 0;
        }
        Polinom out(MaxPower);
        for(int i = 0; i < minMaxPower; i++){
            out.data[i] = data[i] + Arg2.data[i];
        }
        for(int i = minMaxPower; i < out.maxPower; i++){
            if(flag) out.data[i] = data[i];
            else out.data[i] = Arg2.data[i];
        }
        return out;
    }

    Polinom operator - (const Polinom& Arg2){
        int MaxPower;
        int minMaxPower;
        bool flag;
        if(maxPower > Arg2.maxPower) {
            MaxPower = maxPower;
            minMaxPower = Arg2.maxPower;
            flag = 1;
        }
        else {
            MaxPower = Arg2.maxPower;
            minMaxPower = maxPower;
            flag = 0;
        }
        Polinom out(MaxPower);
        for(int i = 0; i < minMaxPower; i++){
            out.data[i] = data[i] - Arg2.data[i];
        }
        for(int i = minMaxPower; i < out.maxPower; i++){
            if(flag) out.data[i] = data[i];
            else out.data[i] = -Arg2.data[i];
        }
        return out;
    }

    Polinom operator * (const Polinom& Arg){
        int MaxPower = maxPower + Arg.maxPower - 1;
        Polinom out(MaxPower);
        for(int i = 0; i < out.maxPower; i++)out.data[i] = 0;
        for(int p1 = 0; p1 < maxPower; p1++){
            for(int p2 = 0; p2 < Arg.maxPower; p2++){
                out.data[p1+p2] += data[p1] * Arg.data[p2];
            }
        }
        return out;
    }

    void Print() {
        for(int i = maxPower; i > 0; i--){
            printf("%lf l^%d     ", data[i-1], i-1);
        }
        printf("\n");
    }

    void Print2() {
        for(int i = maxPower; i > 0; i--){
            printf("%lf l^%d     ", data[i-1], i-1);
        }
    }

    Polinom operator * (double Arg){
        Polinom out(maxPower);
        for(int p1 = 0; p1 < maxPower; p1++){
            out.data[p1] = data[p1] * Arg;
        }
        return out;
    }

    void operator = (const Polinom& Arg){
        if(data != (double *)0)
            delete [] data;
        maxPower = Arg.maxPower;
        data = new double[maxPower];
        for(int i = 0; i < maxPower; i++){
            data[i] = Arg.data[i];
        }
    }

    Polinom Pr(){
        Polinom out(maxPower - 1);
        for(int i = 0; i < out.maxPower; i++){
            out.data[i] = data[i+1] * (i+1);
        }
        return out;
    }

    double Calc(double lyambda){
        double out = 0;
        double k = 1;
        for(int i = 0; i < maxPower; i++){
            out += data[i]*k;
            k *= lyambda;
        }
        return out;
    }
    Polinom operator / (const Polinom& Arg){
        int minMax = Arg.maxPower - 1;
        Polinom temp2;
        temp2 = *this;
        Polinom out(maxPower - Arg.maxPower + 1);
        for(int j = 0; j < maxPower - Arg.maxPower; j ++){
            out.data[j] = 0;
        }
        for(int i = maxPower - 1; i > minMax; i--){
            double ratio = temp2.data[i] / Arg.data[minMax];
            int tempPower = i - minMax;
            Polinom temp3(tempPower + 1);
            for(int j = 0; j < tempPower; j ++){
                temp3.data[j] = 0;
            }
            temp3.data[tempPower] = ratio;
            out.data[tempPower] = ratio;
            temp2 = temp2 - (temp3 * Arg);
        }
        out.data[0] = temp2.data[minMax] / Arg.data[minMax];
        return out;
    }

    double halfDivideSq(double a, double b){
        if( (b - a < 0.001) && (b - a > -0.001) )return a;
        if( (Calc(a) >= 0) && (Calc( (a+b)/2 ) <=0) ){
            return halfDivideSq(a,(a+b)/2);
        }
        else return halfDivideSq((a+b)/2,b);
    }

    Matrix Solve(){
        Matrix out(1,maxPower - 1,0);
        if(maxPower == 3){
            double D = data[1]*data[1] - 4 * data[2]*data[0];
            out.data[0] = (-data[1]-sqrt(D))/2/data[2];
            out.data[1] = (-data[1]+sqrt(D))/2/data[2];
            return out;
        }
        if(maxPower == 2){
            out.data[0] = -data[0]/data[1];
            return out;
        }
        Polinom tempP;
        tempP = this->Pr();
        Matrix tempM(1,maxPower - 2,0);
        tempM = tempP.Solve();
        double x1 = halfDivideSq(tempM.data[0], tempM.data[1]);
        Polinom Sq(2);
        Sq.data[1] = 1;
        Sq.data[0] = -x1;
        tempP = *this / Sq;
        tempM = tempP.Solve();
        memcpy(out.data, tempM.data, (maxPower - 2)*sizeof(double));
        out.data[maxPower - 2] = x1;
        return out;
    }
};

class PowerMatrix{
private:
    int rows;
    int cols;
public:
    Polinom* data;

    Polinom Determinant(){

        if(cols == 1)return data[0];
        PowerMatrix Temp(cols - 1, rows - 1);
        Polinom det(cols);
        for(int i = 0; i < cols; i++){
            det.data[i] = 0;
        }

        int row = 0;
        int sign;

        for(int col = 0; col < cols; col++){
            for(int i = 0; i < Temp.rows; i++){     //construction sub-matrix
                for(int j = 0; j < Temp.cols; j++){
                        if (j < col)  Temp.data[j + (i * Temp.cols)] = data[j + ((i + 1) * cols)];
                        else          Temp.data[j + (i * Temp.cols)] = data[(j + 1) + ((i + 1) * cols)];
                }
            }
            if(col % 2) sign = -1;
            else sign = 1;
            det = det + data[col] * Temp.Determinant() * sign;
        }
        return det;
    }

    PowerMatrix (Matrix A){
        cols = A.getCols();
        rows = A.getRows();
        data = new Polinom [cols * rows];
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                Polinom temp(2);
                if(col == row)  temp.data[1] = -1;
                else temp.data[1] = 0;
                temp.data[0] = A.data[col + ( row * A.getCols())];
                data[col + ( row * cols)] = temp;
            }
        }
    }

    PowerMatrix (int cols, int rows):cols(cols), rows(rows){
        data = new Polinom [cols * rows];
    }

    void operator = (PowerMatrix A){
        cols = A.cols;
        rows = A.rows;
        if(data != (Polinom *) 0)
            delete [] data;
        data = new Polinom [cols * rows];
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                data[col + row * cols] = A.data[col + row * cols];
            }
        }
    }

    ~PowerMatrix(){
        if(data != (Polinom *) 0)
            delete [] data;
    }

    void Print(){
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                data[col + ( row * cols)].Print2();
                printf("\t|||\t");
            }
            printf("\n");
        }
        printf("|||||||||||\n");
    }
};


Matrix getEigenValue(Matrix A){
    PowerMatrix Temp(A);
    Polinom temp;
    temp = Temp.Determinant();
    Matrix out;
    out = temp.Solve();
    return out;
}