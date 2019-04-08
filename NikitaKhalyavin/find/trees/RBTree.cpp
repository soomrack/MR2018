//
// Created by work on 01.04.2019.
//

#include "RBTree.h"

void RBTree::add_to_tree(RBTreeNode * newUnit, RBTreeNode * root) {

    unsigned int key = newUnit->key;
    unsigned int rootKey = root->key;

    RBTreeNode * next;

    if(key > rootKey) {
        if(root->rightChild != NULL) {
            next = (RBTreeNode *)root->rightChild;
        }
        else {
            root->rightChild = newUnit;
            return;
        }
    }
    else {
        if (root->leftChild != NULL) {
            next = (RBTreeNode *)root->leftChild;
        }
        else {
            root->leftChild = newUnit;
            return;
        }
    }
    add_to_tree(newUnit, next);
    return;

}


void * RBTree::recursion_for_search(RBTreeNode * root, unsigned int key) {

    if(root->key == key) {
        return root->data;
    }

    RBTreeNode * next;

    if(key > root->key) {
        if(root->rightChild != NULL) {
            next = (RBTreeNode *)root->rightChild;
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
            next = (RBTreeNode *)root->leftChild;
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


RBTreeNode * RBTree::recursion_for_search_parent(RBTreeNode * root, unsigned int key) {

    if(root->key == key) {
#if DEBUG == 1
        printf("Can't find any parent of the root");
#endif
        return NULL;
    }

    RBTreeNode * next;

    if(key > root->key) {
        if(root->rightChild != NULL) {
            if( ( (RBTreeNode *)(root->rightChild) )->key == key) {
                return root;
            }
            next = (RBTreeNode *)root->rightChild;
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
            if (( (RBTreeNode *)(root->leftChild) )->key == key) {
                return root;
            }
            next = (RBTreeNode *)root->leftChild;
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

void RBTree::add(unsigned int key, void * data) {

    RBTreeNode * newUnit = new RBTreeNode;

    newUnit->rightChild = NULL;
    newUnit->leftChild = NULL;
    newUnit->key = key;
    newUnit->data = data;

    if(root == NULL) {
        root = newUnit;
        return;
    }

    add_to_tree(newUnit, (RBTreeNode *)root);
}



void RBTree::remove(unsigned int key) {

    RBTreeNode * orphan = NULL;

    if( ( (RBTreeNode *)root )->key == key) {
        RBTreeNode * temp = (RBTreeNode *)root;
        if(temp->leftChild) {
            root = temp->leftChild;
            if(temp->rightChild) {
                orphan = (RBTreeNode *)temp->rightChild;
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
            add_to_tree(orphan, (RBTreeNode *)root);
        }
        return;
    }

    RBTreeNode * parent = recursion_for_search_parent((RBTreeNode *)root, key);
    RBTreeNode * child;

    if(key > parent->key) {
        child = (RBTreeNode *)(parent->rightChild);
        parent->rightChild = NULL;
        if(child->leftChild) {
            parent->rightChild = child->leftChild;
            if(child->rightChild) {
                orphan = (RBTreeNode *)child->rightChild;
            }
        }
        else {
            if(child->rightChild != NULL) {
                parent->rightChild = child->leftChild;
            }
        }
        delete child;
        if(orphan != NULL) {
            add_to_tree(orphan, (RBTreeNode *)root);
        }
        return;
    }

    child = (RBTreeNode *)parent->leftChild;
    parent->leftChild = NULL;

    if(child->leftChild != NULL) {
        parent->leftChild = child->leftChild;
        if(child->rightChild != NULL) {
            orphan = (RBTreeNode *)child->rightChild;
        }
    }
    else {
        if(child->rightChild) {
            parent->leftChild = child->rightChild;
        }
    }
    delete child;

    if(orphan != NULL) {
        add_to_tree(orphan, (RBTreeNode *)root);
    }
}

void RBTree::delete_all_branch(RBTreeNode * root) {

    if(root->leftChild != NULL) delete_all_branch((RBTreeNode *)root->leftChild);
    if(root->rightChild != NULL) delete_all_branch((RBTreeNode *)root->rightChild);
    delete root;
}

List<void *>  RBTree::visiting1() {

    Queue<RBTreeNode *> Queue;
    List<void *> out;

    Queue.enqueue((RBTreeNode *)root);
    out.add(((RBTreeNode *)root)->data);


    while(Queue.getSize() > 0) {
        RBTreeNode * temp = Queue.dequeue();
        if(temp->leftChild != NULL) {
            Queue.enqueue( (RBTreeNode *)(temp->leftChild) );
            out.add( ((RBTreeNode *)temp->leftChild)->data);
        }
        if(temp->rightChild != NULL) {
            Queue.enqueue((RBTreeNode *)(temp->rightChild));
            out.add( ((RBTreeNode *)temp->rightChild)->data);
        }
    }
    return out;
}


List<void *>  RBTree::visiting2() {

    Stack<RBTreeNode *> Stack;
    Stack.push((RBTreeNode *)root);
    List<void *> out;

    while(Stack.getSize() > 0) {

        RBTreeNode * temp = Stack.pop();
        out.add(temp->data);

        if(temp->rightChild != NULL) {
            Stack.push((RBTreeNode *)temp->rightChild);
        }
        if(temp->leftChild != NULL) {
            Stack.push((RBTreeNode *)temp->leftChild);
        }
    }
    return out;
}
