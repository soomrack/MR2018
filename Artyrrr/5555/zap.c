//
// Created by 3 on 17.09.2018.
//
//#include <iostream>
#include <stdio.h>
#include <math.h>


typedef struct {
    double dolg;
    double stavka;
} client;


long long gemor(double buf,double znam,int a,int sum,long long payment)
{
    for ( double sch = 0;sch<=a-2;sch++)
    {
        znam+=pow(buf,sch);
};
payment = (sum*pow(buf,a-1))/znam;
return payment;
}

int main()
{
    // kak polzovatcya client
    //client man01[13][11];
    // man01[1][1].dolg = 0.0;

    //perviy chel

    double buf = 1.0+0.18/12.0;
    double znam=0;
    int sum = 5000000;
    long long payment, pay1, pay2;
    int time =120;
    int a = 12*8;
    pay1 = gemor(buf,znam,time,sum,payment);

    printf("Person 1: Payment for first period = %d\n", pay1);

    long long sum2 = pay1*a;

    printf("Sum for 8 years = %d\n", sum2);

    long long sum0 = pay1*time;
    printf("Sum for 10 years = %d\n", sum0);

    long long sum11=sum0-sum2;
    printf("Sum which Person 1 will have to pay in resent 10 years = %d\n", sum11);

    pay2 = gemor(buf,znam,time,sum11,payment);
    printf("Person 1: Payment for second period = %d\n", pay2);

    long long sum22 = pay2*time;
    printf("Sum for the second period of payment = %d\n", sum22);

    //zadacha for neskolkih ludei

    int percent[]={13,14,15,16,17,18,19,20,21,22,23,24,25};
    int money[]={4,5,6,7,8,9,10,11,12,13,14};




    //vtoroi chel

    long long vklad=1000000, rent=20000;
    double percentage2=1.10;
    long long rentsum= rent*time;

    printf("Person 2: Rent sum = %d\n", rentsum);

    long long result=(vklad*pow(percentage2,10));

    printf("Result = %d\n", result);

    long p1=0;
    p1=sum2+sum22-sum-vklad;
    printf("Person 1: zatraty = - %d\n", p1);
    long p2=0;
    p2=result-rentsum;
    printf("Person 2: zatraty = - %d\n", p2);


    if (p1>p2)
        printf("Person 1 paid more than Person 2");
    else
        printf("Person 2 paid more than Person 1");

}