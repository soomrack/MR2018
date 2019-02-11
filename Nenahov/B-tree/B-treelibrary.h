//
// Created by v2719 on 17.11.2018.
//
#include <iostream>
#include <ctime>
#include<random>
#ifndef B_TREE_B_TREELIBRARY_H
#define B_TREE_B_TREELIBRARY_H

#endif //B_TREE_B_TREELIBRARY_H

const int t=3;

struct node{
    node *parent;
    node *children[2*t];
    double keys[2*t-1];
    int keyscount;
};

class tree{

public:
    node *root;
    void add(double var);


    double *search(double var);
    void deletekey(double var);
    tree()
    {
        root=new node;
       // root->leaf=true;
        root->keyscount=0;
        //root->childrencount=0;
        root->parent=nullptr;
        for(int i=0;i<2*t;i++)
        {
            root->children[i]=nullptr;
        }
    }

private:
    void addtonode(node *curnode,double var);
    node *create(node *parent);
    node* searchnode(node *curnode,double var);
    double *searchinnode(node *curnode, double var);
    void deleteinnode(node *curnode,double var);
    void sortchildren(node * curnode);
    node *createuppernode();
    void sort(node *curnode);
    void deleteinleaf(node* curnode,double var);
    void mergenodes(node* firstnode, node* secondnode);
};

