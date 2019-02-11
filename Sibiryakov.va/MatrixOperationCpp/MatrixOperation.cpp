#include "MatrixOperation.h"

Matrix Matrix::operator+ (const Matrix &A) {
    if ( (A.rows != rows) && (A.cols != cols) ) {
        cout << "Matrices must be same size!" << endl;
        exit(1);
    }
    Matrix result(A.rows,A.cols);
    for (unsigned row = 0; row < A.rows; row++) {
        for (unsigned col = 0; col < A.cols; col++) {
            result.data[(row * A.cols) + col] = data[(row * A.cols) + col] + A.data[(row * A.cols) + col];
           // cout << result.data[(row * A.cols) + col] << endl;
        }
    }
    return result;
}

Matrix Matrix::operator * (const Matrix &A) {
    if ( cols != A.rows ) {
        cout << "Matrix B must have cols equals rows of Matrix A" << endl;
        exit(1);
    }
    Matrix result(A.cols, rows);
    cout << result.rows << result.cols << endl;
    for (unsigned row=0; row < result.rows; row++) {
        for (unsigned col = 0; col < result.cols; col++) {
            result.data[row * result.cols + col] = 0;
          //  cout << result.data[row * result.cols + col] << endl;
            for (unsigned u = 0; u < cols; u++) {
                result.data[(row * result.cols) + col] += data[(row * cols) + u] * A.data[(u * A.cols) + col];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(double scalar) {
    Matrix result(rows, cols);
    for (unsigned row=0; row < rows; row++) {
        for (unsigned col = 0; col < cols; col++) {
            result.data[(row * cols) + col] = scalar * data[(row * cols) + col];
        }
    }
    return result;
}

Matrix Matrix::operator/(double x) {
    unsigned i,j;
    for(i=0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            data[i * cols + j] /= x;
        }
    }
    return *this;
}

void Matrix::operator=(const Matrix &A) {
    if ( (A.rows != rows) && (A.cols != cols) ) {
        cout << "Matrices must be same size!" << endl;
        exit(1);
    }
    delete [] data;
    cols = A.cols;
    rows = A.rows;
    data = new double[cols * rows];
    for(unsigned row = 0; row < rows; row++){
        for(unsigned col = 0; col < cols; col++){
            data[row * cols + col] = A.data[row * cols + col];
        }
    }
}

double Matrix::Trace() {
    if ( rows != cols) {
        cout << "Matrix must be square!" << endl;
        exit(1);
    }
    double trace = 0;

    for (unsigned diagonal = 0; diagonal < rows; diagonal++) {
        trace += data[diagonal + (diagonal * rows)];
    }

    return trace;
}

void Matrix::Random() {
    srand(time(0));
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            data[col + row * cols] = -0.5 + (double)(rand())/RAND_MAX;
        }
    }
}

double Matrix::Determinant() { //нахождения определителя методом Гаусса
    if ( rows != cols) {
        cout << "Matrix must be square!" << endl;
        exit(1);
    }

    unsigned size = rows;
    unsigned power = 0;
    double det = 0;

    //преобразование матрицы в матрицу, под диагональю которой нули
    for (unsigned i = 0; i < size-1; i++ ) {
        unsigned t = 1;
        while (data[i * size + i] == 0) {
            for (unsigned j = 0; j < size; j++) {
                data[i * size + j] = det;
                data[i * size + j] = data[(i + t) * size + j];
                data[(i + t) * size + j] = det;
            }
            power++;
            t++;
        }

        for (unsigned k = i + 1; k < size; k++) {
            det = data[k * size + i] / data[i * size + i];
            for (unsigned z = 0; z < size; z++) data[k * size + z] -= data[i * size + z] * det;
        }

    }

    det = pow(-1, power);

    //после такого преобразования произведение элементов главной диагонали равно определителю
    for (unsigned i = 0; i < size; i++) {
        det *= data[i*size + i];
    }

    return det;
}

Matrix Matrix::Trans() {

    Matrix result(cols, rows);

    for(int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            result.data[col*rows + row] = data[row*cols+col];
        }
    }
    return result;
}

void Matrix::Print() {
    cout << "Rows: " << rows << "\tCols: " << cols << endl;
    cout << "Data: " << endl;
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            printf("%.4lf\t", data[j + (i * cols)]);
        }
        printf("\n");
    }
    printf("\n");
}



