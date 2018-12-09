#include <stdio.h>
#include <conio.h>
#include "MatrLib.h"

int main(){

    Matrix M8(4,4);

    M8.beSymmetric();
    M8.Print();

    Matrix M10;

    M10 = M8.getEigenValues();
    M10.Print();

    Matrix M11;

    M11 = M8.getEigenVectors();

    Matrix M12;
    Matrix M13;
    Matrix M14;
    Matrix M15;

    M12 = M11.getVector(0);
    M13 = M8 * M12;
    M14 = M12 * M10.data[0];
    M15 = M14 - M13;


    M13.Print();
    M14.Print();

    M15.Print();

    return  0;
}
