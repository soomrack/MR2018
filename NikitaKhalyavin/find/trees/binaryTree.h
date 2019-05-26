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


//version 4
class binaryTree : public Tree {

protected:

    typedef binaryTreeNode Node;

    void delete_all_branch(Node * root);
    void delete_node(unsigned int key, Node * item = nullptr);

    Stack<void *> search_node(unsigned int key, Node * item = nullptr);

private:

    void add_to_tree(Node * newUnit, Node * root);
    void * get_node_with_next_key(Node * root);

public:
    binaryTree() {
        root = NULL;
    }
    ~binaryTree() {
        delete_all_branch((Node *)root);
    }

    void add(unsigned int key, void * data);

    List<void *> visiting1();
    List<void *> visiting2();
    List<void *> visiting3();

    void * search(unsigned int key) {
        Stack<void *> wayToItem;
        wayToItem = search_node(key);
        Node * item = (Node *)wayToItem.pop();
        return item->data;
    }

    void remove(unsigned int key);
};

//version 3
/*
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
    ~binaryTree() {
        delete_all_branch((Node *)root);
    }

    void add(unsigned int key, void * data);

    List<void *> visiting1();
    List<void *> visiting2();
    List<void *> visiting3();

    void * search(unsigned int key) {
        return recursion_for_search((Node *)root, key);
    }

    void remove(unsigned int key);
};
 */