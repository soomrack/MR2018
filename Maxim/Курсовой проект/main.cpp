#include "avl_library.h"
#include <ctime>
#include <iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;


int main(){

    using namespace std;
    tree A;

for(int i=0;i<=100000;i++)  A.root=A.insert(A.root,i);
    node* t=A.search(A.root,56);
    auto t1 = Clock::now();
    for(int i=0;i<=100000;i++)  A.root=A.remove(A.root,i);
auto t2 = Clock::now();
    cout<< "Delta t2-t1: "<<chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count()
    <<" nanoseconds" <<endl;

   // A.root=A.remove(A.root,54);
    return 0;
}
