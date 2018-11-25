//
// Created by vladburin on 24.09.18.
//

#define SIZE 100
#include "malloc.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include "Matrix/MatrixOperations.h"

int comp;

void InsertionSort(int *Array, int Size) {

    for(int i=1;i<Size;i++) {
        int tmp = Array[i];
        int j = i - 1;
        while (j >= 0 && Array[j] > tmp) {
            comp++;
            Array[j + 1] = Array[j];
            Array[j] = tmp;
            j--;
        }
    }
}


int main() {
     double Data1[4] =
             {2,2,3,3};


     Matrix One={2,2,Data1};

     double Data2[3][3] = {
             {5,1,2},{1,4,1},{2,1,3}
     };

     Matrix Two={3,3,*Data2};
    double lim=matrix_eigen_values(Two);

     Matrix C=matrix_power(Two,3);


     matrix_print(C);





/*
for(int N=100;N<100000;N=N*2)
{
    srand(time(NULL));
int *Array=(int*)malloc(N*sizeof(int));
for(int i=0;i<N;i++)
{
    Array[i]=-rand()%100;
    if(rand()%2)
    {
        Array[i]=-Array[i];
    }
}
comp=0;
InsertionSort(Array, N);
printf("N = %d    Comp = %d \n",N,comp);
free(Array);
}



    int N = 5;

    int *Array = (int*)malloc(N*sizeof(int));
    for (int i = 0; i < N; i++) {
        Array[i] =rand()%100;
        if (rand() % 2) {
            Array[i] = -Array[i];
        }
    }



//Вывод значений алгоритма изначального
    printf("---------------------------------------------------------------\n");
    printf(" Insert sorting method \n");
    for (int i = 0; i < N; i++) {
        printf(" %d", Array[i]);
    }

 InsertionSort(Array, N);
//Вывод отсортированного
    printf("\n\n");
    for (int i = 0; i < N; i++) {
        printf(" %d", Array[i]);
    }
    printf("\n\n");

    free(Array);
    */
    return 0;

}
