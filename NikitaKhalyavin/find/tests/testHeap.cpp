//
// Created by Nikita on 25.05.2019.
//

#include "../heaps/binaryHeap.h"

int main() {

    int data[10] = {0,1,2,3,4,5,6,7,8,9};


    binaryHeap heap1;

    for(int i = 0; i < 10; i++) {
        heap1.add((void *)(&data[i]), i);
    }
    return 0;
}