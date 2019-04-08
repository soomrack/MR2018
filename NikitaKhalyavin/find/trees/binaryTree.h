//
// Created by work on 01.04.2019.
//

#ifndef MR2018_BINARYTREE_H
#define MR2018_BINARYTREE_H

#endif //MR2018_BINARYTREE_H


#include "treesParent.h"


typedef struct {
    void * data;
    unsigned int key;
    void * leftChild;
    void * rightChild;
}binaryTreeNode;



class binaryTree : public Tree {

private:

    void delete_all_branch(binaryTreeNode * root);
    void add_to_tree(binaryTreeNode * newUnit, binaryTreeNode * root);
    void * recursion_for_search(binaryTreeNode * root, unsigned int key);
    binaryTreeNode * recursion_for_search_parent(binaryTreeNode * root, unsigned int key);

public:
    binaryTree() {
        root = NULL;
    }

    void add(unsigned int key, void * data);

    List<void *> visiting1();
    List<void *> visiting2();

    void * search(unsigned int key) {
        return recursion_for_search((binaryTreeNode *)root, key);
    }

    void remove(unsigned int key);
};