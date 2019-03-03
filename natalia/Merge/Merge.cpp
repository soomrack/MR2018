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

void timMerge(int * arr, List *&Subarray, int* buf) {
    List *X = Subarray -> head;
    int start_el = 0;
    do {
        Merge_sub(arr, X, buf, start_el);
        start_el+=(X->sub_size);
        X = X->next;
    }
    while (X != NULL);
}



void Merge_sub (int* arr, List *&Subarray, int* buf, int start_el) {
    //List * MIN = new List;
    //List * MAX = new List;
    if (start_el == 0) {
        for (int i = 0; i < Subarray->sub_size; i++) {
            buf[i] = arr[Subarray->start_index + i];
        }
    }
    else {
        int temp[start_el];
        for (int i = 0; i < start_el; i++) {
            temp[i] = buf[i];
        }

        int index_temp = 0;
        int index_sub = 0;
        for (int i = 0; i < start_el + Subarray->sub_size; i++) {
            if (index_temp <= start_el) {
                if (index_sub <= Subarray->sub_size) {
                    if (temp[index_temp] < arr[Subarray->start_index + index_sub]) {
                        buf[i] = temp[index_temp];
                        index_temp++;
                    } else {
                        buf[i] = arr[Subarray->start_index + index_sub];
                        index_sub++;
                    }
                } else {
                    //std::cout << "end of index_sub" << std::endl;
                    buf[i] = temp[index_temp];
                }

            } else {
                if (index_sub <= Subarray->sub_size) {
                    //std::cout << "end of index_temp" << std::endl;
                    buf[i] = arr[Subarray->start_index + index_sub];
                }
            }
            //std::cout << buf[i] << ' ';
        }
        //std::cout << std::endl;
    }

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
       // Subarray = Subarray->next;
        //Заносим подмассив в стек
        Add(start_index, run, Subarray);


        if (end==size) sorted = true;
        start += run;
        start_index+=run;
        end+=run;
        if (end>size){
            end = size;
            run = end%run;
        }


    }
    while (!sorted);

    int *buf = new int[size+1];
    for(int i = 0; i < 20; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
    timMerge(arr, Subarray, buf);
    std::cout <<  " Merged ";
    for(int i = 0; i < 20; i++)
         arr[i] = buf[i] ;
    std::cout << std::endl;
    ClearList(Subarray); //Очищаем память.
    delete Subarray->head;
    delete Subarray;

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
