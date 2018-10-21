#include <stdio.h>
#include "matrix.h"
#include "stdlib.h"
#include "time.h"
double trace(const Matrix A) {
    double trace=0;
    for(unsigned int i=0;i<A.rows;i++){
            trace+=A.data[i+i*A.cols];
    }
    printf("%s%.2lf","trace=",trace);
}
void print_matrix(const Matrix A) {
    for(unsigned int i=0;i<A.rows;i++){
        for(unsigned int j=0;j<A.cols;j++){
            printf("%10.2lf\t",A.data[j+i*A.cols]);
        }
        printf("%s","\n");
    }
}
int main() {
    Matrix A;
    srand(time(NULL));
    A.rows=3;
    A.cols=3;
    A.data=malloc(A.cols*A.rows*sizeof(double));
    for(unsigned int i=0;i<A.cols;i++) {
        for (unsigned int j = 0; j < A.rows; j++) {
            A.data[j+i*A.cols]=rand();
        }
    }
    print_matrix(A);
    trace(A);
    return 0;
}