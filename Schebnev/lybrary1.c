//
// Created by Nikolay on 17.09.2018.
//
#include "lybrary1.h"
#include <stdio.h>
#include <math.h>

int VKLAD(long int Sum, double procent,double zarplata,double kvartira) {
    int i;
    double P[11];
    P[0] = (double)Sum + (zarplata-kvartira);
    printf("Summa Nakopleniy\n");
    printf("%7.2F\n", P[0]);
    for (i = 1; i < 10; i++) {
        P[i] = P[i-1] + P[i-1] * (procent * 0.01);
        printf("%7.2F\n", (zarplata-kvartira)+P[i]);
    }
    return 0;
}
double VIPLAT(long int Cred,long int Sum, double proc,int N){
    int i;
    double vip[10],K,St,Pog;
    Pog = (double)Cred-(double)Sum;
    St = 1.0;
    for (i = 0; i < N; i++)
        St*=(1.0+0.01*proc/12);
    K=((0.01*proc)*St)/(St-1.0);
    printf("Ostatki po viplatam\n");
    for (i=0;i<10;i++) {
        vip[i]=K*(Cred-Sum);
        Pog-=vip[i];
        printf("%7.2f\n",Pog);
    }
    return (Pog);
}
void git2(){

        int Month;
        long int Summa,Credit;
        double PROCENT,Zarp,Kvar;
        Summa=1000000;
        PROCENT=13.0;
        Zarp=80000.0;
        Kvar=20000.0;
        VKLAD(Summa,PROCENT,Zarp,Kvar);
        Credit=5000000;
        Month=120;
        VIPLAT(Credit,Summa,PROCENT,Month);
}
