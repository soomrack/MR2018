//
// Created by natas on 18.02.2019.
//

#ifndef MERGE_MERGE_H
#define MERGE_MERGE_H

struct List {
    int start_index;
    int sub_size;
    List *next, *head;
};


void MergeSort (int *arr, int begin, int end);
void Merge(int *arr, int begin, int end);
void swap(int *arr, int first_index, int second_index);
void Insert(int* arr, int size);

void TimSort(int* arr, int size);
void Add(int start, int size, List *&Subarray);
void Show(List *MyList);
void ifMerge(int* arr, List *&Subarray, int* buf);
void Merge_sub (int* arr, List *&Subarray1, List *&Subarray2,int* buf);
#endif //MERGE_MERGE_H
