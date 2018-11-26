//
// Created by work on 26.11.2018.
//

#include "../MatrLib.h"

int main(){
    int returnCode;
    for(int a = 2; a < 10; a++){
        Matrix A(a,a);
        Matrix B;
        B = A.Invert();
        Matrix C;
        C = A*B;
        A.Print();
        B.Print();
        C.Print();
        Matrix D(a,a,1);
        for(int row = 2; row < a; row++){
            for(int col = 2; col < a; col++){
                returnCode += (C.data[row*a + col] != D.data[row*a + col]);
            }
        }
        D.Print();
        if(returnCode) return 1;
    }
    return 0;
}