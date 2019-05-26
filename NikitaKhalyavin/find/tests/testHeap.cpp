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
    for(int i = 9; i >=0; i--) {
        int out = *(int *)(heap1.extract());
        if(out != i)
            return 4;
    }

    for(int i = 0; i < 10; i++) {
        heap1.add((void *)(&data[i]), i);
    }
    if(  *(int *)(heap1.extract_by_key(9)) != 9 ) return(1);
    if(  (heap1.extract_by_key(9)) != nullptr ) return(2);
    for(int i = 8; i >=0; i--) {
        int out = *(int *)(heap1.extract());
        if(out != i)
            return 3;
    }
    return 0;
}