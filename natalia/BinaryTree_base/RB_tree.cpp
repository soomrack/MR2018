//
// Created by natas on 05.05.2019.
//

#include "RB_tree.h"
#include "base_tree.h"

RB_node * RB_Tree::parent(Node * child, Node * root){ // работает
    Node * branch = (Node*) root;
    if (root == NULL)
        return NULL;
    if ( root->right == child || (root->left == child))
        return root;
    if(root->key < child->key )
        branch = (Node*)root->right;
    else
        branch = (Node*)root->left;
    return parent(child, branch);
}

RB_node * RB_Tree::grandparent(Node * child, Node * root) {
    Node * branch;
    branch =  parent(child, root);
    branch = parent(branch, root);
    return branch;

}

RB_node * RB_Tree::uncle(RB_Tree::Node *child, RB_Tree::Node *root) {
    Node* g = grandparent(child, this->root);
    if (g == NULL)
        return NULL; // No grandparent means no uncle
    if (parent(child, this->root) == g->left)
        return (Node*)g->right;
    else
        return (Node*)g->left;


}

void RB_Tree::add_to_tree(int key, void *data) {
    Node * leaf = new Node;
    leaf->right = NULL;
    leaf->left = NULL;
    leaf->key = key;
    leaf->data = data;

    if(root == NULL){
        root = leaf;
        leaf->color = BLACK;
        return;
    }
    leaf->color = RED;
    insert1(leaf, (Node*) root);

}


void RB_Tree::insert1(Node * leaf, Node * root)
{
    unsigned int key = leaf->key;
    unsigned int rootKey = root->key;

    Node * branch = (Node*) root;
    Node * parent = branch;
    if(key > rootKey) {
        if(root->right != NULL) {
            branch = (Node *)root->right;
        }
        else {
            root->right = leaf;
            if (parent->color == BLACK) //проверка балансировки дерева
                return;
            else insert2(leaf, root);
        }
    }
    else {
        if (root->left != NULL) {
            branch = (Node *)root->left;
        }
        else {
            root->left = leaf;
            if (parent->color == BLACK) //проверка балансировки дерева
                return;
            else insert2(leaf, root);
        }
    }
    insert1(leaf, branch);
    return;

}

void RB_Tree::insert2(Node * leaf, Node * root) {
    /*Node * branch = (Node*) search_leaf(60, root);
    Node * bparent;
    root = this->root;
    bparent = parent((RB_node*)branch, root);
    bparent = grandparent((RB_node*)branch, root);*/

}

void RB_Tree::insert3(int key, void* data) {
    return;
}