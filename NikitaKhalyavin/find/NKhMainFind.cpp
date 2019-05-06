//
// Created by work on 11.02.2019.
//

#include "findInArray.h"
#include "ArraySort.h"
#include "trees/RBTree.h"
#include <stdio.h>
#include <iostream>


using namespace std;

void dataListPrint(List<void *> data) {
    for(unsigned int i = 0; i < data.getSize(); i++) {
        int temp = *( (int *)(data.getItem(i)) );
        printf("%d\t", temp);
    }
    printf("\n");
}

int main() {

    binaryTree tree1;

    int data[10] = {0,1,2,3,4,5,6,7,8,9};

    tree1.add(100,&data[0]);
    tree1.add(150,&data[1]);
    tree1.add(900,&data[2]);
    tree1.add(90,&data[3]);
    tree1.add(60,&data[4]);
    tree1.add(75,&data[5]);
    tree1.add(98,&data[6]);
    tree1.add(152,&data[7]);
    tree1.add(45,&data[8]);
    tree1.add(0,&data[9]);

    List<void *> result;

    result = tree1.visiting1();
    dataListPrint(result);
    result = tree1.visiting2();
    dataListPrint(result);

    tree1.remove(900);
    tree1.remove(90);

    result = tree1.visiting1();
    dataListPrint(result);
    result = tree1.visiting2();
    dataListPrint(result);

    printf("%d", *( (int *)tree1.search(152) ) );
}