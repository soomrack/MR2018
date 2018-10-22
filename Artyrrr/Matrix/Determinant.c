#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern double matrix_determinant(const Matrix A){
        if(A.cols != A.rows)exit(1);
        if(A.cols == 1) return A.data[0];
        if(A.cols < 1) exit(1);

        Matrix Temp;
        Temp.cols = A.cols - 1;
        Temp.rows = A.rows - 1;
        Temp.data = malloc(Temp.cols * Temp.rows * sizeof(double));
        int row = 0;
        double det = 0;
        int sign;
        for(int col = 0; col < A.cols; col++){
                for(int i = 0; i < Temp.rows; i++){
                        for(int j = 0; j < Temp.cols; j++){
                                if((i <  row) && (j <  col))  Temp.data[j + ( i * Temp.cols)] = A.data[j + ( i * A.cols)];
                                if((i <  row) && (j >= col))  Temp.data[j + ( i * Temp.cols)] = A.data[(j + 1) + ( i * A.cols)];
                                if((i >= row) && (j <  col))  Temp.data[j + ( i * Temp.cols)] = A.data[j + ( (i + 1) * A.cols)];
                                if((i >= row) && (j >= col))  Temp.data[j + ( i * Temp.cols)] = A.data[(j + 1) + ( (i + 1) * A.cols)];
                        }
                }
                if(col % 2) sign = -1;
                else sign = 1;
                det += matrix_determinant(Temp)*A.data[col]*sign;
        }
        return det;
}