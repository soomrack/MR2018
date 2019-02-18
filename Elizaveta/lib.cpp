//
// Created by Елизавета on 13.02.2019.
//
#include "lib.h"
#include <iostream>
#include <cstdlib>

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

int linear_search (int element, int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
            return i;
    }
    return 0;
}

int binary_search (int element, int* array, int size)
{
    bubble_sort(array, size);

    int left = 0;
    int right = size-1;

    while (true)
    {
        int mid = (int)((left + right) * 0.5);
        if (array[mid] = element)
            return mid;
        if (mid > element)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        if (left > right)
            std::cout<<"not found"<<std::endl;
    }
}

void print_array (int *array, int size)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout<<array[i];
    }
    std::cout<<std::endl;
}

void element_replacement (int element, int* array, int size)
{
    int i = 0;
    while ((array[i] < element) & (i < size-1))
    {
        i = i+1;
    }
    array[i] = element;
}