#include <stdio.h>
#include <conio.h>
#include "MatrLib.h"

int main(){

    Matrix M7(2,2,1);
    Matrix M8 = M7.Invert();
    Matrix M9 = M7 * M8;

    M7.Print();
    M8.Print();
    M9.Print();

    PowerMatrix M(M8);
    M.Print();

    Polinom test(1);
    test = M.Determinant();
    test.Print();

    Matrix V;
    V = test.Solve();
    V.Print();

    return  0;
}
