#include <stdio.h>

#include "matrix.h"

int main() {
    fprintf(stdout, "AUIXILARY ARRAYS:\n");

    double array1[1] = {1}; //det = 1
    Matrix mat1 = {1,1,array1};
    fprintf(stdout, "mat1: ");
    MatrixCalc::matrix_print(mat1);

    double array2[4] = {1,2,3,4}; //det = -2
    Matrix mat2 = {2,2,array2};
    fprintf(stdout, "mat2: ");
    MatrixCalc::matrix_print(mat2);

    //double array3[9] = {0,1,2,3,4,5,6,7,8};
    double array3[9] = {1,2,3,4,5,6,7,8,10}; //det = -3
    Matrix mat3 = {3,3,array3};
    fprintf(stdout, "mat3: ");
    MatrixCalc::matrix_print(mat3);

    //double array4[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,15,14,15};
    double array4[16] = {0,1,2,3,4,10,6,7,8,9,20,11,12,13,14,15}; //det = -1800
    Matrix mat4 = {4,4,array4};
    fprintf(stdout, "mat4: ");
    MatrixCalc::matrix_print(mat4);

    //~~~~~~~~~~~

    fprintf(stdout, "MATRIX GENERATORS:\n");

    Matrix ones = MatrixCalc::matrix_one(4);
    fprintf(stdout, "ones: ");
    MatrixCalc::matrix_print(ones);

    Matrix zero = MatrixCalc::matrix_zero(3, 5);
    fprintf(stdout, "zero: ");
    MatrixCalc::matrix_print(zero);

    Matrix random = MatrixCalc::matrix_rand(5,5);
    fprintf(stdout, "random: ");
    MatrixCalc::matrix_print(random);

    Matrix copy = MatrixCalc::matrix_copy(random);
    fprintf(stdout, "copy of random: ");
    MatrixCalc::matrix_print(copy);

    //~~~~~~~~~~~

    fprintf(stdout, "MATRIX TO DOUBLE:\n");

    double trace = MatrixCalc::matrix_trace(mat3);
    fprintf(stdout, "Trace if mat3: %.2f\n", trace);

    double det = MatrixCalc::matrix_determinant(mat1);
    fprintf(stdout, "Determinant of mat1: %.2f\n", det);
    det = MatrixCalc::matrix_determinant(mat2);
    fprintf(stdout, "Determinant of mat2: %.2f\n", det);
    det = MatrixCalc::matrix_determinant(mat3);
    fprintf(stdout, "Determinant of mat3: %.2f\n", det);
    det = MatrixCalc::matrix_determinant(mat4);
    fprintf(stdout, "Determinant of mat4: %.2f\n", det);

    //~~~~~~~~~~~

    fprintf(stdout, "MATRIX TO MATRIX:\n");

    Matrix sum = MatrixCalc::matrix_sum(mat3, mat3);
    fprintf(stdout, "Sum of mat3 and mat3: ");
    MatrixCalc::matrix_print(sum);

    Matrix mult = MatrixCalc::matrix_mult(mat2, mat2);
    fprintf(stdout, "Mult of mat2 and mat2: ");
    MatrixCalc::matrix_print(mult);
    mult = MatrixCalc::matrix_mult(mat3, mat3);
    fprintf(stdout, "Mult of mat3 and mat3: ");
    MatrixCalc::matrix_print(mult);

    Matrix mult_scalar = MatrixCalc::matrix_mult_scalar(0.1, mat3);
    fprintf(stdout, "Mult of mat3 and scalar 0.1: ");
    MatrixCalc::matrix_print(mult_scalar);

    Matrix trans = MatrixCalc::matrix_trans(mat4);
    fprintf(stdout, "mat4 transposed: ");
    MatrixCalc::matrix_print(trans);


    Matrix invert = MatrixCalc::matrix_invert(mat4);
    fprintf(stdout, "mat4 inverted: ");
    MatrixCalc::matrix_print(invert);
    Matrix mul = MatrixCalc::matrix_mult(mat4, invert);
    fprintf(stdout, "Mult of mat4 and mat4 inverted: ");
    MatrixCalc::matrix_print(mul);


    Matrix exp = MatrixCalc::matrix_exp(mat2);
    fprintf(stdout, "Matrix exp of mat2: ");
    MatrixCalc::matrix_print(exp);
    double exp_det = MatrixCalc::matrix_determinant(exp);
    fprintf(stdout, "Matrix exp of mat2 determinant: %.2f\n", exp_det);


    for (int i = 0; i < 4; i++){
        Matrix power = MatrixCalc::matrix_power(mat3, i);
        fprintf(stdout, "Matrix power %d of mat3: ", i);
        MatrixCalc::matrix_print(power);

    }


    return 0;
}