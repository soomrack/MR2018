#include <cstdlib>
#include <random>
#include <cassert>  //assert
#include <cstring>
#include <cmath>    // std::abs
#include "stdio.h"

#include "matrix.h"

///////////////// MATRIX GENERATORS

Matrix MatrixCalc::matrix_one(const unsigned int size)
{
    double * array = new double[size*size]{0};
    Matrix mat = {size,size,array};

    for(unsigned long i = 0; i < size; i++){
        mat.data[i*(size+1)] = 1.0;
    }

    return mat;
}

Matrix MatrixCalc::matrix_zero(const unsigned int rows, const unsigned int cols)
{
    double * array = new double[rows*cols]{0};
    Matrix mat = {rows,cols,array};

    return mat;
}

Matrix MatrixCalc::matrix_copy(const Matrix A)
{
    Matrix copy = MatrixCalc::matrix_zero(A.rows, A.cols);

    std::memcpy(copy.data, A.data, A.rows*A.cols*sizeof(double));

    return copy;
}


Matrix MatrixCalc::matrix_rand(const unsigned int rows, const unsigned int cols)
{
    double * array = new double[rows*cols]{0};
    Matrix mat = {rows,cols,array};

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    unsigned long idx = 0;
    for(unsigned long i = 0; i < rows*cols; i++){
        mat.data[idx] = dist(mt);;
        idx++;
    }

    return mat;
}

////////////////////// UTILS

inline
void MatrixCalc::matrix_free(const Matrix A){
    delete[] A.data;
}

////////////////////// IO

void MatrixCalc::matrix_print(const Matrix A)
{
    fprintf(stdout, "Matrix: {rows:%u, cols:%u, array:[\n", A.rows, A.cols);
    unsigned long idx = 0;
    for (unsigned int i = 0; i < A.rows; i++){
        fprintf(stdout, "[");
        for (unsigned int j = 0; j < A.cols; j++){
            fprintf(stdout, "%.2f,", A.data[idx]);
            idx++;
        }
        fprintf(stdout, "],\n");
    }
    fprintf(stdout, "]}\n");
}

///////////////// MATRIX TO DOUBLE

double MatrixCalc::matrix_trace(const Matrix A)
{
    double trace = 0;
    for(unsigned long i = 0; i < A.rows; i++){
        trace += A.data[i*(A.rows+1)];
    }
    return trace;
}

double MatrixCalc::matrix_determinant(const Matrix A)
{
    Matrix work = MatrixCalc::matrix_copy(A);

    for (unsigned int j = 0; j < A.cols-1; j++){
        for(unsigned int i = A.rows-1; i > j; i--){
            double this_value = work.data[i*A.cols + j];
            double value_over_this = work.data[(i-1)*A.cols + j];
            //fprintf(stdout, "this: %f next: %f\n", this_value, value_over_this);

            const double epsilon = 0.00001;

            if(std::abs(this_value) < epsilon){
                //fprintf(stdout, "i: %d, j: %d\n", i, j);
                //MatrixCalc::matrix_print(work);
                continue;
            }

            if (std::abs(value_over_this) < epsilon){
                //swap lines
                for(unsigned int jj = j; jj < A.rows; jj++){
                    double tmp = work.data[i*A.cols + jj];
                    work.data[i*A.cols + jj] = work.data[(i-1)*A.cols + jj];
                    work.data[(i-1)*A.cols + jj] = tmp * -1.0;
                }
            }else{
                double multiplier = -this_value/value_over_this;
                //fprintf(stdout, "multiplier: %f\n", multiplier);
                work.data[i*A.cols + j] = 0.0;
                for(unsigned int jj = j+1; jj < A.rows; jj++){
                    work.data[i*A.cols + jj] += work.data[(i-1)*A.cols + jj] * multiplier;
                }
            }
            //fprintf(stdout, "i: %d, j: %d\n", i, j);
            //MatrixCalc::matrix_print(work);
        }
    }

    double determinant = work.data[0];
    for(unsigned long i = 1; i < A.rows; i++){
        determinant *= work.data[i*(A.rows+1)];
    }

    MatrixCalc::matrix_free(work);

    return determinant;
}

///////////////// MATRIX TO MATRIX

Matrix MatrixCalc::matrix_sum(const Matrix A, const Matrix B)
{
    Matrix sum = MatrixCalc::matrix_zero(A.rows, A.cols);

    unsigned long idx = 0;
    for(unsigned long i = 0; i < A.rows*A.cols; i++){
        sum.data[idx] = A.data[idx] + B.data[idx];
        idx++;
    }
    return sum;
}

/*
Matrix MatrixCalc::matrix_mult_dot(const Matrix A, const Matrix B)
{
    Matrix mult = MatrixCalc::matrix_copy(A);

    unsigned long idx = 0;
    for(unsigned long i = 0; i < A.rows*A.cols; i++){
        mult.data[idx] *= B.data[idx];
        idx++;
    }
    return mult;
}
*/

