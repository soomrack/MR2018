//
// Created by natas on 04.05.2019.
//

#ifndef BINARYTREE_BASE_BINARYTREE_BASE_H
#define BINARYTREE_BASE_BINARYTREE_BASE_H
;

#include <iostream>
#include <iomanip>

struct base_node{
    int key;
    void* data;
    base_node *left;
    base_node *right;
};


class base_tree{
protected:
    base_node * root;
    typedef base_node node;
    void destroy_tree(node *leaf);
    void *search(int key, node *leaf);
    node* search_leaf(int pkey, node* leaf);
    void insert(node *leaf, int pkey, void* pdata);
public:
    base_tree();
    ~base_tree();
    void insert(int key, void* data);
    void* search(int key);
    bool delete_node(int pkey);
    void destroy_tree();
};


class Queue: public base_tree {
protected:
    static const int SIZE=100;
    int head;
    int tail;
    node *queue;
public :
    Queue () ;
    ~Queue();
    void push ( node data );
    node pop();
    bool isempty();

} ;
















#endif //BINARYTREE_BASE_BINARYTREE_BASE_H