Matrix Matrix::Invert() { //реализация расширенного алгоритма для нахождения обратной матрицы методом Гаусса-Жордана
    if ( rows != cols) {
        cout << "Matrix must be square!" << endl;
        exit(1);
    }

    double temp;

    unsigned size = rows;
    Matrix one(size);
    Matrix result(size);


    //создание единичной матрицы такого же размера и заполнение вспомогательной матрицы
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            one.data[i * rows + j] = 0.0;

            if (i == j)
                one.data[i * rows + j] = 1.0;

            result.data[i*size + j] = data[i*size + j];
        }
    }


    //прямой ход - образование нулей над главной диагональю
    for (int k = 0; k < size; k++) {
        temp = result.data[k*size + k];

        for (int j = 0; j < size; j++) {
            result.data[k*size + j] /= temp;
            one.data[k*size + j] /= temp;
        }

        for (int i = k + 1; i < size; i++) {
            temp = result.data[i*size + k];

            for (int j = 0; j < size; j++) {
                result.data[i*size + j] -= result.data[k*size + j] * temp;
                one.data[i*size + j] -= one.data[k*size + j] * temp;
            }
        }
    }


    //обратный ход - образование нулей под главной диагональю
    for (int k = (size - 1); k > 0; k--) {

        for (int i = k - 1; i >= 0; i--) {

            temp = result.data[i*size + k];

            for (int j = 0; j < size; j++) {
                result.data[i*size + j] -= result.data[k*size + j] * temp;
                one.data[i*size + j] -= one.data[k*size + j] * temp;
            }
        }
    }

    //в результате операций выше единичная матрица превращается в матрицу, обратную исходной
    //а входная матрица превращется в единичную
    return one;
}

Matrix Matrix::One() {
    if ( rows != cols) {
        cout << "Matrix must be square!" << endl;
        exit(1);
    }

    unsigned size = rows;
    Matrix result(size);
    for (unsigned row = 0; row < result.rows; row++) {
        for (unsigned col = 0; col < result.cols; col++) {
            result.data[row * cols + col] = 0;
            if (row == col) result.data[row * cols + col] = 1;
        }
    }
    return result;
}

Matrix Matrix::Zero() {
    Matrix result(rows,cols);
    for (unsigned row = 0; row < result.rows; row++) {
        for (unsigned col = 0; col < result.cols; col++) {
            result.data[row * cols + col] = 0;
        }
    }
    return result;
}

Matrix Matrix::Power(unsigned power) {
    Matrix A(rows, cols);
    Matrix B(rows, cols);
    B = *this;
    //матрица в нулевой степени равна единичной
    if (power == 0) {
        A = B.One();
        return A;
    }
    if (power == 1) {
        return B;
    }
    for(unsigned p = 1; p < power; p++) {
        A = B;
        //   A.Print();
        B = (A * (*this));
        // B.Print();
    }
    return B;
}


double Matrix::norma() {
    double s=0;
    unsigned size = rows;
    for(unsigned i=0; i< size; i++) {
        for (unsigned j = 0; j < size; j++) {
            s += (fabs(data[i * size + j]) * fabs(data[i * size + j]));
        }
    }
    return sqrt(s);
}

Matrix Matrix::Exp() {
    if ( rows != cols) {
        cout << "Matrix must be square!" << endl;
        exit(1);
    }

    double f = 0;
    double T_norma = 0;
    unsigned size = rows;
    unsigned i = 0;
    Matrix E(size);

    for (unsigned row = 0; row < rows; row++) {
        for (unsigned col = 0; col < cols; col++) {
            E.data[row * cols + col] = 0;
        }
    }

    Matrix T(size);
    do
    {
        f = fact(i);
        T = this->Power(i);
        T = T / f;
        T_norma = T.norma();
        T.Print();
        E = E + T;
        i++;
    } while (T_norma > 0.0000001);
    return E;
}


double Matrix::fact(double n) {
    double result = 1.0;
    if (n < 2) {
        return result = 1;
    }
    else {
        for (unsigned counter = 2; counter <= n; counter++) {
            result *= (double)counter * 1.0003;
        }
        return result;
    }
}



