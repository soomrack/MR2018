#include <iostream>
#include <cstdlib>
#include <ctime>

void swap(int *arr, int first_index, int second_index) {
    int temp = arr[ first_index ];
    arr[ first_index ] = arr[ second_index ];
    arr[ second_index ] = temp;
}

void bubbleSort(int *arr, int m){
    for(int i = m - 1; i >= 1; i--)
        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[j+1])
            {
               swap(arr, j, j+1);
            }
        }


}

int main() {
    int n = 5;
    int *array;
    array = new int [n];
    srand(time(0)); //текущее системное время
    for (int i = 0; i < n; i++)
    {
        array[i] = rand()%100;
        std::cout << array[i] << ' ';
    }
    bubbleSort(array,n);
    std::cout << std::endl;
    for(int i = 0; i < n; i++)
        std::cout << array[i] << ' ';
    return 0;
}