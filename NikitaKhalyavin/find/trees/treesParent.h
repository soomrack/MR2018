//
// Created by work on 01.04.2019.
//

#ifndef MR2018_TREESPARENT_H
#define MR2018_TREESPARENT_H

#endif //MR2018_TREESPARENT_H

#include "../structs.h"



class Tree {
protected:
    void * root;
public:
    virtual void add(unsigned int key, void * data) = 0;
    virtual void * search(unsigned int key) = 0;
    virtual void remove(unsigned int key) = 0;
    virtual List<void *> visiting1() = 0;
    virtual List<void *> visiting2() = 0;
    virtual List<void *> visiting3() = 0;

};