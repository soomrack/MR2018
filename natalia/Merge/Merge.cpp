//
// Created by natas on 18.02.2019.
//

#include "Merge.h"
#include <iostream>


void MergeSort (int *arr, int begin, int end) {
    if (begin < end)
    {
        MergeSort(arr, begin, (begin+end)/2);//сортировка левой части
        MergeSort(arr, (begin+end)/2+1, end); //сортировка правой части
        Merge(arr, begin, end); //слияние двух частей
    }
}


void Merge(int *arr, int begin, int end) {
    int middle = (begin + end)/2;
    int start = begin;
    int final = middle+1;
    int *buf = new int[end+1];
    for (int i = begin; i<=end; i++) {
        if ((start<= middle) && ((final>end) || (arr[start] < arr[final]))) {
            buf[i] = arr[start];
            start++;
        }
        else {
            buf[i] = arr[final];
            final++;
        }
    }
    for (int i = begin; i<=end; i++) {
        arr[i] = buf[i];
    }
    delete[] buf;
}



void swap(int *arr, int first_index, int second_index) {
    int temp = arr[first_index];
    arr[first_index] = arr[second_index];
    arr[second_index] = temp;
}

void Insert(int* arr, int size) {
    int item;
    int place;
    for (int i = 1; i < size; i++)
    {
        item = arr[i];
        place = i - 1;
        while(place >= 0 && arr[place] > item)
        {
            arr[place+1] = arr[place];
            place --;
        }
        arr[place+1] = item;
    }
}


int CalcRun (int size) { // выбираем run, равный степени 2
    bool flag = 0;         // будет равно 1, если среди сдвинутых битов есть хотя бы один ненулевой
    while (size >= 48) {
        flag |= size & 1;
        size >>= 1;
    }
    return size + flag;
}




void Add(int start, int size, List *&Subarray) {
    List *temp = new List;                              //Выделяем память для нового элемента
    temp->start_index = start;                          //Записываем в поля стека принимаемые элементы
    temp->sub_size = size;
    temp->next = Subarray->head;                        //Указываем, что следующий элемент это предыдущий
    Subarray->head = temp;                              //Сдвигаем голову на позицию вперед
}


void ClearList(List *MyList)
{
    while (MyList->head != NULL)                        //Пока по адресу не пусто
    {
        List *temp = MyList->head->next;                    //Временная переменная для хранения адреса следующего элемента
        delete MyList->head;                                //Освобождаем адрес обозначающий начало
        MyList->head = temp;                                //Меняем адрес на следующий
    }
}

void ifMerge(int * arr, List *&Subarray, int* buf) {
    List *X = Subarray -> head;
    List *Y = X -> next;
    List *Z = Y -> next;
    do {
        if ((X->sub_size > (Y->sub_size + Z->sub_size)) &&
            (Y->sub_size > Z->sub_size)) {}
        else {
            List *MIN = new List;
            MIN = (X->sub_size < Z->sub_size) ? X : Z;
            Merge_sub(arr, Y, MIN, buf);
        }

        X = X->next;
        Y = Y->next;
        Z = Z ->next;
    }
    while (Z!= NULL);

}



void Merge_sub (int* arr, List *&Subarray1, List *&Subarray2, int* buf) {
    List *MIN = new List;
    List *MAX = new List;

    if (Subarray1->sub_size < Subarray2->sub_size) {
        List *MIN = Subarray1;
        List *MAX = Subarray2;
    } else {
        MIN = Subarray2;
        MAX = Subarray1;
    }
    int temp_size = MIN->sub_size;
    int temp[temp_size];
    for (int i = 0; i < temp_size; i++)
        temp[i] = arr[(MIN->start_index) + i];
    int index_max = (MAX->start_index);
    int index_min = 0;
    std::cout << "buf";
    for (int i=0; i<=(temp_size+MAX->sub_size); i++) {
        if (index_min<=temp_size) {
            if (index_max <= (index_max+(MAX->sub_size))) {
                if (arr[index_max] < temp[index_min]) {
                    buf[i] = arr[index_max];
                    index_max++;
                } else {
                    buf[i] = temp[index_min];
                    index_min++;
                }

            } else {                            //здесь непонятно, когда закончился один из массивов и перекидываем остатки второго
                buf[i] = temp[index_min];
                index_min++;
                std::cout << "end of index_max";
            }
        } else {
            buf[i] = arr[index_max];
            index_max++;
            std::cout << "end of index_min";
        }
        std::cout << buf[i] << ' ';

    }
    std::cout << std::endl;
}

