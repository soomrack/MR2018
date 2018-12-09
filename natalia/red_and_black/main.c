#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define RED 1
#define BLACK 0

typedef struct tree
{
    bool color;               //цвет узла
    int data;              // данные
    struct tree *left;  // левый  сын
    struct tree *right; // правый сын
    struct tree *parent; //родитель
} TREE;


void insert_case1(TREE *n);
void insert_case2(TREE *n);
void insert_case3(TREE *n);
void insert_case4(TREE *n);
void insert_case5(TREE *n);
void delete_node(TREE *root);
void balance_delete_1(TREE *root);
void balance_delete_2(TREE *root);
void balance_delete_3(TREE *root);
void balance_delete_4(TREE *root);

TREE *grandparent(TREE *n)
{
    if ((n != NULL) && (n->parent != NULL))
        return n->parent->parent;
    else
        return NULL;
}

TREE *uncle(TREE *n)
{
    TREE *g = grandparent(n);
    if (g == NULL)
        return NULL; // No grandparent means no uncle
    if (n->parent == g->left)
        return g->right;
    else
        return g->left;
}

TREE *sibling(TREE *n)
{
    if (n == n->parent->left)
        return n->parent->right;
    else
        return n->parent->left;
}

void rotate_right(TREE *n)
{
    TREE *pivot = n->left;

    pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
    if (n->parent != NULL) {
        if (n->parent->left==n)
            n->parent->left = pivot;
        else
            n->parent->right = pivot;
    }

    n->left = pivot->right;
    if (pivot->right != NULL)
        pivot->right->parent = n;

    n->parent = pivot;
    pivot->right = n;
}

void rotate_left(TREE *n)
{
    TREE *pivot = n->right;

    pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
    if (n->parent != NULL) {
        if (n->parent->left==n)
            n->parent->left = pivot;
        else
            n->parent->right = pivot;
    }

    n->right = pivot->left;
    if (pivot->left != NULL)
        pivot->left->parent = n;

    n->parent = pivot;
    pivot->left = n;
}






TREE *find_succesor(TREE *root, TREE * new_node)
{
    TREE * successor;
    while (root!=NULL) {
        successor = root;
        if (root->data < new_node->data)
            root = root->right;
        else
            root = root->left;

    }
    new_node->parent = successor;
    if (successor->data < new_node->data)
    {
        successor->right = new_node;
    }
    else {
        successor->left = new_node;
    }
    return successor;
}



void insert_case2(TREE *n)
{
    if (n->parent->color == BLACK)
        return; /* Tree is still valid */
    else
        insert_case3(n);
}

void insert_case1(TREE *n)
{
    if (n->parent == NULL)
        n->color = BLACK;
    else
        insert_case2(n);
}

void insert_case3(TREE *n)
{
    TREE *u = uncle(n), *g;

    if ((u != NULL) && (u->color == RED)) {
        // && (n->parent->color == RED) Второе условие проверяется в insert_case2, то есть родитель уже является красным.
        n->parent->color = BLACK;
        u->color = BLACK;
        g = grandparent(n);
        g->color = RED;
        insert_case1(g);
    } else {
        insert_case4(n);
    }
}

void insert_case4(TREE *n)
{
    TREE *g = grandparent(n);

    if ((n == n->parent->right) && (n->parent == g->left)) {
        rotate_left(n->parent);
        n = n->left;
    } else if ((n == n->parent->left) && (n->parent == g->right)) {
        rotate_right(n->parent);
        n = n->right;
    }
    insert_case5(n);
}

void insert_case5(TREE *n) {
    TREE *g = grandparent(n);

    n->parent->color = BLACK;
    g->color = RED;
    if ((n == n->parent->left) && (n->parent == g->left)) {
        rotate_right(g);
    } else {
        rotate_left(g);
    }
}

