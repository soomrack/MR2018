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

void insert_case1(TREE *n);
void insert_case2(TREE *n);
void insert_case3(TREE *n);
void insert_case4(TREE *n);
void insert_case5(TREE *n);

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

        /*
         * rotate_left может быть выполнен следующим образом, учитывая что уже есть *g =  grandparent(n)
         *
         * struct node *saved_p=g->left, *saved_left_n=n->left;
         * g->left=n;
         * n->left=saved_p;
         * saved_p->right=saved_left_n;
         *
         */

        n = n->left;
    } else if ((n == n->parent->left) && (n->parent == g->right)) {
        rotate_right(n->parent);

        /*
         * rotate_right может быть выполнен следующим образом, учитывая что уже есть *g =  grandparent(n)
         *
         * struct node *saved_p=g->right, *saved_right_n=n->right;
         * g->right=n;
         * n->right=saved_p;
         * saved_p->left=saved_right_n;
         *
         */

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
    } else { /* (n == n->parent->right) && (n->parent == g->right) */
        rotate_left(g);
    }
}

void fixDeleting(TREE *key)
{
    // далее родственные связи относительно p
    while (key->color ==BLACK && key->parent != NULL)
        if (key->parent->left == key) { //if p — левый ребенок
            if (key->parent->right->color == RED) { //if "брат" красный
                key->parent->right->color = BLACK; //brother = black
                key->parent->color = RED; //parent = red
                rotate_left(key->parent);
            }
            if ((key->parent->right->left ==NULL && key->parent->right->right == NULL)||(key->parent->right->left->color == BLACK && key->parent->right->right->color == BLACK)) //if у "брата" черные дети
                key->parent->right->color = RED;
            else {
                if (key->parent->right->right->color == BLACK) {
                    key->parent->right->left->color = BLACK; // "брат" красный с черными правым ребенком
                    key->parent->right->color = RED; //брат красный
                    rotate_right(key->parent->right);
                }
                key->parent->right->color = key->parent->color;
                key->parent->color = BLACK;
                key->parent->right->right->color = BLACK;
                rotate_left(key->parent);
            }
        }
        else {
            if (key->parent->left->color == RED) { //if "брат" красный
                key->parent->left->color = BLACK; //brother = black
                key->parent->color = RED; //parent = red
                rotate_right(key->parent);
            }
            if (key->parent->left->left->color == BLACK && key->parent->left->right->color == BLACK)   //if у "брата" черные дети
                key->parent->left->color = RED;
            else {
                if (key->parent->left->left->color == BLACK) {
                    key->parent->left->right->color = BLACK; // "брат" красный с черными правым ребенком
                    key->parent->left->color = RED; //брат красный
                    rotate_left(key->parent->left);
                }
                key->parent->left->color = key->parent->color;
                key->parent->color = BLACK;
                key->parent->left->left->color = BLACK;
                rotate_right(key->parent);
            }
        }
        key->color = BLACK;
}



void delete(TREE *key)
{
    if (key->right == NULL && key->left == NULL) {
        if (key->parent == NULL)
            key = NULL;
        else {
            if (key->parent->right == key) { //НЕПРАВИЛЬНО!!!!!!!!
                key->parent->right = NULL;
                //if (key->color==BLACK)
                    insert_case1(key);
                    return;

            }
            else {
                //if (key->color==BLACK)
                key->parent->left = NULL;
                    insert_case1(key);
                    return;

            }
        }
    }
    else {
        if (key->right && key->left == NULL) {
            if (key->right->parent->parent->left = key)
                key->right->parent->parent->left = key->right;
            else key->right->parent->parent->right = key->right;
            key->parent->right = NULL;
        }
        if (key->left && key->right == NULL) {
            if (key->right->parent->parent->left = key)
                key->left->parent->parent->left = key->left;
            if (key->right->parent->parent->right = key)
                key->left->parent->parent->right = key->left;
            key->parent->left = NULL;
        }
        //if (key->left && key->right)
            insert_case1(key);
    }
   // при удалении черной вершины могла быть нарушена балансировка
}

void* add_leaves(TREE *root) {
    if (root->right == NULL) {
        root->right = (TREE *) malloc(sizeof(TREE));
        root->right->color = BLACK;
    }
    else if (root->right->parent) add_leaves(root->right);
    if (root->left == NULL) {
        root->left = (TREE *) malloc(sizeof(TREE));
        root->left->color = BLACK;
    }
    else if (root->left->parent) add_leaves(root->left);
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
        //return root;
    }
    else
    {
        root = find_succesor(root, new_node);
    }

    insert_case1(new_node);/*

    check_color(root, new_node);

    /*if (root->data < new_value)          // добавлем ветвь
    {
        if(root->right != NULL)
            root = find_succesor(root);
        root->right = add_to_tree(root->right, new_value, root->color);
        if (root->right->parent == NULL)
            root->right->parent = root;
    }
    else
    {
        if(root->left != NULL)
            root = find_succesor(root);
        root->left = add_to_tree(root->left, new_value, root->color);
        if (root->left->parent == NULL)
            root->left->parent = root;
    }*/
    return root;
}


void tree_to_array(TREE *root, int a[]) // процедура заполнения массива
{
    static int max2=0;                      // счетчик элементов нового массива
    if (root==NULL) return;             // условие окончания - нет сыновей
    tree_to_array(root->right, a);       // обход левого поддерева
    a[max2++] = root->data;
    tree_to_array(root->left, a);      // обход правого поддерева
    free(root);
}

void sort_tree(int a[], int elem_total)        // собственно сортировка
{
    bool done = 0;
    TREE *root;
    int i;
    root = NULL;
    for (i=0; i<elem_total; i++)        // проход массива и заполнение дерева
        root = add_to_tree(root, a[i]);
    i=0;
    //TREE *new_root = root;

    while (!done)
    {
        while (root->parent != NULL)
            root = root->parent;
        //add_leaves(root);   //ЭТО НУЖНО ПОПРАВИТЬ, ЧТОБЫ УДАЛЯТЬ УЗЛЫ
        while (root->left != NULL) {
            root = root->left;
        }
        a[i] = root->data;
        delete(root); //ИЛИ ПОПРАВИТЬ ЭТО
        if (root->parent == NULL) {
            done = true;
            return;
        }
        root = root->parent;
        i++;

    }
    //tree_to_array(root, a);             // заполнение массива
}
/* тестовая программа */
void main() {
    int i;
    /* Это будем сортировать */
    int a[14]={ 0,7,8,3,52,14,16,18,15,13,42,30,35,26 };

    sort_tree(a, 14);

    printf("sorted array:\n");
    for (i=0;i<14;i++) printf("%d ",a[i]);
}