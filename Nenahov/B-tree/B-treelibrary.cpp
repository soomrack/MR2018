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
    for(int i=0;i<2*t;i++)
    {
        curnode->children[i]=0;
    }
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
        if(var<curnode->keys[0])
        {
            if(curnode->children[0]==0) curnode->children[0]=create(curnode);
            addtonode(var, curnode->children[0]);
        }

        if(var>curnode->keys[curnode->keyscount-1])
        {
            if(curnode->children[curnode->keyscount]==0) curnode->children[curnode->keyscount]=create(curnode);
            addtonode(var, curnode->children[curnode->keyscount]);
        }

        for (int i = 1; i < curnode->keyscount; i++) {
            if (((var > curnode->keys[i]) && (var < curnode->keys[i + 1])||((var > curnode->keys[i]) && (curnode->keyscount==1)))) {
                if(curnode->children[i]==0) curnode->children[i]=create(curnode);
                addtonode(var, curnode->children[i]);

            }
        }

    } else {
        if (curnode->keyscount < 2*t) {
            curnode->keys[curnode->keyscount] = var;
            curnode->keyscount++;
            sort(curnode);
        } else
            {
                if (curnode->parent != 0)
                {
                    node *par = curnode->parent;


                    par->leaf = true;
                    par->children[curnode->keyscount / 2] = create(curnode);    //создание второго узла
                    node *child2 = par->children[curnode->keyscount / 2];
                    addtonode(curnode->keys[curnode->keyscount / 2], par);    //вставка медианы в родиетльский узел
                    par->leaf = false;


                    for (int i = curnode->keyscount / 2; i < curnode->keyscount; i++)
                    {
                        child2->keys[i - curnode->keyscount / 2] = curnode->keys[i];
                    }

                    child2->parent = par;
                    child2->keyscount = curnode->keyscount - curnode->keyscount / 2;

                    curnode->keyscount /= 2;
                    addtonode(var,curnode);
                }
                else
                {
                    curnode->children[curnode->childrencount]=create(curnode);
                    for(int i=0;i<curnode->keyscount / 2;i++)
                    {
                        curnode->children[0]->keys[i] = curnode->keys[i];
                        curnode->children[0]->keyscount++;
                    }

                    curnode->children[curnode->childrencount]=create(curnode);
                    for (int i = curnode->keyscount / 2; i < curnode->keyscount; i++)
                    {
                        curnode->children[1]->keys[i - curnode->keyscount / 2] = curnode->keys[i];
                        curnode->children[1]->keyscount++;
                    }

                    curnode->keys[0]=curnode->keys[curnode->keyscount/2];
                    curnode->keyscount=1;
                    curnode->leaf=false;
                    addtonode(var,curnode);
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