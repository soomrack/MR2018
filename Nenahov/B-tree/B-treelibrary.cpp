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
    //curnode->childorder=CO;

    parent->childrencount++;
    curnode->parent=parent;
    for(int i=0;i<2*t;i++)
    {
        curnode->children[i]=0;
    }
    for(int i=0;i<2*t-1;i++)
    {
        curnode->keys[i]=0;
    }
    return curnode;
}

node *tree::createuppernode()
{
    node *curnode=new node;
    root->parent=curnode;
    curnode->childrencount=1;
    root->childorder=0;
    curnode->children[0]=root;
    curnode->keyscount=0;
    curnode->leaf=false;
    //curnode->keys[0]=root->keys[t-1];
    //curnode->keyscount++;
    root=curnode;
    curnode->parent=0;
    for(int i=1;i<2*t;i++)
    {
        curnode->children[i]=0;
    }
    for(int i=1;i<2*t-1;i++)
    {
        curnode->keys[i]=0;
    }
    return curnode;
}

void tree::sortchildren(node *curnode)
{
    int i=1;
    int j=2;
    int t;
    node* z;
    while (i<curnode->keyscount+1) {
        if (curnode->children[i]->keys[0]>curnode->children[i-1]->keys[0]) {
            i = j;
            j++;
        } else {
            z = curnode->children[i];
            curnode->children[i] = curnode->children[i-1];
            curnode->children[i-1] = z;
            i--;
            if (i==0) {
                i = j;
                j++;
            }
        }
    }
}


void tree::sort(node *curnode)
{
    int i=1;
    int j=2;
    double k;
    int t;
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
    using namespace std;
    node *node=searchnode(root,var);
    double *position=searchinnode(node,var);
    if(position!=0) cout<<var<<" has already been added to address "<<search(var)<<endl;
    addtonode(var,node);
}



void tree::addtonode(double var, node *curnode) {
    if ((curnode->keyscount < 2 * t - 1)) {
        curnode->keys[curnode->keyscount] = var;
        curnode->keyscount++;
        sort(curnode);
    } else {

        if (!curnode->parent) createuppernode();
        addtonode(curnode->keys[t-1],curnode->parent);


        double key=curnode->keys[t-1];
        node *par = curnode->parent;
        par->children[par->keyscount] = create(par);
        node *child2 = par->children[par->keyscount];

        int medianposition;
        for(int i=0;i<par->keyscount;i++)
        {
            if(par->keys[i]==curnode->keys[t-1]) medianposition=i;
        }



        int z = 0;
        for (int i = t; i < 2 * t - 1; i++) {
            child2->keys[z] = curnode->keys[i];
            child2->keyscount++;
            curnode->keys[i]=0;
            curnode->keyscount--;
            if (curnode->children[i]) {
                child2->childrencount++;
                child2->children[z] = curnode->children[i];
                curnode->children[i]->parent=child2;
                curnode->children[i] = 0;


            }
            z++;
        }
        if (curnode->children[2 * t - 1]) {
            child2->childrencount++;
            child2->children[z] = curnode->children[2 * t - 1];
            curnode->children[2 * t - 1]->parent=child2;
            curnode->children[2 * t - 1] = 0;
        }

        curnode->keys[t-1]=0;
        curnode->keyscount--;
        if(var<key) {
            curnode->keys[t-1]=var;
            curnode->keyscount++;
            sort(curnode);
        }
        else {
            child2->keys[child2->keyscount]=var;
            child2->keyscount++;
            sort(child2);
        }
        sort(par);
        sortchildren(par);





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
     node *targetnode=searchnode(root,var);
     double *ret=searchinnode(targetnode,var);

     return ret;
}

node *tree::searchnode(node *curnode, double var)
{
    if(curnode->keyscount==0) return curnode;
    if(var>=curnode->keys[curnode->keyscount-1])
    {
        if(curnode->children[0]==0) return curnode;
        else return searchnode(curnode->children[curnode->keyscount],var);
    }
    for(int i=0;i<curnode->keyscount;i++)
    {
        if(var<curnode->keys[i])
        {
            if(curnode->children[i]==0) return curnode;
            else return searchnode(curnode->children[i],var);
        }
        if((curnode->keyscount==1)&&(var==curnode->keys[0])) return curnode;
    }
   return 0;
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
    deleteinnode(var,searchnode(root,var));

}

void tree::deleteinnode(double var, node *curnode) {
    if(curnode->children[0]==0) {
        for (int i = 0; i < curnode->keyscount; i++) {
            if (var == curnode->keys[i]) {
                for (int k = i; k < curnode->keyscount; k++) {
                    curnode->keys[k] = curnode->keys[k + 1];
                    curnode->children[k] = curnode->children[k + 1];

                }
                curnode->keyscount--;
            }
        }

        if(curnode->keyscount<t-1)
        {
            int order=-1;
            for(int i=0;i<curnode->parent->keyscount+1;i++)
            {
                if(curnode->parent->children[i]==curnode) order=i;
            }
            node *prechild=curnode->parent->children[order-1];
            node *postchild=curnode->parent->children[order+1];
            if(postchild!=NULL) {
                if (postchild->keyscount > (t - 1))
                {


                    add(curnode->parent->keys[order+1]);
                    curnode->parent->keys[order+1] = postchild->keys[0];
                    deleteinnode(postchild->keys[0], postchild);
                    return;
                }
                for(int i=curnode->keyscount-1;i<curnode->keyscount+postchild->keyscount;i++)
                {
                    curnode->keys[i]=postchild->keys[i];
                    curnode->keyscount++;

                }
                delete curnode->parent->children[order+1];
                sort(curnode->parent);
                deleteinnode(curnode->parent->keys[order+1],curnode->parent);
                return;
            }
            if(prechild!=NULL) {
                if (prechild->keyscount > (t - 1)) {


                    addtonode(curnode->parent->keys[order],curnode);
                    curnode->parent->keys[order] = prechild->keys[prechild->keyscount - 1];
                    deleteinnode(prechild->keys[prechild->keyscount - 1], prechild);
                    return;
                }
                for(int i=curnode->keyscount-1;i<curnode->keyscount+prechild->keyscount;i++)
                {
                    curnode->keys[i]=prechild->keys[i];
                    curnode->keyscount++;

                }
                delete curnode->parent->children[order];
                sort(curnode->parent);
                deleteinnode(curnode->parent->keys[order],curnode->parent);
                return;
            }


        }

        }

    else
    {
        node* Dnode=curnode;
        int keynumber;
        for(int i=0;i<curnode->keyscount;i++) if(var==curnode->keys[i]) keynumber=i;
        curnode=curnode->children[keynumber];

        do {
            curnode=curnode->children[curnode->keyscount];
        }
        while(curnode->children[0]!=0);
        double Replacekey=curnode->keys[curnode->keyscount-1];
        deleteinnode(Replacekey,curnode);
        Dnode->keys[keynumber]=Replacekey;

    }
}