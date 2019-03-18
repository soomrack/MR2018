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

class binaryTreePoint;

class binaryTreePointStack;

class binaryTreePointList;

class binaryTreePoint {
private:
    binaryTreePoint * leftChild;
    binaryTreePoint * rightChild;
    unsigned int startAdressPull;
    unsigned int  stopAdressPull;
    unsigned int eigenAdress;
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
        eigenAdress = 0;
        startAdressPull = 1;
        stopAdressPull = UINT_MAX;
    }
    binaryTreePoint(int value) : hasLeftChild(false), hasRightChild(false) {
        this->value = value;
    }


    void readress(unsigned int stAdr, unsigned int stopAdr) {
        eigenAdress = stAdr;
        startAdressPull = stAdr + 1;
        stopAdressPull = stopAdr;

        unsigned int middle = (unsigned int)(( (uint64_t)stAdr + (uint64_t)stopAdr ) / 2);

        if(hasLeftChild) leftChild->readress(startAdressPull, middle - 1);
        if(hasRightChild) rightChild->readress(middle, stopAdressPull);
    }

    void setLeftChild(binaryTreePoint * child) {
        hasLeftChild = true;
        leftChild = child;
        unsigned int middle = (unsigned int)(( (uint64_t)startAdressPull + (uint64_t)stopAdressPull ) / 2);
        leftChild->readress(startAdressPull, middle - 1);
    }

    void setRightChild(binaryTreePoint * child) {
        hasRightChild = true;
        rightChild = child;
        unsigned int middle = (unsigned int)(( (uint64_t)startAdressPull + (uint64_t)stopAdressPull ) / 2);
        rightChild->readress(middle, stopAdressPull);
    }

    unsigned int getKey() {
        return eigenAdress;
    }

    void setValue(int value) {
        this->value = value;
    }

    binaryTreePoint * returnLeftChild() {
        if(hasLeftChild) {
            return leftChild;
        }
        printf("there aren't left child");
        exit(1);
    }

    binaryTreePoint * returnRightChild() {
        if(hasRightChild) {
            return rightChild;
        }
        printf("there aren't right child");
        exit(1);
    }

    template <typename Ret>
    void visiting1WithAction(Ret (*action)(binaryTreePoint *)) {
        List<binaryTreePoint*> List;
        List.add(this);
        action(this);

        int i = 0;
        while(i < List.getSize()) {
            binaryTreePoint * temp = List.getItem(i);
            if(temp->hasLeftChild) {
                List.add(temp->returnLeftChild());
                action(temp->returnLeftChild());
            }
            if(temp->hasRightChild) {
                List.add(temp->returnRightChild());
                action(temp->returnRightChild());
            }
            i++;
        }
    }

    template <typename Ret>
    void visiting2WithAction(Ret (*action)(binaryTreePoint *)) {
        Stack<binaryTreePoint*> Stack;
        Stack.push(this);

        int i = Stack.getSize();
        while(i > 0) {
            binaryTreePoint * temp = Stack.pop();
            action(temp);
            if(temp->hasRightChild) {
                Stack.push(temp->returnRightChild());
            }
            if(temp->hasLeftChild) {
                Stack.push(temp->returnLeftChild());
            }

            i = Stack.getSize();
        }
    }

    template <typename Ret>
    Ret search(unsigned long int key, Ret (*action)(binaryTreePoint *)) {

        if(eigenAdress == key) {
            return action(this);
        }

        if( (stopAdressPull < key) || (startAdressPull > key) ) {
            printf("Error: can't find item");
            exit(1);
        }


        unsigned int middle = (unsigned int)(( (uint64_t)startAdressPull + (uint64_t)stopAdressPull ) / 2);
        if(key >= middle) {
            if(hasRightChild) {
                return returnRightChild()->search(key, action);
            }
            printf("Error: can't find item");
            exit(1);
        }

        if(hasLeftChild) {
            return returnLeftChild()->search(key, action);
        }
        printf("Error: can't find item");
        exit(1);
    }

};




class B_TreePoint {
private:

    List<B_TreePoint *> list;
    List<unsigned long int> keys;

