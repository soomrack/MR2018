//
// Created by work on 20.05.2019.
//

#include "binaryHeap.h"

#define DEBUG 1


void binaryHeap :: sift_down(Node * start) {
    Node * next = nullptr;
    if(start->rightChild->key > start->leftChild->key) {
        if (start->key < start->rightChild->key) {
            start->Swap(start->rightChild);
            next = start->rightChild;
        }
    }
    else {
        if (start->key < start->leftChild->key) {
            start->Swap(start->leftChild);
            next = start->leftChild;
        }
    }
    if(next != nullptr) {
        sift_down(next);
    }
}

void binaryHeap :: sift_up(int startNumber) {

    int parent = startNumber / 2;

    Node * Current = getItem(startNumber);
    Node * Parent = getItem(parent);
    if(Current->key > Parent->key ) {
        Current->Swap(Parent);
        sift_up(parent);
    }
}


List<void *>  binaryHeap :: visiting() {

    Queue<Node *> Queue;
    List<void *> out;

    Queue.enqueue((Node *)root);
    out.add(((Node *)root)->data);


    while(Queue.getSize() > 0) {
        Node * temp = Queue.dequeue();
        if(temp->leftChild != NULL) {
            Queue.enqueue( (Node *)(temp->leftChild) );
            out.add( (void *)(temp->leftChild));
        }
        if(temp->rightChild != NULL) {
            Queue.enqueue((Node *)(temp->rightChild));
            out.add( (void *)(temp->rightChild) );
        }
    }
    return out;
}

void * binaryHeap :: extract() {
    void * out = root->data;
    Node * left = root->leftChild;
    Node * right = root->rightChild;
    delete root;

    root = left;
    merge(root, right);

    return out;
}


void binaryHeap :: merge(Node * currentRoot, Node * newRoot) {

    if (currentRoot->key < newRoot->key) {
        currentRoot->Swap(newRoot);
    }
    if ( (currentRoot->rightChild != nullptr) && (currentRoot->leftChild != nullptr) )
    if (currentRoot->rightChild->key > currentRoot->leftChild->key) {
        currentRoot = currentRoot->leftChild;
    }
    else {
        currentRoot = currentRoot->rightChild;
    }

    merge(currentRoot, newRoot);
}


void binaryHeap::add(void * data, int key) {
    size++;
    if(size == 1) {
        root = new abstractNode(data, key);
        return;
    }

    int high = log(size);
    int leftBord = power(2, high) - 1;
    int rightBord = leftBord * 2;
    Node * parent;
    Node * place = root;

    while(1) {
        int half = (leftBord + rightBord) / 2;
        if (size - 1 <= half) {
            rightBord = half;
            parent = place;
            place = parent->leftChild;
            if(place == nullptr)
            {
                parent->leftChild = new abstractNode(data, key);
                break;
            }
        }
        else {
            leftBord = half + 1;
            parent = place;
            place = parent->rightChild;
            if(place == nullptr)
            {
                parent->rightChild = new abstractNode(data, key);
                break;
            }
        }
    }

    sift_up(size - 1);

}