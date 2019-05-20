#include <iostream>
#include "BinTree_Class.h"

using namespace std;

int main() {
    Tree *tree = new Tree();
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
    return 0;
}