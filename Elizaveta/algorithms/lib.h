//
// Created by Елизавета on 13.02.2019.
//

#ifndef UNTITLED22_SORT_H
#define UNTITLED22_SORT_H

void bubble_sort (int* array, int size);
int linear_search (int element, int* array, int size);
int binary_search (int element, int* array, int size);
void print_array (int *array, int size);
void element_replacement (int element, int* array, int size);
void swap(int a, int b);

struct Subarray {
    int begin;
    int end;
};
void InsertSort (int *arr, int begin, int end);
void Timsort(int *arr, int size);
void MergeSort(int *A, int begin, int end);
void HeapSort (int * arr, int size);

struct node
{
    int key;
    int value;
    node *left, *right;
};

void infix_traverse(node *&tree);
void prefix_traverse(node *&tree);
void postfix_traverse(node *&tree);
void level_traverse(node *&tree);
void clean(node *&tree);
void insert(node *&tree, int key, int value);
node search(node *&tree, int key);
void delete_node(node *&tree, int key);

const int t = 2;
struct Bnode
{
    bool leaf;      //является ли узел листом
    int count;      //количество ключей узла
    int key[2*t];      //ключи узла
    int child_count;
    Bnode *child[2*t+1]; //указатели на потомков узла
    Bnode *parent;
};

class Btree
{
private:
    Bnode *root;
    void insert_to_node(int key, Bnode *node);
    void sort(Bnode *node);
    void restruct(Bnode *node);
    void deletenode(Bnode *node);
    bool search_key(int key, Bnode *node);
    void remove(int key, Bnode *node);
    void remove_from_node(int key, Bnode *node);
    void remove_leaf(int key, Bnode *node);
    void left_connect(Bnode *node, Bnode *othernode);
    void right_connect(Bnode *node, Bnode *othernode);
    void repair(Bnode *node);

public:
    Btree();
    ~Btree();
    void insert(int key);
    bool search(int key);
    void remove(int key);
};


struct RBnode
{
    bool color;
    void *data;
    int key;
    RBnode *left;
    RBnode *right;
    RBnode *parent;
};


class RBtree
{
    const bool BLACK = 1;
    const bool RED = 0;
private:
    void rotate_left(RBnode *n);
    void rotate_right(RBnode *n);
    RBnode * get_grandparent(RBnode *n);
    RBnode * get_uncle(RBnode *n);
    void insert_case1(RBnode *n);
    void insert_case2(RBnode *n);
    void insert_case3(RBnode *n);
    void insert_case4(RBnode *n);
    void insert_case5(RBnode *n);
    RBnode * get_sibling(RBnode *n);
    void delete_case1(RBnode *n);
    void delete_case2(RBnode *n);
    void delete_case3(RBnode *n);
    void delete_case4(RBnode *n);
    void delete_case5(RBnode *n);
    void delete_case6(RBnode *n);

public:
    RBtree();
    ~RBtree();

};
#endif //UNTITLED22_SORT_H

