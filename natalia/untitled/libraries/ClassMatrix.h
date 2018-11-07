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
<<<<<<< HEAD

};

double minor(ClassMatrix A, int row, int col, int size);
=======
};


>>>>>>> 33a26d8985261ae7bf72b981c6f43d46ceae23be
#endif