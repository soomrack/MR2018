//
// Created by natas on 03.03.2019.
//

#include "BinTree.h"
#include <stdlib.h>
#include <iostream>

TREE *add_to_tree(TREE *root, int new_value)
{
    TREE *new_node;
    new_node = new TREE;

    new_node->data = new_value;
    new_node->left = new_node->right = NULL;
    if (root==NULL)  // если нет сыновей - создаем новый элемент
    {
        root = new TREE;
        root = new_node;
        new_node->parent = NULL;
    }
    else
    {
        root = find_succesor(root, new_node);
    }
    //insert_case1(new_node);
    return root;
}

TREE *find_succesor(TREE *root, TREE * new_node)
{
    TREE * successor;
    while (root!=NULL) {
        successor = root;
        if (root->data < new_node->data)
            root = root->right;
        else
            root = root->left;

    }
    new_node->parent = successor;
    if (successor->data < new_node->data)
    {
        successor->right = new_node;
    }
    else {
        successor->left = new_node;
    }
    return successor;
}

void show(TREE *Tree)              //Функция обхода
{
    if (Tree != NULL)               //Пока не встретится пустое звено
    {
        show(Tree->left);               //Рекурсивная функция для вывода левого поддерева
        std:: cout <<Tree->data;               //Отображаем корень дерева
        show(Tree->right);               //Рекурсивная функци для вывода правого поддерева
    }
}


TREE *getMinNode(TREE *root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}


TREE* getMaxNode(TREE *root) {
    while (root->right) {
        root = root->right;
    }
    return root;
}


TREE *getNodeByValue(TREE *root, int value) {
    while (root) {
        if (root -> data == value)
            return root;
        if (root->data > value ) {
            if (root -> left != NULL)
                root = root->left;
            else root = root->right;
            continue;
        } else if (root->data < value) {
            if (root->right!=NULL)
                root = root->right;
            else root = root->left;
            continue;
        }
    }
    return NULL;
}

void delete_node(TREE *root) {

    if (root->parent == NULL) {
        if ((root->right == NULL) && (root->left == NULL)) {
            root = NULL;
            delete(root);
            return;
        }
        else if (root->right != NULL) {
            TREE* min = getMinNode( root->right);
            root->data = min -> data;
            delete_node(min);
            return;
        } else {
            TREE* min = getMinNode( root->left);
            root->data = min -> data;
            delete_node(min);
            return;
        }
    }
    if ((root->right == NULL) && (root->left == NULL)) {
        if (root->parent->left == root)
            root->parent->left = NULL;
        else root->parent->right = NULL;


        delete(root);
        return;
    }
    else {
        if ((root->right == NULL) && (root->left != NULL))
            if (root->parent->left == root)
                root->parent->left = root->parent->left->left;
            else root->parent->right = root->parent->right->left;
        if ((root->right != NULL) && (root->left == NULL))
            if (root->parent->left == root)
                root->parent->left = root->parent->left->right;
            else root->parent->right = root->parent->right->right;

        if ((root->right != NULL) && (root->left != NULL)) {
            TREE *node = root;
            node = node->right;
            while (node->left != NULL) {
                node = node->left;
            }
            root -> data = node-> data;
            //free (node);
            root = root ->right;
            while (root->left != NULL) {
                root = root->left;
            }
            delete_node(root);

        }
    }
}



