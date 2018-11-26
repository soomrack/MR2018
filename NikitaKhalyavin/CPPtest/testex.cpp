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

    Matrix M16(4,4,1);
    M16.data[1] = 3;        M16.data[2] = 1;        M16.data[3] = 1;
                            M16.data[6] = 2;        M16.data[7] = 1;
                                                    M16.data[11] = 1;
    Matrix M17;
    M17 = M16.SolveForEigen();
    M16.Print();
    M17.Print();


    return  0;
}
