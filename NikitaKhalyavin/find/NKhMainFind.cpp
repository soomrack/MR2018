//
// Created by work on 11.02.2019.
//

#include "findInArray.h"
#include "ArraySort.h"
#include "trees.h"
#include <stdio.h>

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
}