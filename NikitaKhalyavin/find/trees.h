//
// Created by work on 03.03.2019.
//

#include <malloc.h>
#include <cstring>
#include <cstdio>
#include <limits.h>
#include <stdint.h>
#include "structs.h"

#ifndef MR2018_TREES_H
#define MR2018_TREES_H

#endif //MR2018_TREES_H




template <typename DataType>
class binaryTreeUnit {
private:
    binaryTreeUnit * leftChild;
    binaryTreeUnit * rightChild;
    unsigned int key;
    DataType data;
public:

    binaryTreeUnit() {
        leftChild = NULL;
        rightChild = NULL;
        key = 0;
    }
    binaryTreeUnit(DataType input, unsigned int key) {
        leftChild = NULL;
        rightChild = NULL;
        data = input;
        this->key = key;
    }
    binaryTreeUnit(binaryTreeUnit & input) {
        leftChild = input.leftChild;
        rightChild = input.rightChild;
        this->data = input.data;
        this->key = input.key;
    }

    void setLeftChild(binaryTreeUnit * child) {
        leftChild = child;
    }
    void setRightChild(binaryTreeUnit * child) {
        rightChild = child;
    }

    bool hasLeftChild() {
        return leftChild != NULL;
    }
    bool hasRightChild() {
        return rightChild != NULL;
    }

    binaryTreeUnit * getRightChild() {
        return rightChild;
    }
    binaryTreeUnit * getLeftChild() {
        return leftChild;
    }

    void deleteLeftChild() {
        leftChild = NULL;
    }
    void deleteRightChild() {
        rightChild = NULL;
    }

    void setData(DataType input) {
        data = input;
    }
    DataType getData() {
        return data;
    }

    void setKey(unsigned int key) {
        this->key = key;
    }
    unsigned int getKey() {
        return key;
    }
};


template <typename DataType>
class binaryTree {
private:
    binaryTreeUnit<DataType> * root;

    void deleteAllBranch(binaryTreeUnit<DataType> * root);
    void addToTree(binaryTreeUnit<DataType> * newUnit, binaryTreeUnit<DataType> * root);
    DataType recursionForSearch(binaryTreeUnit<DataType> * root, unsigned int key);
    binaryTreeUnit<DataType> * recursionForSearchParent(binaryTreeUnit<DataType> * root, unsigned int key);
    List<binaryTreeUnit<DataType> *> recursionForSort(binaryTreeUnit<DataType> * root);
    void recursionForBalancing(List<binaryTreeUnit<DataType> *> List, unsigned int Middle, unsigned int step, binaryTreeUnit<DataType> * root);

public:
    binaryTree() {
        root = NULL;
    }

    void Add(unsigned int key, DataType data);

    List<DataType> visiting1();
    List<DataType> visiting2();

    void balancing();

    DataType search(unsigned long int key) {
        return recursionForSearch(root, key);
    }

    void deleteItem(unsigned int key);
    void deleteItemWithoutChildren(unsigned int key);

};


template <typename DataType>
void binaryTree<DataType>::addToTree(binaryTreeUnit<DataType> * newUnit, binaryTreeUnit<DataType> * root) {

    unsigned int key = newUnit->getKey();
    unsigned int rootKey = root->getKey();

    binaryTreeUnit<DataType> * next;

    if(key == rootKey) {
        printf("Error: this key is already exist");
        exit(1);
    }

    if(key > rootKey) {
        if(root->hasRightChild()) {
            next = root->getRightChild();
        }
        else {
            root->setRightChild(newUnit);
            return;
        }
    }
    else {
        if (root->hasLeftChild()) {
            next = root->getLeftChild();
        }
        else {
            root->setLeftChild(newUnit);
            return;
        }
    }
    addToTree(newUnit, next);
    return;

}


template <typename DataType>
DataType binaryTree<DataType>::recursionForSearch(binaryTreeUnit<DataType> * root, unsigned int key) {

    if(root->getKey() == key) {
        return root->getData();
    }

    binaryTreeUnit<DataType> * next;

    if(key > root->getKey()) {
        if(root->hasRightChild()) {
            next = root->getRightChild();
        }
        else {
            printf("Error: can't find item");
            exit(1);
        }
    }

    else {

        if (root->hasLeftChild()) {
            next = root->getLeftChild();
        }
        else {
            printf("Error: can't find item");
            exit(1);
        }
    }

    return recursionForSearch(next, key);
}


template <typename DataType>
binaryTreeUnit<DataType> * binaryTree<DataType>::recursionForSearchParent(binaryTreeUnit<DataType> * root, unsigned int key) {

    if(root->getKey() == key) {
        printf("Can't find any parent of the root");
        exit(1);
    }

    binaryTreeUnit<DataType> * next;

    if(key > root->getKey()) {
        if(root->hasRightChild()) {
            if(root->getRightChild()->getKey() == key) {
                return root;
            }
            next = root->getRightChild();
        }
        else {
            printf("Error: can't find item");
            exit(1);
        }
    }
    else {
        if (root->hasLeftChild()) {
            if (root->getLeftChild()->getKey() == key) {
                return root;
            }
            next = root->getLeftChild();
        }
        else {
            printf("Error: can't find item");
            exit(1);
        }
    }
    return recursionForSearchParent(next, key);
}

template <typename DataType>
void binaryTree<DataType>::Add(unsigned int key, DataType data) {

    binaryTreeUnit<DataType> * newUnit = new binaryTreeUnit<DataType>(data, key);

    if(root == NULL) {
        root = newUnit;
        return;
    }

    addToTree(newUnit, root);
}

