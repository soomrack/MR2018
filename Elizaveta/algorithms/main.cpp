
#include "lib.h"
#include <iostream>
#include <cstdlib>

int main() {
    //int arr[23] = {2, 5, 8, 1, 0, 3, 5, 6, 8, 5, 7, 1, 3, 6, 9, 2, 4, 3, 7, 5, 6, 9, 4};
    //int arr[23] = {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2};
    int arr[23] = {7,9,1,3,4,6,8,5,2,6,1,3,7,2,4,9,8,5,7,5,8,6,1};

    print_array(arr,23);

    /*int index = linear_search(1,arr,5);
    std::cout<<index<<std::endl;

    bubble_sort(arr,5);
    print_array(arr,5);

    index = binary_search(2,arr,5);
    std::cout<<index<<std::endl;

    element_replacement(3,arr,5);
    print_array(arr,5);

    element_replacement(5,arr,5);
    print_array(arr,5);


    element_replacement(8,arr,5);
    print_array(arr,5);*/

    //MergeSort(arr, 0, 23);
    //InsertSort(arr, 0, 23);
    //Timsort(arr, 23);
    //HeapSort(arr, 23);
    print_array(arr, 23);




    return 0;
}