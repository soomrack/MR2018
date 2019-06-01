//
// Created by Елизавета on 13.02.2019.
//
#include "lib.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stack>

#include <map>

//СОРТИРОВКА ПУЗЫРЬКОМ
void bubble_sort (int* array, int size)
{
    for (int k = size - 1; k >= 1; k--)
    {
        for (int m = 0; m < k; m++)
        {
            if (array[m] > array[m+1])
            {
                int temp = array[m];
                array[m] = array[m+1];
                array[m+1] = temp;
            }
        }
    }
}

//ЛИНЕЙНЫЙ ПОИСК
int linear_search (int element, int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
            return i;
    }
    return 0;
}

//БИНАРНЫЙ ПОИСК
int binary_search (int element, int* array, int size)
{
    bubble_sort(array, size);

    int left = 0;
    int right = size-1;

    while (true)
    {
        int mid = (int)((left + right) * 0.5);
        if (array[mid] == element) return mid;
        else {
            if (mid > element) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            if (left > right)
                std::cout << "not found" << std::endl;
        }
    }
}

//ВЫВОД МАССИВА
void print_array (int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout<<array[i];
    }
    std::cout<<std::endl;
}

//ЗАМЕНА ЭЛЕМЕНТА
void element_replacement (int element, int* array, int size)
{
    int i = 0;
    while ((array[i] < element) & (i < size-1))
    {
        i = i+1;
    }
    array[i] = element;
}

//СЛИЯНИЕ
void Merge(int *arr, int begin, int end)
{
    int *buf = new int[100];
    int middle = (begin + end)/2;
    int first = begin;
    int second = middle + 1;
    for(int i = begin; i <= end; i++)
        if ((first <= middle) && ((second > end) || (arr[first] < arr[second])))
        {
            buf[i]=arr[first];
            first++;
        }
        else
        {
            buf[i] = arr[second];
            second++;
        }

    for (int i = begin; i <= end; i++)
    {
        arr[i] = buf[i];
    }
    delete []buf;
}

//СОРТИРОВКА СЛИЯНИЕМ
void MergeSort(int *arr, int begin, int end)
{
    if (begin < end)
    {
        MergeSort(arr, begin, (begin + end) / 2);
        MergeSort(arr, (begin + end) / 2 + 1, end);
        Merge(arr, begin, end);
    }
}

//смена элементов массива
void swap_arr (int * a, int * b)
{
    int t = * a;
    * a = * b;
    * b = t;
}

//СОРТИРОВКА ВСТАВКАМИ
void InsertSort (int *arr, int begin, int end)
{
    unsigned int item = begin + 1;
    int place = 0;
    int temp;
    for (; item <= end; item++)
    {
        place = item - 1;
        while (place >= begin)
        {
            if (arr[place] >= arr[place+1])
            {
                swap_arr(&arr[place], &arr[place+1]);
            }
            else break;
            place--;
        }
    }
}

//минимальное значение из пары
int min (int a, int b)
{
    if (a <= b) return a;
    else return b;
}

//ГИБРИДНАЯ СОРТИРОВКА
int GetMinrun (int size)
{
    int r = 0;
    while (size >= 64)
    {
        r |= size & 1;
        size >>= 1;
    }
    return size + r;
}

//модифицированное слияние
void merge_modified(int *arr, int first, int size_1, int second,  int size_2)
{
    int buf[size_1];
    for (int i = 0; i < size_1; i++)
    {
        buf[i] = arr[first + i];
    }

    int end = second + size_2 - 1;
    int i = 0;

    while (second <= end) {
        if (buf[i] < arr[second])
        {
            arr[first] = buf[i];
            i++;
        }
        else
        {
            arr[first] = arr[second];
            second++;
        }
        first++;
    }
    while (first <= end)
    {
        arr[first] = buf[i];
        first++;
        i++;
    }
}

//ГИБРИДНАЯ СОРТИРОВКА
void Timsort (int *arr, int arr_size) {
    int minrun = GetMinrun(arr_size);
    std::cout << minrun << std::endl;

    //разбиение на подмассивы и их сортировка

    std::stack<int> stack_begin;
    std::stack<int> stack_size;

    int begin = 0;
    int end = begin;

    while (end < arr_size - 1) {
        if (arr[end] <= arr[end + 1]) {
            end++;
        } else {
            int start = end;
            if (begin != end) {
                start++;
            }

            bool sorted = true;
            while (sorted & (end < arr_size)) {
                end++;
                sorted = arr[end] >= arr[end + 1] ? true : false;
            }

            for (int i = 0; i <= ((end - start) / 2); i++) {
                swap_arr(&arr[start + i], &arr[end - i]);
            }
        }
        if ((end - begin + 1 == minrun) || (end == arr_size - 1)) {
            InsertSort(arr, begin, end);
            stack_begin.push(begin);
            stack_size.push(end - begin + 1);
            end++;
            begin = end;
        }
    }

    //слияние

    while (!stack_size.empty()) {
        int begin_x = stack_begin.top();
        stack_begin.pop();
        int begin_y = stack_begin.top();
        stack_begin.pop();

        int size_x = stack_size.top();
        stack_size.pop();
        int size_y = stack_size.top();
        stack_size.pop();

        if (!stack_size.empty()) {
            int begin_z = stack_begin.top();
            stack_begin.pop();
            int size_z = stack_size.top();
            stack_size.pop();

            if (((size_x > (size_y + size_z)) && (size_y > size_x)) || (size_x <= size_z)) {
                merge_modified(arr, begin_y, size_y, begin_x, size_x);
                stack_begin.push(begin_z);
                stack_size.push(size_z);
                stack_begin.push(begin_y);
                stack_size.push(size_x + size_y);
            } else {
                merge_modified(arr, begin_z, size_z, begin_y, size_y);
                stack_begin.push(begin_z);
                stack_size.push(size_z + size_y);
                stack_begin.push(begin_x);
                stack_size.push(size_x);
            }
        } else {
            merge_modified(arr, begin_y, size_y, begin_x, size_x);
        }
    }
}

