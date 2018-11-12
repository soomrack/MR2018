#include <stdio.h>
#include "matrix.h"
#include "stdlib.h"
#include "time.h"
extern Matrix matrix_rand(const unsigned int rows, const unsigned int cols)
{
    Matrix ext2;
    srand(time(NULL));
    ext2.rows=rows;
    ext2.cols=cols;
    ext2.data=malloc(ext2.cols*ext2.rows*sizeof(double));
    for(unsigned int i=0;i<ext2.rows;i++)
    {
        for(unsigned int j=0;j<ext2.cols;j++)
        {
            ext2.data[i+j*ext2.cols]=(double)(-100+rand()%200)/100;
        }
    }
    return ext2;
}