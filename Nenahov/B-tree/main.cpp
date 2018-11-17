#include <iostream>
#include "B-treelibrary.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    tree A;
    A.add(100);
    A.add(1);
    A.add(45);
    A.add(2);
    A.add(20);
    A.add(12);
    A.add(200);
    A.add(199);
    A.print();
    return 0;
}