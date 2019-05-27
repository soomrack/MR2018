#include <iostream>
#include "Heap.h"

int main() {
    HEAP heap(1000);
    int size = 10;
    ITEM element;
    int Var = 1050;
    void *data = &Var;

    for(int i = 0; i < size; i++){
        element.key = i;
        element.data = data;
        heap.insert(element);
    }
    heap.outHeap();
    heap.search(5);
    return 0;
}