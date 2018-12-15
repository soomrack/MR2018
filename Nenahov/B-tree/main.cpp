#include <iostream>
#include "B-treelibrary.h"

int main() {
    using namespace std;
    tree A;
    int time0=clock();
    int count=50000000;
    for(int i=1;i<count;i++) {
        A.add(i);
    }
    int time1=clock();

    int elapsedtime=time1-time0;

    cout<<"adding "<<count<<" keys has spent "<<elapsedtime<<" msec"<<endl;

    time0=clock();

    for(int i=1;i<count;i++) {
        A.search(i);
    }
    time1=clock();

    elapsedtime=time1-time0;

    cout<<"searching  "<<count<<" keys has spent "<<elapsedtime<<" msec"<<endl;

     time0=clock();

    for(int i=1;i<count;i++) {
        A.deletekey(i);
    }
     time1=clock();

     elapsedtime=time1-time0;

    cout<<"deleting  "<<count<<" keys has spent "<<elapsedtime<<" msec"<<endl;



    return 0;
}