void TimSort(int* arr, int size) {
    int* start = arr;
    int start_index = 0;
    int run = 8; //CalcRun(size);
    int end = run;
    bool sorted = false;

    //стек пар <индекс начала подмассива><размер подмассива>
    List *Subarray = new List;
    Subarray->head = NULL;

    do {
        Insert(start, run);

        //Заносим подмассив в стек
        Add(start_index, run, Subarray);


        if (end==size) sorted = true;
        start += run;
        end+=run;
        if (end>size){
            end = size;
            run = end%run;
        }
        start_index+=run;

    }
    while (!sorted);

    int *buf = new int[size+1];
    for(int i = 0; i < 20; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
    ifMerge(arr, Subarray, buf);

    //Show(Subarray); //Выводим стек на экран

}

void Show(List *MyList)
{
    List *temp = MyList->head;                          //Объявляем указатель и Указываем ему, что его позиция в голове стека
    //с помощью цикла проходим по всему стеку
    while (temp != NULL)                                //выходим при встрече с пустым полем
    {
        std::cout << "Subarray "<< temp->start_index << " " << temp->sub_size << " ";      //Выводим на экран элементы стека
        temp = temp->next;                              //Переходим к следующему элементу
    }
    std::cout << std::endl;
}














/*void TimSort(int* arr, int n) {
    for (int i = 0; i < n; i+=48)
        Insert(arr, i, __min((i+48),(n-1)));
    for (int size = 48; size < n; size = 2*size)
    {
        // pick starting point of left sub array. We
        // are going to merge arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we increase left by 2*size
        for (int left = 0; left < n; left += 2*size)
        {
            // find ending point of left sub array
            // mid+1 is starting point of right sub array
            int mid = left + size - 1;
            int right = __min((left + 2*size - 1), (n-1));
            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
            MergeSort(arr, left, right);
        }
    }

}

*/


/*
void TimSort(int* arr, int size) {
    int index = 0;
    int begin = index;
    while (index<size) {
        int end = begin;
        end ++;
        if (arr[begin] > arr[end]) {
            swap( arr, arr[begin], arr[end]);
        }
        bool sorted = true;
        while(sorted) {
            end++;
            sorted = arr[end] > arr[end - 1] ? true : false;
        }
        if ((end-begin)<48) {
            end = __min(begin+48, size);
        }
        Merge(arr, begin,end);
        begin ++;
    }

}
/*

int Heap(int *arr, int size) { //O(n^2)
    int end = size-1;
    for(int begin = 0; begin < size - 1; begin++) {
        make_heap(arr, begin, end);

    }

}


int Heap_2(int *arr, int size, int root = 0) {
    if (root>=size) return;
    if (2root >= size) return;
    if (2root+1 >= size) return;
    //
    if (arr[2*root] < arr[2*root+1]) {
        swap(arr, arr[2*root], arr[2*root+1]);
        update_heap(arr, size, 2*root+1);
    }
}

int update_heap(int *arr, int size, int root)  {
    if(2*root>=size) return;
    if (2*root>=size-1) {
        if (arr[root]<arr[2*root]) {
            swap(arr[root], arr[2*root]);
            return;
        }
        if (arr[root]<arr[2*root]) {
            swap(arr[root], arr[2*root]);
            return;
        }
        //тут что-тооо происходит
    }
}

int Create_Heap(int* arr, int size, int root) {
    for (root=size - 1; root > 0 ; root --) {
        update_heap(arr, size, root);
    }


}*/
