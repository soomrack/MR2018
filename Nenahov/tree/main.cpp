#include <iostream>
#include <random>
#include <cmath>

using namespace std;

void make_section_tree_MAX(int *ar,unsigned int size)
{
    int *buff;
    unsigned int newsize;
    double var=log(size)/log(2);

    if(fmod(var,(int)var)==0) newsize=size;
    else newsize=pow(2,ceil(var));

    for(unsigned int i=size;i<newsize;i++)
    {
        ar[i]=INT32_MIN;
    }


    unsigned int fullsize=0;
    for(unsigned int i=0;i<=var;i++)
    {
        fullsize+=pow(2,i);
    }
    //fullsize=(unsigned int)pow(2,ceil(var));
    buff=new int(fullsize);
    for(unsigned int i=0;i<newsize;i++)
    {
        buff[i]=ar[i];
        cout<<buff[i]<<" ";
    }

    for(unsigned int i=newsize;i<fullsize;i++)
    {
        buff[i]=max(buff[(i-newsize)*2],buff[(i-newsize)*2+1]);
        cout<<buff[i]<<" ";
    }
    delete [] buff;

}

//void find_MAX(int *ar,unsigned int begin,unsigned int end)
//{
//
//    unsigned int left=begin;
//    unsigned int right=end;
//    unsigned int level=1;
//    int *buff2;
//
//    while(left<right*level)
//    {
//        if(left%2)
//        left++;
//    }
//
//}



int main() {
   srand(10);
   int size=8;
   int arr[8];
   for(int i=0;i<8;i++)
   {
       arr[i]=rand();
       cout<<arr[i]<<" ";
   }
   cout<<endl;
   make_section_tree_MAX(arr,8);
   return 0;
}