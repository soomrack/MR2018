#include "avl_library.h"
#include <iostream>
int main(){
 node tree;
 node *tree1=&tree;
   tree1 = insert(tree1,3);
   tree=*tree1;
    tree1 = remove(tree1,3);
    tree=*tree1;
    return 0;
}
