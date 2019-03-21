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
public:
    binaryTree() {
        root = NULL;
    }
    void Add(unsigned int key, DataType data) {
        binaryTreeUnit<DataType> * newUnit = new binaryTreeUnit<DataType>(data, key);
        if(root == NULL) {
            root = newUnit;
            return;
        }
        addToTree(newUnit, root);
    }
    static void addToTree(binaryTreeUnit<DataType> * newUnit, binaryTreeUnit<DataType> * root) {
        unsigned int key = newUnit->getKey();
        unsigned int rootKey = root->getKey();
        if(key == rootKey) {
            printf("Error: this key is already exist");
            exit(1);
        }
        if(key > rootKey) {
            if(root->hasRightChild()) {
                addToTree(newUnit, root->getRightChild());
                return;
            }
            root->setRightChild(newUnit);
            return;
        }
        if(root->hasLeftChild()) {
            addToTree(newUnit, root->getLeftChild());
            return;
        }
        root->setLeftChild(newUnit);
        return;
    }

    void visiting1() {
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
        return;
    }

    void visiting2() {
        Stack<binaryTreeUnit<DataType>*> Stack;
        Stack.push(root);

        while(Stack.getSize() > 0) {
            binaryTreeUnit<DataType> * temp = Stack.pop();
            action(temp);
            if(temp->hasRightChild) {
                Stack.push(temp->returnRightChild());
            }
            if(temp->hasLeftChild) {
                Stack.push(temp->returnLeftChild());
            }
        }
    }


    static DataType recursionForSearch(binaryTreeUnit<DataType> * root, unsigned int key) {
        if(root->getKey() == key) {
            return root->getData();
        }

        if(key > root->getKey()) {
            if(root->hasRightChild()) {
                return recursionForSearch(root->getRightChild(), key);
            }
            printf("Error: can't find item");
            exit(1);
        }

        if(root->hasLeftChild()) {
            return recursionForSearch(root->getLeftChild(), key);
        }
        printf("Error: can't find item");
        exit(1);
    }

    DataType search(unsigned long int key) {
        return recursionForSearch(root, key);
    }

    static binaryTreeUnit<DataType> * recursionForSearchParent(binaryTreeUnit<DataType> * root, unsigned int key) {

        if(key > root->getKey()) {
            if(root->hasRightChild()) {
                if(root->getRightChild()->getKey() == key) {
                    return root;
                }
                return recursionForSearchParent(root->getRightChild(), key);
            }
            printf("Error: can't find item");
            exit(1);
        }

        if(root->hasLeftChild()) {
            if(root->getLeftChild()->getKey() == key) {
                return root;
            }
            return recursionForSearchParent(root->getLeftChild(), key);
        }
        printf("Error: can't find item");
        exit(1);
    }

    void deleteAllBranch(binaryTreeUnit<DataType> * root) {
        if(root->hasLeftChild()) deleteAllBranch(root->getLeftChild());
        if(root->hasRightChild()) deleteAllBranch(root->getRightChild());
        delete root;
    }

    void deleteItem(unsigned int key) {
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

    void deleteItemWithoutChildren(unsigned int key) {
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


};

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

    void createLeftChild() {
        binaryTreePoint * child = new binaryTreePoint;
        setLeftChild(child);
    }

    void createRightChild() {
        binaryTreePoint * child = new binaryTreePoint;
        setRightChild(child);
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


    void visiting1WithAction(void (*action)(binaryTreePoint *)) {
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


    void visiting2WithAction(void (*action)(binaryTreePoint *)) {
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


    binaryTreePoint * searchForParent(binaryTreePoint * heap) {
        Stack<binaryTreePoint*> Stack;
        Stack.push(heap);

        int i = Stack.getSize();
        while(i > 0) {
            binaryTreePoint * temp = Stack.pop();
            if( (temp->leftChild == this) || (temp->rightChild == this) ) {
                return temp;
            }
            if(temp->hasRightChild) {
                Stack.push(temp->returnRightChild());
            }
            if(temp->hasLeftChild) {
                Stack.push(temp->returnLeftChild());
            }

            i = Stack.getSize();
        }
        printf("Can't find parent");
        exit(1);
    }

    void deleteHimself(binaryTreePoint * heap) {

        binaryTreePoint * parent = searchForParent(heap);
        binaryTreePoint * orphan;
        bool isOrphan = 0;

        if (hasLeftChild || hasRightChild) {

            binaryTreePoint * changer;

            if(hasLeftChild) {
                changer = leftChild;
                if(hasRightChild) {
                    orphan = rightChild;
                    isOrphan = 1;
                }
            }
            else {
                changer = rightChild;
            }
            if(parent->leftChild == this) {
                parent->setLeftChild(changer);
            }
            else {
                parent->setRightChild(changer);
            }
            if(isOrphan) {
                orphan->shelter(heap);
            }
        }
        else {
            if(parent->leftChild == this) {
                parent->hasLeftChild = 0;
            }
            else {
                parent->hasRightChild = 0;
            }
        }
    }

    void shelter(binaryTreePoint * heap);

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

