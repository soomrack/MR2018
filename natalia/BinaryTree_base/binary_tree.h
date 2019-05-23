//
// Created by natas on 04.05.2019.
//

#ifndef BINARYTREE_BASE_BINARY_TREE_H
#define BINARYTREE_BASE_BINARY_TREE_H

#include "base_tree.h"
#include <iostream>
#include <iomanip>


class binary_tree: public base_tree {

private:
    void insert(node *leaf, int pkey, void* pdata);
    void preOrder(int pkey, node*leaf);
    void inOrder(int pkey, node * leaf);
    void postOrder(int pkey, node * leaf);
    void widthOrder(int pkey, node* leaf);

public:
    /*binary_tree();
    ~binary_tree();*/
    void insert(int key, void* data);
    bool delete_node(int pkey);
    void preOrder(int pkey);
    void inOrder(int pkey);
    void postOrder(int pkey);
    void widthOrder(int pkey);

};






#endif //BINARYTREE_BASE_BINARY_TREE_H
