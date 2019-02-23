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

    Insert(arr, 5);
    for(int i = 0; i < 5; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    return 0;
}