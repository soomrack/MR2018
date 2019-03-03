//
// Created by natas on 02.03.2019.
//

#include "Heap.h"
#include <iostream>

void HeapSort(int* arr, int size) {
    Heap heap;
    int rez[size];
    for(int i = 0; i < size; i++) {
        heap.addelem(arr[i]);
    }
    heap.out();
    for (int i = size-1; i>=0; i--) {
        rez[i] = heap.getmax();

    }
    for(int i=0; i< size; i++) {
        arr[i] = rez[i];
    }

}


int getK(int* arr, int size, int k) { //поиск К-й порядковой статистики
    Heap heap;
    int rez;
    for(int i = 0; i < size; i++) {
        heap.addelem(arr[i]);
    }
    int i = size-1;
    while (i>=k) {
        heap.getmax();
        i--;
    }
    rez = heap.getmax();
    return rez;

}



Heap :: Heap() {
    h = new int[SIZE];
    HeapSize = 0;
}


void Heap :: addelem(int n) {
    int i, parent;
    i = HeapSize;
    h[i] = n;
    parent = (i-1)/2;
    while(parent >= 0 && i > 0)  {
        if(h[i] > h[parent]) {
            int temp = h[i];
            h[i] = h[parent];
            h[parent] = temp;
        }
        i = parent;
        parent = (i-1)/2;
    }
    HeapSize++;
}


void Heap:: out() {
    for(int i=0; i< HeapSize; i++) {
        std::cout << h[i] << ' ';
    }
    std::cout << std::endl;
}



void Heap:: heapify(int i) {
    int left, right;
    int temp;
    left = 2*i+1;
    right = 2*i+2;
    if(left < HeapSize) {
        if(h[i] < h[left]) {
            temp = h[i];
            h[i] = h[left];
            h[left] = temp;
            heapify(left);
        }
    }
    if(right < HeapSize) {
        if(h[i] < h[right]) {
            temp = h[i];
            h[i] = h[right];
            h[right] = temp;
            heapify(right);
        }
    }
}

int Heap:: getmax(void) {
    int x;
    x = h[0];
    h[0] = h[HeapSize-1];
    HeapSize--;
    heapify(0);
    return(x);
}