//
// Created by v2719 on 17.11.2018.
//

#include "B-treelibrary.h"
#include<iostream>



node *tree::create(node *parent,int CO)
{
    node *curnode=new node;
    curnode->childrencount=0;
    curnode->keyscount=0;
    curnode->leaf=true;
    curnode->childorder=CO;

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
            curnode->keys[i]=curnode->keys[i-1];
            curnode->keys[i-1]=k;
            i--;
            if (i==0)
            {
                i=j;
                j++;
            }
        }
    }

    if(curnode->childrencount!=0) {
        i = 1;
        j = 2;
        int t;
        node* z;
        while (i<curnode->childrencount) {
            if (curnode->children[i]->keys[0]>curnode->children[i-1]->keys[0]) {
                i = j;
                j++;
            } else {
                z = curnode->children[i];
                if (curnode->childrencount!=0) t = curnode->children[i]->childorder;
                curnode->children[i] = curnode->children[i-1];
                if (curnode->childrencount!=0)curnode->children[i]->childorder = curnode->children[i-1]->childorder;
                curnode->children[i-1] = z;
                if (curnode->childrencount!=0) curnode->children[i]->childorder = t;
                i--;
                if (i==0) {
                    i = j;
                    j++;
                }
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
            if(curnode->children[0]==0) curnode->children[0]=create(curnode,0);
            addtonode(var, curnode->children[0]);
        }

        if(var>curnode->keys[curnode->keyscount-1])
        {
            if(curnode->children[curnode->keyscount]==0) curnode->children[curnode->keyscount]=create(curnode,curnode->keyscount);
            addtonode(var, curnode->children[curnode->keyscount]);
        }

        for (int i = 1; i < curnode->keyscount; i++) {
            if ((((var > curnode->keys[i-1]) && (var < curnode->keys[i]))||((var > curnode->keys[i]) && (curnode->keyscount==1)))) {
                if(curnode->children[i]==0) curnode->children[i]=create(curnode,i);
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
                    addtonode(curnode->keys[curnode->keyscount / 2], par);                  //вставка медианы в родиетльский узел
                    par->children[par->childrencount] = create(par,par->childrencount);    //создание второго узла
                    node *child2 = par->children[par->childrencount-1];

                    par->leaf = false;


                    for (int i = curnode->keyscount / 2+1; i < curnode->keyscount; i++)
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
                    curnode->children[curnode->childrencount]=create(curnode,curnode->childrencount);
                    for(int i=0;i<curnode->keyscount / 2;i++)
                    {
                        curnode->children[0]->keys[i] = curnode->keys[i];
                        curnode->children[0]->keyscount++;
                    }

                    curnode->children[curnode->childrencount]=create(curnode,curnode->childrencount);
                    for (int i = curnode->keyscount / 2+1; i < curnode->keyscount; i++)
                    {
                        curnode->children[1]->keys[i - curnode->keyscount / 2-1] = curnode->keys[i];
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

double *tree::search(double var)
{
    using namespace std;
     //searchinnode(root,var);
     node *targetnode=searchnode(root,var);
     double *ret=searchinnode(targetnode,var);
     //cout<<"The address of "<<var<<" is "<<ret<<endl;
     return ret;
}

node *tree::searchnode(node *curnode, double var)
{
    node *ret=0;
    if(var>curnode->keys[curnode->keyscount-1]) ret=searchnode(curnode->children[curnode->keyscount-1],var);
    if(var<curnode->keys[0]) ret=searchnode(curnode->children[0],var);
    for(int i=0;i<curnode->keyscount;i++)
    {
        if(var==curnode->keys[i])
        {
            ret=curnode;


        }
        if((var>curnode->keys[i-1])&&(var<curnode->keys[i]))
        {
            searchnode(curnode->children[i],var);
        }

    }
    if (ret==0) std::cout<<"key "<<var<<" not found"<<std::endl;
    return ret;
}


double *tree::searchinnode(node *curnode, double var)
{
    double *ret=0;
    for(int i=0;i<curnode->keyscount;i++)
    {
        if(var==curnode->keys[i]) ret=&curnode->keys[i];
    }
    return ret;
}

void tree::deletekey(double var)
{
    if(root->leaf)
    {
        deleteinnode(var,root);
        return;
    }
    else
    {
        node *curnode=searchnode(root,var);
        if (curnode->leaf)
        {
            if((curnode->keyscount>t-1)) {
                deleteinnode(var,curnode);
                return;
            }
            node *prechild=curnode->parent->children[curnode->childorder-1];
            node *postchild=curnode->parent->children[curnode->childorder+1];
            if(postchild->keyscount>(t-1))
            {
                deleteinnode(var,curnode);

                add(curnode->parent->keys[curnode->childorder]);
                curnode->parent->keys[curnode->childorder]=postchild->keys[0];
                deleteinnode(postchild->keys[0],postchild);
                return;
            }
            if((postchild->keyscount<(t-1))&&(prechild->keyscount>(t-1)))
            {

                deleteinnode(var,curnode);
                add(curnode->parent->keys[curnode->childorder]);
                curnode->parent->keys[curnode->childorder]=prechild->keys[prechild->keyscount-1];
                deleteinnode(prechild->keys[prechild->keyscount-1],prechild);
            }
        }
        else
        {
            node* Dnode=curnode;
            int keynumber;
            for(int i=0;i<curnode->keyscount;i++) if(var==curnode->keys[i]) keynumber=i;
            do {
                curnode=curnode->children[keynumber];
            }
            while(!curnode->leaf);
            double Replacekey=curnode->keys[curnode->keyscount-1];
            deleteinnode(Replacekey,curnode);
            Dnode->keys[keynumber]=Replacekey;



        }
    }

}

void tree::deleteinnode(double var, node *curnode) {
    for (int i = 0; i < curnode->keyscount; i++) {
        if (var == curnode->keys[i]) {
            for (int k = i; k < curnode->keyscount-1; k++) {
                curnode->keys[k] = curnode->keys[k+1];
                curnode->children[k]=curnode->children[k+1];
                if(curnode->childrencount!=0) curnode->children[k]->childorder--;
            }
            curnode->keyscount--;
        }
    }
}