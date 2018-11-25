#include <iostream>
#ifndef AVL_TREES_AVL_LIBRARY_H
#define AVL_TREES_AVL_LIBRARY_H

struct node // структура для представления узлов дерева
{
    int key;//текущий ключ
    unsigned short height;//высота поддерева с корнем в текущем узле
    node* left;//указатель на левое дерево
    node* right;//указатель на правое дерево
    node(int k) { key = k; left = right = 0; height = 1; }//конструктор создания нового узла с ключом k
    node(){ key = 0; left = right = 0; height = 1; }//конструктор создания нового узла
};
extern node* turnright(node* p);
extern node* turnleft(node* q);
extern node* findmin(node* p);
extern node* removemin(node* p);
extern node* remove(node* p, int k);
extern node* insert(node* p, int k);
extern node* balance(node* p);
#endif //AVL_TREES_AVL_LIBRARY_H
