#include <stdio.h>
#include <conio.h>
#include "MatrLib.h"


int main(){
    Polinom P1(3,2,4);
    Polinom P2(3,0,1);

    P1.Print();
    P2.Print();


    Polinom P3 = P1 + P2;
    Polinom P4 = P1 * P2;
    Polinom P5 = P1.Pr();

    P1.Print();
    P2.Print();
    P3.Print();
    P4.Print();
    P5.Print();

    printf("%lf", P5.Calc(5));

    return  0;
}
