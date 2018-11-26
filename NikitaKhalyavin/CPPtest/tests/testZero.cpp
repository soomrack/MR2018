//
// Created by work on 26.11.2018.
//

#include "TestingLib.h"

int main(){
    int returnCode;
    Matrix A(2,2);
    A.data[0] = 0;  A.data[1] = 0;
    A.data[2] = 0;  A.data[3] = 0;
    Matrix B(2,2,0);
    returnCode = MatrixCompare(A,B);
    if(returnCode) {
        A.Print();
        B.Print();
        return 1;
    }
    Matrix C(5,5);
    C.data[0]  = 0;  C.data[1]  = 0;  C.data[2]  = 0;  C.data[3]  = 0;  C.data[4]  = 0;
    C.data[5]  = 0;  C.data[6]  = 0;  C.data[7]  = 0;  C.data[8]  = 0;  C.data[9]  = 0;
    C.data[10] = 0;  C.data[11] = 0;  C.data[12] = 0;  C.data[13] = 0;  C.data[14] = 0;
    C.data[15] = 0;  C.data[16] = 0;  C.data[17] = 0;  C.data[18] = 0;  C.data[19] = 0;
    C.data[20] = 0;  C.data[21] = 0;  C.data[22] = 0;  C.data[23] = 0;  C.data[24] = 0;
    Matrix D(5,5,0);
    returnCode = MatrixCompare(C,D);
    if(returnCode) {
        C.Print();
        D.Print();
        return 1;
    }
    return 0;
}