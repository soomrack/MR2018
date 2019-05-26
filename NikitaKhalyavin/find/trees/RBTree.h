//
// Created by work on 01.04.2019.
//

#ifndef MR2018_RBTREE_H
#define MR2018_RBTREE_H

#endif //MR2018_RBTREE_H

#include "binaryTree.h"

enum color {RED, BLACK};

struct RBNode : binaryTreeNode {

    color type;
};


class RBTree : public binaryTree {

protected:

    typedef RBNode Node;

private:

    void add_to_tree(Node * newUnit, Node * root);

public:
    RBTree() {
        root = nullptr;
    }

    void add(unsigned int key, void * data) final;

    void remove(unsigned int key) final;
};