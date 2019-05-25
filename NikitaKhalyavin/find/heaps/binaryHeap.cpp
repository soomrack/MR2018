//
// Created by work on 20.05.2019.
//

#include "binaryHeap.h"

#define DEBUG 1

static int power(int a, int b) {
    int out = 1;
    for(int i = 0; i < b; i ++) {
        out *= a;
    }
    return out;
}

static int log(int input) {
    int out = 0;
    while(input > 1) {
        input /= 2;
        out++;
    }
    return out;
}


void binaryHeap :: sift_down(Node * start) {

    Node * next = start;

    if(start->rightChild != nullptr) {
        if(start->rightChild->key > next->key) {
            next = start->rightChild;
        }
    }
    if(start->leftChild != nullptr) {
        if(start->leftChild->key > next->key) {
            next = start->leftChild;
        }
    }

    if(next != start) {
        next->Swap(start);
        sift_down(next);
    }
}

void binaryHeap :: sift_up(int startNumber) {

    int parent = startNumber / 2;

    Node * Current = (Node *)getItem(startNumber);
    Node * Parent = (Node *)getItem(parent);
    if(Current->key > Parent->key ) {
        Current->Swap(Parent);
        sift_up(parent);
    }
}




void binaryHeap::add(void * data, int key) {
    size++;
    if(size == 1) {
        root = new abstractNode(data, key);
        return;
    }

    Node * parent = (Node*) getItem( (size - 2) / 2 );

    if( (size - 1) % 2 ) {
        parent->leftChild = new abstractNode(data, key);
    }
    else {
        parent->rightChild = new abstractNode(data, key);
    }

    sift_up(size - 1);

}


void * binaryHeap :: getItem(int number) {
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
    return (void *)place;
}


void * binaryHeap :: extract() {

    Node * last = (Node *)getItem(size - 1);
    Node * parentOfLast = (Node *)getItem( (size - 2) / 2);
    void * out = root->data;

    root->Swap(last);
    delete last;
    if( (size - 1) % 2) {
        parentOfLast->leftChild = nullptr;
    }
    else {
        parentOfLast->rightChild = nullptr;
    }
    size--;

    if(size > 0) {
        sift_down(root);
    }
    return out;
}