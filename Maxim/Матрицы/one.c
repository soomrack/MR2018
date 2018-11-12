#include <stdio.h>
#include "matrix.h"
#include "stdlib.h"
#include "time.h"

extern Matrix matrix_one(const unsigned int rows, const unsigned int cols){
    Matrix ext4;
    ext4.rows=rows;
    ext4.cols=cols;
    ext4.data=malloc(ext4.cols*ext4.rows*sizeof(double));
    for(unsigned int i=0;i<ext4.rows;i++) {
        for(unsigned int j=0;j<ext4.cols;j++) {
            if(i==j){
                ext4.data[j + i * ext4.cols] = 1;
            }
            else {
                ext4.data[j + i * ext4.cols] = 0;
            }
        }
    }
    return ext4;
}

