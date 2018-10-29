//
// Created by work on 29.10.2018.
//

#include <malloc.h>
#include <time.h>
#include <stdio.h>

#ifndef MR2018_MATRLIB_H
#define MR2018_MATRLIB_H

#endif //MR2018_MATRLIB_H


class Matrix{
private:
    int m_cols;
    int m_rows;
public:
    double * data;
    Matrix(int cols, int rows):    m_cols(cols), m_rows(rows){
        data = (double*)malloc(m_cols * m_rows * sizeof(double));
        srand(time(NULL));
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_cols; j++){
                data[j + ( i * m_cols)] = -1 + (double)(rand())/RAND_MAX * 2;
            }
        }
    }

    Matrix(int cols, int rows, int type): m_cols(cols), m_rows(rows){
        data = (double*)malloc(m_cols * m_rows * sizeof(double));
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_cols; j++){
                if(i == j) data[j + ( i * m_cols)] = type;
                else       data[j + ( i * m_cols)] = 0;
            }
        }
    }

    ~Matrix(){
        free(data);
    }

    void Print() {
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                printf("%5.2lf\t", data[j + (i * m_cols)]);
            }
            printf("\n");
        }
        printf("\n");
    }

    double Trace(){
        double trace = 0;

        for(int i = 0; i < m_rows; i++){     //construction sub-matrix
            trace += data[i + ( i * m_cols)];
        }
        return trace;
    }


};

class Polinom{
private:
    int maxPower;
    double * data;
public:
    Polinom(int power):     maxPower(power){
        data = (double*)malloc(maxPower * sizeof(double));
    }

    Polinom(int power, double min, double max):   maxPower(power){
        data = (double*)malloc(maxPower * sizeof(double));
        srand(time(NULL));
        for(int i = 0; i < maxPower; i++){
            data[i] = min + (rand() * (max - min) / RAND_MAX);
        }
    }
    ~Polinom(){
        free(data);
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

    Polinom operator * (Polinom& Arg){
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
        for(int i = 0; i < maxPower; i++){
            printf("%lf l^%d     ", data[i], i);
        }
        printf("\n");
    }

    Polinom operator * (double& Arg){
        Polinom out(maxPower);
        for(int p1 = 0; p1 < maxPower; p1++){
            out.data[p1] = data[p1] * Arg;
        }
        return out;
    }

    Polinom Pr(){
        Polinom out(maxPower - 1);
        for(int i = 0; i < out.maxPower; i++){
            out.data[i] = data[i+1] * (i+1);
        }
        return (out);
    }

    double Calc(double lyambda){
        double out = 0;
        double k = 1;
        for(int i = 0; i < maxPower; i++){
            out += data[i]*k;
            k*=lyambda;
        }
        return out;
    }
};