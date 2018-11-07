//#include "mcu_support_package/inc/stm32f10x.h"

#include "eval1.h"

#include <string.h>

#include <stdlib.h>

#include <stdio.h>

static int lev;
static int max_level = 1;
static short int lev_drob = 0;
static char sign;
static char out_sign;
static int counter;
static int start_clean;
static int end_clean;
static int check;
static int drob = 0;
static int minus_flag = 0;
static int check_len = 0;
static int count_1 = 0;
static int count_2 = 0;
static int count = 0;
char myformula [100];
static char chislo_1[100];
static char *ptr;

static int level[100];
int32_t eval1( const char * formula )
{
    strcpy(myformula, formula);
    unsigned int len = strlen(myformula);
    unsigned int length = len;
    static int result = 0;
    do {
        sign = ' ';
        out_sign = ' ';
        check = 0;
        minus_flag = 0;
        check_len = 0;
        lev = 0;
        for (int i = 0; i < length; ++i)
        {
            if (myformula[i] == ' ') {                  //clean all spaces
                for (int k = i; k < length; k++) {
                    myformula[k] = myformula[k + 1];
                }
                length--;
            }
            if (myformula[i] == ' ')
                i--;

        }
        while ((myformula[check_len] == ')') || (myformula[check_len] == '+') || (myformula[check_len] == '-') || (myformula[check_len] == '*') ||
               (myformula[check_len] == '/') || (myformula[check_len] == '(') || ((myformula[check_len] >= '0') && (myformula[check_len] <= '9')))
            check_len ++;
        length = check_len ;

        myformula[length] = ('\0');
        for (int i = 0; i < length ; ++i) {
            if ((myformula[i] == '(') || ((myformula[i] >= '0') && (myformula[i] <= '9'))) {
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

        int sym = 0;

        while (level[sym] != max_level)
            sym++;
        for (int i = 0; i<length; i++)
        {
            if ((level[i] == level[sym])&&(myformula[i] == '('))
            {
                sym = i;
                break;
            }

        }

        if (myformula[sym-1] == '(')
            start_clean = sym-1;
        else
            start_clean = sym;
        counter = 0;
        while (!(myformula[sym] >= '0' && myformula[sym] <= '9'))
            sym++;
        while (myformula[sym] >= '0' && myformula[sym] <= '9') {
            if ((myformula[sym - 1] == '-') && ((sym - 1) >= start_clean))
                minus_flag = 1;
            if (((myformula[sym-3] == '+') || (myformula[sym-3] == '-') || (myformula[sym-3] == '*') ||
                 (myformula[sym-3] == '/')) && (myformula[sym-2] == '('))
            {
                out_sign = myformula[sym-3];
                start_clean = sym-3;
            }
            if (((myformula[sym-2] == '+') || (myformula[sym-2] == '-') || (myformula[sym-2] == '*') ||
                 (myformula[sym-2] == '/')) && (myformula[sym-1] == '('))
            {
                out_sign = myformula[sym-2];
                start_clean = sym-2;
            }
            chislo_1[counter] = myformula[sym];
            counter++;
            sym++;
        }

        chislo_1[counter] = '\0';
        count_1 = strtol(chislo_1,  &ptr, 10);

        if (minus_flag)
            count_1 *= (-1);
        if ((myformula[sym] == '+') || (myformula[sym] == '-') || (myformula[sym] == '*') ||
            (myformula[sym] == '/'))
        {

            sign = myformula[sym];
            sym++;
            counter = 0;
            while (myformula[sym] >= '0' && myformula[sym] <= '9') {
                chislo_1[counter] = myformula[sym];
                counter++;
                sym++;
            }
            chislo_1[counter] = '\0';
            count_2 = strtol(chislo_1,  &ptr, 10);
            switch (sign) {
                case '-':
                    count = count_1 - count_2;
                    break;
                case '+':
                    count = count_1 + count_2;
                    break;
                case '*':
                    count = count_1 * count_2;
                    if (lev_drob == max_level )
                    {
                        drob *= count;
                    }

                    break;
                case '/':
                    drob = (count_1 % count_2* 100 / count_2);
                    lev_drob = max_level;
                    count= count_1/count_2;

                    break;

            }
        }
        else
        {
            count = count_1;
        }
        switch (out_sign) {
            case '-':
                result -= count;
                break;
            case '+':
                result +=  count;
                break;
            case '*':
                result *= count;
                if (lev_drob == max_level )
                {
                    drob *= count;
                }

                break;
            case '/':
                drob = (result % count* 100 / count);
                lev_drob = max_level;
                result /= count;

                break;
            default:
                result += count;
                break;
        }
        if (myformula[sym] == ')') end_clean = sym;
        else end_clean = sym - 1;
        max_level--;

        for (int i = start_clean; i <= end_clean; i++) {
            myformula[i] = ' ';
        }

        for (int i = 0; i < length; i++) {
            if ((myformula[i] != ' ') && (myformula[i] != '(') && (myformula[i] != ')'))
            {
                check = 1;
            }
        }
    }  while (check == 1);
    if (drob != 0)
        result += drob/100;

    return result;
}

int64_t eval_64( const char * formula )
{
#warning Implement this!
    return 0;
}
