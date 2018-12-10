//
// Created by v2719 on 17.11.2018.
//
#include <iostream>
#include <ctime>
#ifndef B_TREE_B_TREELIBRARY_H
#define B_TREE_B_TREELIBRARY_H

#endif //B_TREE_B_TREELIBRARY_H

const int t=3;

struct node{
    node *parent;
    node *children[2*t];
    bool leaf;
    double keys[2*t-1];
    int keyscount;
    int childrencount;
    int childorder;
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
        root->leaf=true;
        root->keyscount=0;
        root->childrencount=0;
        root->parent=0;
        for(int i=0;i<2*t;i++)
        {
            root->children[i]=0;
        }


    };
private:
    void addtonode(double var,node *curnode);
    node *create(node *parent);
    node* searchnode(node *curnode,double var);
    double *searchinnode(node *curnode, double var);
    void deleteinnode(double var, node *curnode);
    void sortchildren(node * curnode);
    node *createuppernode();
    void sort(node *curnode);

};

