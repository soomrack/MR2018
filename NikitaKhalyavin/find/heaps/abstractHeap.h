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

    abstractNode (void * data, int key) {
        this->key = key;
        this->data = data;
        leftChild = nullptr;
        rightChild = nullptr;
    }

    void Swap(abstractNode * input) {
        int temp = key;
        key = input->key;
        input->key = temp;
        void * temp2 = data;
        data = input->data;
        input->data = temp2;
    }
};

class abstractHeap {
protected:
    typedef abstractNode Node;
    Node * root;
    unsigned int size;
public:
    virtual void add(void * data, int key) = 0;
    virtual void * extract() = 0;
};