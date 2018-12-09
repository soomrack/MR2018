//
// Created by CryLab on 06.12.2018.
//

#ifndef MATRIX_LIBRARY_MATRIX_H
#define MATRIX_LIBRARY_MATRIX_H

namespace Mx
{
        class Matrix
        {
        private:
                unsigned char cols;
                unsigned char rows;
                double *data;
        public:
                Matrix(unsigned char rows_in, unsigned char cols_in);
                Matrix(Matrix &o);
                ~Matrix();
                void set(double *input);
                void print();
                double trace();
                void rand();
                void zero();
                void one();
                void sum(const Matrix &B);
                void mult(const Matrix &B);
                void mult_scalar(const double scalar);
                void power(const unsigned int power);
                void trans();
                double determinant();
                void invert();
        };

};
Mx::Matrix mexp(const Mx::Matrix A);
#endif //MATRIX_LIBRARY_MATRIX_H
