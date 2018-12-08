//
// Created by work on 29.10.2018.
//

#include "MatrLib.h"


unsigned long long int fact(unsigned int n){
    unsigned long long int out = 1;
    for(int i = 2; i < n; i++)out*=i;
    return  out;
}

Matrix Matrix::getEigenValues(){
    PowerMatrix Temp(*this);
    Polinom temp;
    temp = Temp.Determinant();
    Matrix out;
    out = temp.Solve();
    return out;
}