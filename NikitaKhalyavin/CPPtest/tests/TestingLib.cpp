//
// Created by work on 26.11.2018.
//

#include "TestingLib.h"

bool MatrixCompare(Matrix A, Matrix B){
    int returnCode = 0;
    int cols = A.getCols();
    int rows = A.getRows();
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            double temp = (A.data[row * cols + col] - B.data[row * cols + col]);
            returnCode += ((temp > PRECISION) || (temp < -PRECISION));
        }
    }
    if(returnCode)returnCode = 1;
    return (bool)returnCode;
}