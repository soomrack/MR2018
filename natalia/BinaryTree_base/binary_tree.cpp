#include "binary_tree.h"//
// Created by natas on 04.05.2019.
//

#include "binary_tree.h"

using namespace std;





void binary_tree::insert(int pkey, void* pdata){
    base_node * new_node = new base_node;
    if(root != NULL){
        insert( root,  pkey, pdata);
    }else{
        new_node->data = pdata;
        new_node->key = pkey;
        new_node->left = NULL;
        new_node->right = NULL;
        root = new_node;

    }
}

void binary_tree::insert(node *leaf, int pkey, void* pdata) {

    if(pkey < leaf->key){
        if(leaf->left != NULL){
            insert( leaf->left, pkey, pdata);
        }else{
            leaf->left = new node;
            leaf->left->key = pkey;
            leaf->left->data = pdata;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }else if(pkey >= leaf->key){
        if(leaf->right != NULL){
            insert(leaf->right, pkey, pdata);
        }else{
            leaf->right = new node;
            leaf->right->data = pdata;
            leaf->right->key = pkey;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }

}



bool binary_tree::delete_node(int pkey) {
    node* leaf = search_leaf(pkey, (node*)root);
    void* got = leaf->data;
    if (leaf == NULL)
        return false;
    if(leaf->right == NULL && leaf->left == NULL) {
        delete leaf;
        return true;
    }
    if(leaf->right == NULL && leaf->left != NULL) {
        leaf = leaf->left;
        return true;
    }
    if(leaf->right != NULL && leaf->left == NULL) {
        leaf = leaf->right;
        return true;
    }
    if(leaf->right != NULL && leaf->left != NULL) {
        node* parent_temp = leaf;
        node* temp = leaf->right;
        while (temp->left != NULL) {
            parent_temp = temp;
            temp = temp-> left;
        }
        leaf->key = temp->key;
        leaf->data = temp-> data;
        if (temp->right != NULL) {
            *temp = *(temp->right);
            return true;
        }
        parent_temp -> left == temp ? parent_temp -> left = NULL : parent_temp -> right = NULL;
        delete temp;
        return true;
    }
    return false;
}


//обход в глубину Depth-first
//Pre-order - прямой обход - сначала корень, затем левое поддерево, затем правое
void binary_tree::preOrder(int pkey){
    node* leaf = search_leaf(pkey, (node*)root);
    preOrder(pkey, leaf);
}

void binary_tree::preOrder(int pkey, node* leaf){
    cout << " key= " << pkey << "   data = " << leaf->data << endl;
    if (leaf->left == NULL && leaf->right == NULL) {
        cout << "that's all" << endl;
        return;
    }
    if (leaf->left != NULL) preOrder(leaf->left->key, leaf->left);
    if (leaf->right != NULL) preOrder(leaf->right->key, leaf->right);
}

void binary_tree::inOrder(int pkey){ //сначала левое поддерево, потом корень, потом правое
    node* leaf = search_leaf(pkey, (node*)root);
    inOrder(pkey, leaf);

}

void binary_tree::inOrder(int pkey, node* leaf) {
    if (leaf->left != NULL) inOrder(leaf->left->key, leaf-> left);
    cout << " key= " << pkey << "   data = " << leaf->data << endl;
    if (leaf->right != NULL) inOrder(leaf->right->key, leaf-> right);
}



void binary_tree::postOrder(int pkey){ //сначала листья, потом корни
    node* leaf = search_leaf(pkey, (node*)root);
    postOrder(pkey, leaf);
}

void binary_tree::postOrder(int pkey, node* leaf){
    if (leaf->left != NULL) inOrder(leaf->left->key, leaf-> left);
    if (leaf->right != NULL) inOrder(leaf->right->key, leaf-> right);
    cout << " key= " << pkey << "   data = " << leaf->data << endl;
}

//обход в ширину

void binary_tree::widthOrder(int pkey){ //по слоям дерева
    node* leaf = search_leaf(pkey, (node*)root);
    widthOrder(pkey, leaf);
}

void binary_tree::widthOrder(int pkey, node* leaf) {
    if (leaf == NULL)
        return;
    Queue queue;
    queue.push(*leaf);
    while (!(queue.isempty())) {
        node curr = queue.pop();
        printf("%d ", curr.key);
        if (curr.left)
            queue.push(*curr.left);
        if (curr.right)
            queue.push(*curr.right);
    }
}



