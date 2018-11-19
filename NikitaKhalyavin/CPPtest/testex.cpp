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




    Polinom P01(5);
    P01.data[0] = -0.001;
    P01.data[1] = 2;
    P01.data[2] = -1;
    P01.data[3] = -4;
    P01.data[4] = 3;

    P01.Print();
    Matrix M02;
    M02 = P01.Solve();

    M02.Print();

    return  0;
}
