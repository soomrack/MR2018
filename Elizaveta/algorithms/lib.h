//
// Created by Елизавета on 13.02.2019.
//
#include "stdlib.h"
#include <vector>
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
    void * value;
    node *left, *right;
};

class Tree
{

private:
    void delete_branch(node *root);
    void insertion(node *root, int key, int *value);
    node search(node *root, int key);
    void delete_node(node *root, int key);
public:
    Tree();
    ~Tree();
    node *root;
    void insert(int key, int *value);
    node search(int key);
    void remove(int key);
    void infix_traverse(node *root);
    void prefix_traverse(node *root);
    void postfix_traverse(node *root);
    void level_traverse(node *root);
};


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
    Bnode * search_key(int key, Bnode *node);
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
    //ВОЗВРАТ УЗЛА!!!
    Bnode * search(int key);
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
private:
    RBnode *root;
    const bool BLACK = 0;
    const bool RED = 1;
    RBnode Empty = {0, 0, BLACK, nullptr, nullptr, nullptr};
    RBnode *NullNode = &Empty;
    RBnode * rotate_left(RBnode *root, RBnode *node);
    RBnode * rotate_right(RBnode *root, RBnode *node);
    RBnode * insert(RBnode *root, int key, void *data);
    RBnode * insert_recover(RBnode *root, RBnode *node);
    void delete_node(RBnode *n);
    void delete_recover(RBnode *node);

public:
    RBtree();
    ~RBtree();
   //ПО КЛЮЧУ!!! РЕАЛИЗОВАТЬ ПОИСК
    void insert(int key, void *data);
    RBnode * search (int key);
    void remove (int key);

};

class SplayTree
{
private:
    struct SplayNode
    {
        SplayNode * leftChild;
        SplayNode * rightChild;
        SplayNode * parent;
        void * data;
        int key;

        SplayNode (/*const T & key = T()*/)
                : leftChild(nullptr), rightChild(nullptr), parent(nullptr), key(key) {}

        ~SplayNode () {
            delete leftChild;
            delete rightChild;
            delete parent;
        }
    } * root;

    SplayNode * _Successor(SplayNode * localRoot) const
    {
        SplayNode * successor = localRoot;
        if (successor->rightChild != nullptr)
        {
            successor = _Minimum(successor->rightChild);
        }
        else
        {
            while ((successor != root) || (successor != successor->parent->leftChild))
            {
                successor = successor->parent;
            }
        }
        return successor;
    }

    SplayNode * _Presecessor(SplayNode * localRoot) const
    {
        SplayNode * predecessor = localRoot;
        if (predecessor->leftChild != nullptr)
        {
            predecessor = _Maximum(predecessor->leftChild);
        }
        else
        {
            while ((predecessor != root)||(predecessor != predecessor->parent->rightChild))
            {
                predecessor = predecessor->parent;
            }
        }
        return predecessor;
    }

    SplayNode * _Minimum(SplayNode * localRoot) const
    {
        SplayNode * min = localRoot;
        while (min->leftChild != nullptr)
            min = min->leftChild;
        return min;
    }

    SplayNode * _Maximum(SplayNode * localRoot) const
    {
        SplayNode * max = localRoot;
        while (max->rightChild != nullptr)
            max = max->rightChild;
        return max;
    }

    SplayNode * _Search (int key)
    {
        SplayNode * searchedElement = root;
        while (searchedElement != nullptr)
        {
            if (searchedElement->key < key)
                searchedElement = searchedElement->rightChild;
            else if (key < searchedElement->key)
                searchedElement = searchedElement->leftChild;
            else if (searchedElement->key == key)
            {
                _Splay(searchedElement);
                return searchedElement;
            }
        }
        return nullptr;
    }

    void _LeftRotate(SplayNode * localRoot)
    {
        SplayNode * rightChild = localRoot->rightChild;
        localRoot->rightChild = rightChild->leftChild;
        if (rightChild->leftChild != nullptr)
            rightChild->leftChild->parent = localRoot;
        _Transplant(localRoot,rightChild);
        rightChild->leftChild = localRoot;
        rightChild->leftChild->parent = rightChild;
    }

    void _RightRotate(SplayNode * localRoot)
    {
        SplayNode * leftChild = localRoot->leftChild;
        localRoot->leftChild = leftChild->rightChild;
        if (leftChild->rightChild != nullptr)
            leftChild->rightChild->parent = localRoot;
        _Transplant(localRoot, leftChild);
        leftChild->rightChild = localRoot;
        leftChild->rightChild->parent = leftChild;
    }

    void _Transplant(SplayNode * localParent, SplayNode * localChild)
    {
        if (localParent->parent == nullptr)
            root = localChild;
        else if (localParent == localParent->parent->leftChild)
            localParent->parent->leftChild = localChild;
        else if (localParent == localParent->parent->rightChild)
            localParent->parent->rightChild = localChild;
        if (localChild != nullptr)
            localChild->parent = localParent->parent;
    }

    void _Splay(SplayNode * pivotElement)
    {
        while (pivotElement != root)
        {
            if (pivotElement->parent == root)
            {
                if (pivotElement == pivotElement->parent->leftChild)
                    _RightRotate(pivotElement);
                else if (pivotElement == pivotElement->parent->rightChild)
                    _LeftRotate(pivotElement);
            }
            else
            {
                if (pivotElement == pivotElement->parent->leftChild && pivotElement->parent == pivotElement->parent->parent->leftChild)
                {
                    _RightRotate(pivotElement->parent->parent);
                    _RightRotate(pivotElement->parent);
                }
                //else if (pivotElement == pivotElement->parent->rightChild &&)
            }
        }
    }

};



class HeapNode
{
public:
    int key;
    int * data;
    HeapNode * leftChild;
    HeapNode * rightChild;
    HeapNode * parent;
};

class BinaryMinHeap
{
private:
    HeapNode * heap;
    unsigned int size;

    void SiftUp(HeapNode * node);
    void SiftDown(HeapNode * node);
    void SwapUp(HeapNode * parent, HeapNode * child);
    //void Repair(HeapNode * node);
public:
     BinaryMinHeap(int n)
     {
         heap = (HeapNode*) malloc(sizeof(HeapNode) * n);
         size = 0;
     }
    ~BinaryMinHeap()
    {
        if (heap) free(heap);
    }

    void Insert(int key, int * data);
    //HeapNode * Search(int key);
    //void Remove(int key);
    HeapNode extractMin(void);
};


class Graph
{
    int size;

    //условная бесконечность, д.б. > количества вершин
    static const int inf = 10000;

    struct Vertex
    {
        char * name;
        int index = 0;
        int distance = inf;
        Vertex * predecessor = nullptr;
    };
    struct Edge
    {
        int vert1index;
        int vert2index;
        int weight;
    };
    //source index, destination index, weight
    //std::map <std::pair<int, int>, int> edges;
    std::vector <Edge> edges;
    std::vector <Vertex> vertices;

public:
    Graph()
    {
        size = 0;
        //std::map <std::pair<int, int>, int> edges;
    }
    void addVertex(char * newName);
    void addEdge(int source, int destination, int weight);
    std::vector <Graph::Vertex> FordBellman(Graph * graph, int sourceIndex);
    void printPath(std::vector <Graph::Vertex> vertices, int sourceIndex, int destIndex);
};






#endif //UNTITLED22_SORT_H

