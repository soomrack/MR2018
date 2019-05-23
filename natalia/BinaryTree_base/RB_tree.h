//
// Created by natas on 05.05.2019.
//

#ifndef BINARYTREE_BASE_RB_TREE_H
#define BINARYTREE_BASE_RB_TREE_H

#include "base_tree.h"
#include "binary_tree.h"

#define RED 1
#define BLACK 0

struct RB_node : base_node {
    //RB_node *left;
    //RB_node *right;
    bool color;
};


class RB_Tree : public binary_tree {

protected:
    RB_node * root;
    typedef RB_node Node;

private:
    void insert(RB_node *leaf, int pkey, void* pdata);
    Node * parent(Node * child, Node* root );
    Node * grandparent(Node * child, Node * root);
    Node * uncle(Node * child, Node *root);
    void insert1(Node * leaf, Node * root);
    void insert2(Node * leaf, Node * root);
    void insert3(int key, void* data);
    void insert4(int key, void* data);
    void insert5(int key, void* data);
public:
    RB_Tree() {
        root = NULL;
    }
    void add_to_tree(int key, void* data);

    bool delete_node(int pkey);


};










#endif //BINARYTREE_BASE_RB_TREE_H
