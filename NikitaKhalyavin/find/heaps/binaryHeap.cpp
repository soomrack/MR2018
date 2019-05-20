//
// Created by work on 20.05.2019.
//

#include "binaryHeap.h"

#define DEBUG 1


void binaryHeap::sift_down(Node * start) {
    Node * next = nullptr;
    if(start->rightChild->key > start->leftChild->key) {
        if (start->key < start->rightChild->key) {
            start->swap(&start->rightChild);
            next = start->rightChild;
        }
    }
    else {
        if (start->key < start->leftChild->key) {
            start->swap(&start->leftChild);
            next = start->leftChild;
        }
    }
    if(next != nullptr) {
        sift_down(next);
    }
}

void binaryHeap::sift_up(Node * start) {

    List<void *> nodes = visiting();
    int i;
    for(i = 0; i < nodes.getSize(); i++) {
        if(nodes.getItem(i) == (void *)start) break;
    }
    if(i == nodes.getSize()) {
#if DEBUG == 1
      printf("error: there aren't node in heap");
      exit(1);
#endif
    }
    int parent = i;
    while(parent != 0) {
        parent = parent / 2;
        if(start->key > ((Node *)nodes.getItem(parent))->key ) {
            start->swap((Node *) nodes.getItem(parent));
            start = (Node *) nodes.getItem(parent);
        }
    }


}


List<void *>  binaryHeap::visiting() {

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
            out.add( ((void *)(temp->rightChild));
        }
    }
    return out;
}

void * binaryHeap::extract() {
    return root->data;
}

void binaryHeap::add(void * data, int key) {

}