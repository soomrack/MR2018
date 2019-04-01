//
// Created by Елизавета on 13.02.2019.
//
#include "lib.h"
#include <iostream>
#include <cstdlib>
#include <stack>

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
//вертикальный обход дерева
//обратный обход
void infix_traverse(node *&tree)
{
    if (tree != nullptr)
    {
        infix_traverse(tree->left);
        std::cout<< tree->key;
        infix_traverse(tree->right);
    }
}

//прямой обход
void prefix_traverse(node *&tree)
{
    std::cout<< tree->key;
    if (tree->left != nullptr)
        prefix_traverse(tree->left);
    if (tree->right != nullptr)
        prefix_traverse(tree->right);
}

//концевой обход
void postfix_traverse(node *&tree)
{
    if (tree->left != nullptr)
        postfix_traverse(tree->left);
    if (tree->right != nullptr)
        postfix_traverse(tree->right);
    std::cout<< tree->key;
}

//горизонтальный обход дерева
#include <queue>
void level_traverse(node *&tree)
{
    std::queue <node*> myqueue;
    do
    {
        std::cout<< tree->key;
        if (tree->left != nullptr)
            myqueue.push(tree->left);
        if (tree->right != nullptr)
            myqueue.push(tree->right);
        if (!myqueue.empty())
        {
            tree = myqueue.front();
            myqueue.pop();
        }
    }
    while (!myqueue.empty());
}

//удаление ветви
void clean(node *&tree)
{
    if (tree != nullptr)
    {
        clean(tree->left);
        clean(tree->right);
        delete tree;
        tree = nullptr;
    }
}

//вставка узла
void insert(node *&tree, int key, int value)
{
    if (tree == nullptr)
    {
        tree = new node;
        tree->key = key;
        tree->value = value;
        tree->left = tree->right = nullptr;
    }
    else if (key == tree->key)
         tree->value = value;
    else if (key < tree->key)
    {
        if (tree->left != nullptr)
            insert(tree->left, key, value);
        else
        {
            tree->left = new node;
            tree->left->left = tree->left->right = nullptr;
            tree->left->key = key;
            tree->left->value = value;
        }
    }
    else
    {
        if (tree->right != nullptr)
            insert(tree->right, key, value);
        else
        {
            tree->right = new node;
            tree->right->left = tree->right->right = nullptr;
            tree->right->key = key;
            tree->right->value = value;
        }
    }
}

//поиск по ключу
node search(node *&tree, int key)
{
    if ((tree == nullptr) || (tree->key == key))
    {
        return *tree;
    }
    if (key < tree->key)
        return search(tree->left, key);
    return search(tree->right, key);
}

