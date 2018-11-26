#include <iostream>
#include "B-treelibrary.h"
#include <ctime>
int main() {
    //srand((unsigned int)time(nullptr));
   srand(10);
    using namespace std;
    tree A;
    double var;
    for(int i=0;i<9;i++) {
        var=rand();
        A.add(var);
        cout<<var<<"\t";
    }
    cout<<endl;

    A.add(1);
    /*A.add(10);
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
    //A.deletekey(10);
    A.print();
    A.deletekey(50);
    A.print();
*/
    return 0;
}