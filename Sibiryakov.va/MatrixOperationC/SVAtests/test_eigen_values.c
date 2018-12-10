#include <stdio.h>
#include <math.h>
#include "../matrix.h"
#include <malloc.h>

int main() {
    double example1[3][3] = {{3.6, 6.4, 100.4},
                             {12.5, 20.8, 33.2},
                             {123.4, 11.56, 72.65}};
    Matrix example_one = {3,3,*example1};

    double result = matrix_eigen_values(example_one);
    printf("%lf\n",result);
    matrix_eigen_vectors(example_one);
    return 0;
}

