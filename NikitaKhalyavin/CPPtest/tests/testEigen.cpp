//
// Created by work on 26.11.2018.
//

#include "TestingLib.h"

int main(){
    int returnCode;
    for(int i = 2; i < 10; i++){

        Matrix A(i,i);
        A.beSymmetric();
        Matrix B;
        B = A.getEigenValues();
        Matrix C;
        C = A.getEigenVectors();

        for(int j = 0; j < i; j++) {

            Matrix D;
            D = C.getVector(j);

            Matrix E;
            Matrix F;
            E = A * D;
            F = D * B.data[j];

            returnCode = MatrixCompare(E, F);
            if(returnCode) {
                A.Print();
                B.Print();
                C.Print();
                D.Print();
                E.Print();
                F.Print();
                Matrix Err;
                Err = E - F;
                Err.Print();
                return 1;
            }
        }
    }
    return 0;
}