template <typename DataType>
void binaryTree<DataType>::deleteItem(unsigned int key) {

    if(root->getKey() == key) {
        deleteAllBranch(root);
        return;
    }

    binaryTreeUnit<DataType> * parent = recursionForSearchParent(root, key);
    binaryTreeUnit<DataType> * child;

    if(key > parent->getKey()) {
        child = parent->getRightChild();
        parent->deleteRightChild();
        deleteAllBranch(child);
        return;
    }

    child = parent->getLeftChild();
    parent->deleteLeftChild();
    deleteAllBranch(child);
    return;
}


template <typename DataType>
void binaryTree<DataType>::deleteItemWithoutChildren(unsigned int key) {

    binaryTreeUnit<DataType> * orphan = NULL;

    if(root->getKey() == key) {
        binaryTreeUnit<DataType> * temp = root;
        if(temp->hasLeftChild()) {
            root = temp->getLeftChild();
            if(temp->hasRightChild()) {
                orphan = temp->getRightChild();
            }
        }
        else {
            if(temp->hasRightChild()) {
                root = temp->getRightChild();
            }
            else root = NULL;
        }
        delete temp;

        if(orphan != NULL) {
            addToTree(orphan, root);
        }
        return;
    }

    binaryTreeUnit<DataType> * parent = recursionForSearchParent(root, key);
    binaryTreeUnit<DataType> * child;

    if(key > parent->getKey()) {
        child = parent->getRightChild();
        parent->deleteRightChild();
        if(child->hasLeftChild()) {
            parent->setRightChild(child->getLeftChild());
            if(child->hasRightChild()) {
                orphan = child->getRightChild();
            }
        }
        else {
            if(child->hasRightChild()) {
                parent->setRightChild(child->getLeftChild());
            }
        }
        delete child;
        if(orphan != NULL) {
            addToTree(orphan, root);
        }
        return;
    }

    child = parent->getLeftChild();
    parent->deleteLeftChild();

    if(child->hasLeftChild()) {
        parent->setLeftChild(child->getLeftChild());
        if(child->hasRightChild()) {
            orphan = child->getRightChild();
        }
    }
    else {
        if(child->hasRightChild()) {
            parent->setLeftChild(child->getRightChild());
        }
    }
    delete child;

    if(orphan != NULL) {
        addToTree(orphan, root);
    }
}

template <typename DataType>
void binaryTree<DataType>::deleteAllBranch(binaryTreeUnit<DataType> * root) {

    if(root->hasLeftChild()) deleteAllBranch(root->getLeftChild());
    if(root->hasRightChild()) deleteAllBranch(root->getRightChild());
    delete root;
}

template <typename DataType>
List<DataType>  binaryTree<DataType>::visiting1() {

    Queue<binaryTreeUnit<DataType>*> Queue;
    List<DataType> out;

    Queue.enqueue(root);
    out.add(root->getData());


    while(Queue.getSize() > 0) {
        binaryTreeUnit<DataType> * temp = Queue.dequeue();
        if(temp->hasLeftChild()) {
            Queue.enqueue(temp->getLeftChild());
            out.add(temp->getLeftChild()->getData());
        }
        if(temp->hasRightChild()) {
            Queue.enqueue(temp->getRightChild());
            out.add(temp->getRightChild()->getData());
        }
    }
    return out;
}

template <typename DataType>
List<DataType>  binaryTree<DataType>::visiting2() {

    Stack<binaryTreeUnit<DataType>*> Stack;
    Stack.push(root);
    List<DataType> out;

    while(Stack.getSize() > 0) {

        binaryTreeUnit<DataType> * temp = Stack.pop();
        out.add(temp->getData());

        if(temp->hasRightChild) {
            Stack.push(temp->returnRightChild());
        }
        if(temp->hasLeftChild) {
            Stack.push(temp->returnLeftChild());
        }
    }
    return out;
}

template <typename DataType>
List<binaryTreeUnit<DataType> *> binaryTree<DataType>::recursionForSort(binaryTreeUnit<DataType> * root) {

    static List<binaryTreeUnit<DataType> *> List;
    static Stack<binaryTreeUnit<DataType> *> Stack;
    binaryTreeUnit<DataType> * next;


    if(root->hasLeftChild()) {
        Stack.push(root);
        recursionForSort(root->getLeftChild());
    }

    List.add(root);

    if(root->hasRightChild()) {
        recursionForSort(root->getRightChild());
    }
    while(Stack.getSize() > 0) {
        binaryTreeUnit<DataType> * temp = Stack.pop();
        List.add(temp);
        if(temp->hasRightChild()) {
            recursionForSort(temp->getRightChild());
        }
    }
    return List;
}

template <typename DataType>
void binaryTree<DataType>::balancing() {

    if(root == NULL) return;
    List<binaryTreeUnit<DataType> *> List;
    List = recursionForSort(root);

    int step = List.getSize() / 2;

    root = List.getItem(step);
    recursionForBalancing(List, step, step, root);

}

template <typename DataType>
void binaryTree<DataType>::recursionForBalancing(List<binaryTreeUnit<DataType> *> List, unsigned int Middle, unsigned int step, binaryTreeUnit<DataType> * root) {
    if(step == 0) {
        root->deleteLeftChild();
        root->deleteRightChild();
        return;
    }
    root->setLeftChild(List.getItem(Middle - step));
    root->setRightChild(List.getItem(Middle + step));
    recursionForBalancing(List, Middle - step, step / 2, root->getLeftChild());
    recursionForBalancing(List, Middle + step, step / 2, root->getRightChild());
}












