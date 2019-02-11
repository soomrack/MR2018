#include <iostream>
#include <time.h>
#include <vector>
#include <iterator>
using namespace std;

typedef vector <int> Mass;

int main()
{
    unsigned int a = 0, b = 0;
    int Amount = 0;

    Mass::iterator LagA;                //создаем все итераторы
    Mass::iterator LagB;
    Mass::iterator Lag;

    std::cout<<" Lag a = ";             //запрос параметров
    std::cin>>a;
    std::cout<<" Lag b = ";
    std::cin>>b;
    std::cout<<" Amount of numbers ";
    std::cin>>Amount;

    Mass massive(1);                    //создаем массив
    massive.resize(max(a,b)+Amount+1);

    LagA=massive.begin();               //инициализируем лаги и сдвигаем на значения а и б
    advance(LagA,a);
    LagB=massive.begin();
    advance(LagB,b);

    if(LagA>LagB) Lag=LagA;             //доп. итератор для корректной работы цикла
    else Lag=LagB;

    Mass::iterator index;               //основной итератор движения по массиву
    index=massive.begin();

    srand(time(NULL));                  //заполняем первую часть массива случайными значениями
    while(index<=Lag){
        *index = rand();
        cout<<"number="<<*index<<endl;
        index++;
    }

    for (; index != massive.end(); index++,LagA++,LagB++)
    {
        if (*LagA >= *LagB)             //получаем последовательность методом Фиблначчи с запаздываем
        {
            *index = *LagA - *LagB;
        } else *index = *LagB -*LagA;
        std::cout<<*index<< std::endl;
    }
}