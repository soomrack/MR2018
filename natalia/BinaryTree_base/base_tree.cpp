//
// Created by natas on 04.05.2019.
//

#include "base_tree.h"
using namespace std;

base_tree::base_tree() {
    root = NULL;
}


base_tree::~base_tree() {
    destroy_tree();
}

void *base_tree::search(int pkey, node *leaf){
    if(leaf != NULL){
        if(pkey == leaf->key){
            return leaf->data;
        }
        if(pkey < leaf->key){
            return search(pkey, leaf->left);
        }else{
            return search(pkey, leaf->right);
        }
    }else{
        return leaf->data;
    }
}

void* base_tree::search(int key){
    return search(key, (node*)root);
}

void base_tree::destroy_tree(node *leaf){
    if(leaf != NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void base_tree::destroy_tree(){
    destroy_tree((node*)root);
}

base_node* base_tree:: search_leaf(int pkey, node* leaf) {
    if(leaf != NULL){
        if(pkey == leaf->key){
            return leaf;
        }
        if(pkey < leaf->key){
            return search_leaf(pkey, leaf->left);
        }else{
            return search_leaf(pkey, leaf->right);
        }
    }else{
        return leaf;
    }


}

//Реализация очереди

Queue::Queue()
{
    queue = new node[SIZE];
    head = 0;
    tail = 0;
}

Queue::~Queue() {
    delete(queue);
}

void Queue::push (node data )
{
    if ( tail + 1 == head || ( tail + 1 == SIZE && !head )) {
        cout << "Queue is full" ;
        return ;
    }

    if ( tail==SIZE ) tail = 0 ;
    queue [ tail ] = data;
    tail++;
}

base_tree::node Queue::pop()
{
    node res = queue[head];
    head++;
    if ( head==SIZE ) head = 0 ;
    return res;

}

bool Queue::isempty() {
    if (head == tail) {
        cout << "Queue is empty";
        return true;
    } else return false;
}