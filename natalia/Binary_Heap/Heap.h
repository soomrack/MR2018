//
// Created by natas on 27.05.2019.
//
#include "stdlib.h"
#ifndef BINARY_HEAP_HEAP_H
#define BINARY_HEAP_HEAP_H

typedef struct {
    void * data;
    int key;
} ITEM;

class HEAP {
private:
    void heapify(int i);
    void * search(int i, int key);
public:
    ITEM *h;
    int size;
    void insert(ITEM x);
    void outHeap(void);
    HEAP(unsigned int n);
    ~HEAP();
    void * search(int key);
};



#endif //BINARY_HEAP_HEAP_H
