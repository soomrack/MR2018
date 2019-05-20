//
// Created by work on 20.05.2019.
//

#ifndef MR2018_BINARYHEAP_H
#define MR2018_BINARYHEAP_H

#endif //MR2018_BINARYHEAP_H

#include "abstractHeap.h"

class binaryHeap::abstractHeap {

protected:
    typedef abstractNode Node;

private:
    void sift_down(Node * start);
    void sift_up(Node * start) = 0;
    void merge(Node * currentRoot, Node * newRoot);
    List<void *>  visiting();

public:
    void add(void * data, int key);
    void * extract();

};