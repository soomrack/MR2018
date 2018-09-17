//
// Created by science on 16.09.18.
//

#include "librain.h"

#include <stdio.h>
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
        }
        else {
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

void main2()
{



                        int count=0;
                typedef struct data
                {
                        long int effect;
                        long int summm;
                        int percent;
                } client;
                client data[121];
                client tmp;
                for(int stavka=10; stavka<=20; stavka++)
                {
                        for(long int sum=5000000; sum<=15000000; sum+=1000000)
                        {
                                double money = 1000000;
                                long int stavkavklada = 10;
                                int arenda = 20000;
                                double paid = 0;
                                double Vyplati;
                                double Summa;
                                double raznica;
                                for (int q = 1; q<120; q++) {
                                        Vyplati = ipoteka(sum, stavka);
                                        Summa = vklad(money, stavkavklada, q);
                                        raznica = rashodi(Summa, arenda, q);
                                        paid += Vyplati;
                                        //  if (q%12==0) {
                                        //    printf("%d", q/12); }
                                }
                                data[count].effect=(int)((Vyplati*120)-sum);
                                data[count].summm=sum;
                                data[count].percent=stavka;
                                count++;
                        }
                }
                int n=121;
                for(int i = 0 ; i < n - 1; i++) {
                        for(int j = 0 ; j < n - i - 1 ; j++) {
                                if(data[j].effect > data[j+1].effect) {
                                        tmp = data[j];
                                        data[j] = data[j+1];
                                        data[j+1] = tmp;
                                }
                        }
                }
                for(int i = 0 ; i < n - 1; i++) {
                        printf("%10li рублей переплаты при ставке %i%% и сумме %8li рублей на 10 лет\n", data[i].effect, data[i].percent, data[i].summm);
                }
                /* printf("Выплачено %10.2lf\n",paid);
                double newsum = Vyplati * 120.0 - paid;
                stavka = 17;
                printf("Осталось %10.2lf\n",newsum);
                for (int k = 97; k < 217; k++) {
                        Vyplati = ipoteka((long int) newsum, stavka);
                        Summa = vklad(money, stavkavklada, k);
                        raznica = rashodi(Summa, arenda, k);
                        if (k % 12 == 0) {
                                printf("%d", k / 12);
                                printf("\t%10.2lf\n", Vyplati * 12.0);
                        }
                }*/
                return 0;

}
