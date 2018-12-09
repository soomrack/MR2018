#include <iostream>
#include <time.h>

int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int main()
{
    unsigned int lagA = 0, lagB = 0;
    int Amount = 0;

    std::cout<<" Lag a = ";
    std::cin>>lagA;
    std::cout<<" Lag b = ";
    std::cin>>lagB;
    std::cout<<" Amount of numbers ";
    std::cin>>Amount;

    srand(time(NULL));
    int* Arr = new int[(max(lagA,lagB) + Amount + 1)];
    for (int i = 0; i<max(lagA,lagB); i++){
        Arr[i] = rand();
    }


    for (int i = max(lagA,lagB); i < (max(lagA,lagB) + Amount); i++)
    {
        if (Arr[i-lagA] >= Arr[i-lagB])
        {
            Arr[i+1] = Arr[i-lagA] - Arr[i-lagB];
        } else Arr[i+1] = Arr[i-lagB]-Arr[i-lagA];
        std::cout<<Arr[i+1]<< std::endl;
    }
}