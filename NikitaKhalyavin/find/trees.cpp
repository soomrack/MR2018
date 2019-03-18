//
// Created by work on 03.03.2019.
//

#include "trees.h"

static binaryTreePoint * fiduciary = NULL;

void firstFiduciaryFind(binaryTreePoint * test) {
    if(fiduciary == NULL) {
        if(  !((test->hasRightChild) && (test->hasLeftChild)) )fiduciary = test;
    }
}

void binaryTreePoint::shelter(binaryTreePoint * heap) {
    fiduciary = NULL;
    heap->visiting1WithAction(firstFiduciaryFind);

    if(!fiduciary->hasLeftChild) {
        fiduciary->setLeftChild(this);
        return;
    }
    if(!fiduciary->hasRightChild) {
        fiduciary->setRightChild(this);
        return;
    }
    printf("Error: can't find fiduciary");
    exit(1);
}
