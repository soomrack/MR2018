//
// Created by work on 03.03.2019.
//

#include <cstdlib>
#include <cstdio>

#ifndef MR2018_STRUCTS_H
#define MR2018_STRUCTS_H

#endif //MR2018_STRUCTS_H

template <typename T>
class Stack {
private:
    unsigned int size;
    T * data;
public:
    Stack() : size(0) {

    }

    Stack(Stack &input) {
        this->size = input.size;
        this->data = (T * )malloc(size * sizeof(T));
        memcpy(this->data, input.data, sizeof(T) * size);
    }

    void push(T input) {
        T * temp = (T * )malloc((size + 1) * sizeof(T));
        memcpy(temp, data, sizeof(T) * size);
        temp[size] = input;
        size++;
        free(data);
        data = temp;
    }

    T pop() {
        if(size == 0) {
            printf("Error: stack is empty");
            exit(1);
        }
        size--;
        T * temp = (T * )malloc((size) * sizeof(T));
        memcpy(temp, data, sizeof(T) * size);
        T out = data[size];
        free(data);
        data = temp;
        return out;
    }

    unsigned int getSize() {
        return size;
    }
};

template <typename T>
class List {
private:
    unsigned int size;
    T * data;
public:
    List() : size(0) {

    }

    List(List &input) {
        this->size = input.size;
        this->data = (T * )malloc(size * sizeof(T));
        memcpy(this->data, input.data, sizeof(T) * size);
    }

    void add(T input) {
        T * temp = (T * )malloc((size + 1) * sizeof(T));
        memcpy(temp, data, sizeof(T) * size);
        temp[size] = input;
        size++;
        free(data);
        data = temp;
    }

    T getItem(unsigned int index) {
        if(index < size) return data[index];
        printf("There aren't item with this index in the List");
        exit(1);
    }

    unsigned int getSize() {
        return size;
    }

};