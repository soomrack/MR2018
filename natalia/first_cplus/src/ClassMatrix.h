#ifndef FIRST_CPLUS_CLASSMATRIX_H
#define FIRST_CPLUS_CLASSMATRIX_H


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


#endif //FIRST_CPLUS_CLASSMATRIX_H
