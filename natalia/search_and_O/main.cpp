#include <iostream>
#include <cstdlib>
#include <ctime>
#include "search_and_O.h"

int main() {
    int n = 5;
    int *array;
    array = new int [n];
   // srand(time(0)); //текущее системное время
    for (int i = 0; i < n; i++)
    {
        array[i] = n-i;
        //array[i] = rand()%100;
        std::cout << array[i] << ' ';
    }

    bubbleSort(array,n);
    std::cout << std::endl;
    for(int i = 0; i < n; i++)
        std::cout << array[i] << ' ';
    std::cout << std::endl;
    std::cout << linsearch(array, n, 4)<< std::endl;
    std::cout << binsearch(array, 0, n, 4);
    return 0;
}