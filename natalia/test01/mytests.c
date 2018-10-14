

#include <stdio.h>
#include "library.h"

#define N 2

int main(void){


    int result[N][N]={{5,4},{4,5}};
    int X[2][2]={{1,2},{2,1}};
    int Y[2][2]={{1,2},{2,1}};
    int rez[2][2] = {{0,0},{0,0}};
    multiplication(*X, *Y, *rez);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (result [i][j] == rez[i][j]){
                continue;
            }
            else {
                return 1;
            }
        }
    }

    return 0;


}
