#include <iostream>
#include <cstdlib>
#include "MatrixART.h"

#define M 2
#define N 3
#define Q 4

int main ()
{
    double M1[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double M2[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double M3[Q][Q] = {{1, 2, 3, 4}, {5, 6 , 7 ,8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    Mat A = {3, 3, *M1};
    Mat B = {3, 3, *M2};
    Mat C = {4, 4, *M3};

    double trace, det;

    std::cout << "A = \n";
    A.print(A);
    std::cout << "\nB = \n";
    B.print(B);

    trace = A.trace(A);
    std::cout << "\n trace A = " << trace << "\n";

    Mat Sum;
    std::cout << "\n A + B = \n";
    Sum = A.sum(A, B);
    Sum.print(Sum);

    Mat Mult;
    std::cout << "\n A * B = \n";
    Mult = B.mult(A, B);
    Mult.print(Mult);

    Mat MultConst;
    std::cout << "\n A * 5 = \n";
    MultConst = A.mult_const(5, A);
    MultConst.print(MultConst);

    Mat Transp;
    std::cout << "\n A(transp) \n";
    Transp = A.transp(A);
    Transp.print(Transp);


    Mat Minor;
    std::cout << "\n minor B \n";
    Minor = B.minor(1, 1, B);
    Minor.print(Minor);

    Mat Dop;
    std::cout << "\n dop B \n";
    Dop = B.dop(B);
    Dop.print(Dop);

    det = B.det(C);
    std::cout << "\n det C = " << det << "\n";

    Mat One;
    std::cout << "\n one \n";
    One = One.one(4);
    One.print(One);

    Mat power;
    std::cout << "\n B^2 \n";
    power = B.power(B, 2);
    power.print(power);

    Mat Exp;
    std::cout << "\n exponent \n";
    Exp = B.exp(B);
    Exp.print(Exp);

    return 0;
}
