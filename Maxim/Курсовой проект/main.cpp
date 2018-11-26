#include "avl_library.h"
#include <iostream>
int main(){
    using namespace std;
    tree A;
    A.root=A.insert(A.root,1);
    A.root=A.insert(A.root,54);
    A.root=A.insert(A.root,50);
    A.root=A.insert(A.root,24);
    A.root=A.remove(A.root,54);
    return 0;
}
