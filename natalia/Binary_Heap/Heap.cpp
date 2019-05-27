//
// Created by natas on 27.05.2019.
//

#include "Heap.h"

#include "Heap.h"
#include <iostream>

HEAP::HEAP(unsigned int n) {
    size = 0;
    h = (ITEM*) malloc( sizeof(ITEM) * n);
}

HEAP::~HEAP() {
    if(h) free(h);
}

void HEAP::insert(ITEM x) {
    h[size]=x;
    size++;
    heapify(0);
    return;
}

void HEAP:: heapify(int i) {
    int left, right;
    ITEM temp;
    left = 2*i+1;
    right = 2*i+2;
    if(left < size) {
        if(h[i].key < h[left].key) {
            temp.key = h[i].key;
            temp.data = h[i].data;
            h[i] = h[left];
            h[left].key = temp.key;
            h[left].data = temp.data;
            heapify(left);
        }
    }
    if(right < size) {
        if(h[i].key < h[right].key) {
            temp.key = h[i].key;
            temp.data = h[i].data;
            h[i] = h[right];
            h[right].key = temp.key;
            h[right].data = temp.data;
            heapify(right);
        }
    }
}

void HEAP:: outHeap(void) {
    int i = 0;
    int k = 1;
    while(i < size) {
        while((i < k) && (i < size)) {
            std::cout<< h[i].key << " ";
            i++;
        }
        std::cout << std::endl;
        k = k * 2 + 1;
    }
}

void * HEAP:: search(int i, int key){
    int left, right;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (h[i].key == key) {
        std::cout << key << " найден "<< std::endl;
        return h[i].data;

    }
    if (h[i].key > key || i>=size) {
        //std::cout << key << " не найден ";
        return NULL;
    } else {
        void* res = search(left, key);
        if (res == NULL)
            return search(right, key);
        else return res;
    }

}

void * HEAP:: search(int key){
    return search(0, key);
}

