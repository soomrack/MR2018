//
// Created by work on 01.04.2019.
//

#ifndef MR2018_RBTREE_H
#define MR2018_RBTREE_H

#endif //MR2018_RBTREE_H

#include "treesParent.h"

enum color {RED, BLACK};

typedef struct {
    void * data;
    unsigned int key;
    void * leftChild;
    void * rightChild;
    color type;
}RBTreeNode;



class RBTree : public Tree {

private:

    void delete_all_branch(RBTreeNode * root);
    void add_to_tree(RBTreeNode * newUnit, RBTreeNode * root);
    void * recursion_for_search(RBTreeNode * root, unsigned int key);
    RBTreeNode * recursion_for_search_parent(RBTreeNode * root, unsigned int key);

public:
    RBTree() {
        root = NULL;
    }

    void add(unsigned int key, void * data);

    List<void *> visiting1();
    List<void *> visiting2();

    void * search(unsigned int key) {
        return recursion_for_search((RBTreeNode *)root, key);
    }

    void remove(unsigned int key);
};