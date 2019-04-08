//
// Created by work on 01.04.2019.
//

#include "binaryTree.h"

#define DEBUG 1


void binaryTree::add_to_tree(binaryTreeNode * newUnit, binaryTreeNode * root) {

    unsigned int key = newUnit->key;
    unsigned int rootKey = root->key;

    binaryTreeNode * next;

    if(key > rootKey) {
        if(root->rightChild != NULL) {
            next = (binaryTreeNode *)root->rightChild;
        }
        else {
            root->rightChild = newUnit;
            return;
        }
    }
    else {
        if (root->leftChild != NULL) {
            next = (binaryTreeNode *)root->leftChild;
        }
        else {
            root->leftChild = newUnit;
            return;
        }
    }
    add_to_tree(newUnit, next);
    return;

}


void * binaryTree::recursion_for_search(binaryTreeNode * root, unsigned int key) {

    if(root->key == key) {
        return root->data;
    }

    binaryTreeNode * next;

    if(key > root->key) {
        if(root->rightChild != NULL) {
            next = (binaryTreeNode *)root->rightChild;
        }
        else {
#if DEBUG == 1
            printf("Error: can't find item");
#endif
            return NULL;
        }
    }

    else {

        if (root->leftChild != NULL) {
            next = (binaryTreeNode *)root->leftChild;
        }
        else {
#if DEBUG == 1
            printf("Error: can't find item");
#endif
            return NULL;
        }
    }

    return recursion_for_search(next, key);
}


binaryTreeNode * binaryTree::recursion_for_search_parent(binaryTreeNode * root, unsigned int key) {

    if(root->key == key) {
#if DEBUG == 1
        printf("Can't find any parent of the root");
#endif
        return NULL;
    }

    binaryTreeNode * next;

    if(key > root->key) {
        if(root->rightChild != NULL) {
            if( ( (binaryTreeNode *)(root->rightChild) )->key == key) {
                return root;
            }
            next = (binaryTreeNode *)root->rightChild;
        }
        else {
#if DEBUG == 1
            printf("Error: can't find item");
#endif
            return NULL;
        }
    }
    else {
        if (root->leftChild) {
            if (( (binaryTreeNode *)(root->leftChild) )->key == key) {
                return root;
            }
            next = (binaryTreeNode *)root->leftChild;
        }
        else {
#if DEBUG == 1
            printf("Error: can't find item");
#endif
            return NULL;
        }
    }
    return recursion_for_search_parent(next, key);
}

void binaryTree::add(unsigned int key, void * data) {

    binaryTreeNode * newUnit = new binaryTreeNode;

    newUnit->rightChild = NULL;
    newUnit->leftChild = NULL;
    newUnit->key = key;
    newUnit->data = data;

    if(root == NULL) {
        root = newUnit;
        return;
    }

    add_to_tree(newUnit, (binaryTreeNode *)root);
}



void binaryTree::remove(unsigned int key) {

    binaryTreeNode * orphan = NULL;

    if( ( (binaryTreeNode *)root )->key == key) {
        binaryTreeNode * temp = (binaryTreeNode *)root;
        if(temp->leftChild) {
            root = temp->leftChild;
            if(temp->rightChild) {
                orphan = (binaryTreeNode *)temp->rightChild;
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
            add_to_tree(orphan, (binaryTreeNode *)root);
        }
        return;
    }

    binaryTreeNode * parent = recursion_for_search_parent((binaryTreeNode *)root, key);
    binaryTreeNode * child;

    if(key > parent->key) {
        child = (binaryTreeNode *)(parent->rightChild);
        parent->rightChild = NULL;
        if(child->leftChild) {
            parent->rightChild = child->leftChild;
            if(child->rightChild) {
                orphan = (binaryTreeNode *)child->rightChild;
            }
        }
        else {
            if(child->rightChild != NULL) {
                parent->rightChild = child->leftChild;
            }
        }
        delete child;
        if(orphan != NULL) {
            add_to_tree(orphan, (binaryTreeNode *)root);
        }
        return;
    }

    child = (binaryTreeNode *)parent->leftChild;
    parent->leftChild = NULL;

    if(child->leftChild != NULL) {
        parent->leftChild = child->leftChild;
        if(child->rightChild != NULL) {
            orphan = (binaryTreeNode *)child->rightChild;
        }
    }
    else {
        if(child->rightChild) {
            parent->leftChild = child->rightChild;
        }
    }
    delete child;

    if(orphan != NULL) {
        add_to_tree(orphan, (binaryTreeNode *)root);
    }
}

void binaryTree::delete_all_branch(binaryTreeNode * root) {

    if(root->leftChild != NULL) delete_all_branch((binaryTreeNode *)root->leftChild);
    if(root->rightChild != NULL) delete_all_branch((binaryTreeNode *)root->rightChild);
    delete root;
}

List<void *>  binaryTree::visiting1() {

    Queue<binaryTreeNode *> Queue;
    List<void *> out;

    Queue.enqueue((binaryTreeNode *)root);
    out.add(((binaryTreeNode *)root)->data);


    while(Queue.getSize() > 0) {
        binaryTreeNode * temp = Queue.dequeue();
        if(temp->leftChild != NULL) {
            Queue.enqueue( (binaryTreeNode *)(temp->leftChild) );
            out.add( ((binaryTreeNode *)temp->leftChild)->data);
        }
        if(temp->rightChild != NULL) {
            Queue.enqueue((binaryTreeNode *)(temp->rightChild));
            out.add( ((binaryTreeNode *)temp->rightChild)->data);
        }
    }
    return out;
}


List<void *>  binaryTree::visiting2() {

    Stack<binaryTreeNode *> Stack;
    Stack.push((binaryTreeNode *)root);
    List<void *> out;

    while(Stack.getSize() > 0) {

        binaryTreeNode * temp = Stack.pop();
        out.add(temp->data);

        if(temp->rightChild != NULL) {
            Stack.push((binaryTreeNode *)temp->rightChild);
        }
        if(temp->leftChild != NULL) {
            Stack.push((binaryTreeNode *)temp->leftChild);
        }
    }
    return out;
}
