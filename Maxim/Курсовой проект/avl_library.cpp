#include "avl_library.h"
#include <iostream>
//вспомогательные функции
//----------------------------------------------
unsigned short height(node* p)
{
    return p?p->height:0;
}

int8_t bfactor(node* p)
{
    return (int8_t)(height(p->right)-height(p->left));
}

void realheight(node* p)
{
    unsigned short hleft = height(p->left);
    unsigned short hright = height(p->right);
    p->height = (hleft>hright?hleft:hright)+1;
}
//-------------------------------------------
//основные функции
extern node* turnright(node* p) // правый поворот вокруг p
{
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    realheight(p);
    realheight(q);
    return q;
}

extern node* turnleft(node* q) // левый поворот вокруг q
{
    node* p = q->right;
    q->right = p->left;
    p->left = q;realheight(q);
    realheight(p);
    return p;
}

extern node* balance(node* p) // балансировка узла p
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

extern node* insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
    if( !p ) return new node(k);
    if( k<p->key )
        p->left = insert(p->left,k);
    else
        p->right = insert(p->right,k);
    return balance(p);
}

extern node* findmin(node* p) // поиск узла с минимальным ключом в дереве p
{
    return p->left?findmin(p->left):p;
}

extern node* removemin(node* p) // удаление узла с минимальным ключом из дерева p
{
    if( p->left==0 )
        return p->right;
    p->left = removemin(p->left);
    return balance(p);
}

extern node* remove(node* p, int k) // удаление ключа k из дерева p
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