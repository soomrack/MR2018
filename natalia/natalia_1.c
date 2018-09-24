#include <stdio.h>
#include <math.h>
#define TIME 120 // срок ипотеки в месяцах
#define SUM 500000000 // сумма ипотеки в копейках
#define PERCENT 0.18 // процент ипотеки в долях
#define VKLAD 100000000 // сумма вклада в копейках
#define PROCENTY 0.1 // проценты по вкладу в долях
#define OPLATA 20000 // стоимость аренды квартиры за месяц в рублях
#define VZNOS 100000000 // первоначальный взнос за ипотеку в копейках
#define nol 0

int ipoteka(int month) {
    int platezh = (SUM * PERCENT * pow((1 + PERCENT),TIME / 12)) / (12 * (pow(1 + PERCENT,TIME / 12) - 1));// Вычисляем ежемесячный платеж
    int sum = platezh * month; //сумма за заданное количество месяцев
    return (sum);
}

int vklad(int year) {
    int schet = VKLAD * pow((1 + PROCENTY), year); //сумма на счете после заданного количества лет
    return (schet);
}

int main() {
    int years = TIME / 12; // задаем количество лет
    int rez = ipoteka(TIME); //платеж за весь заданный период
    int sum_pribyl = 0;
    int sum_vyplata = 0;
    for (int  i = 1;  i <= years ; ++ i) {
        printf("%d-й год \t\t ", i);
        printf("Выплата %15.2f рублей \t\t\t", -(float)(ipoteka(i*12))/100);
        printf("Прибыль от вклада %8.2f рублей \t\t\t",(float)(vklad(i))/100);
        printf("Оплата квартиры %8d рублей \n", -OPLATA*i*12);
    }
    printf("\n--------------------------------------------------------------------------------------- \n");
    printf("Итого на счете 1: %.2f рублей \t\t", -(float)(rez + VZNOS) / 100);
    sum_vyplata += OPLATA*TIME; // вычисляем общие траты на квартиру
    sum_pribyl += vklad(years) ; // вычисляем итоговую прибыль от вклада
    printf("Итого на счете 2: %.2f рублей \n", (float)(sum_pribyl/100 - sum_vyplata) );
    return 0;
}