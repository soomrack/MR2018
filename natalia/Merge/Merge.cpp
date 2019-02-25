//
// Created by natas on 18.02.2019.
//

#include "Merge.h"
#include <iostream>


void MergeSort (int *arr, int begin, int end) {
    if (begin < end)
    {
        MergeSort(arr, begin, (begin+end)/2);//сортировка левой части
        MergeSort(arr, (begin+end)/2+1, end); //сортировка правой части
        Merge(arr, begin, end); //слияние двух частей
    }
}


void Merge(int *arr, int begin, int end) {
    int middle = (begin + end)/2;
    int start = begin;
    int final = middle+1;
    int *buf = new int[end+1];
    for (int i = begin; i<=end; i++) {
        if ((start<= middle) && ((final>end) || (arr[start] < arr[final]))) {
            buf[i] = arr[start];
            start++;
        }
        else {
            buf[i] = arr[final];
            final++;
        }
    }
    for (int i = begin; i<=end; i++) {
        arr[i] = buf[i];
    }
    delete[] buf;
}



void swap(int *arr, int first_index, int second_index) {
    int temp = arr[first_index];
    arr[first_index] = arr[second_index];
    arr[second_index] = temp;
}

void Insert(int* arr, int size) {
    int item;
    int place;
    for (int i = 1; i < size; i++)
    {
        item = arr[i];
        place = i - 1;
        while(place >= 0 && arr[place] > item)
        {
            arr[place+1] = arr[place];
            place --;
        }
        arr[place+1] = item;
    }
}








/*void TimSort(int* arr, int n) {
    for (int i = 0; i < n; i+=48)
        Insert(arr, i, __min((i+48),(n-1)));
    for (int size = 48; size < n; size = 2*size)
    {
        // pick starting point of left sub array. We
        // are going to merge arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we increase left by 2*size
        for (int left = 0; left < n; left += 2*size)
        {
            // find ending point of left sub array
            // mid+1 is starting point of right sub array
            int mid = left + size - 1;
            int right = __min((left + 2*size - 1), (n-1));
            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
            MergeSort(arr, left, right);
        }
    }

}

*/



void TimSort(int* arr, int size) {
    int index = 0;
    int begin = index;
    while (index<size) {
        int end = begin;
        end ++;
        if (arr[begin] > arr[end]) {
            swap( arr, arr[begin], arr[end]);
        }
        bool sorted = true;
        while(sorted) {
            end++;
            sorted = arr[end] > arr[end - 1] ? true : false;
        }
        if ((end-begin)<48) {
            end = __min(begin+48, size);
        }
        Merge(arr, begin,end);
        begin ++;
    }

}
/*

int Heap(int *arr, int size) { //O(n^2)
    int end = size-1;
    for(int begin = 0; begin < size - 1; begin++) {
        make_heap(arr, begin, end);

    }

}


int Heap_2(int *arr, int size, int root = 0) {
    if (root>=size) return;
    if (2root >= size) return;
    if (2root+1 >= size) return;
    //
    if (arr[2*root] < arr[2*root+1]) {
        swap(arr, arr[2*root], arr[2*root+1]);
        update_heap(arr, size, 2*root+1);
    }
}

int update_heap(int *arr, int size, int root)  {
    if(2*root>=size) return;
    if (2*root>=size-1) {
        if (arr[root]<arr[2*root]) {
            swap(arr[root], arr[2*root]);
            return;
        }
        if (arr[root]<arr[2*root]) {
            swap(arr[root], arr[2*root]);
            return;
        }
        //тут что-тооо происходит
    }
}

int Create_Heap(int* arr, int size, int root) {
    for (root=size - 1; root > 0 ; root --) {
        update_heap(arr, size, root);
    }


}*/
