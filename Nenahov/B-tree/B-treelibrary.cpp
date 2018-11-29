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
            /*if(curnode->childrencount!=0)
            {   t=curnode->children[i]->childorder;
                curnode->children[i]->childorder=t;
                curnode->children[i]->childorder=curnode->children[i-1]->childorder;
            }*/
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
    node *node=searchnode(root,var);
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
        node *par = curnode->parent;
        par->children[par->keyscount] = create(par);
        node *child2 = par->children[par->keyscount];
        sort(par);
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
        double key=curnode->keys[t-1];
        curnode->keys[t-1]=0;
        curnode->keyscount--;
        if(var<key) {
            curnode->keys[t-1]=var;
            curnode->keyscount++;
        }
        else {
            child2->keys[child2->keyscount]=var;
            child2->keyscount++;
        }


        //addtonode(var,curnode);


    }
}








    /*if (!curnode->leaf ) {
        if(var<curnode->keys[0])
        {
            if(curnode->children[0]==0) curnode->children[0]=create(curnode,0);
            addtonode(var, curnode->children[0]);
            return;
        }

        if(var>curnode->keys[curnode->keyscount-1])
        {
            if(curnode->children[curnode->keyscount]==0) curnode->children[curnode->keyscount]=create(curnode,curnode->keyscount);
            addtonode(var, curnode->children[curnode->keyscount]);
            return;
        }

        for (int i = 1; i < curnode->keyscount; i++) {
            if ((((var > curnode->keys[i-1]) && (var < curnode->keys[i]))||((var > curnode->keys[i]) && (curnode->keyscount==1)))) {
                if(curnode->children[i]==0) curnode->children[i]=create(curnode,i);
                addtonode(var, curnode->children[i]);

            }
        }

    } else {
        if (curnode->keyscount < 2*t-1) {
            curnode->keys[curnode->keyscount] = var;
            curnode->keyscount++;
            sort(curnode);
        } else
            {



                if (curnode->parent != 0)
                {
                    node *par = curnode->parent;


                    if(par->keyscount<2*t-1)
                    {
                        par->keys[par->keyscount] = curnode->keys[t-1];
                        par->keyscount++;
                    }
                    else{
                        par->leaf=true;
                        addtonode(curnode->keys[t-1], par);
                        par->leaf=false;
                    }
                        par->children[par->keyscount] = create(par,par->keyscount);
                        node *child2 = par->children[par->keyscount];
                        sort(par);

                        int z=0;
                    for (int i = t; i < 2*t-1; i++)
                    {
                        child2->keys[z] = curnode->keys[i];
                        child2->keyscount++;
                        if(curnode->children[i]) {
                            child2->childrencount++;
                            curnode->children[i]=0;
                            child2->children[z]=curnode->children[i];
                        }
                        z++;

                    }
                        curnode->keyscount = t-1;
                        add(var);
                    }
                else
                {
                    curnode->parent=createuppernode(curnode);
                    node *par = curnode->parent;
                    root=par;
                    par->keys[0] = curnode->keys[t-1];
                    par->keyscount++;
                    par->children[par->keyscount] = create(par,par->keyscount);
                    node *child2 = par->children[par->keyscount];
                    sort(par);
                    // par->children[curnode->childorder+2] = create(par,curnode->childorder+2);    //создание второго узла

                    int z=0;
                    for (int i = t; i < 2*t-1; i++)
                    {
                        child2->keys[z] = curnode->keys[i];
                        child2->keyscount++;
                        if(curnode->children[i]) {
                            child2->childrencount++;
                            curnode->children[i]=0;

                            child2->children[z]=curnode->children[i];
                        }
                        z++;

                    }
                    curnode->keyscount = t-1;
                    add(var);
                }

                    }
                }
            }
*/




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
    //if((curnode->leaf)&&(var>curnode->parent->keys[i]) return
    if(var>curnode->keys[curnode->keyscount-1])
    {
        if(curnode->children[0]==0) return curnode;
        else return searchnode(curnode->children[curnode->keyscount],var);
    }
    for(int i=0;i<curnode->keyscount;i++)
    {
        if(var<curnode->keys[i])
        {
            if(curnode->leaf) return curnode;
            else return searchnode(curnode->children[i],var);
        }
    }


   /* if(var>curnode->keys[curnode->keyscount-1]) ret=searchnode(curnode->children[curnode->keyscount],var);
    if(var<curnode->keys[0]) ret=searchnode(curnode->children[0],var);
    if(var==curnode->keys[0]) ret=curnode;
    for(int i=1;i<curnode->keyscount;i++)
    {
        if((curnode->leaf)&&(var>curnode->parent->keys[i])
        if(var==curnode->keys[i])
        {
            ret=curnode;


        }
        if((var>curnode->keys[i-1])&&(var<curnode->keys[i]))
        {
            ret=searchnode(curnode->children[i],var);
        }

    }
    if (ret==0) std::cout<<"key "<<var<<" not found"<<std::endl;
    return ret;*/
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
            int order=-1;
            for(int i=0;i<curnode->parent->keyscount;i++)
            {
                if(curnode->parent->children[i]==curnode) order=i;
            }
            if((curnode->keyscount>t-1)) {
                deleteinnode(var,curnode);
                return;
            }

            node *prechild=curnode->parent->children[order-1];
            node *postchild=curnode->parent->children[order+1];
            if(postchild->keyscount>(t-1))
            {
                deleteinnode(var,curnode);

                add(curnode->parent->keys[order]);
                curnode->parent->keys[order]=postchild->keys[0];
                deleteinnode(postchild->keys[0],postchild);
                return;
            }
            if((postchild->keyscount<(t-1))&&(prechild->keyscount>(t-1)))
            {

                deleteinnode(var,curnode);
                add(curnode->parent->keys[order]);
                curnode->parent->keys[order]=prechild->keys[prechild->keyscount-1];
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
                //if(curnode->childrencount!=0) curnode->children[k]->childorder--;
            }
            curnode->keyscount--;
        }
    }
}