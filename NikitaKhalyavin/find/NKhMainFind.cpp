//
// Created by work on 11.02.2019.
//

#include "findInArray.h"
#include "ArraySort.h"
#include "trees.h"
#include <stdio.h>
#include <iostream>


using namespace std;

void dataListPrint(List<int> data) {
    for(unsigned int i = 0; i < data.getSize(); i++) {
        int temp = data.getItem(i);
        printf("%d\t", temp);
    }
    printf("\n");
}



int main() {

    binaryTree<int> tree1;
    tree1.Add(512, 0);
    tree1.Add(24, 1);
    tree1.Add(514, 2);
    tree1.Add(513,3);
    tree1.Add(1024, 4);

    int bla = tree1.search(1024);

    tree1.deleteItemWithoutChildren(514);
    tree1.deleteItemWithoutChildren(512);

    List<int> temp;


    temp = tree1.visiting1();

    for (int i = 0; i < temp.getSize(); i++) {
        printf("%d\t", temp.getItem(i));
    }

    tree1.balancing();

    temp = tree1.visiting1();

    for (int i = 0; i < temp.getSize(); i++) {
        printf("%d\t", temp.getItem(i));
    }

}