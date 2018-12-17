//
// Created by vladburin on 24.09.18.
//

#define SIZE 100
#include "malloc.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include "Matrix/MatrixOperations.h"


void InsertionSort(int *Array, unsigned int Size) {

    for(unsigned int i=1; i<Size; i++)
    {
        int tmp=Array[i];
        int j = i-1;
        while (j >= 0 && Array[j] > Array[j + 1])
        {
            Array[j + 1]= Array[j + 1]^Array[j];
            Array[j] = Array[j + 1]^Array[j];
            Array[j + 1]= Array[j + 1]^Array[j];
            j--;
        }
    }
}


int main() {



/*
    double Data1[4] =
             {2,2,3,3};


     Matrix One={2,2,Data1};

     double Data2[3][3] = {
             {5,1,2},{1,4,1},{2,1,3}
     };

     Matrix Two={3,3,*Data2};

     Matrix C=matrix_rand(3,3);


     matrix_print(C);




for(int N=10000;N<100001;N=N+10000)*/

int N=66060;
srand(time(NULL)-clock());
int *Array=(int*)malloc(N*sizeof(int));
for(int i=0;i<N;i++)
{
    Array[i]=-rand()%100;
    if(rand()%2)
    {
        Array[i]=-Array[i];
    }
}

double Begin1=clock();
double Begin=time(NULL);
InsertionSort(Array, N);
double End=time(NULL);
double End1=clock();


printf("N = %d    Time = %lf   Clock = %lf\n",N, (End-Begin),(End1-Begin1)/CLOCKS_PER_SEC);
free(Array);



/*

srand(clock());

    unsigned int N = 40000;

    int *Array = (int*)malloc(N*sizeof(int));

    for (unsigned int i = 0; i < N; i++) {
        Array[i] =rand()%100;
        if (rand() % 2) {
            Array[i] = -Array[i];
        }
    }

//Вывод значений алгоритма изначального
    printf("---------------------------------------------------------------\n");

    printf(" Insert sorting method \n");
    for (unsigned i = 0; i < N; i++) {
        printf(" %d", Array[i]);
    }

double Begin=time(NULL);

 InsertionSort(Array, N);

 double End=time(NULL);


//Вывод отсортированного
    printf("\n\n");
    for (unsigned i = 0; i < N; i++) {
        printf(" %d", Array[i]);
    }
    printf("\n\n%lf",End-Begin);

    free(Array);


*/

    return 0;

}
