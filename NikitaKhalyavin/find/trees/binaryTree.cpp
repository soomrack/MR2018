//
// Created by work on 01.04.2019.
//

#include "binaryTree.h"

#define DEBUG 1


void binaryTree::add_to_tree(Node * newUnit, Node * root) {

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


void * binaryTree::recursion_for_search(Node * root, unsigned int key) {

    if(root->key == key) {
        return root->data;
    }

    Node * next;

    if(key > root->key) {
        if(root->rightChild != NULL) {
            next = (Node *)root->rightChild;
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
            next = (Node *)root->leftChild;
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


void * binaryTree::recursion_for_search_parent(Node * root, unsigned int key) {

    if(root->key == key) {
#if DEBUG == 1
        printf("Can't find any parent of the root");
#endif
        return NULL;
    }

    Node * next;

    if(key > root->key) {
        if(root->rightChild != NULL) {
            if( ( (Node *)(root->rightChild) )->key == key) {
                return root;
            }
            next = (Node *)root->rightChild;
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
            if (( (Node *)(root->leftChild) )->key == key) {
                return root;
            }
            next = (Node *)root->leftChild;
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



void binaryTree::remove(unsigned int key) {

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

void binaryTree::delete_all_branch(Node * root) {

    if(root->leftChild != NULL) delete_all_branch((Node *)root->leftChild);
    if(root->rightChild != NULL) delete_all_branch((Node *)root->rightChild);
    delete root;
}

List<void *>  binaryTree::visiting1() {

    Queue<Node *> Queue;
    List<void *> out;

    Queue.enqueue((Node *)root);
    out.add(((Node *)root)->data);


    while(Queue.getSize() > 0) {
        Node * temp = Queue.dequeue();
        if(temp->leftChild != NULL) {
            Queue.enqueue( (Node *)(temp->leftChild) );
            out.add( ((Node *)temp->leftChild)->data);
        }
        if(temp->rightChild != NULL) {
            Queue.enqueue((Node *)(temp->rightChild));
            out.add( ((Node *)temp->rightChild)->data);
        }
    }
    return out;
}


List<void *>  binaryTree::visiting2() {

    Stack<Node *> Stack;
    Stack.push((Node *)root);
    List<void *> out;

    while(Stack.getSize() > 0) {

        Node * temp = Stack.pop();
        out.add(temp->data);

        if(temp->rightChild != NULL) {
            Stack.push((Node *)temp->rightChild);
        }
        if(temp->leftChild != NULL) {
            Stack.push((Node *)temp->leftChild);
        }
    }
    return out;
}


List<void *>  binaryTree::visiting3() {

    Stack<Node *> Stack;
    Node * Current = (Node *)root;
    List<void *> out;

    while( (Stack.getSize() > 0) || (Current->leftChild != nullptr)
    || (Current->rightChild != nullptr) ){

        if(Current->leftChild != nullptr) {
            Stack.push(Current);
            Current = (Node *)(Current->leftChild);
        }
        else {
            while(1) {
                out.add(Current->data);
                if (Current->rightChild != nullptr) {
                    Current = (Node *) (Current->rightChild);
                    break;
                }
                else {
                    if(Stack.getSize() == 0) return out;
                    Current = Stack.pop();
                }
            }
        }

    }
    out.add(Current->data);
    return out;
}
