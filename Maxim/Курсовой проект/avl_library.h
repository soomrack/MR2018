#include <iostream>
#ifndef AVL_TREES_AVL_LIBRARY_H
#define AVL_TREES_AVL_LIBRARY_H

struct node // структура для представления узлов дерева
{
    int key;//текущий ключ
    unsigned short height;//высота поддерева с корнем в текущем узле
    node* left;//указатель на левое дерево
    node* right;//указатель на правое дерево


};
class tree{

public:
    node *root;
    node* turnright(node* p);
    node* turnleft(node* q);
    node* findmin(node* p);
    node* removemin(node* p);
    node* remove(node* p, int k);
    node* search(node* p, int k);
    node* insert(node* p, int k);
    node* balance(node* p);
    tree()
    {
        root=new node;
        root->left=0;
        root->right=0;
        root->key=0;
        root->height=1;
    };
private:
    unsigned short height(node* p);
    int8_t bfactor(node* p);
    void realheight(node* p);
};
#endif //AVL_TREES_AVL_LIBRARY_H
