//
// Created by v2719 on 17.11.2018.
//

#ifndef B_TREE_B_TREELIBRARY_H
#define B_TREE_B_TREELIBRARY_H

#endif //B_TREE_B_TREELIBRARY_H

const int t=6;

struct node{
    node *parent;
    node *children[2*t+1];
    bool leaf;
    double keys[2*t];
    int keyscount;
    int childrencount;
};

class tree{

public:
    node *root;
    node *currentnode;
    void add(double var);
    void sort(node *curnode);
    void print();
    tree()
    {
        currentnode=new node;
        root=new node;
        root->leaf=true;
        root->keyscount=0;
        root->childrencount=0;
        root->parent=0;


    };
private:
    void addtonode(double var,node *curnode);
    node *create(node *parent);

};

