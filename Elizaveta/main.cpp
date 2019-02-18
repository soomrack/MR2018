
#include "lib.h"
#include <iostream>
#include <cstdlib>

int main() {
    int arr[5] = {2, 5, 8, 1, 0};

    print_array(arr,5);

    int index = linear_search(1,arr,5);
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
    print_array(arr,5);


    return 0;
}