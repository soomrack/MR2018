//
// Created by work on 11.02.2019.
//

#include "findInArray.h"
#include "ArraySort.h"
#include "trees.h"
#include <stdio.h>


void KeyAndValuePrint(B_TreePoint * object) {
    printf("%u\t%d\n",(*object).getKey(), (*object).value);
}

void KeyAndValuePrintBinary(binaryTreePoint * object) {
    printf("%u\t%d\n",object->getKey(), object->value);
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

    tree1.visiting1();



}