    B_TreePoint * parent;
    unsigned int size;
    unsigned int keyMax;

public:
    int value;
    unsigned long int getKey() {
        return keys.getItem(0);
    }
    B_TreePoint() : size(0), keyMax(UINT_MAX) {
        keys.add(0);
        parent = (B_TreePoint *)0;
    }
    B_TreePoint(unsigned int size) {
        this->size = size;
        keys.add(0);
        parent = (B_TreePoint *)0;
    }
    B_TreePoint(B_TreePoint &input) {
        this->size = input.size;

        this->keys = input.keys;
        this->list = input.list;

        this->value = input.value;
        this->parent = input.parent;
    }

    void keysRestruct(unsigned long int NewKey) {
        List<unsigned long int> temp;
        temp.add(NewKey);
        if(list.getSize() != 0) {
            unsigned long int keyStep = (keyMax - keys.getItem(0)) / size;
            for (int i = 1; i < list.getSize(); i++) {
                temp.add(temp.getItem(0) + keyStep * i);
                (*list.getItem(i - 1)).keyMax = temp.getItem(i);
                (*list.getItem(i - 1)).keysRestruct(temp.getItem(i - 1));
            }
            if(list.getSize() > 0) {
                (*list.getItem(list.getSize() - 1)).keyMax = keyMax;
                (*list.getItem(list.getSize() - 1)).keysRestruct(temp.getItem(temp.getSize() - 1));
            }
        }
        keys = temp;
    }

    unsigned int getChildNumber() {
        return list.getSize();
    }

    B_TreePoint * returnChild(unsigned int number) {
        if(number < list.getSize()) return list.getItem(number);
        printf("there aren't any child with this number");
        exit(1);
    }

    void addChild(B_TreePoint * child) {
        if(list.getSize() < size) {
            list.add(child);
            unsigned long int keyStep = ( keyMax - keys.getItem(0) ) / size;
            keys.add(keys.getItem(keys.getSize() - 1) + keyStep);
            keysRestruct(keys.getItem(0));
            return;
        }
        printf("Error: overflau of point");
        exit(1);
    }


    void deleteChild(unsigned int number) {
        if(number >= size) {
            printf("there aren't any child with this number");
            exit(1);
        }
        list.deleteItem(number);
        keysRestruct(keys.getItem(0) + 1);
    }


    void setValue(int value) {
        this->value = value;
    }

    void resize(unsigned int size) {

        this->size = size;
        if(list.getSize() > size) {
            printf("Error: Overflau of point");
            exit(1);
        }

    }

    void Print() {
        printf("%d\t", value);
    }


    template <typename Ret>
    void visiting1WithAction(Ret (*action)(B_TreePoint *)) {
        List<B_TreePoint*> List;
        List.add(this);
        action(this);

        int i = 0;
        while(i < List.getSize()) {
            B_TreePoint * temp = List.getItem(i);
            for(int j = 0; j < (*temp).list.getSize(); j++) {
                List.add((*temp).returnChild(j));
                action((*temp).returnChild(j));
            }
            i++;
        }
    }

    template <typename Ret>
    Ret search(unsigned long int key, Ret (*action)(B_TreePoint *)) {

        if(keys.getItem(0) == key) {
           return action(this);
        }

        if(keyMax < key) {
            printf("Error: can't find item");
            exit(1);
        }

        unsigned int i;
        for(i = 1; i < keys.getSize(); i++) {
            if( keys.getItem(i) >= key ) {
                break;
            }
        }
        i--;
        (*returnChild(i)).search(key, action);
    }


    template <typename Ret>
    void visiting2WithAction(Ret (*action)(B_TreePoint *)) {
        Stack<B_TreePoint*> Stack;
        Stack.push(this);

        int i = Stack.getSize();
        while(i > 0) {
            B_TreePoint * temp = Stack.pop();
            action(temp);
            for(int j = (*temp).list.getSize() - 1; j >= 0; j--) {
                Stack.push((*temp).returnChild(j));
            }
            i = Stack.getSize();
        }
    }

};

