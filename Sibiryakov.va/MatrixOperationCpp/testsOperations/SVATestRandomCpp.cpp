#include <iostream>
#include <stdio.h>
#include <math.h>
#include <windows.h>

#include "../MatrixOperation.h"

int main() {
    Matrix A(2,3);
    Matrix B(2,3);

    for (int i = 0; i < 20; i++) {
        A.Random();
        Sleep(1000);
        B.Random();

        if (A == B) {
            return 1;
        }
    }

    return 0;
}

