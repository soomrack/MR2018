//#include "mcu_support_package/inc/stm32f10x.h"

#include "eval1.h"

#include <string.h>

#include <stdlib.h>

#include <stdio.h>

//#include <malloc.h>

int32_t eval1( const char * formula )
{

    char myformula [sizeof(formula)+15];
    sprintf(myformula,"%s         \0", formula);
    const int len = strlen(myformula);
    printf("len %d\n", len);
    int level[sizeof(formula)+15];

    static int lev = 0;
    static int max_level = 1;

    short int lev_drob = 0;
    //char chislo_2[len];
    static char sign;
    static int count;
    int counter;
    static int start_clean;
    static int end_clean;
    static int check;
    int drob=0;

    int result;
    int length = len;
    char chislo_2[length];
    char chislo_1[length];
    do {
        check = 0;
        for (int i = 0; i < length; ++i) {
            /*if (myformula[i] == '(')
            {
                int n = i;
                while (!((myformula[n] >= '0') && (myformula[n] <= '9')))
                {
                    if (myformula[n] == '-')
                    {
                        for (int m = length; m > n; m--) {
                            myformula[m] = myformula[m - 1];
                        }
                        myformula[n] = '0';
                        break;
                    }
                    n++;
                }
            }*/
            /*if ((myformula[i] == '-')&&(myformula[i+1] == '-'))
            {
                myformula[i] = '+';
                myformula[i+1] = ' ';
            }
            if ((myformula[i] == '+')&&(myformula[i+1] == '-'))
            {
                myformula[i] = '-';
                myformula[i+1] = ' ';
            }*/


            if (myformula[i] == ' ') {
                for (int k = i; k < length; k++) {
                    myformula[k] = myformula[k + 1];
                }
                length--;
            }
            if (myformula[i] == ' ')
                i--;

        }
        myformula[length+1] = ('\0');
        for (int i = 0; i < length; ++i) {
            printf("%c\n", myformula[i]);
        }

        for (int i = 0; i < length + 1; ++i) {
            if ((myformula[i] == ',') ||(myformula[i] == '(') || ((myformula[i] >= '0') && (myformula[i] <= '9'))) {
                if (!(myformula[i - 1] >= '0') || !(myformula[i - 1] <= '9')) {
                    lev++;
                }
                level[i] = lev;
                if (level[i] > max_level)
                    max_level = level[i];
            }
            if ((myformula[i] == ')') || (myformula[i] == '+') || (myformula[i] == '-') || (myformula[i] == '*') ||
                (myformula[i] == '/')) {
                lev--;
                level[i] = lev;
            }
        }

        for (int i = 0; i < length + 1; ++i) {
            printf("%d\n", level[i]);
        }

        for (int i = 0; i < length + 1; ++i) {
            if (level[i] == max_level) {
                if (myformula[i - 1] == '(') start_clean = i - 1;
                else start_clean = i;
                counter = 0;

                while (myformula[i] >= '0' && myformula[i] <= '9') {
                    chislo_1[counter] = myformula[i];
                    counter++;
                    i++;
                }

                chislo_1[counter] = '\0';
                sign = myformula[i];
                i++;
                counter = 0;
                while (myformula[i] >= '0' && myformula[i] <= '9') {
                    chislo_2[counter] = myformula[i];
                    counter++;
                    i++;
                }
                chislo_2[counter] = '\0';
                if (myformula[i] == ')') end_clean = i;
                else end_clean = i - 1;
                break;
            }
        }
        printf("chislo_1=");
        for (counter = 0; counter < length; counter++) {
            printf("%c", chislo_1[counter]);
        }
        printf("\n");


        printf("sign %c\n", sign);
        printf("chislo_2=");
        for (counter = 0; counter < length + 1; counter++) {
            printf("%c", chislo_2[counter]);
        }
        switch (sign) {
            case '-':

                count = atoi(chislo_1) - atoi(chislo_2);
                break;
            case '+':
                count = atoi(chislo_1) + atoi(chislo_2);
                break;
            case '*':
                count = atoi(chislo_1) * atoi(chislo_2);
                if (lev_drob == max_level )
                {
                    drob *= atoi(chislo_2);

                }

                break;
            case '/':
                count = atoi(chislo_1) / atoi(chislo_2);
                drob = (atoi(chislo_1) % atoi(chislo_2)*100/atoi(chislo_2));
                lev_drob = max_level;
                break;
            default:
                count = atoi(chislo_1);
        }
        printf("\n count %d\n", count);

        char count_char[length * 2];
        if (drob != 0 ) sprintf(count_char, "%d , %d %c", count, drob, '\0');
        sprintf(count_char, "%d %c", count, '\0');

        int k;
        for (int i = start_clean; i <= end_clean; i++) {
            int s = 0;
            while (count_char[s] != '\0')
            {
                myformula[i] = count_char[s];
                s++;
                i++;
            }
            k=i;
            break;
        }
        for (int i = k; i <= end_clean; i++) {
            myformula[i] = ' ';

        }

        printf("myformula");
        for (int i = 0; i < length; i++) {
            if (!((myformula[i] >= '0') && (myformula[i] <= '9'))&&(myformula[i] != '-')&&(myformula[i] != ' ') &&(myformula[i] != ','))
            {check = 1;}
            printf("%c", myformula[i]);
        }
        printf("\n");
    }  while (check == 1);
    if (drob == 0)
        result = atoi(myformula);
    else result = (atoi(myformula)+drob/100);
    printf("result = %d\n", result);
    return result;
}

int64_t eval_64( const char * formula )
{
#warning Implement this!
    return 0;
}
