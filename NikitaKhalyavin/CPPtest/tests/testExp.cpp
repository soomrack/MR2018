//
// Created by work on 26.11.2018.
//

#include "TestingLib.h"

int main(){
    int returnCode;
    for(int a = 2; a < 10; a++){
        Matrix A(a,a,1);
        Matrix B;
        B = A * 2.71828182846;
        Matrix C;
        C = A.Exp();
        returnCode = MatrixCompare(B,C);
        if(returnCode) {
            A.Print();
            B.Print();
            C.Print();
            return 1;
        }
    }
    return 0;
}