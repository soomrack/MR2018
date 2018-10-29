#include <stdio.h>
#include <conio.h>
#include "MatrLib.h"

int main(){
    Matrix M1(3,3,1);
    Matrix M2(4,3,0);
    Matrix M3(1,3);

    M1.Print();
    M2.Print();
    M3.Print();

    printf("%lf\n", M1.Trace());

    Matrix M4 = M3.Trans();
    M4.Print();

    Matrix M5(3,3,1);
    M5 = M5 * 2;

    Matrix M6 = M1 * M3;
    M6.Print();

    M6 = M5.Power(3);

    M5.Print();

    M6.Print();

    return  0;
}