//ПИРАМИДАЛЬНАЯ СОРТИРОВКА
//индекс родителя
int iParent(int i)
{
    return ((i-1)/2);
}

//индекс левого потомка
int iLeftChild(int i)
{
    return 2*i+1;
}

//просеивание вниз
void siftDown(int * arr, int start, int end)
{
    int root = start;
    int child;
    int older;

    while (iLeftChild(root) <= end)
    {
        child = iLeftChild(root);
        older = root;

        if (arr[older] < arr[child])
        {
            older = child;
        }

        if (((child + 1) <= end) && (arr[older] < arr[child+1]))
        {
            older = child + 1;
        }

        if (older == root)
        {
            break;
        }

        else
        {
            swap_arr(&arr[root], &arr[older]);
            root = older;
        }
    }
}

//построение кучи
void heapify (int * arr, int n)
{
    int start;
    start = iParent(n-1);

    while (1)
    {
        siftDown(arr, start, n-1);

        if (start > 0)
        {
            start--;
        }
        else
        {
            break;
        }
    }
}

//сортировка
void HeapSort (int * arr, int size)
{
    if (size < 2) return;

    heapify(arr, size);

    int end;
    end = size-1;

    while (end > 0)
    {
        swap_arr(&arr[end], &arr[0]);
        end--;
        siftDown(arr, 0, end);
    }
}

//ПОИСК k-ПОРЯДКОВОЙ СТАТИСТИКИ
int getOrderStatistic( int * arr, int size, int j )
{
	int left = 0;
	int right = size - 1;
	int pivot;
	int border;
	int p, i;

	while (1)
	{
		if (left == right)
		{
			return arr[left];
		}
		p =(left + right)/2;
		pivot = arr[p];
		swap_arr(&arr[p], &arr[right]);

		border = left;

		for (i = left; i < right; i++)
		{
			if (arr[i] <= pivot)
			{
				swap_arr(&arr[border], &arr[i]);
				border++;
			}
		}

		swap_arr(&arr[border], &arr[right]);

		if (border == j)
		{
			return arr[border];
		}

		if (j < border)
		{
			right = border - 1;
		}

		else
		{
			left = border + 1;
		}
	}
}

//ДВОИЧНОЕ ДЕРЕВО ПОИСКА
Tree::Tree() {root = nullptr;}
Tree::~Tree() {if (root != nullptr) Tree::delete_node(root, root->key);}
//вертикальный обход дерева
//обратный обход
void Tree::infix_traverse(node *root)
{
    if (root != nullptr)
    {
        Tree::infix_traverse(root->left);
        std::cout<< root->key;
        Tree::infix_traverse(root->right);
    }
}

//прямой обход
void Tree::prefix_traverse(node *root)
{
    std::cout<< root->key;
    if (root->left != nullptr)
        Tree::prefix_traverse(root->left);
    if (root->right != nullptr)
        Tree::prefix_traverse(root->right);
}

//концевой обход
void Tree::postfix_traverse(node *root)
{
    if (root->left != nullptr)
        Tree::postfix_traverse(root->left);
    if (root->right != nullptr)
        Tree::postfix_traverse(root->right);
    std::cout<< root->key;
}

//горизонтальный обход дерева
#include <queue>
void Tree::level_traverse(node *root)
{
    std::queue <node*> myqueue;
    do
    {
        std::cout<< root->key;
        if (root->left != nullptr)
            myqueue.push(root->left);
        if (root->right != nullptr)
            myqueue.push(root->right);
        if (!myqueue.empty())
        {
            root = myqueue.front();
            myqueue.pop();
        }
    }
    while (!myqueue.empty());
}

//удаление ветви
void Tree::delete_branch(node *root)
{
    if (root != nullptr)
    {
        Tree::delete_branch(root->left);
        Tree::delete_branch(root->right);
        delete root;
        root = nullptr;
    }
}

//вставка узла

