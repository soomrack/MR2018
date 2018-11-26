#include "avl_library.h"
#include <iostream>
//вспомогательные функции
//----------------------------------------------
unsigned short tree::height(node* p)
{
    return p?p->height:0;
}

int8_t tree::bfactor(node* p)
{
    return (int8_t)(height(p->right)-height(p->left));
}

void tree::realheight(node* p)
{
    unsigned short hleft = height(p->left);
    unsigned short hright = height(p->right);
    p->height = (hleft>hright?hleft:hright)+1;
}
//-------------------------------------------
//основные функции
node* tree::turnright(node* p) // правый поворот вокруг p
{
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    realheight(p);
    realheight(q);
    return q;
}

node* tree::turnleft(node* q) // левый поворот вокруг q
{
    node* p = q->right;
    q->right = p->left;
    p->left = q;realheight(q);
    realheight(p);
    return p;
}

node* tree::balance(node* p) // балансировка узла p
{
    realheight(p);
    if( bfactor(p)==2 )
    {
        if( bfactor(p->right) < 0 )
            p->right = turnright(p->right);
        return turnleft(p);
    }
    if( bfactor(p)==-2 )
    {
        if( bfactor(p->left) > 0 )
            p->left = turnleft(p->left);
        return turnright(p);
    }
    return p; // балансировка не нужна
}

node* tree::insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
    if( !p ) {
        node* A=new node;
A->height=1;
A->key=k;
A->left=0;
A->right=0;
    return A;}
    if( k<p->key )
        p->left = insert(p->left,k);
    else
        p->right = insert(p->right,k);
    return balance(p);
}

node* tree::findmin(node* p) // поиск узла с минимальным ключом в дереве p
{
    return p->left?findmin(p->left):p;
}

node* tree::removemin(node* p) // удаление узла с минимальным ключом из дерева p
{
    if( p->left==0 )
        return p->right;
    p->left = removemin(p->left);
    return balance(p);
}

node* tree::remove(node* p, int k) // удаление ключа k из дерева p
{
    if( !p ) return 0;
    if( k < p->key )
        p->left = remove(p->left,k);
    else if( k > p->key )
        p->right = remove(p->right,k);
    else // k == p->key
    {
        node* q = p->left;
        node* r = p->right;
        delete p;
        if( !r ) return q;
        node* min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}