TREE *add_to_tree(TREE *root, int new_value)
{
    TREE *new_node;
    new_node = (TREE*)malloc(sizeof(TREE));

    new_node->data = new_value;
    new_node->left = new_node->right = NULL;
    new_node->color = RED;
    if (root==NULL)  // если нет сыновей - создаем новый элемент
    {
        root = (TREE*)malloc(sizeof(TREE));
        root = new_node;
        new_node->parent = NULL;
    }
    else
    {
        root = find_succesor(root, new_node);
    }
    insert_case1(new_node);
    return root;
}


/* тестовая программа */
void main() {
    int i;
    int a[14]={ 0,7,8,3,52,14,16,18,15,13,42,30,35,26 };
    TREE *root;
    root = NULL;
    for (i=0; i<14; i++)        // проход массива и заполнение дерева
        root = add_to_tree(root, a[i]);
    root = root->parent->parent;
    delete_node(root);

}

void delete_node(TREE *root) {

    if (root->parent == NULL) {
        root = NULL;
        return;
    }
    if ((root->right == NULL) && (root->left == NULL)) {
        if (root->parent->left == root)
            root->parent->left = NULL;
        else root->parent->right = NULL;
        if (root->color == RED)
            root = root -> parent;
        else {
            root = root -> parent;
            balance_delete_1(root);
        }

        //free(node);
        return;
    }
    else {
        if ((root->right == NULL) && (root->left != NULL))
            if (root->parent->left == root)
                root->parent->left = root->parent->left->left;
            else root->parent->right = root->parent->right->left;
        if ((root->right != NULL) && (root->left == NULL))
            if (root->parent->left == root)
                root->parent->left = root->parent->left->right;
            else root->parent->right = root->parent->right->right;

        if ((root->right != NULL) && (root->left != NULL)) {
            TREE *node = root;
            node = node->right;
            while (node->left != NULL) {
                node = node->left;
            }
            root -> data = node-> data;
            //free (node);
            root = root ->right;
            while (root->left != NULL) {
                root = root->left;
            }
            delete_node(root);

        }
    }
}

void balance_delete_1(TREE *root) {
    if ((root->color != BLACK) || (root->parent == NULL) )
        return;
    TREE *s = sibling(root);
    if ((s != NULL)&& (s->color == RED)) {
        if (root->parent->left == s) {
            root ->parent->color = RED;
            root->parent->left->color = BLACK;
            rotate_right(root->parent);
        }
        else {
            root ->parent->color = RED;
            root->parent->right->color = BLACK;
            rotate_left(root->parent);
        }
        root = root->parent;
        balance_delete_1(root);
    }
    else balance_delete_2(root);


};

void balance_delete_2(TREE *root) {
    TREE *s = sibling(root);
    if ((s->left == NULL)&&(s->right == NULL) || (s->left->color == BLACK)&&(s->right->color == BLACK)  ) {

        if (root->parent->left == s)
            root->parent->left->color = RED;
        else root->parent->right->color = RED;
        root->parent->color = BLACK;
        root = root->parent;
        balance_delete_1(root);
    }
    else balance_delete_3(root);
}


void balance_delete_3(TREE *root) {
    TREE *s = sibling(root);
    if (((s->right == NULL)||(s->right->color == BLACK)) && (s->left->color == RED)) {
        if (root->parent->left == s) {
            root->parent->left->color = RED;
            root->parent->left->left->color = BLACK;
            rotate_left(root->parent->left);
        } else {
            root->parent->right->color = RED;
            root->parent->right->left->color = BLACK;
            rotate_left(root->parent->right);
        }
        root = root->parent;
        balance_delete_1(root);
    }
    else balance_delete_4(root);
}



void balance_delete_4(TREE *root) {
    TREE *s = sibling(root);
    if (s->right->color == RED) {
        if (root->parent->left == s) {
            root->parent->left->color = root->parent->color;
            root->parent->left->right->color = BLACK;
            root->parent->color = BLACK;
            rotate_right(root->parent);
        } else {
            root->parent->right->color = root->parent->color;
            root->parent->right->right->color = BLACK;
            root->parent->color = BLACK;
            rotate_right(root->parent);
        }
    }
    root = root->parent;
    balance_delete_1(root);
}