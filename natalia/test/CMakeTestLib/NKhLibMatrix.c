//
// Created by work on 08.10.2018.
//

#include "NKhLibMatrix.h"

int MatrixMultiplexing(int* matrix1, int len1, int hig1, int* matrix2, int len2, int hig2, int* out){
    if(hig1 != len2) return 1;
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < hig1; j++){

            out[i * hig2 + j] = 0;
            for(int k = 0; k < len2; k++) out[i * hig2 + j] += matrix1[i * hig1 + k] * matrix2[k * len2 + j];

        }
    }
    return 0;
}
