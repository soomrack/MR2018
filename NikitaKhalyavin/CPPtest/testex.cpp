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

    Polinom P02(2);
    Polinom P03(1);

    P02.data[1] = 1;
    P03.data[0] = 3;

    for(int i = 0; i < 3; i++){
        P03.Print();
        P02.data[0] = -M02.data[i];
        P03 = P03 * P02;
    }

    P03.Print();
    Polinom P04;

    P04 = P01 / P03;
    P04.Print();


    P02.data[0] = -0.537457;
    P03 = P03 * P04;

    P03.Print();

    M02.Print();

    return  0;
}
