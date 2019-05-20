#include <iostream>
#include "B-tree.h"

int main() {
    int a[14]={ 0,7,8,3,52,14,16,18,15,13,42,30,35,26 };
    BNode *root;
    root = NULL;
    for (int i=0; i<14; i++)        // проход массива и заполнение дерева
        root = add_to_tree(root, a[i]);
    return 0;
}