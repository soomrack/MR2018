#include "ksenya.h"

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include "ksenya.h"
#define TIME 121
#define TIME2 97
#define STAVKA 0.18
#define STAVKA2 0.17
#define PROCENT 0.1
#define VZNOS 1000000
#define DOLG 5000000
#define KVPAY 20000

int ezmes_pay1_do_krizisa(int mes)
{
    int pay=0;
    int sum=0;
    int ostat = DOLG-VZNOS;


    for (int i=0;i<mes;i++) // считаем платежи до кризиса (то есть 96 месяцев)
    {
        pay =(int) DOLG/TIME+(STAVKA/12)*ostat; // платёж за ипотеку в месяц
        ostat = ostat-pay;
        sum = sum+pay; // сумма всех платежей
    }

    return sum; // общая сумма выплат
}

int ezmes_pay1_posle_krizisa(int mes) // после кризиса берем сумму, получившуюся за 8 лет и делаем новые вычисления с ней
{
    int pay=0;
    int sum2;
    sum2=ezmes_pay1_do_krizisa(mes);
    int ostat = DOLG-VZNOS-sum2;
    for (int i=0;i<mes;++i)
    {
        pay = (int) DOLG / TIME + (STAVKA2 / 12) * ostat; // платёж за ипотеку в месяц
        ostat = ostat - pay;
        sum2 = sum2 + pay; // сумма всех платежей
    }
    return sum2; // общая сумма выплат
}


int ezmes_pay2(int mes)
{
    int bank=VZNOS;
    for (int i=0;i<mes;++i)
    {
        bank=bank+(PROCENT/12)*bank; //счёт в банке
    }
    bank=bank-KVPAY*120; // вычет из счёта денег за кварплату
    return bank; // сколько денег имеет
}

int main()
{
    for (int mes=1; mes < TIME2; mes++) // выводим общие суммы выплат в первые 8 лет
    {
        printf("%d        %d\n", ezmes_pay1_do_krizisa(mes), ezmes_pay2(mes) );
    }

    for (int mes=97; mes < TIME; mes++)
    {
        printf("%d\n", ezmes_pay1_posle_krizisa(mes));
    }


    return 0;
}