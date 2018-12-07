//
// Created by admin on 07.12.2018.
//
#include <iostream>
#include "kurshakov_matrix.h"
#include <windows.h>


int main() {
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);
    Matrix A = matrix_one(14, 15);
    A.matrix_print();
    return 0;
}