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

    void * getItem(int number);
    List<int> visiting();

public:
    binaryHeap() {
        root = nullptr;
        size = 0;
    }

    void add(void * data, int key) override;

    void * extract() override;
    void * extract_by_key(int key) override;

};