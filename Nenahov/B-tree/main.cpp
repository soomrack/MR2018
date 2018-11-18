#include <iostream>
#include "B-treelibrary.h"
int main() {
    using namespace std;
    tree A;
    A.add(1);
    A.add(10);
    A.add(30);
    A.add(50);
    A.add(60);
    A.add(100);

    A.add(200);
    A.add(201);

    A.add(19);
    A.add(43);
    A.print();
    //A.search(30);
    cout<<"The address of "<<*A.search(30)<<" is "<<A.search(30)<<endl;

    return 0;
}