#include <iostream>
#include "B-treelibrary.h"

int main() {
    using namespace std;
    tree A;
    int time0=clock();
    for(int i=1;i<10000;i++) {
        A.add(i);
    }
    int time1=clock();

    int elapsedtime=time1-time0;

    cout<<"adding 10000 "<<" keys has spent "<<elapsedtime<<" msec"<<endl;
     time0=clock();

    for(int i=1;i<9999;i++) {
        A.deletekey(i);
    }
     time1=clock();

     elapsedtime=time1-time0;

    cout<<"deleting 10000 "<<" keys has spent "<<elapsedtime<<" msec"<<endl;

    A.deletekey(43);
  /*  tree B;
     time0=clock();
    for(int i=0;i<100000;i++) {
        B.add(i);
    }
     time1=clock();

     elapsedtime=time1-time0;

    cout<<"adding 100000 "<<" keys has spent "<<elapsedtime<<" msec"<<endl;

    tree C;
    time0=clock();
    for(int i=0;i<1000000;i++) {
        C.add(i);
    }
    time1=clock();

    elapsedtime=time1-time0;

    cout<<"adding 1000000 "<<" keys has spent "<<elapsedtime<<" msec"<<endl;

    tree E;
    time0=clock();
    for(int i=0;i<10000000;i++) {
        E.add(i);
    }
    time1=clock();

    elapsedtime=time1-time0;

    cout<<"adding 10000000 "<<" keys has spent "<<elapsedtime<<" msec"<<endl;


    /*time0=clock();
    for(int i=0;i<10000000;i++) {
        E.deletekey(i);
    }
    time1=clock();

    elapsedtime=time1-time0;

    cout<<"deleting 10000000 "<<" keys has spent "<<elapsedtime<<" msec"<<endl;*/
    return 0;
}