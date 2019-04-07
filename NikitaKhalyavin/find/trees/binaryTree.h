//
// Created by work on 01.04.2019.
//

#ifndef MR2018_BINARYTREE_H
#define MR2018_BINARYTREE_H

#endif //MR2018_BINARYTREE_H


#include "treesParent.h"


struct binaryTreeNode{
    void * data;
    unsigned int key;
    void * leftChild;
    void * rightChild;
};


class binaryTree : public Tree {

protected:

    typedef binaryTreeNode Node;

    void delete_all_branch(Node * root);
    void * recursion_for_search(Node * root, unsigned int key);
    void * recursion_for_search_parent(Node * root, unsigned int key);


private:

    void add_to_tree(Node * newUnit, Node * root);

public:
    binaryTree() {
        root = NULL;
    }

    void add(unsigned int key, void * data);

    List<void *> visiting1();
    List<void *> visiting2();

    void * search(unsigned int key) {
        return recursion_for_search((Node *)root, key);
    }

    void remove(unsigned int key);
};