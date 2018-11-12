#include <stdio.h>
#include <conio.h>
#include "MatrLib.h"

int main(){

    Matrix M7(4,4);
    Matrix M8 = M7.Invert();
    Matrix M9 = M7 * M8;

    M7.Print();
    M8.Print();
    M9.Print();

    M7.memUsedPrint();
    M7.countPrint();



    Polinom P1(5,-3,3);
    Polinom P2(2,-3,3);

    P1.Print();
    P2.Print();

    Polinom P3 = P1 / P2;

    P1.Print();
    P2.Print();
    P3.Print();

    Matrix M;
    M = P3.Solve();
    M.Print();

    Polinom P01(2);
    P01.data[0] = -M.data[0];
    P01.data[1] = 1;
    Polinom P02(2);
    P02.data[0] = -M.data[1];
    P02.data[1] = 1;
    Polinom P03(2);
    P03.data[0] = -M.data[2];
    P03.data[1] = 1;
    Polinom P04(2);
    P04 = P01 * P02 * P03;
    P04.Print();

    return  0;
}