void Tree::insert(int key, int *value)
{
    Tree::insertion(root, key, value);
}

void Tree::insertion(node *root, int key, int *value)
{
    if (root == nullptr)
    {
        root = new node;
        root->key = key;
        root->value = value;
        root->left = root->right = nullptr;
    }
    else if (key == root->key)
         root->value = value;
    else if (key < root->key)
    {
        if (root->left != nullptr)
            insertion(root->left, key, value);
        else
        {
            root->left = new node;
            root->left->left = root->left->right = nullptr;
            root->left->key = key;
            root->left->value = value;
        }
    }
    else
    {
        if (root->right != nullptr)
            insertion(root->right, key, value);
        else
        {
            root->right = new node;
            root->right->left = root->right->right = nullptr;
            root->right->key = key;
            root->right->value = value;
        }
    }
}

//поиск по ключу

node Tree::search(int key)
{
    return Tree::search(root, key);
}

node Tree::search(node *root, int key)
{
    if ((root == nullptr) || (root->key == key))
    {
        return *root;
    }
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

void Tree::remove(int key)
{
    Tree::delete_node(root,key);
}

//удаление узла
void Tree::delete_node(node *root, int key)
{
    if (root == nullptr)
        return;
    if (key > root->key)
        delete_node(root->right, key);
    if (key < root->key)
        delete_node(root->left, key);
    if (key == root->key)
    {
        if ((root->left == nullptr) && (root->right == nullptr))
        {
            Tree::delete_branch(root);
            return;
        }
        if ((root->left != nullptr) && (root->right != nullptr))
        {
            if (root->right->left == nullptr)
            {
                root->key = root->right->key;
                root->value = root->right->value;
                root->right->key = root->right->right->key;
                root->right->value = root->right->right->value;
            }
            else
            {
                root->key = root->right->key;
                root->value = root->right->value;
                delete_node(root->right, root->right->key);
            }
        }
        else
        {
            if (root->left == nullptr)
            {
                root->key = root->right->key;
                root->value = root->right->value;
                delete_node(root->right, root->right->key);
            }
            else if (root->right == nullptr)
            {
                root->key = root->left->key;
                root->value = root->left->value;
                delete_node(root->left, root->left->key);
            }
        }
    }
}

// B-ДЕРЕВО
// конструктор и деструктор

Btree::Btree() {root = nullptr;}
Btree::~Btree() {if (root != nullptr) deletenode(root);}

void Btree::deletenode(Bnode *node)
{
    if (node != nullptr)
    {
        for (int i = 0; i <= (2*t-1); i++)
        {
            if (node->child[i] != nullptr) Btree::deletenode(node->child[i]);
            else
            {
                delete(node);
                break;
            }
        }
    }
}

// простое добавление узла
void Btree::insert_to_node(int key, Bnode *node)
{
    node->key[node->count] = key;
    node->count = node->count+1;
    Btree::sort(node);
}

//сортировка чисел в узле
void Btree::sort(Bnode *node)
{
    int m;
    for (int i = 0; i <(2*t-1); i++)
    {
        for (int j = i+1; j <= (2*t-1); j++)
        {
            if ((node->key[i] != 0) && (node->key[j] != 0))
            {
                if ((node->key[i]) > (node->key[j]))
                {
                    m = node->key[i];
                    node->key[i] = node->key[j];
                    node->key[j] = m;
                }
            }
            else break;
        }
    }
}

//добавление в узел с предварительным поиском
void Btree::insert(int key)
{
    if (root == nullptr)
    {
        Bnode *newRoot = new Bnode;
        newRoot->key[0] = key;
        for (int j = 1; j <= (2*t-1); j++)
            newRoot->key[j] = 0;
        for (int i = 0; i <= (2*t); i++)
            newRoot->child[i] = nullptr;
        newRoot->count = 1;
        newRoot->child_count = 0;
        newRoot->leaf = true;
        newRoot->parent = nullptr;
        root = newRoot;
    }
    else
    {
        Bnode *ptr = root;
        while (ptr->leaf == false)
        {
            for (int i = 0; i <= (2*t-1); i++)
            {
                if (ptr->key[i] != 0)
                {
                    if (key < ptr->key[i])
                    {
                        ptr = ptr->child[i];
                        break;
                    }
                    if ((ptr->key[i+1] == 0) && (key > ptr->key[i]))
                    {
                        ptr = ptr->child[i+1];
                        break;
                    }
                    else break;
                }
            }
            Btree::insert_to_node(key, ptr);

            while (ptr->count == 2*t)
            {
                if (ptr == root)
                {
                    Btree::restruct(ptr);
                    break;
                }
                else
                {
                    Btree::restruct(ptr);
                    ptr = ptr->parent;
                }
            }
        }
    }
}

//разбиение узла
void Btree::restruct(Bnode *node)
{
    if (node->count < (2*t-1))
        return;
    Bnode *child1 = new Bnode;
    int j;
    for (j = 0; j <= t-2; j++)
        child1->key[j] = node->key[j];
    for (j = t-1; j <= (2*t-1); j++)
        child1->key[j] = 0;
    child1->count = t-1;
    if (node->child_count != 0)
    {
        for (int i = 0; i <= (t-1); i++)
        {
            child1->child[i] = node->child[i];
            child1->child[i]->parent = child1;
        }
        for (int i = t; i <= (2*t); i++)
            child1->child[i] = nullptr;
        child1->leaf = false;
        child1->child_count = t-1;
    }
    else
    {
        child1->leaf = true;
        child1->child_count = 0;
        for (int i = 0; i <= (2*t); i++)
            child1->child[i] = nullptr;
    }

    Bnode *child2 = new Bnode;
    for (int j = 0; j <= (t-1); j++)
        child2->key[j] = node->key[j+t];
    for (j = t; j <= (2*t-1); j++)
        child2->key[j] = 0;
    child2->count = t;
    if (node->child_count != 0)
    {
        for (int i = 0; i <= t; i++)
        {
            child2->child[i] = node->child[i+t];
            child2->child[i]->parent = child2;
        }
        for (int i = t+1; i <= (2*t); i++)
            child2->child[i] = nullptr;
        child2->leaf = false;
        child2->child_count = t;
    }
    else
    {
        child2->leaf = true;
        child2->child_count = 0;
        for (int i = 0; i <= (2*t); i++)
            child2->child[i] = nullptr;
    }

    if (node->parent == nullptr)
    {
        node->key[0] = node->key[t-1];
        for (int j = 1; j <= (2*t-1); j++)
            node->key[j] = 0;
        node->child[0] = child1;
        node->child[1] = child2;
        for (int i = 2; i <= (2*t); i++)
            node->child[i] = nullptr;
        node->parent = nullptr;
        node->leaf = false;
        node->count = 1;
        node->child_count = 2;
        child1->parent = node;
        child2->parent = node;
    }
    else
    {
        Btree::insert_to_node(node->key[t-1], node->parent);
        for (int i = 0; i <= (2*t); i++)
        {
            if (node->parent->child[i] == node)
            node->parent->child[i] = nullptr;

        }
        for (int i = 0; i <= (2*t); i++)
        {
            if (node->parent->child[i] == nullptr)
            {
                for (int j = (2*t); j > (i+1); j--)
                    node->parent->child[j] = node->parent->child[j-1];
                node->parent->child[i+1] = child2;
                node->parent->child[i] = child1;
                break;
            }
        }
        child1->parent = node->parent;
        child2->parent = node->parent;
        node->parent->leaf = false;
        delete node;
    }
}

//поиск
Bnode * Btree::search(int key)
{
    return Btree::search_key(key, this->root);
}

Bnode * Btree::search_key(int key, Bnode *node)
{
    if (node != nullptr) {
        if (node->leaf == false) {
            int i;
            for (i = 0; i <= (2 * t - 1); i++) {
                if (node->key[i] != 0) {
                    if (key == node->key[i])
                        return node;
                    if (key < node->key[i]) {
                        return Btree::search_key(key, node->child[i]);
                        break;
                    }
                } else break;
            }
            return Btree::search_key(key, node->child[i]);
        } else {
            for (int j = 0; j <= (2 * t - 1); j++)
                if (key == node->key[j])
                    return node;
            return nullptr;
        }
    }
    else return nullptr;
}

//удаление ключа из узла
void Btree::remove_from_node(int key, Bnode *node)
{
    for (int i = 0; i < node->count; i++)
    {
        if (node->key[i] == key)
        {
            for (int j = 1; j < node->count; j++)
            {
                node->key[j] = node->key[j+1];
                node->child[j] = node->child[j+1];
            }
            node->key[node->count-1] = 0;
            node->child[node->count-1] = node->child[node->count];
            node->child[node->count] = nullptr;
            break;
        }
    }
    node->count--;
}

//соединение узлов
void Btree::left_connect(Bnode *node, Bnode *othernode)
{
    if (node == nullptr)
        return;
    for (int i = 0; i <= (othernode->count-1); i++)
    {
        node->key[node->count] = othernode->key[i];
        node->child[node->count] = othernode->child[i];
        node->count = node->count+1;
    }
    node->child[node->count] = othernode->child[othernode->count];
    for (int j = 0; j <= node->count; j++)
    {
        if (node->child[j] == nullptr)
            break;
        node->child[j]->parent = node;
    }
    delete othernode;
}

void Btree::right_connect(Bnode *node, Bnode *othernode)
{
    if (node == nullptr)
        return;
    for (int i = 0; i <= (othernode->count-1); i++)
    {
        node->key[node->count] = othernode->key[i];
        node->child[node->count+1] = othernode->child[i+1];
        node->count = node->count+1;
    }
    for (int j = 0; j <= node->count; j++)
    {
        if (node->child[j] == nullptr)
            break;
        node->child[j]->parent = node;
    }
    delete othernode;
}

//восстановление условий
void Btree::repair(Bnode *node)
{
    if ((node == root) && (node->count == 0))
    {
        if (root->child[0] != nullptr)
        {
            root->child[0]->parent = nullptr;
            root = root->child[0];
        }
        else
        {
            delete root;
        }
        return;
    }
    Bnode *ptr = node;
    int positionChild;
    Bnode *parent = ptr->parent;
    for (int j = 0; j <= parent->count; j++)
    {
        if (parent->child[j] == ptr)
        {
            positionChild = j;
            break;
        }
    }
    if (positionChild == 0)
    {
        Btree::insert_to_node(parent->key[positionChild], ptr);
        Btree::left_connect(ptr, parent->child[positionChild+1]);
        parent->child[positionChild+1] = ptr;
        parent->child[positionChild] = nullptr;
        Btree::remove_from_node(parent->key[positionChild], parent);
        if (ptr->count == 2*t)
        {
            while (ptr->count == 2*t)
            {
                Btree::restruct(ptr);
                if (ptr != root)
                    ptr = ptr->parent;
                else break;
            }
        }
        else
            if (parent->count <= (t-2))
                Btree::repair(parent);
    }
    else
    {
        if (positionChild == parent->count)
        {
            Btree::insert_to_node(parent->key[positionChild-1], parent->child[positionChild-1]);
            Btree::left_connect(parent->child[positionChild-1], ptr);
            parent->child[positionChild] = parent->child[positionChild-1];
            parent->child[positionChild-1] = nullptr;
            Btree::remove_from_node(parent->key[positionChild-1], parent);
            Bnode *temp = parent->child[positionChild];
            if (ptr->count == 2*t)
            {
                while (temp->count == 2*t)
                {
                    Btree::restruct(temp);
                    if (temp != root)
                        temp = temp->parent;
                    else break;
                }
            }
            else
                if (parent->count <= (t-2))
                    Btree::repair(parent);
        }
        else
        {
            Btree::insert_to_node(parent->key[positionChild], ptr);
            Btree::left_connect(ptr, parent->child[positionChild+1]);
            parent->child[positionChild+1] = ptr;
            parent->child[positionChild] = nullptr;
            Btree::remove_from_node(parent->key[positionChild], parent);
            if (ptr->count == 2*t)
            {
                while (ptr->count == 2*t)
                {
                    Btree::restruct(ptr);
                    if (ptr != root)
                        ptr = ptr->parent;
                    else break;
                }
            }
            else
                if (parent->count <= (t-2))
                    Btree::repair(parent);
        }
    }
}

void Btree::remove_leaf(int key, Bnode *node)
{
    if ((node == root) && (node->count == 1))
    {
        Btree::remove_from_node(key, node);
        root->child[0] = nullptr;
        delete root;
        root = nullptr;
        return;
    }

    if ((node == root) || (node->count > (t-1)))
    {
        Btree::remove_from_node(key, node);
        return;
    }

    Bnode *ptr = node;
    int k1;
    int k2;
    int position;
    int positionSon;
    for (int i = 0; i <= node->count-1; i++)
    {
        if (key == node->key[i])
        {
            position = i;
            break;
        }
    }
    Bnode *parent = ptr->parent;
    for (int j = 0; j <= parent->count; j++)
    {
        if (parent->child[j] == ptr)
        {
            positionSon = j;
            break;
        }
    }
    if (positionSon == 0)
    {
        if (parent->child[positionSon+1]->count > (t-1))
        {
            k1 = parent->child[positionSon+1]->key[0];
            k2 = parent->key[positionSon];
            Btree::insert_to_node(k2, ptr);
            Btree::remove_from_node(key, ptr);
            parent->key[positionSon] = k1;
            Btree::remove_from_node(k1, parent->child[positionSon+1]);
        }
        else
        {
            Btree::remove_from_node(key, ptr);
            if (ptr->count <= (t-2))
                repair(ptr);
        }
    }
    else
    {
        if (positionSon == parent->count)
        {
            if (parent->child[positionSon-1]->count > (t-1))
            {
                Bnode *temp = parent->child[positionSon-1];
                k1 = temp->key[temp->count-1];
                k2 = parent->key[positionSon-1];
                Btree::insert_to_node(k2, ptr);
                Btree::remove_from_node(key, ptr);
                parent->key[positionSon-1] = k1;
                Btree::remove_from_node(k1, temp);
            }
            else
            {
                Btree::remove_from_node(key, ptr);
                if (ptr->count <= (t-2))
                    repair(ptr);
            }
        }
        else
        {
            if (parent->child[positionSon+1]->count > (t-1))
            {
                k1 = parent->child[positionSon+1]->key[0];
                k2 = parent->key[positionSon];
                Btree::insert_to_node(k2, ptr);
                Btree::remove_from_node(key, ptr);
                parent->key[positionSon] = k1;
                Btree::remove_from_node(k1, parent->child[positionSon+1]);
            }
            else
            {
                if (parent->child[positionSon-1]->count > (t-1))
                {
                    Bnode *temp = parent->child[positionSon-1];
                    k1 = temp->key[temp->count-1];
                    k2 = parent->key[positionSon-1];
                    Btree::insert_to_node(k2, ptr);
                    Btree::remove_from_node(key, ptr);
                    parent->key[positionSon-1] = k1;
                    Btree::remove_from_node(k1, temp);
                }
                else
                {
                    Btree::remove_from_node(key, ptr);
                    if (ptr->count <= (t-2))
                        repair(ptr);
                }
            }
        }
    }
}

void Btree::remove(int key, Bnode *node)
{
    Bnode *ptr = node;
    int position;
    for (int i = 0; i <= node->count-1; i++)
    {
        if (key == node->key[i])
        {
            position = i;
            break;
        }
    }
    int positionSon;
    if (ptr->parent != nullptr)
    {
        for (int i = 0; i <= ptr->parent->count; i++)
        {
            if (ptr->child[i] == ptr)
            {
                positionSon == i;
                break;
            }
        }
    }
    ptr = ptr->child[position+1];
    int newkey = ptr->key[0];
    while (ptr->leaf == false)
        ptr = ptr->child[0];
    if (ptr->count > (t-1))
    {
        newkey = ptr->key[0];
        Btree::remove_from_node(newkey, ptr);
        node->key[position] = newkey;
    }
    else
    {
        ptr = node;
        ptr = ptr->child[position];
        newkey = ptr->key[ptr->count-1];
        while (ptr->leaf == false)
            ptr = ptr->child[ptr->count];
        newkey = ptr->key[ptr->count-1];
        node->key[position] = newkey;
        if (ptr->count > (t-1))
            Btree::remove_from_node(newkey, ptr);
        else
            Btree::remove_leaf(newkey, ptr);
    }
}

void Btree::remove(int key)
{
    Bnode *ptr = this->root;
    int position;
    int positionChild;
    if (Btree::search_key(key,ptr) == nullptr)
        return;
    else
    {
        for (int i = 0; i <= ptr->count-1; i++)
        {
            if (ptr->key[i] != 0)
            {
                if (key == ptr->key[i])
                {
                    position = i;
                    break;
                }
                else {
                    if ((key < ptr->key[i])) {
                        ptr = ptr->child[i];
                        positionChild = i;
                        i = -1;
                    }
                    else if (i == (ptr->count-1))
                        {
                            ptr = ptr->child[i+1];
                            positionChild = i+1;
                            i = -1;
                        }
                }
            }
            else break;
        }
    }
    if (ptr->leaf == true)
    {
        if (ptr->count > (t-1))
            Btree::remove_from_node(key, ptr);
        else Btree::remove_leaf(key, ptr);
    }
    else Btree::remove(key, ptr);
}


/*
 в си++ это пишут в заголовочный файл
 stack
 class Stack {
 public:
    push(int data);
    int pop();
}
 сначала интерфейс, потом его реализация
 в си была бы структура и два метода
 инкапсуляция


 struct TyA {
    int a1;
    int a2;
}

 struct TyB {
    int a1;
    int a2;
    int a3;
}

 int sum (TyA *A) {
    return A->a1+A->a2;
}


 QUEUE
 class Queue {
 public:
    push(int data);
    int pop();
}

 class Queue {
 public:
    push (T data, int priority);
    int pop();
    merge (Queue q);
}



 */

//КРАСНО-ЧЕРНОЕ ДЕРЕВО
//конструктор и деструктор

RBtree::RBtree() {root = nullptr;}
RBtree::~RBtree() {if (root != nullptr) RBtree::delete_node(root);}

RBnode * RBtree::rotate_left(RBnode *root, RBnode *node)
{
    RBnode *right = node->right;
    node->right = right->left;
    if (right->left != NullNode)
        right->left->parent = node;
    if (right != NullNode)
        right->parent = node->parent;
    if (node->parent != NullNode)
    {
        if (node == node->parent->left)
            node->parent->left = right;
        else
            node->parent->right = right;
    } else
        root = right;
    right->left = node;
    if (node != NullNode)
        node->parent = right;
    return root;
}

RBnode * RBtree::rotate_right(RBnode *root, RBnode *node)
{
    RBnode *left = node->left;
    node->left = left->right;
    if (left->right != NullNode)
        left->right->parent = node;
    if (left != NullNode)
        left->parent = node->parent;
    if (node->parent != NullNode)
    {
        if (node == node->parent->right)
            node->parent->right = left;
        else
            node->parent->left = left;
    } else
        root = left;
    left->right = node;
    if (node != NullNode)
        node->parent = left;
    return root;
}

void RBtree::insert(int key, void *data)
{
    RBtree::insert(root, key, data);
}

RBnode * RBtree::insert(RBnode *root, int key, void *data)
{
    RBnode *node = nullptr;
    RBnode *parent = nullptr;
    for (node = root; node != NullNode && node != nullptr;)
    {
        parent = node;
        if (key < node->key)
            node = node->left;
        else if (key > node->key)
            node = node->right;
        else
            return root;
    }

    if (node == nullptr)
        return nullptr;

    node->key = key;
    node->data = data;
    node->color = RED;
    node->parent = parent;
    node->left = NullNode;
    node->right = NullNode;

    if (parent != NullNode)
    {
        if (key < parent->key)
            parent->left = node;
        else
            parent->right = node;
    }
    else
        root = node;
    return RBtree::insert_recover(root, node);
}

RBnode * RBtree::insert_recover(RBnode *root, RBnode *node)
{
    RBnode *uncle;

    while (node != root && node->parent->color == RED)
    {
        if (node->parent == node->parent->parent->left)
        {
            uncle = node->parent->parent->right;
            if (uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    root = RBtree::rotate_left(root, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                root = RBtree::rotate_right(root, node->parent->parent);
            }
        }
        else
        {
            uncle = node->parent->parent->left;
            if (uncle->color == RED)
            {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->left)
                {
                    node = node->parent;
                    root = RBtree::rotate_right(root, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                root = RBtree::rotate_left(root, node->parent->parent);
            }
        }
    }
    root->color = BLACK;
    return root;
}

RBnode * RBtree::search(int key)
{
    RBnode *current = root;
    while (current != nullptr)
        if (key == current->key)
            return current;
        else
            current = (key < current->key) ? current->left : current->right;
        return 0;
}

void RBtree::remove(int key)
{
    RBnode *temp = search(key);
    RBtree::delete_node(temp);
}

void RBtree::delete_node(RBnode *n)
{
    RBnode *x;
    RBnode *y;
    if (!n || n == nullptr)
        return;
    if ((n->left == nullptr) || (n->right == nullptr))
        y = n;
    else
    {
        y = n->right;
        while (y->left != nullptr)
            y = y->left;
    }
    if (y->left != nullptr)
        x = y->left;
    else
        x = y->right;
    x->parent = y->parent;
    if (y->parent)
    {
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    }
    else
        root = x;
    if (y != n)
        n->data = y->data;
    if (y->color == BLACK)
        delete_recover(x);
    free(y);
}

void RBtree::delete_recover(RBnode *node)
{
    while ((node != root) && (node->color == BLACK))
    {
        if (node == node->parent->left)
        {
            RBnode *s = node->parent->right;
            if (s->color == RED)
            {
                s->color = BLACK;
                node->parent->color = RED;
                rotate_left(root, node->parent);
                s = node->parent->right;
            }
            if ((s->left->color == BLACK) && (s->right->color == BLACK))
            {
                s->color = RED;
                node = node->parent;
            }
            else
            {
                if (s->right->color == BLACK)
                {
                    s->left->color = BLACK;
                    s->color = RED;
                    rotate_right(root, s);
                    s = node->parent->right;
                }
                s->color = node->parent->color;
                node->parent->color = BLACK;
                s->right->color = BLACK;
                rotate_left(root, node->parent);
                node = root;
            }
        }
        else
        {
            RBnode *s = node->parent->left;
            if (s->color == RED)
            {
                s->color = BLACK;
                node->parent->color = RED;
                rotate_right(root, node->parent);
                s = node->parent->left;
            }
            if ((s->right->color == BLACK) && (s->left->color == BLACK))
            {
                s->color = RED;
                node = node->parent;
            }
            else
            {
                if (s->left->color == BLACK)
                {
                    s->right->color = BLACK;
                    s->color = RED;
                    rotate_left(root, s);
                    s = node->parent->left;
                }
                s->color = node->parent->color;
                node->parent->color = BLACK;
                s->left->color = BLACK;
                rotate_right(root, node->parent);
                node = root;
            }
        }
    }
    node->color = BLACK;
}

//РАСШИРЯЮЩЕЕСЯ (КОСОЕ) ДЕРЕВО



//ДВОИЧНАЯ КУЧА для минимума (минимум в корне)

void BinaryMinHeap::SwapUp(HeapNode *parent, HeapNode *child)
{
    int temp = parent->key;
    parent->key = child->key;
    child->key = temp;

    int * temp2 = parent->data;
    parent->data = child->data;
    child->data = temp2;
}

/*void BinaryMinHeap::Repair(HeapNode * node)
{
    if ((node->key >= node->rightChild->key) || (node->key >= node->leftChild->key))
    {
        if (node->leftChild->key < node->rightChild->key)
            Swap(node, node->leftChild);
        else
            Swap(node, node->rightChild);
        SiftDown(node);
    }
}*/

void BinaryMinHeap::SiftDown(HeapNode *node)
{
    if ((node->rightChild != nullptr) && (node->rightChild->key < node->leftChild->key))
    {
        if (node->key > node->rightChild->key)
        {
            BinaryMinHeap::SwapUp(node, node->rightChild);
            SiftDown(node->rightChild);
        }
    }
    else if ((node->leftChild != nullptr) && (node->key > node->leftChild->key))
    {
        BinaryMinHeap::SwapUp(node, node->leftChild);
        SiftDown(node->leftChild);
    }
}

void BinaryMinHeap::SiftUp(HeapNode *node)
{
    if (node->parent != nullptr)
    {
        if (node->key < node->parent->key) {
            SwapUp(node->parent, node);
            SiftUp(node->parent);
        }
    }
}

void BinaryMinHeap::Insert(int key, int *data)
{
    static unsigned int i = 0;
    heap[i].key = key;
    heap[i].data = data;
    if (i > 0)
    {
        heap[i].parent = &heap[(i-1)/2];
        if (heap[i].parent->leftChild == nullptr)
            heap[i].parent->leftChild = &heap[i];
        else
            heap[i].parent->rightChild = &heap[i];
    }
    else
    {
        heap[i].parent = nullptr;

    }
    heap[i].rightChild = nullptr;
    heap[i].leftChild = nullptr;
    SiftUp(&heap[i]);
    if (i > size)
        size = i + 1;
    i++;
}

HeapNode BinaryMinHeap::extractMin(void)
{
    HeapNode min = heap[0];
    heap[0].key = heap[size - 1].key;
    heap[0].data = heap[size - 1].data;
    size = size - 1;
    SiftDown(&heap[0]);
    return min;
}
/*
HeapNode * BinaryMinHeap::Search(int key)
{
    if (heap[0].key > key)
        return nullptr;

    HeapNode * node = &heap[0];

    while (node->key < key)
    {
        if ((node->leftChild != nullptr)&&(node->rightChild != nullptr))
        {
            if (node->leftChild->key > key) {
                if (node->rightChild->key > key)
                    return nullptr;
                else
                    node = node->rightChild;
            }
            else
            {
                if (node->rightChild->key > key)
                    node = node->leftChild;
                else {
                    if (node->leftChild->key > node->rightChild->key)
                        node = node->leftChild;
                    else node = node->rightChild;
                }
            }
        }
        else
        {
            if (node->leftChild != nullptr)
            {
                if (node->leftChild->key < key)
                    node = node->leftChild;
                else
                    return nullptr;
            }
            else if (node->rightChild != nullptr)
            {
                if (node->rightChild->key < key)
                    node = node->rightChild;
                else
                    return nullptr;
            }
            else return nullptr;

        }
    }
    return node;
}*/


//ГРАФЫ


//АЛГОРИТМ ФОРДА-БЕЛЛМАНА
//поиск кратчайших путей во взвешенном графе
//допускает рёбра с отрицательным весом
//если содержит отрицательные циклы, то кратч. путей нет

//возвращает вектор вершин с установленными кратчайшими путями
std::vector <Graph::Vertex> Graph::FordBellman(Graph * graph, int sourceIndex)
{
    vertices[sourceIndex].distance = 0;

    //замена путей на более короткие
    for (int i = 1; i < vertices.size(); i++)
    {
        for (int j = 1; j < edges.size(); j++)
        {
            int src = edges[j].vert1index;
            int dest = edges[j].vert2index;
            int weight = edges[j].weight;
            if (vertices[dest].distance > vertices[src].distance + weight)
            {
                vertices[dest].distance = vertices[src].distance + weight;
                vertices[dest].predecessor = &vertices[src];
            }
        }
    }

    //проверка на наличие отрицательных циклов
    for (int j = 1; j < edges.size(); j++)
    {
        int src = edges[j].vert1index;
        int dest = edges[j].vert2index;
        int weight = edges[j].weight;
        if (vertices[dest].distance > vertices[src].distance + weight)
        {
            std::cout << "Граф содержит отрицательные циклы. Кратчайший путь невозможно найти." << "\n";
            exit(0);
        }
    }

    return vertices;
}

void Graph::addVertex(char * newName)
{
    Vertex newVertex;
    newVertex.name = newName;
    newVertex.index = size;
    size = size + 1;
    newVertex.distance = inf;
    newVertex.predecessor = nullptr;

    vertices.push_back(newVertex);
}

void Graph::addEdge(int vertInd1, int vertInd2, int weight)
{
    Edge newEdge;
    newEdge.vert1index = vertInd1;
    newEdge.vert2index = vertInd2;
    newEdge.weight = weight;

    edges.push_back(newEdge);

    newEdge.vert1index = vertInd2;
    newEdge.vert2index = vertInd1;

    edges.push_back(newEdge);
}

void Graph::printPath(std::vector <Graph::Vertex> vert, int sourceIndex, int destIndex)
{
    using namespace std;
    cout << "Source: " << sourceIndex << "\n";
    cout << "Destination: " << destIndex << "\n";
    cout << "Distance: " << vert[destIndex].distance << "\n";
    cout << "Path: ";
    char name;
    Vertex * next = &vert[destIndex];
    do
    {
        name = * next->name;
        cout << name << " <- ";
        next = next->predecessor;
    }
    while(next->predecessor != nullptr);

    name = * vert[sourceIndex].name;
    cout << name << "\n";
}
