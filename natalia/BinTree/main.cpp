#include <iostream>
#include "BinTree.h"
#include <stdlib.h>


int main() {
    int i;
    int a[14]={ 0,7,8,3,52,14,16,18,15,13,42,30,35,26 };
    TREE *root;
    root = NULL;
    for (i=0; i<14; i++)        // проход массива и заполнение дерева
        root = add_to_tree(root, a[i]);
    while (root->parent != NULL)
        root = root->parent;
    root = getNodeByValue(root, 0);
    delete_node(root);
    show(root);
    delete(root);
    return 0;
    //delete_node(root);
}