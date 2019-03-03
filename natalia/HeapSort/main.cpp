#include "Heap.h"
#include <iostream>

int main() {
    int size = 8;
    int arr[8] = {4, 5, 1, 9, 2, 1, 0, -2};
    HeapSort(arr, size);

    for(int i=0; i< size; i++) {
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;
    int arr1[8] = {4, 5, 1, 9, 2, 1, 0, -2};
    std::cout << getK(arr, 8, 7);
    std::cout << std::endl;
    return 0;
}