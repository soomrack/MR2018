//
// Created by work on 01.04.2019.
//

#include "RBTree.h"

void RBTree::add_to_tree(Node * newUnit, Node * root) {

    unsigned int key = newUnit->key;
    unsigned int rootKey = root->key;

    Node * next;

    if(key > rootKey) {
        if(root->rightChild != NULL) {
            next = (Node *)root->rightChild;
        }
        else {
            root->rightChild = newUnit;
            return;
        }
    }
    else {
        if (root->leftChild != NULL) {
            next = (Node *)root->leftChild;
        }
        else {
            root->leftChild = newUnit;
            return;
        }
    }
    add_to_tree(newUnit, next);
    return;

}





void RBTree::add(unsigned int key, void * data) {

    Node * newUnit = new Node;

    newUnit->rightChild = NULL;
    newUnit->leftChild = NULL;
    newUnit->key = key;
    newUnit->data = data;

    if(root == NULL) {
        root = newUnit;
        return;
    }

    add_to_tree(newUnit, (Node *)root);
}



void RBTree::remove(unsigned int key) {

    Node * orphan = NULL;

    if( ( (Node *)root )->key == key) {
        Node * temp = (Node *)root;
        if(temp->leftChild) {
            root = temp->leftChild;
            if(temp->rightChild) {
                orphan = (Node *)temp->rightChild;
            }
        }
        else {
            if(temp->rightChild) {
                root = temp->rightChild;
            }
            else root = NULL;
        }
        delete temp;

        if(orphan != NULL) {
            add_to_tree(orphan, (Node *)root);
        }
        return;
    }

    Node * parent = (Node *)recursion_for_search_parent((Node *)root, key);
    Node * child;

    if(key > parent->key) {
        child = (Node *)(parent->rightChild);
        parent->rightChild = NULL;
        if(child->leftChild) {
            parent->rightChild = child->leftChild;
            if(child->rightChild) {
                orphan = (Node *)child->rightChild;
            }
        }
        else {
            if(child->rightChild != NULL) {
                parent->rightChild = child->leftChild;
            }
        }
        delete child;
        if(orphan != NULL) {
            add_to_tree(orphan, (Node *)root);
        }
        return;
    }

    child = (Node *)parent->leftChild;
    parent->leftChild = NULL;

    if(child->leftChild != NULL) {
        parent->leftChild = child->leftChild;
        if(child->rightChild != NULL) {
            orphan = (Node *)child->rightChild;
        }
    }
    else {
        if(child->rightChild) {
            parent->leftChild = child->rightChild;
        }
    }
    delete child;

    if(orphan != NULL) {
        add_to_tree(orphan, (Node *)root);
    }
}