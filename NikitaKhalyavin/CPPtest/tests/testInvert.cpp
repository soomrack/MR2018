//
// Created by work on 26.11.2018.
//


#include "TestingLib.h"

int main(){
    int returnCode;
    for(int a = 2; a < 10; a++){
        Matrix A(a,a);
        Matrix B;
        B = A.Invert();
        Matrix C;
        Matrix D(a,a,1);
        C = A*B;
        returnCode = MatrixCompare(C,D);
        if(returnCode) {
            A.Print();
            B.Print();
            C.Print();
            D.Print();
            return 1;
        }
    }
    return 0;
}