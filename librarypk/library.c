#include "library.h"

#include <stdio.h>
#define TIME 120
#define STAVKA 0.18
#define PROCENT 0.1
#define VZNOS 1000000
#define DOLG 5000000
#define KVPAY 20000
int ezmes_pay1(mes)
{
    int pay=0;
    int sum=0;
    int ostat = DOLG-VZNOS;
    for (int i=0;i<mes;++i)
    {
        pay = DOLG/TIME+(STAVKA/12)*ostat; // платёж за ипотеку в месяц
        ostat = ostat-pay;
        sum = sum+pay; // сумма всех платежей
    }
    return DOLG-sum; // сколько денег имеет
}
int ezmes_pay2(mes)
{
    int bank=VZNOS;
    for (int i=0;i<mes;++i)
    {
        bank=bank+(PROCENT/12)*bank; //счёт в банке
    }
    bank=bank-KVPAY*120; // вычет из счёта денег за кварплату
    return bank; // сколько денег имеет
}


void main2()
{
    printf("man1 %d\n",ezmes_pay1(TIME));
    printf("man2 %d\n",ezmes_pay2(TIME));
}
