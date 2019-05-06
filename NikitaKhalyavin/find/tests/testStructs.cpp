//
// Created by Nikita on 06.05.2019.
//

#include "../structs.h"

int main() {
    Stack<int> St1;
    Queue<int> Qu1;
    for (int i = 0; i < 100; i++) {
        St1.push(i);
        Qu1.enqueue(i);
    }
    for(int i = 99; i >=0; i--) {
        if(St1.pop() != i) return 1;
    }
    for(int i = 0; i < 100; i++) {
        if(Qu1.dequeue() != i) return 1;
    }
    return 0;
}