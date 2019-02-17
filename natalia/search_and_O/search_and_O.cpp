#include <iostream>
#include <cstdlib>

void swap(int *arr, int first_index, int second_index) {
    int temp = arr[first_index];
    arr[first_index] = arr[second_index];
    arr[second_index] = temp;
}

void bubbleSort(int *arr, int n){
    for(int i = n - 1; i >= 1; i--)
        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr, j, j+1);
            }
        }
}



int linsearch (int *arr, int n, int x) {
    int k;
    for (k=0; k<n ; k++) {
        if (arr[k] == x) break;
        else if (k == n-1) {
            std::cout << "Can't find ";
            return x;
        }
    }
    return k;
}


int binsearch ( int *arr, int begin, int n, int x ) {
    int end = n;
    if (begin >= end) {
        std::cout << "Can't find ";
        return x;
    }
    int center = (int) (end+begin)/2;
        if (x == arr[center]) {
            return center;
        }
        if (x < arr[center])
            end = center;
        else {
            begin = center + 1;
        }
        return binsearch(arr, begin, end, x);

}

void add (int *arr, int n, int x) {
    int k;
    for (k=0; k<n ; k++) {
        if ((arr[k] < x) && (arr[k+1]>=x)) {
            arr[k+1] = x;
            break;
        }
    }
}