Matrix MatrixCalc::matrix_mult(const Matrix A, const Matrix B)
{
    Matrix mult = MatrixCalc::matrix_zero(A.rows, A.cols);

    unsigned long idx = 0;
    for(unsigned int i = 0; i < A.rows; i++){
        unsigned int this_row = i*A.cols;
        for(unsigned int j = 0; j < A.cols; j++){
            for(unsigned int k = 0; k < A.cols; k++){
                mult.data[idx] += A.data[this_row + k] * B.data[k*A.cols + j];
            }
            idx++;
        }
    }
    return mult;
}

Matrix MatrixCalc::matrix_mult_scalar(const double scalar, const Matrix A)
{
    Matrix mult = MatrixCalc::matrix_copy(A);

    unsigned long idx = 0;
    for(unsigned long i = 0; i < A.rows*A.cols; i++){
        mult.data[idx] *= scalar;
        idx++;
    }
    return mult;
}

Matrix MatrixCalc::matrix_trans(const Matrix A)
{
    Matrix trans = MatrixCalc::matrix_zero(A.rows, A.cols);

    unsigned long idx = 0;
    for(unsigned int i = 0; i < A.rows; i++){
        for(unsigned int j = 0; j < A.cols; j++){
            trans.data[idx] = A.data[i + j*A.rows];
            idx++;
        }
    }
    return trans;
}

Matrix MatrixCalc::matrix_invert(const Matrix A)
{
    double determinant = MatrixCalc::matrix_determinant(A);

    Matrix alg_dop = MatrixCalc::matrix_zero(A.rows, A.cols);

    for(unsigned int i = 0; i < A.rows; i++){
        for(unsigned int j = 0; j < A.cols; j++){
            Matrix aux = MatrixCalc::matrix_zero(A.rows-1, A.cols-1);
            unsigned int iii = 0;
            for(unsigned int ii = 0; ii < A.rows; ii++){
                if (ii == i)
                    continue;
                //fprintf(stdout, "i %d, j %d, ii %d, iii %d, jjj %d\n", i, j, ii, iii, jjj);
                unsigned long this_row = ii*A.rows;
                unsigned long this_row_aux = iii*aux.rows;

                unsigned int jjj = 0;
                for(unsigned int jj = 0; jj < A.cols; jj++){
                    if (jj == j)
                        continue;
                    aux.data[this_row_aux + jjj] = A.data[this_row + jj];
                    //fprintf(stdout, "ii %d, jj %d, iii %d, jjj %d\n", ii, jj, iii, jjj);
                    jjj++;
                }
                iii++;
            }
            //MatrixCalc::matrix_print(aux);
            //fprintf(stdout, "==============\n");

            double det = MatrixCalc::matrix_determinant(aux);
            MatrixCalc::matrix_free(aux);
            if( (i+j) % 2 == 0){
                alg_dop.data[i*A.rows + j] = det;
            }else{
                alg_dop.data[i*A.rows + j] = -det;
            }
        }
    }

    Matrix trans = MatrixCalc::matrix_trans(alg_dop);
    MatrixCalc::matrix_free(alg_dop);
    Matrix invert = MatrixCalc::matrix_mult_scalar(1.0/determinant, trans);
    MatrixCalc::matrix_free(trans);

    return invert;
}

inline static double factorial(double x)
{
    double fact = 1;
    for (int i = 2; i <= x; i++){
        fact *= i;
    }
    return fact;
}

Matrix MatrixCalc::matrix_exp(const Matrix A)
{
    Matrix matrix_exp = MatrixCalc::matrix_one(A.rows);

    const double epsilon = 0.000000000000000001;

    int i = 1;
    while(true){
        Matrix taylor_element_num = MatrixCalc::matrix_power(A, i);
        double taylor_element_den = factorial(i);

        //fprintf(stdout, "taylor_element_num: ");
        //MatrixCalc::matrix_print(taylor_element_num);
        //fprintf(stdout, "factorial: %f\n", taylor_element_den);

        Matrix taylor_element = MatrixCalc::matrix_mult_scalar(1.0/taylor_element_den, taylor_element_num);
        MatrixCalc::matrix_free(taylor_element_num);

        //fprintf(stdout, "taylor_element: ");
        //MatrixCalc::matrix_print(taylor_element);

        double determinant = MatrixCalc::matrix_determinant(taylor_element);

        //fprintf(stdout, "i: %d, determinant: %f\n", i, determinant);

        Matrix matrix_exp_tmp = MatrixCalc::matrix_sum(matrix_exp, taylor_element);
        MatrixCalc::matrix_free(taylor_element);
        MatrixCalc::matrix_free(matrix_exp);
        matrix_exp = matrix_exp_tmp;
        i++;

        if(std::abs(determinant) < epsilon)
            break;
    }

    return matrix_exp;
}

Matrix MatrixCalc::matrix_power(const Matrix A, const unsigned int power)
{
    if (power == 0)
        return MatrixCalc::matrix_one(A.rows);

    Matrix mat_power = MatrixCalc::matrix_copy(A);
    for (unsigned int i = 1; i < power; i++){
        Matrix mat_power_tmp = MatrixCalc::matrix_mult(A, mat_power);
        MatrixCalc::matrix_free(mat_power);
        mat_power = mat_power_tmp;
    }

    return mat_power;
}

