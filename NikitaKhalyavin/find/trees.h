//
// Created by work on 03.03.2019.
//

#include <malloc.h>
#include <cstring>
#include <cstdio>

#ifndef MR2018_TREES_H
#define MR2018_TREES_H

#endif //MR2018_TREES_H

class binaryTreePoint;

class binaryTreePointStack;

class binaryTreePointList;

class binaryTreePoint {
private:
    binaryTreePoint * leftChild;
    binaryTreePoint * rightChild;
public:
    bool hasLeftChild;
    bool hasRightChild;
    int value;
    binaryTreePoint(binaryTreePoint &input) {
        if(input.hasLeftChild) {
            this->leftChild = input.leftChild;
        }
        this->hasLeftChild = input.hasLeftChild;
        if(input.hasRightChild) {
            this->rightChild = input.rightChild;
        }
        this->hasRightChild = input.hasRightChild;
        this->value = input.value;
    }
    binaryTreePoint() : hasLeftChild(false), hasRightChild(false) {

    }
    binaryTreePoint(int value) : hasLeftChild(false), hasRightChild(false) {
        this->value = value;
    }
    /*   void operator = (binaryTreePoint &input) {
           if(input.hasLeftChild) {
               this->hasLeftChild = true;
               this->leftChild = input.leftChild;
           }
           if(input.hasRightChild) {
               this->hasRightChild = true;
               this->rightChild = input.rightChild;
           }
           this->value = input.value;
       }*/

    void setLeftChild(binaryTreePoint * child) {
        hasLeftChild = true;
        leftChild = child;
    }
    void setRightChild(binaryTreePoint * child) {
        hasRightChild = true;
        rightChild = child;
    }
    void setValue(int value) {
        this->value = value;
    }

    binaryTreePoint returnLeftChild() {
        if(hasLeftChild) {
            return *leftChild;
        }
        binaryTreePoint voidret;
        return voidret;
    }

    binaryTreePoint returnRightChild() {
        if(hasRightChild) {
            return *rightChild;
        }
        binaryTreePoint voidret;
        return voidret;
    }
};

class binaryTreePointStack {
private:
    binaryTreePoint * data;
    unsigned int size;
public:
    binaryTreePointStack() : size(0) {
        data = (binaryTreePoint * )0;
    }

    binaryTreePointStack(binaryTreePointStack &input) {
        this->size = input.size;
        this->data = (binaryTreePoint * )malloc(size * sizeof(binaryTreePoint));
        memcpy(this->data, input.data, sizeof(binaryTreePoint) * size);
    }

    void push(binaryTreePoint input) {
        binaryTreePoint * temp = (binaryTreePoint * )malloc((size + 1) * sizeof(binaryTreePoint));
        memcpy(temp, data, sizeof(binaryTreePoint) * size);
        temp[size] = input;
        size++;
        free(data);
        data = temp;
    }

    binaryTreePoint pop() {
        if(size == 0) {
            binaryTreePoint voidOut;
            return voidOut;
        }
        size--;
        binaryTreePoint * temp = (binaryTreePoint * )malloc((size) * sizeof(binaryTreePoint));
        memcpy(temp, data, sizeof(binaryTreePoint) * size);
        binaryTreePoint out = data[size];
        free(data);
        data = temp;
        return out;
    }

    unsigned int getSize() {
        return size;
    }
};

class binaryTreePointList {
private:
    binaryTreePoint * data;
    unsigned int size;
public:
    binaryTreePointList() : size(0) {
        data = (binaryTreePoint * )0;
    }

    binaryTreePointList(binaryTreePointList &input) {
        this->size = input.size;
        this->data = (binaryTreePoint * )malloc(size * sizeof(binaryTreePoint));
        memcpy(this->data, input.data, sizeof(binaryTreePoint) * size);
    }

    void Add(binaryTreePoint input) {
        binaryTreePoint * temp = (binaryTreePoint * )malloc((size + 1) * sizeof(binaryTreePoint));
        memcpy(temp, data, sizeof(binaryTreePoint) * size);
        temp[size] = input;
        size++;
        free(data);
        data = temp;
    }

    void Print() {
        for(int i = 0; i < size; i++) {
            printf("%d\t", data[i].value);
        }
    }

    void search1(binaryTreePoint head) {

        Add(head);
        int i = 0;

        while(i < size) {
            binaryTreePoint temp;

            if(data[i].hasLeftChild) {
                temp = data[i].returnLeftChild();
                Add(temp);
            }

            if (data[i].hasRightChild) {
                temp = data[i].returnRightChild();
                Add(temp);
            }
            i++;
        }
        Print();
    }

    void search2(binaryTreePoint head) {

        int i = size;
        binaryTreePointStack stack;
        stack.push(head);
        while(1) {
            binaryTreePoint temp1;
            temp1 = stack.pop();
            Add(temp1);

            binaryTreePoint temp2;

            if(temp1.hasRightChild) {
                temp2 = temp1.returnRightChild();
                stack.push(temp2);
            }

            if (temp1.hasLeftChild) {
                temp2 = temp1.returnLeftChild();
                stack.push(temp2);
            }
            if(stack.getSize() == 0) break;
        }
        Print();
    }
};

class B_Tree;