//
// Created by work on 20.05.2019.
//

#ifndef MR2018_ABSTRACTHEAP_H
#define MR2018_ABSTRACTHEAP_H

#endif //MR2018_ABSTRACTHEAP_H

class abstractNode {
public:
    int key;
    void * data;
    abstractNode * leftChild;
    abstractNode * rightChild;

    abstractNode () {
        key = 0;
        data = nullptr;
        leftChild = nullptr;
        rightChild = nullptr;
    }

    void swap(abstractNode * input) {
        swap(key, input->key);
        swap(data, input->data);
    }
};

class abstractHeap {
protected:
    typedef abstractNode Node;
    Node * root;
public:
    virtual void add(void * data, int key) = 0;
    virtual void * extract() = 0;
};