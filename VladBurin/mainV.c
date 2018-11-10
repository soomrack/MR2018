//
// Created by vladburin on 24.09.18.
//

#define SIZE 50

#include <time.h>
#include <stdio.h>
#include <stdlib.h>




int *Sorting(int *Array) {

    for(int i=1;i<SIZE;i++) {
        int tmp;
        for (int j = i; j > 0 && Array[j - 1] > Array[j]; j--) {
            int tmp = Array[j - 1];
            Array[j - 1] = Array[j];
            Array[j] = tmp;
        }
    }
    return Array;
}

int *SortingWithBinarySearch(int *Array) {

    for(int i=1;i<SIZE;i++) {
        int tmp;
        for (int j = i; j > 0 && Array[j - 1] > Array[j]; j--) {
            int tmp = Array[j - 1];
            Array[j - 1] = Array[j];
            Array[j] = tmp;
        }
    }
    return Array;
}



void main()
{

srand(42);

int Array[SIZE];


for(int i=0;i<SIZE;i++)
{
    Array[i]=-rand()%100;
}

//Вывод значений алгоритма изначального
printf("---------------------------------------------------------------\n");
printf(" Метод сортировки вставками \n");
for(int i=0;i<SIZE;i++)
{
    printf(" %d",Array[i]);
}

double BeginTime=clock();
Sorting(Array);
double EndTime=clock();

//Вывод отсортированного
printf("\n\n");
for(int i=0;i<SIZE;i++)
{
    printf(" %d",Array[i]);
}
printf("\n\n");
printf(" Время работы: %lf\n",EndTime-BeginTime);
printf("---------------------------------------------------------------\n");
}

