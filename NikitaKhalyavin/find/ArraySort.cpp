//
// Created by work on 11.02.2019.
//

#include "ArraySort.h"
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <cstring>

#define swap(a,b) { a ^= b; b ^= a; a ^= b;}

void BubbleSort(int * array, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1 - i; j++) {
            if( array[j] > array[j + 1] ) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


static void downHeap(int * array, int size, int newIndex) {

    int child;
    int newElement = array[newIndex];

    while(newIndex < size / 2) {

        child = newIndex * 2 + 1;
        if( (child + 1 < size) && (array[child + 1] > array[child]) ) {
            child++;
        }
        if(array[child] <= newElement) {
            break;
        }
        array[newIndex] = array[child];
        newIndex = child;
    }
    array[newIndex] = newElement;
}

static void makeHeap(int * array, int size) {
    for(int i = size / 2; i >= 0; i--) downHeap(array, size, i);
}

void HeapSort(int * array, int size) {

    makeHeap(array, size);

    for(int i = size - 1; i > 0; i--) {

        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        downHeap(array, i, 0);
    }
}

void InsertSort(int * array, int size) {

    int place;

    for(int item = 1; item < size; item++ ) {
        place = item - 1;
        while(place >= 0) {
            if(array[place] > array[place + 1]) {
                swap(array[place], array[place + 1]);
            }
            else break;
            place--;
        }
    }
}

void MergeSort(int * array, int size) {
    if(size < 2) return;
    MergeSort(array, size / 2);
    MergeSort(array + (size / 2), size - (size / 2));
    int temp[size];

    int i = 0;
    int counterLeft = 0;
    int counterRight = size / 2;

    for(i = 0; i < size; i++) {
        if(array[counterLeft] < array[counterRight]) {
            temp[i] = array[counterLeft];
            counterLeft++;
            if(counterLeft == (size / 2)) break;
        }
        else {
            temp[i] = array[counterRight];
            counterRight++;
            if(counterRight == size) break;
        }
    }

    for(counterLeft; counterLeft < size / 2; counterLeft++) {
        i++;
        temp[i] = array[counterLeft];
    }
    for(counterRight; counterRight < size; counterRight++) {
        i++;
        temp[i] = array[counterRight];
    }

    memcpy(array, temp, sizeof(int) * size);
}

static int GetMinrun(int n)
{
    int r = 0;
    while (n >= 64) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

void arrayTurnAround (int * array, int size) {
    for(int i = 0; i < size / 2; i++) {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

struct subArrayCoord{
    int start;
    int size;
};

class stackOfSubArrays {
private:

public:
    int size;
    subArrayCoord * data;

    stackOfSubArrays() : size(0) {
        data = (subArrayCoord *)0;
    }

    void push(subArrayCoord input) {
        this->size ++;

        subArrayCoord * tempData = (subArrayCoord *)malloc(sizeof(subArrayCoord) * size);
        memcpy(tempData, data, sizeof(subArrayCoord) * (size - 1) );
        free(data);
        tempData[size - 1] = input;
        data = tempData;
    }

    subArrayCoord pop() {

        subArrayCoord out;
        if(size == 0){
            out.size = 0;
            out.start = 0;
            return out;
        }

        out = data[size - 1];
        size--;
        if(size == 0) {
            free(data);
            data = (subArrayCoord *)0;
            return out;
        }
        subArrayCoord * tempData = (subArrayCoord *)malloc(sizeof(subArrayCoord) * size);
        memcpy(tempData, data, sizeof(subArrayCoord) * size);
        free(data);
        data = tempData;
        return out;
    }

    ~stackOfSubArrays(){
        if (size != 0) free(data);
    }

    void subArraysMerging(int * array, int ind1, int ind2) {

        if (ind2 < ind1) {
            int temp = ind2;
            ind2 = ind1;
            ind1 = temp;
        }

        subArrayCoord arr1 = data[ind1];
        subArrayCoord arr2 = data[ind2];

        int Newsize = arr1.size + arr2.size;
        //printf("%d\t", Newsize);
        int minStart = arr1.start;
        if (minStart > arr2.start) minStart = arr2.start;

        int i = 0;
        int counterLeft = arr1.start;
        int counterRight = arr2.start;

        int * temp = (int *)malloc(sizeof(int) * Newsize);

        for(i = 0; i < Newsize; i++) {
            if(array[counterLeft] < array[counterRight]) {
                temp[i] = array[counterLeft];
                counterLeft++;
                if(counterLeft == (arr1.start + arr1.size)) break;
            }
            else {
                temp[i] = array[counterRight];
                counterRight++;
                if(counterRight == arr2.start + arr2.size) break;
            }
        }

        for(counterLeft; counterLeft < arr1.start + arr1.size; counterLeft++) {
            i++;
            temp[i] = array[counterLeft];
        }
        for(counterRight; counterRight < arr2.start + arr2.size; counterRight++) {
            i++;
            temp[i] = array[counterRight];
        }

        memcpy(&array[minStart], temp, sizeof(int) * Newsize);
        free(temp);

        subArrayCoord newSubArr;
        newSubArr.start = minStart;
        newSubArr.size = Newsize;

        size--;
        subArrayCoord * tempData = (subArrayCoord *)malloc(sizeof(subArrayCoord) * (size) );
        memcpy(tempData, data, sizeof(subArrayCoord) * ind1);
        tempData[ind1] = newSubArr;
        memcpy(&tempData[ind2], &data[ind2 + 1], sizeof(subArrayCoord) * (size - ind1));
        free(data);
        data = tempData;

        return;
    }
};



void TimSort ( int * array, int size) {

    int minRun = GetMinrun(size);
    int thisIndex = 0;

    stackOfSubArrays stack;


    while(thisIndex < size) {
        int start = thisIndex;
        if(thisIndex > size - 3) {
            thisIndex = size;
        }
        else {
            if (array[thisIndex] > array[thisIndex + 1]) {
                while (array[++thisIndex] > array[thisIndex + 1]) {
                    if (thisIndex + 2 == size) break;
                }
                arrayTurnAround(&array[start], thisIndex + 1 - start);
            } else {
                while (array[++thisIndex] <= array[thisIndex + 1]) {
                    if (thisIndex + 2 == size) break;
                }
            }
            if (++thisIndex < start + minRun) thisIndex = start + minRun;
            if (thisIndex > size) thisIndex = size;
        }
        InsertSort(&array[start], thisIndex - start);

        subArrayCoord newCoords;
        newCoords.start = start;
        newCoords.size = thisIndex - start;

        stack.push(newCoords);
    }



    while (stack.size > 2) {
        //stack.subArraysMerging(array, 0, 1);

        int i = 2;
        int Size = stack.size;
        int ind1 = 0;
        int ind2 = 0;
        subArrayCoord buf[stack.size];
        buf[0] = stack.pop();
        buf[1] = stack.pop();
        for(; i < Size; i++) {
            buf[i] = stack.pop();
            if( (buf[i - 2].size <= buf[i - 1].size + buf[i].size) || (buf[i - 1].size <= buf[i].size) ) {
                ind1 = i - 1;
                if(buf[i - 2].size <= buf[i].size) ind2 = i - 2;
                else ind2 = i;
                break;
            }
        }
        if (ind1 + ind2 == 0) {
            stack.push(buf[Size-1]);
            for(i = Size - 2; i >= 0; i--) {
                stack.push(buf[i]);
                stack.subArraysMerging(array, 0, 1);
            }
        }
        else {
            for (; i >= 0; i--) {
                stack.push(buf[i]);
            }
            stack.subArraysMerging(array, ind1, ind2);
        }


    }

    if(stack.size == 2) stack.subArraysMerging(array, 0, 1);

}

int * CreateRandArray(int size, int min, int max) {
    int * a = (int *) malloc(size * sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < size; i ++) {
        a[i] = (int)(rand()) * (max - min) / RAND_MAX + min;
    }
    return a;
}

void  ArrayPrint(int * array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}