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
    int arr2[20] = { 20, 19, 18, 17, 16 , 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    TimSort(arr2, 20);
    for(int i = 0; i < 20; i++)
        std::cout << arr2[i] << ' ';
    std::cout << std::endl;
    return 0;
}