//
// Created by work on 03.03.2019.
//

#include <malloc.h>
#include <cstring>
#include <cstdio>
#include <limits.h>
#include "structs.h"

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



class B_TreePoint {
private:
    B_TreePoint ** list;
    B_TreePoint * parent;
    unsigned long int * keys;
    unsigned int size;
public:
    int value;
    unsigned long int getKey() {
        return keys[0];
    }
    B_TreePoint() : size(0) {
        keys = (unsigned long int *)malloc(sizeof(unsigned long int) * 1);
        keys[0] = 0;
        parent = (B_TreePoint *)0;
    }
    B_TreePoint(unsigned int size) {
        this->size = size;
        keys = (unsigned long int *)malloc(sizeof(unsigned long int * ) * size);
        keys[0] = 0;
        keysRestruct(UINT_MAX);
        list = (B_TreePoint **)malloc(sizeof(B_TreePoint * ) * size);
        for(int i = 0; i < size; i++) {
            list[i] = (B_TreePoint *)0;
        }
        parent = (B_TreePoint *)0;
    }
    B_TreePoint(B_TreePoint &input) {
        this->size = input.size;

        this->keys = (unsigned long int *)malloc(sizeof(unsigned long int * ) * size);
        this->list = (B_TreePoint **) malloc(sizeof(B_TreePoint * ) * this->size);

        memcpy(this->list, input.list, sizeof(B_TreePoint * ) * this->size);
        memcpy(this->keys, input.keys, sizeof(B_TreePoint * ) * (this->size - 1));

        this->value = input.value;
        this->parent = input.parent;
    }

    void keysRestruct(unsigned long int keyMax) {
        if(keyMax - keys[0] < size) {
            printf("not enought key values");
            exit(1);
        }
        if(size != 0) {
            unsigned long int step = keyMax / size;
            for (int i = 1; i < size; i++) {
                keys[i] = keys[0] + step * i;
                if(hasChild(i - 1))
                    (*list[i - 1]).keysRestruct(keys[i]);
            }
            if(hasChild(size - 1))
                (*list[size - 1]).keysRestruct(keyMax);
        }

    }

    bool hasChild(unsigned int number) {
        if(number >= size) {
            printf("there aren't any child with this number");
            exit(1);
        }
        if(list[number] == (B_TreePoint *)0) return false;
        return  true;
    }

    unsigned int getSize() {
        return size;
    }

    B_TreePoint * returnChild(unsigned int number) {
        if(hasChild(number)) return list[number];
        printf("there aren't any child with this number");
        exit(1);
    }

    void addChild(B_TreePoint * child) {

    }

    void setChild(unsigned int number, B_TreePoint * child) {
        if(number >= size) {
            printf("there aren't any child with this number");
            exit(1);
        }
        list[number] = child;
        (*child).parent = this;
        if(number > 0) (*child).keys[0] = keys[number] + 1;
        if(number == size - 1)
            (*child).keysRestruct(keys[UINT_MAX]);
        else
            (*child).keysRestruct(keys[number + 1]);
    }

    void deleteChild(unsigned int number) {
        if(number >= size) {
            printf("there aren't any child with this number");
            exit(1);
        }
        list[number] = (B_TreePoint *)0;
    }

    void deleteHimself() {
        for(int i = 0; i < (*parent).size; i++) {
            if((*parent).list[i] == this) {
                (*parent).list[i] = (B_TreePoint * )0;
                parent = (B_TreePoint * )0;
                return;
            }
        }
    }

    void setValue(int value) {
        this->value = value;
    }

    void resize(unsigned int size) {

        if(size == 0) {
            if(this->size != 0) free(list);
            this->size = size;
            return;
        }
        B_TreePoint ** temp = (B_TreePoint **)malloc(sizeof(B_TreePoint * ) * size);
        unsigned int twoHas = size;
        if(this->size < twoHas) twoHas = this->size;
        memcpy(temp, list, sizeof(B_TreePoint * ) * twoHas);
        for(int i = twoHas; i < size; i++) {
            temp[i] = (B_TreePoint *)0;
        }
        if(this->size != 0) free(list);
        this->size = size;
        list = temp;
    }

    void Print() {
        printf("%d\t", value);
    }

    void addPointWithBalance(B_TreePoint * arg) {

        List<B_TreePoint *> List;
        List.add(this);

        int i = 0;
        int j = 0;
        B_TreePoint * addTo = (B_TreePoint * )0;
        while(i < List.getSize()) {
            B_TreePoint * temp = List.getItem(i);
            for(int j = 0; j < (*temp).size; j++) {
                if( (*temp).hasChild(j)) {
                    List.add((*temp).returnChild(j));
                }
                else {
                    addTo = temp;
                    break;
                }
            }
            if(addTo != (B_TreePoint *)0) break;
            i++;
        }
        if(addTo == (B_TreePoint * )0) {
            printf("Error: there aren't any free place in the tree");
            return;
        }
        (*addTo).setChild(j, arg);

    }

    List<B_TreePoint*> search1() {
        List<B_TreePoint*> List;
        List.add(this);
        (*this).Print();

        int i = 0;
        while(i < List.getSize()) {
            B_TreePoint * temp = List.getItem(i);
            for(int j = 0; j < (*temp).size; j++) {
                if( (*temp).hasChild(j)) {
                    List.add((*temp).returnChild(j));
                    ( *(*temp).returnChild(j) ).Print();
                }
            }
            i++;
        }
        return List;
    }


    template <typename Ret>
    void visiting1WithAction(Ret (*action)(B_TreePoint *)) {
        List<B_TreePoint*> List;
        List.add(this);
        action(this);

        int i = 0;
        while(i < List.getSize()) {
            B_TreePoint * temp = List.getItem(i);
            for(int j = 0; j < (*temp).size; j++) {
                if( (*temp).hasChild(j)) {
                    List.add((*temp).returnChild(j));
                    action((*temp).returnChild(j));
                }
            }
            i++;
        }
    }

    template <typename Ret>
    Ret search(unsigned long int key, Ret (*action)(B_TreePoint *)) {

        if(keys[0] == key) {
           return action(this);
        }
        unsigned int i;
        for(i = 1; i < size; i++) {
            if( keys[i] >= key ) break;
        }
        if(keys[i] >= key) i--;
        if( !hasChild(i)) {
            printf("There aren't any child with this number");
            exit(1);
        }
        (*returnChild(i)).search(key, action);
    }

    List<B_TreePoint*> search2() {
        Stack<B_TreePoint*> Stack;
        Stack.push(this);

        List<B_TreePoint*> out;

        int i = Stack.getSize();
        while(i > 0) {
            B_TreePoint * temp = Stack.pop();
            out.add(temp);
            (*temp).Print();
            for(int j = (*temp).size - 1; j >= 0; j--) {
                if( (*temp).hasChild(j)) {
                    Stack.push((*temp).returnChild(j));
                }
            }
            i = Stack.getSize();
        }
        return out;
    }

    template <typename Ret>
    void visiting2WithAction(Ret (*action)(B_TreePoint *)) {
        Stack<B_TreePoint*> Stack;
        Stack.push(this);

        int i = Stack.getSize();
        while(i > 0) {
            B_TreePoint * temp = Stack.pop();
            action(temp);
            for(int j = (*temp).size - 1; j >= 0; j--) {
                if( (*temp).hasChild(j)) {
                    Stack.push((*temp).returnChild(j));
                }
            }
            i = Stack.getSize();
        }
    }


    void balancing() {
        List<B_TreePoint * > List1;
        List1 = search1();
    }
};

