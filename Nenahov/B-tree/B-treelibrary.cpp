//
// Created by v2719 on 17.11.2018.
//

#include "B-treelibrary.h"
#include<iostream>



node *tree::create(node *parent)
{
    node *curnode=new node;
   // curnode->childrencount=0;
    curnode->keyscount=0;
   // curnode->leaf=true;
    //curnode->childorder=CO;

  //  parent->childrencount++;
    curnode->parent=parent;
    for(int i=0;i<2*t;i++)
    {
        curnode->children[i]=nullptr;
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
   // curnode->childrencount=1;
  // root->childorder=0;
    curnode->children[0]=root;
    curnode->keyscount=0;
   // curnode->leaf=false;
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
        if ((curnode->children[i]->keys[0]>curnode->children[i-1]->keys[0])||(curnode->children[i]==nullptr)) {
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
    if(position!=0) {
        cout<<var<<" has already been added to address "<<search(var)<<endl;
        return;
    }
    addtonode(node,var);
}



void tree::addtonode(node *curnode,double var) {
    if ((curnode->keyscount < 2 * t - 1)) {
        curnode->keys[curnode->keyscount] = var;
        curnode->keyscount++;
        sort(curnode);
    } else {

        if (!curnode->parent) createuppernode();
        addtonode(curnode->parent,curnode->keys[t-1]);
        double key=curnode->keys[t-1];
        node *par = curnode->parent;
        par->children[par->keyscount] = create(par);
        node *child2 = par->children[par->keyscount];
        int z = 0;
        for (int i = t; i < 2 * t - 1; i++) {
            child2->keys[z] = curnode->keys[i];
            child2->keyscount++;
            curnode->keys[i]=0;
            curnode->keyscount--;
            if (curnode->children[i]) {
              //  child2->childrencount++;
                child2->children[z] = curnode->children[i];
                curnode->children[i]->parent=child2;
                curnode->children[i] = 0;
            }
            z++;
        }
        if (curnode->children[2 * t - 1]) {
          //  child2->childrencount++;
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
       // if((child2->children[0]!=0)&&(child2->children[child2->keyscount]==0)) std::cout<<"children count is incorrect"<<child2->keys[0]<<std::endl;




    }
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
    if(var>curnode->keys[curnode->keyscount-1])
    {
        if(curnode->children[0]==0) return curnode;
        else return searchnode(curnode->children[curnode->keyscount],var);
    }
    for(int i=0;i<curnode->keyscount;i++)
    {
        if(var==curnode->keys[i]) return curnode;
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
    deleteinnode(searchnode(root,var),var);
    if(root->keyscount==0)
    {
        root=root->children[0];
        delete root->parent;
        root->parent=nullptr;
    }

}

void tree::deleteinnode(node *curnode,double var) {
    if(curnode->children[0]==0) {
        deleteinleaf(curnode,var);
        }
    else
    {
        node* Dnode=curnode;
        int keynumber;
        for(int i=0;i<curnode->keyscount;i++) if(var==curnode->keys[i]) keynumber=i;
        curnode=curnode->children[keynumber];
        if(curnode->children[0]!=0) {
            do {
                curnode = curnode->children[curnode->keyscount];
            } while (curnode->children[0] != 0);
        }
        double Replacekey=curnode->keys[curnode->keyscount-1];
        deleteinnode(curnode,Replacekey);
        Dnode->keys[keynumber]=Replacekey;

    }
}

void tree::deleteinleaf(node* curnode,double var)
{
    for (int i = 0; i < curnode->keyscount; i++) {
        if (var == curnode->keys[i]) {
            for (int k = i; k < curnode->keyscount; k++) {
                curnode->keys[k] = curnode->keys[k + 1];


            }
            curnode->keyscount--;
        }
    }
    if(curnode->parent==nullptr) return;
    if(curnode->keyscount<t-1)
    {
        int order=-1;
        for(int i=0;i<curnode->parent->keyscount+1;i++)
        {
            if(curnode->parent->children[i]==curnode) order=i;
            break;
        }
        node *prechild=nullptr;
        if(order!=0) prechild=curnode->parent->children[order-1];
        node *postchild=nullptr;
        if(order!=curnode->parent->keyscount) postchild=curnode->parent->children[order+1];
        if(postchild!=nullptr) {
            if (postchild->keyscount > (t - 1))
            {
                addtonode(curnode,curnode->parent->keys[order]);
                if(curnode->children[0]!=nullptr) {
                    curnode->children[curnode->keyscount] = postchild->children[0];
                    postchild->children[0]->parent = curnode;
                }
                curnode->parent->keys[order] = postchild->keys[0];
                deleteinleaf(postchild,postchild->keys[0]);
                //delete postchild->children[0];
                postchild->children[0]=nullptr;

                for(int i=0;i<=postchild->keyscount+1;i++)
                {
                    postchild->children[i]=postchild->children[i+1];
                }
                return;
            }

        }
        if(prechild!=nullptr) {
            if (prechild->keyscount > (t - 1)) {
                addtonode(curnode,curnode->parent->keys[order-1]);
                if(curnode->children[0]!=nullptr) {
                    for(int i=curnode->keyscount+1;i>0;i--)
                    {
                        curnode->children[i]=curnode->children[i-1];
                    }
                    curnode->children[0] = prechild->children[prechild->keyscount];
                    prechild->children[prechild->keyscount]->parent = curnode;
                }
                curnode->parent->keys[order-1] = prechild->keys[prechild->keyscount - 1];
                deleteinleaf(prechild,prechild->keys[prechild->keyscount - 1]);
                //delete prechild->children[prechild->keyscount];
                prechild->children[prechild->keyscount]=nullptr;
                return;
            }
        }
        if((curnode->parent->children[order+1]!=nullptr)&&(postchild->keyscount<=(t-1)))
        {
            mergenodes(curnode,postchild);
            return;
        }
        if((curnode->parent->children[order-1]!=nullptr)&&(prechild->keyscount<=(t-1)))
        {
            mergenodes(prechild,curnode);
            return;
        }



    }

}

void tree::mergenodes(node* curnode,node* postchild)
{
    int order=-1;
    for(int i=0;i<curnode->parent->keyscount+1;i++)
    {
        if(curnode->parent->children[i]==curnode)
        {
            order = i;
            break;
        }
    }

    addtonode(curnode,curnode->parent->keys[order]);
    int z=0;
    for(int i=curnode->keyscount;i<curnode->keyscount+postchild->keyscount+1;i++)
    {
        curnode->keys[i]=postchild->keys[z];
        curnode->children[i]=postchild->children[z];
        z++;
    }
    curnode->keyscount+=postchild->keyscount;
    for (int j=0; j<curnode->keyscount+1; j++){
        if (curnode->children[j]==nullptr) break;
        curnode->children[j]->parent=curnode;
    }

  /*  if(postchild->children[0]!=nullptr) {
        for (int i = 0;i < postchild->children[0]->keyscount; i++)   //merge the last child and the first child of the next node
        {
            addtonode(curnode->children[curnode->keyscount], postchild->children[0]->keys[i]);
        }
    }*/


    delete curnode->parent->children[order+1];
    curnode->parent->children[order+1]=nullptr;


    for(int i=order+1;i<curnode->parent->keyscount+1;i++)
    {
        curnode->parent->children[i]=curnode->parent->children[i+1];
    }


    deleteinleaf(curnode->parent,curnode->parent->keys[order]);
}