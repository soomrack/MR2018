//
// Created by work on 11.02.2019.
//

#include "findInArray.h"
#include "ArraySort.h"
#include "trees.h"
#include <stdio.h>


void KeyPrint(B_TreePoint * object) {
    printf("%u\t",(*object).getKey());
}

int main() {
    binaryTreePoint tree[5];

    tree[0].setValue(0);
    tree[0].setLeftChild(&tree[1]);
    tree[0].setRightChild(&tree[2]);

    tree[1].setValue(1);
    tree[1].setLeftChild(&tree[3]);

    tree[2].setValue(2);
    tree[2].setLeftChild(&tree[4]);

    tree[3].setValue(3);

    tree[4].setValue(4);

    binaryTreePointList listForSearch1;
    binaryTreePointList listForSearch2;

    listForSearch1.search1(tree[0]);
    listForSearch2.search2(tree[0]);

    B_TreePoint tree2[8];

    tree2[0].setValue(0);
    tree2[1].setValue(1);
    tree2[2].setValue(2);
    tree2[3].setValue(3);
    tree2[4].setValue(4);
    tree2[5].setValue(5);
    tree2[6].setValue(6);
    tree2[7].setValue(7);

    tree2[0].resize(4);
    tree2[3].resize(2);
    tree2[6].resize(1);

    tree2[1].resize(1);

    tree2[0].setChild(0, &tree2[4]);
    tree2[0].setChild(1, &tree2[2]);
    tree2[0].setChild(2, &tree2[3]);
    tree2[0].setChild(3, &tree2[1]);

    tree2[3].setChild(0, &tree2[7]);
    tree2[3].setChild(1, &tree2[6]);

    tree2[6].setChild(0, &tree2[5]);

    B_TreePoint AddPoint;

    AddPoint.setValue(100);

    tree2[0].addPointWithBalance(&AddPoint);
    printf("\n");
    tree2[0].search1();
    printf("\n");
    tree2[0].search2();
    printf("\n");


    tree2[0].visiting1WithAction<void>(KeyPrint);



}