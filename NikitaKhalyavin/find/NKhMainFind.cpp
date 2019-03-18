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

    tree[0].visiting1WithAction(KeyAndValuePrintBinary);
    tree[0].visiting2WithAction(KeyAndValuePrintBinary);

    tree[0].search(2, KeyAndValuePrintBinary);
    binaryTreePoint * temp = tree[3].searchForParent(&tree[0]);
    KeyAndValuePrintBinary(temp);

    tree[1].createRightChild();
    tree[1].returnRightChild()->setValue(5);
    tree[0].visiting1WithAction(KeyAndValuePrintBinary);
    tree[1].deleteHimself(&tree[0]);
    tree[0].visiting1WithAction(KeyAndValuePrintBinary);

}