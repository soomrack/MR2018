//
// Created by work on 01.04.2019.
//

#include "binaryTree.h"

#define DEBUG 1

//version 4


void binaryTree::add_to_tree(Node * newUnit, Node * root) {

    unsigned int key = newUnit->key;
    unsigned int rootKey = root->key;

    Node * next;

    if(key > rootKey) {
        if(root->rightChild != nullptr) {
            next = (Node *)root->rightChild;
        }
        else {
            root->rightChild = newUnit;
            return;
        }
    }
    else {
        if (root->leftChild != nullptr) {
            next = (Node *)root->leftChild;
        }
        else {
            root->leftChild = newUnit;
            return;
        }
    }
    add_to_tree(newUnit, next);

}

Stack<void *> binaryTree::search_node(unsigned int key, Node * item) {

    Stack<void *> out;
    out.push(root);
    Node * next = (Node *) root;

    //unsigned int key = item->key;

    while(true) {
        if (next == nullptr)  return out;
        if ( (next->key == key) && (item == nullptr) ) return out;
        if (next == item) return out;
        if (key > next->key) {
            out.push(next->rightChild);
            next = (Node *)(next->rightChild);
        }
        else {
            out.push(next->leftChild);
            next = (Node *)(next->leftChild);
        }
    }
}



void binaryTree::add(unsigned int key, void * data) {

    Node * newUnit = new Node;

    newUnit->rightChild = nullptr;
    newUnit->leftChild = nullptr;
    newUnit->key = key;
    newUnit->data = data;

    if(root == nullptr) {
        root = newUnit;
        return;
    }

    add_to_tree(newUnit, (Node *)root);
}

void * binaryTree::get_node_with_next_key(Node * root) {

    if(root->rightChild == nullptr) return nullptr;

    Node * out = (Node *)(root->rightChild);

    while(  out->leftChild != nullptr ) {
        out = (Node *)(root->leftChild);
    }
    return (void *)out;

}

void binaryTree::remove(unsigned int key) {
    delete_node(key);
}

void binaryTree::delete_node(unsigned int key, binaryTree::Node *item) {

    Stack<void *> wayToItem;
    wayToItem = search_node(key, item);
    Node * itemToDelete = (Node *)wayToItem.pop();

    if ( (itemToDelete->leftChild != nullptr) &&
    (itemToDelete->rightChild != nullptr) ) {
        Node * next = (Node *)get_node_with_next_key(itemToDelete);
        itemToDelete->data = next->data;
        unsigned int temp = next->key;
        delete_node(next->key, next);
        itemToDelete->key = temp;
        return;
    }

    void * heir;

    if (itemToDelete->leftChild != nullptr) {
        heir = itemToDelete->leftChild;
    }
    else {
        heir = itemToDelete->rightChild;
    }

    if(wayToItem.getSize() == 0) {
        root = heir;
        delete itemToDelete;
        return;
    }

    Node * parent = (Node *)wayToItem.pop();

    if( parent->leftChild == (void *)itemToDelete ) {
        parent->leftChild = heir;
    }
    else {
        parent->rightChild = heir;
    }

    delete itemToDelete;
}

void binaryTree::delete_all_branch(Node * root) {

    if(root->leftChild != nullptr) delete_all_branch((Node *)root->leftChild);
    if(root->rightChild != nullptr) delete_all_branch((Node *)root->rightChild);
    delete root;
}

