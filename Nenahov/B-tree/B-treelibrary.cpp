//
// Created by v2719 on 17.11.2018.
//

#include "B-treelibrary.h"
#include<iostream>



node *tree::create(node *parent)
{
    node *curnode=new node;
    curnode->childrencount=0;
    curnode->keyscount=0;
    curnode->leaf=true;

    parent->childrencount++;
    curnode->parent=parent;
    return curnode;
}


void tree::sort(node *curnode)
{
    int i=1;
    int j=2;
    double k;
    node *z;
    while(i<curnode->keyscount)
    {
        if(curnode->keys[i]>curnode->keys[i-1])
        {
            i=j;
            j++;
        }
        else
        {
            k=curnode->keys[i];
            z=curnode->children[i];
            curnode->keys[i]=curnode->keys[i-1];
            curnode->children[i]=curnode->children[i-1];
            curnode->keys[i-1]=k;
            curnode->children[i-1]=z;
            i--;
            if (i==0)
            {
                i=j;
                j++;
            }
        }
    }
}

void tree::add(double var)
{
    addtonode(var,root);
}

void tree::addtonode(double var, node *curnode) {
    if (!curnode->leaf ) {
        for (int i = 0; i < curnode->keyscount; i++) {
            if ((var > curnode->keys[i]) && (var < curnode->keys[i + 1])) {
                curnode->children[i]=create(curnode);
                addtonode(var, curnode->children[i]);

            }
        }

    } else {
        if (curnode->keyscount < t) {
            curnode->keys[curnode->keyscount] = var;
            curnode->keyscount++;
            sort(curnode);
        } else
            {
                if (curnode->parent != 0)
                {
                    node *par = curnode->parent;

                    node *child2 = par->children[curnode->keyscount / 2];
                    par->leaf = true;
                    par->children[curnode->keyscount / 2] = create(curnode);    //создание второго узла
                    addtonode(curnode->keys[curnode->keyscount / 2], par);    //вставка медианы в родиетльский узел
                    par->leaf = false;


                    for (int i = curnode->keyscount / 2; i < curnode->keyscount; i++)
                    {
                        child2->keys[i - curnode->keyscount / 2] = curnode->keys[i];
                    }

                    child2->parent = par;
                    child2->keyscount = curnode->keyscount - curnode->keyscount / 2;

                    curnode->keyscount /= 2;
                    add(var);
                }
                else
                {
                    curnode->children[curnode->childrencount]=create(curnode);
                    //curnode->children[curnode->childrencount]->parent=curnode;
                    for (int i = curnode->keyscount / 2; i < curnode->keyscount; i++)
                    {
                        curnode->children[curnode->childrencount-1]->keys[i - curnode->keyscount / 2] = curnode->keys[i];
                        curnode->children[curnode->childrencount-1]->keyscount++;
                    }
                    curnode->keyscount/=2;
                    curnode->childrencount++;
                    curnode->leaf=false;
                    curnode=curnode->children[0];
                    add(var);
                }
            }
        }
        }



void tree::print()
{
    using namespace std;
    node *curnode=root;
    while(!curnode->leaf)
    {
        std::cout<<"(\t";
        for(int i=0;i<curnode->keyscount;i++)
            std::cout<<curnode->keys[i]<<"\t";
        cout<<")"<<endl;
     curnode=curnode->children[0];

    }


    std::cout<<"(\t";
    for(int i=0;i<curnode->keyscount;i++)
        std::cout<<curnode->keys[i]<<"\t";
    cout<<")"<<endl;
}