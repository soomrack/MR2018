#include <iostream>

#include "binary_tree.h"
#include "RB_tree.h"

using namespace std;

int main() {
    auto *tree = new binary_tree();
    void* data;
    int Var = 1050;
    data = &Var;
    /*tree->insert(10, data);
    int* n = (int*)tree->search(10);
    int rez = *n;*/
    // tree->insert(10, data);
    tree->insert(50, data);
    tree->insert(75, data);
    tree->insert(60, data);
    tree->insert(65, data);
    tree->insert(80, data);
    tree->insert(85, data);
    tree->insert(25, data);
    tree->insert(40, data);
    tree->insert(30, data);
    tree->insert(45, data);
    tree->insert(20, data);

    tree->widthOrder(50);

    tree->delete_node(25);


    delete tree;

    auto *rb = new RB_Tree();
    rb->add_to_tree(50, data);
    rb->add_to_tree(75, data);
    rb->add_to_tree(60, data);
    rb->add_to_tree(65, data);

    return 0;
}