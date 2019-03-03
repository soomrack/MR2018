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

#endif //UNTITLED22_SORT_H

