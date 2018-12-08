#include <iostream>
#include "B-treelibrary.h"

int main() {
    //srand((unsigned int)time(nullptr));
   srand(10);
    using namespace std;
    tree A;
    double var;
    for(int i=0;i<1000000;i++) {
        var=rand();
        int time0=clock();
        time(0);

        A.add(var);
        int time1=clock();

        int elapsedtime=time1-time0;

        cout<<"adding "<<i+1<<" key has spent "<<clock()<<" msec"<<endl;
    //    cout<<i<<'\t'<<var<<'\t'<<"The address of "<<*A.search(var)<<" is "<<A.search(var)<<endl;
    }

    //for(int i=0;i<30;i++) cout<<i<<'\t'<<"The address of "<<*A.search(i)<<" is "<<A.search(i)<<endl;
    A.add(rand());
    A.add(2000);
    A.deletekey(13694);
    A.deletekey(2000);

    cout<<"The address of "<<*A.search(2000)<<" is "<<A.search(2000)<<endl;
//    cout<<"The address of "<<*A.search(30)<<" is "<<A.search(30)<<endl;




    /*for(int i=35;i<38;i++) {
        var=rand();
        A.add(var);
        cout<<var<<"\t";
    }
    cout<<endl;
//    A.add(1);
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