#include <stdio.h>
#include "matrix.h"
#include "stdlib.h"
#include "time.h"

extern Matrix matrix_zero(const unsigned int rows, const unsigned int cols) {
    Matrix ext3;
    ext3.rows=rows;
    ext3.cols=cols;
    ext3.data=malloc(ext3.cols*ext3.rows*sizeof(double));
    for(unsigned int i=0;i<ext3.rows;i++) {
        for(unsigned int j=0;j<ext3.cols;j++) {
            ext3.data[j+i*ext3.cols]=0;
        }
    }
    return ext3;
}


