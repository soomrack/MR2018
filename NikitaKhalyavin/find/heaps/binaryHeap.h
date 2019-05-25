//
// Created by work on 20.05.2019.
//

#ifndef MR2018_BINARYHEAP_H
#define MR2018_BINARYHEAP_H

#endif //MR2018_BINARYHEAP_H

#include "abstractHeap.h"
#include "../structs.h"

class binaryHeap : public abstractHeap {

protected:
    typedef abstractNode Node;

private:
    void sift_down(Node * start);
    void sift_up(int startNumber);
    void merge(Node * currentRoot, Node * newRoot);
    List<void *>  visiting();

    Node * getItem(int number) {
        int high = log(number + 1);
        int leftBord = power(2, high) - 1;
        int rightBord = leftBord * 2;
        Node * place = root;

        for(int i = 0; i < high; i++) {
            int half = (leftBord + rightBord) / 2;
            if (number <= half) {
                rightBord = half;
                place = place->leftChild;
            }
            else {
                leftBord = half + 1;
                place = place->rightChild;
            }
        }
        return place;
    }

    int power(int a, int b) {
        int out = 1;
        for(int i = 0; i < b; i ++) {
            out *= a;
        }
        return out;
    }

    int log(int input) {
        int out = 0;
        while(input > 1) {
            input /= 2;
            out++;
        }
        return out;
    }

public:
    binaryHeap() {
        root = nullptr;
        size = 0;
    }

    void add(void * data, int key);

    void * extract();

};