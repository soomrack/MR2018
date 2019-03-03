//
// Created by natas on 03.03.2019.
//

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

typedef struct tree
{
    int data;              // данные
    struct tree *left;  // левый  сын
    struct tree *right; // правый сын
    struct tree *parent; //родитель
} TREE;

TREE *add_to_tree(TREE *root, int new_value);
TREE *find_succesor(TREE *root, TREE * new_node);
void show(TREE *Tree);
TREE *getMinNode(TREE *root);
TREE* getMaxNode(TREE *root);
TREE *getNodeByValue(TREE *root, int value);
//TREE* delete_node(TREE* root, int z);
void delete_node(TREE *root);
#endif //BINTREE_BINTREE_H
