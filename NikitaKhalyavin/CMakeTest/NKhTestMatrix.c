//
// Created by work on 08.10.2018.
//

#include <stdio.h>
#include "../CMakeTestLib/NKhLibMatrix.h"

int main(){
    int Matrix1[3][5] = {
            {1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
    };
    int Matrix2[5][2] = {
            {1, 0},
            {0, 0},
            {1, 0},
            {0, 0},
            {0, 0}
    };
    int Matrix3[3][2];
    if(!MatrixMultiplexing(&Matrix1[0][0], 3, 5, &Matrix2[0][0], 5, 2, &Matrix3[0][0])) {
        printf("%d", Matrix3[0][0]);
        return 0;
    }
    else return 1;
}