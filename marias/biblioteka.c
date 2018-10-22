//
// Created by prog on 17.09.2018.
//

#include "biblioteka.h"
#include <stdio.h>
#include <math.h>

double okruglenie(double in){
    double out;
    out=((double)(int)(in*100))/100;
    return out;
}
double ipoteka(int sum,int stavka) {
    double Vyplati;
    double znam=0;
    int i;
    for (i=0;i<=119;i++) {
        znam=znam+pow(1.0+(double)stavka/1200,i);
    }

    Vyplati=pow(1.0+(double)stavka/1200,120)*sum/znam;
    Vyplati=okruglenie(Vyplati);
    return Vyplati;
}

double vklad(double Summa,int stavkavklada,int months) {
    if (months>0) {
        Summa=Summa*(1.0+(double)stavkavklada/1200);
        return vklad(Summa,stavkavklada,months-1);
    } else {

        Summa=okruglenie(Summa);
        return Summa;
    }
}

double rashodi(double Summa,int arenda, int months){
    double raznica;
    raznica=Summa-1000000-arenda*months;
    raznica=okruglenie(raznica);
    return raznica;
}

void biblio() {
    int sum=5000000;
    int stavka=18;
    double money=1000000;
    int stavkavklada=10;
    int arenda=20000;
    printf("Month \tIpoteka \tvklad \trashodi\n");
    for (int q=1;q<121;q++) {
        double Vyplati;
        Vyplati=ipoteka(sum,stavka);
        double Summa;
        Summa=vklad(money,stavkavklada,q);
        double raznica;
        raznica=rashodi(Summa,arenda,q);
        printf("%d",q);
        printf("\t%10.2lf",Vyplati);
        printf("\t%10.2lf",Summa);
        printf("\t%10.2lf\n",raznica);
    }
}