List<void *>  binaryTree::visiting1() {

    Queue<Node *> Queue;
    List<void *> out;

    Queue.enqueue((Node *)root);
    out.add(((Node *)root)->data);


    while(Queue.getSize() > 0) {
        Node * temp = Queue.dequeue();
        if(temp->leftChild != nullptr) {
            Queue.enqueue( (Node *)(temp->leftChild) );
            out.add( ((Node *)temp->leftChild)->data);
        }
        if(temp->rightChild != nullptr) {
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

        if(temp->rightChild != nullptr) {
            Stack.push((Node *)temp->rightChild);
        }
        if(temp->leftChild != nullptr) {
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
            while(true) {
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


//version 3
/*
void binaryTree::add_to_tree(Node * newUnit, Node * root) {

    unsigned int key = newUnit->key;
    unsigned int rootKey = root->key;

    Node * next;

    if(key > rootKey) {
        if(root->rightChild != nullptr) {
            next = (Node *)root->rightChild;
        }
        else {
            root->rightChild = newUnit;
            return;
        }
    }
    else {
        if (root->leftChild != nullptr) {
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
        if(root->rightChild != nullptr) {
            next = (Node *)root->rightChild;
        }
        else {
#if DEBUG == 1
            printf("Error: can't find item");
#endif
            return nullptr;
        }
    }

    else {

        if (root->leftChild != nullptr) {
            next = (Node *)root->leftChild;
        }
        else {
#if DEBUG == 1
            printf("Error: can't find item");
#endif
            return nullptr;
        }
    }

    return recursion_for_search(next, key);
}


void * binaryTree::recursion_for_search_parent(Node * root, unsigned int key) {

    if(root->key == key) {
#if DEBUG == 1
        printf("Can't find any parent of the root");
#endif
        return nullptr;
    }

    Node * next;

    if(key > root->key) {
        if(root->rightChild != nullptr) {
            if( ( (Node *)(root->rightChild) )->key == key) {
                return root;
            }
            next = (Node *)root->rightChild;
        }
        else {
#if DEBUG == 1
            printf("Error: can't find item");
#endif
            return nullptr;
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
            return nullptr;
        }
    }
    return recursion_for_search_parent(next, key);
}

void binaryTree::add(unsigned int key, void * data) {

    Node * newUnit = new Node;

    newUnit->rightChild = nullptr;
    newUnit->leftChild = nullptr;
    newUnit->key = key;
    newUnit->data = data;

    if(root == nullptr) {
        root = newUnit;
        return;
    }

    add_to_tree(newUnit, (Node *)root);
}



void binaryTree::remove(unsigned int key) {

    Node * orphan = nullptr;

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
            else root = nullptr;
        }
        delete temp;

        if(orphan != nullptr) {
            add_to_tree(orphan, (Node *)root);
        }
        return;
    }

    Node * parent = (Node *)recursion_for_search_parent((Node *)root, key);
    Node * child;

    if(key > parent->key) {
        child = (Node *)(parent->rightChild);
        parent->rightChild = nullptr;
        if(child->leftChild) {
            parent->rightChild = child->leftChild;
            if(child->rightChild) {
                orphan = (Node *)child->rightChild;
            }
        }
        else {
            if(child->rightChild != nullptr) {
                parent->rightChild = child->leftChild;
            }
        }
        delete child;
        if(orphan != nullptr) {
            add_to_tree(orphan, (Node *)root);
        }
        return;
    }

    child = (Node *)parent->leftChild;
    parent->leftChild = nullptr;

    if(child->leftChild != nullptr) {
        parent->leftChild = child->leftChild;
        if(child->rightChild != nullptr) {
            orphan = (Node *)child->rightChild;
        }
    }
    else {
        if(child->rightChild) {
            parent->leftChild = child->rightChild;
        }
    }
    delete child;

    if(orphan != nullptr) {
        add_to_tree(orphan, (Node *)root);
    }
}

void binaryTree::delete_all_branch(Node * root) {

    if(root->leftChild != nullptr) delete_all_branch((Node *)root->leftChild);
    if(root->rightChild != nullptr) delete_all_branch((Node *)root->rightChild);
    delete root;
}

List<void *>  binaryTree::visiting1() {

    Queue<Node *> Queue;
    List<void *> out;

    Queue.enqueue((Node *)root);
    out.add(((Node *)root)->data);


    while(Queue.getSize() > 0) {
        Node * temp = Queue.dequeue();
        if(temp->leftChild != nullptr) {
            Queue.enqueue( (Node *)(temp->leftChild) );
            out.add( ((Node *)temp->leftChild)->data);
        }
        if(temp->rightChild != nullptr) {
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

        if(temp->rightChild != nullptr) {
            Stack.push((Node *)temp->rightChild);
        }
        if(temp->leftChild != nullptr) {
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
*/