//удаление узла
void delete_node(node *&tree, int key)
{
    if (tree == nullptr)
        return;
    if (key > tree->key)
        delete_node(tree->right, key);
    if (key < tree->key)
        delete_node(tree->left, key);
    if (key == tree->key)
    {
        if ((tree->left == nullptr) && (tree->right == nullptr))
        {
            clean(tree);
            return;
        }
        if ((tree->left != nullptr) && (tree->right != nullptr))
        {
            if (tree->right->left == nullptr)
            {
                tree->key = tree->right->key;
                tree->value = tree->right->value;
                tree->right->key = tree->right->right->key;
                tree->right->value = tree->right->right->value;
            }
            else
            {
                tree->key = tree->right->key;
                tree->value = tree->right->value;
                delete_node(tree->right, tree->right->key);
            }
        }
        else
        {
            if (tree->left == nullptr)
            {
                tree->key = tree->right->key;
                tree->value = tree->right->value;
                delete_node(tree->right, tree->right->key);
            }
            else if (tree->right == nullptr)
            {
                tree->key = tree->left->key;
                tree->value = tree->left->value;
                delete_node(tree->left, tree->left->key);
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
bool Btree::search(int key)
{
    return Btree::search_key(key, this->root);
}

bool Btree::search_key(int key, Bnode *node)
{
    if (node != nullptr) {
        if (node->leaf == false) {
            int i;
            for (i = 0; i <= (2 * t - 1); i++) {
                if (node->key[i] != 0) {
                    if (key == node->key[i])
                        return true;
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
                    return true;
            return false;
        }
    }
    else return false;
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
                    if (temp == root)
                    {
                        Btree::restruct(temp);
                        break;
                    }
                    else
                    {
                        Btree::restruct(temp);
                        temp = temp->parent;
                    }
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
        Btree:remove_from_node(key, node);
        root->child[0] = nullptr;
        delete root;
        root = nullptr;
        return;
    }

    if (node == root)
    {
        Btree::remove_from_node(key, node);
        return;
    }

    if (node->count > (t-1))
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
    if (Btree::search_key(key,ptr) == false)
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
                    else
                    {
                        if (i == (ptr->count-1))
                        {
                            ptr = ptr->child[i+1];
                            positionChild = i+1;
                            i = -1;
                        }
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


RBnode * RBtree::get_grandparent (RBnode *n)
{
    if ((n != nullptr) && (n->parent != nullptr))
        return n->parent->parent;
    else
        return nullptr;
}

RBnode * RBtree::get_uncle (RBnode *n)
{
    RBnode *g = RBtree::get_grandparent(n);
    if (g == nullptr)
        return nullptr;
    if (n->parent == g->left)
        return g->right;
    else
        return g->left;
}

void RBtree::rotate_left(RBnode *n)
{
    RBnode *pivot = n->right;

    pivot->parent = n->parent;
    if (n->parent != nullptr) {
        if (n->parent->left == n)
            n->parent->left = pivot;
        else
            n->parent->right = pivot;
    }
    n->right = pivot->left;
    if (pivot->left != nullptr)
        pivot->left->parent = n;
    n->parent = pivot;
    pivot->left = n;
}

void RBtree::rotate_right(RBnode *n)
{
    RBnode *pivot = n->left;
    pivot->parent = n->parent;
    if (n->parent != nullptr)
    {
        if (n->parent->left == n)
            n->parent->left = pivot;
        else
            n->parent->right = pivot;
    }
    n->left = pivot->right;
    if (pivot->right != nullptr)
        pivot->right->parent = n;
    n->parent = pivot;
    pivot->right = n;
}

//текущий узел в корне дерева
void RBtree::insert_case1(RBnode *n)
{
    if (n->parent == nullptr)
        n->color = BLACK;
    else
        RBtree::insert_case2(n);
}

//предок текущего узла черный
void RBtree::insert_case2(RBnode *n)
{
    if (n->parent->color == BLACK)
        return;
    else
        RBtree::insert_case3(n);
}

//родитель и дядя красные
void RBtree::insert_case3(RBnode *n)
{
    RBnode *u = RBtree::get_uncle(n);
    RBnode *g;
    if ((u != nullptr) && (u->color == RED))// && (n->parent->color == RED) Второе условие проверяется в insert_case2, то есть родитель уже является красным.
    {
        n->parent->color = BLACK;
        u->color = BLACK;
        g = RBtree::get_grandparent(n);
        g->color = RED;
        RBtree::insert_case1(g);
    }
    else
        RBtree::insert_case4(n);
}

//родитель красный, дядя черный
void RBtree::insert_case4(RBnode *n)
{
    RBnode *g = RBtree::get_grandparent(n);
    if ((n == n->parent->right) && (n->parent == g->left))
    {
        RBtree::rotate_left(n->parent);
        n = n->left;
    }
    else if ((n == n->parent->left) && (n->parent == g->right))
    {
        RBtree::rotate_right(n->parent);
        n = n->right;
    }
    RBtree::insert_case5(n);
}

//родитель красный, дядя черный, текущий узел - левый потомок левого потомка
void RBtree::insert_case5(RBnode *n)
{
    RBnode *g = RBtree::get_grandparent(n);
    n->parent->color = BLACK;
    g->color = RED;
    if ((n == n->parent->left) && (n->parent == g->left))
        RBtree::rotate_right(g);
    else
        RBtree::rotate_left(g);
}

//поиск брата
RBnode * RBtree::get_sibling(RBnode *n)
{
    if (n == n->parent->left)
        return n->parent->right;
    else
        return n->parent->left;
}

//n - новый корень
void RBtree::delete_case1(RBnode *n)
{
    if (n->parent != nullptr)
        RBtree::delete_case2(n);
}

//s - красный
void RBtree::delete_case2(RBnode *n)
{
    RBnode *s = RBtree::get_sibling(n);
    if (s->color == RED)
    {
        n->parent->color = RED;
        s->color = BLACK;
        if (n == n->parent->left)
            RBtree::rotate_left(n->parent);
        else
            RBtree::rotate_right(n->parent);
    }
    RBtree::delete_case3(n);
}

//p, s, дети s - черные
void RBtree::delete_case3(RBnode *n)
{
    RBnode *s = get_sibling(n);
    if ((n->parent->color == BLACK) && (s->color == BLACK)&&
            (s->left->color == BLACK) && (s->right->color == BLACK))
    {
        s->color = RED;
        RBtree::delete_case1(n->parent);
    }
    else
        RBtree::delete_case4(n);
}

//s, дети s - черные, p - красный
void RBtree::delete_case4(RBnode *n)
{
    RBnode *s = RBtree::get_sibling(n);
    if ((n->parent->color == RED) && (s->color == BLACK) &&
            (s->left->color == BLACK) && (s->right->color == BLACK))
    {
        s->color = RED;
        n->parent->color = BLACK;
    }
    else
        RBtree::delete_case5(n);
}

//s - черный, лев потомок s - красный, прав потомок s - черный,  n - левый потомок
void RBtree::delete_case5(RBnode *n)
{
    RBnode *s = RBtree::get_sibling(n);
    if (s->color == BLACK)
    {
        if ((n == n->parent->left) &&
            (s->right->color == BLACK) &&
            (s->left->color == RED))
        {
            s->color = RED;
            s->left->color = BLACK;
            RBtree::rotate_right(s);
        }
        else if ((n == n->parent->right) &&
                 (s->left->color == BLACK) &&
                 (s->right->color == RED))
        {
            s->color = RED;
            s->right->color = BLACK;
            RBtree::rotate_left(s);
        }
    }
    RBtree::delete_case6(n);
}

//s - черный, прав потомок s - красный, n - левый потомок
void RBtree::delete_case6(RBnode *n)
{
    RBnode *s = RBtree::get_sibling(n);
    s->color = n->parent->color;
    n->parent->color = BLACK;
    if (n == n->parent->left)
    {
        s->right->color = BLACK;
        RBtree::rotate_left(n->parent);
    }
    else
    {
        s->left->color = BLACK;
        RBtree::rotate_right(n->parent);
    }
}