#include "VolkovaA.h"
#include "Volkova.h"
#include <stdio.h>
#include <math.h>
#define PREPAY 100000000                                                         //Первоначальный платеж по кредиту
#define SUM 500000000                                                            //Сумма в копейках
#define PERCENTCERDIT 20.00                                                      //Процент годовых по кредиту
#define PERCENTDEBIT 10.00                                                       //Процент годовых по вкладу
#define PERCENTNEWCHEL 18.00
#define TIME2 180
#define TIME 120                                                                 //Срок кредита в месяцах
#define RENT 20000                                                               //Ежемесячная аренда жилья
int AUN()
{
    int H=(SUM-PREPAY);
    int K=ceil(H*((PERCENTCERDIT/1200)*pow(1+(PERCENTCERDIT/1200), TIME))/(pow(1+(PERCENTCERDIT/1200), TIME)-1));   //Воспользуемся формулой аннуитетных платежей
    return(K);
}
void credit(int y)
{
    int H=(SUM-PREPAY);
    for(int i=1; i<y; i++)
    {
        H=H*(1+(PERCENTCERDIT/1200))-AUN();
    }
    if(H<0)                                                                  //Проверим выплачен ли кредит, ибо из-за округления может быть переплата
    {
        H=0;
    }
    printf("%6i rubles %2i copeek   ",(int)ceil(H/100),(int)H % 100);
}


float debit(int y)
{
    int H=PREPAY;
    for(int i=1; i<y; i++)
    {
        H=H*(1+(PERCENTDEBIT/1200))+AUN()-RENT;
    }
    if(H>SUM)                                                               //Проверим достаточно ли денег на покупку квартиры
    {
        H=0;                                                                 //Если денег достаточно то покупаем кваритру и дальше не копим
    }
    if(H<0)                                                               //Проверим достаточно ли денег на покупку квартиры
    {
        H=0;                                                                 //Если денег достаточно то покупаем кваритру и дальше не копим
    }
    printf("%6i rubles %2i copeek \n",(int)H/100, (int)H % 100);
}

int AUN2()
{
    int H1=(SUM-PREPAY);
    int K=ceil(H1*((PERCENTNEWCHEL/1200)*pow(1+(PERCENTNEWCHEL/1200), TIME2))/(pow(1+(PERCENTNEWCHEL/1200), TIME2)-1));   //Воспользуемся формулой аннуитетных платежей
    return(K);
}
void credit2(int y)
{
    int H2=(SUM-PREPAY);
    for(int i=1; i<y; i++)
    {
        H2=H2*(1+(PERCENTNEWCHEL/1200))-AUN2();
    }
    if(H2<0)                                                                  //Проверим выплачен ли кредит, ибо из-за округления может быть переплата
    {
        H2=0;
    }
    printf("%6i rubles %2i copeek   ",(int)ceil(H2/100),(int)H2 % 100);
}


int main() {
    printf("  Month         Credit left             Credit2 left                             Debit left\n");
    for (int year = 1; year < TIME2 + 2; year++) {
        printf("%3i month     ", year);
        credit(year);
        credit2(year);
        debit(year);
    }

    return 0;
