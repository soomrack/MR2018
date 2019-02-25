#include <iostream>
#include "Merge.h"

int main() {
    int arr[5] = {4, 5, 1, 9, 2};
    for(int i = 0; i < 5; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    MergeSort(arr, 0, 5);
    for(int i = 0; i < 5; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
    int arr1[5] = {4, 5, 1, 9, 2};
    Insert(arr1, 5);
    for(int i = 0; i < 5; i++)
        std::cout << arr1[i] << ' ';
    std::cout << std::endl;
    int arr2[5] = {4, 5, 1, 9, 2};
    /*TimSort(arr2, 5);
    for(int i = 0; i < 5; i++)
        std::cout << arr2[i] << ' ';
    std::cout << std::endl;*/
    return 0;
}