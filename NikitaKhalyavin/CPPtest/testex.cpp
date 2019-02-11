#include <stdio.h>
#include <conio.h>
#include "MatrLib.h"

int main(){

    Polinom P1(4);
    P1.data[0] = 10;
    P1.data[1] = 10;
    P1.data[2] = 10;
    P1.data[3] = 10;
    P1.Print();
    Matrix M;
    M = P1.Solve();
    M.Print();

    return  0;
}
