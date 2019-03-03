//
// Created by natas on 02.03.2019.
//

#ifndef HEAPSORT_HEAPCLASS_H
#define HEAPSORT_HEAPCLASS_H

class Heap {
    static const int SIZE = 100; // максимальный размер кучи
    int *h;         // указатель на массив кучи
    int HeapSize; // размер кучи
public:
    Heap();  // конструктор кучи
    void addelem(int);  // добавление элемента кучи
    void outHeap();  // вывод элементов кучи в форме кучи
    void out();  // вывод элементов кучи в форме массива
    int getmax();  // удаление вершины (максимального элемента)
    void heapify(int);  // упорядочение кучи
    void make_Heap(int *arr, int size);
};

void HeapSort(int* arr, int size);







#endif //HEAPSORT_HEAPCLASS_H
