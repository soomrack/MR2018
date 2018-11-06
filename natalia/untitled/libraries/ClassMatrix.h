#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H


class ClassMatrix{
public:
    unsigned int rows;
    unsigned int cols;
    double* data;
    // След матрицы

    double matrix_trace(ClassMatrix A);
    // Определитель матрицы
    double matrix_determinant(ClassMatrix);
};


#endif