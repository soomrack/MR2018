#include "Matrix.h"

int main() {

    double a[2][2]={{1.0, 3.0},
                    {-2.0, 4.0}};
    double b[2][3]={{1.0, -1.0, 2.0},
                    {3.0, -1.0, -4.0}};

    Matrix A(2,2);
    A.data=*a;
    A.Print();
    Matrix B(2,3);
    B.data=*b;
    B.Print();
    Matrix C = B.Mult(A,B);
    C.Print();

    return 0;
}