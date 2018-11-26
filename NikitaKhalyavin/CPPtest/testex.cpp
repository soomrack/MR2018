#include <stdio.h>
#include <conio.h>
#include "MatrLib.h"

int main(){

    Matrix M7(4,4);
    Matrix M8;
    M8 = M7.Invert();
    Matrix M9;
    M9 = M7 * M8;

    M7.Print();
    M8.Print();
    M9.Print();

    M8.beSymmetric();
    M8.Print();

    Matrix M10;

    M10 = M8.getEigenValues();
    M10.Print();

    return  0;
}
