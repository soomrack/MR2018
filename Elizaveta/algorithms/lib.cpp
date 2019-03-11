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
    delete[]buf;
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
void siftDown(int32_t * arr, uint32_t start, uint32_t end)
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

//ДВОИЧНОЕ ДЕРЕВО ПОИСКА

void show(node *&tree)
{
    if (tree != NULL)
    {
        show(tree->left);
        std::cout<< tree->key;
        show(tree->right);
    }

}

void clean(node *&tree)
{
    if (tree != NULL)
    {
        clean(tree->left);
        clean(tree->right);
        delete tree;
        tree = NULL;
    }
}

void insert(node *&tree, int key, int value)
{
    if (tree == NULL)
    {
        tree = new node;
        tree->key = key;
        tree->value = value;
        tree->left = tree->right = NULL;
    }
    else if (key == tree->key)
         tree->value = value;
    else if (key < tree->key)
    {
        if (tree->left != NULL)
            insert(tree->left, key, value);
        else
        {
            tree->left = new node;
            tree->left->left = tree->left->right = NULL;
            tree->left->key = key;
            tree->left->value = value;
        }
    }
    else
    {
        if (tree->right != NULL)
            insert(tree->right, key, value);
        else
        {
            tree->right = new node;
            tree->right->left = tree->right->right = NULL;
            tree->right->key = key;
            tree->right->value = value;
        }
    }
}

node search(node *&tree, int key)
{
    if ((tree == NULL) || (tree->key == key))
    {
        return *tree;
    }
    if (key < tree->key)
        return search(tree->left, key);
    return search(tree->right, key);
}

void delete_node(node *&tree, int key)
{
    if (tree == NULL)
        return;
    if (key > tree->key)
        delete_node(tree->right, key);
    if (key < tree->key)
        delete_node(tree->left, key);
    if (key == tree->key)
    {
        if ((tree->left == NULL) && (tree->right == NULL))
        {
            clean(tree);
            return;
        }
        if ((tree->left != NULL) && (tree->right != NULL))
        {
            if (tree->right->left == NULL)
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
            if (tree->left == NULL)
            {
                tree->key = tree->right->key;
                tree->value = tree->right->value;
                delete_node(tree->right, tree->right->key);
            }
            else if (tree->right == NULL)
            {
                tree->key = tree->left->key;
                tree->value = tree->left->value;
                delete_node(tree->left, tree->left->key);
            }
        }
    }
}

























